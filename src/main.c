#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "metatiles.h"
#include <maxmod.h>
#include "soundbank.bin.h"
#include "soundbank.h"

#define NUM_CHANNELS 8
ALIGN4 u8 myMixingBuffer[MM_MIXLEN_31KHZ];
EWRAM_DATA u8 music_data[NUM_CHANNELS * (MM_SIZEOF_MODCH
                               +MM_SIZEOF_ACTCH
                               +MM_SIZEOF_MIXCH)
                               +MM_MIXLEN_31KHZ];

void vblank_handler() {
    mmVBlank();
    
    // Run sound
    mmFrame();
}

void init_maxmod() {
    u8* myData;
    mm_gba_system mySystem;
 
    // Allocate data for channel buffers & wave buffer (malloc'd data goes to EWRAM)
    // Use the SIZEOF definitions to calculate how many bytes to reserve
    myData = music_data;
    
    // Setup system info
    // 31KHz software mixing rate, select from mm_mixmode
    mySystem.mixing_mode       = MM_MIX_31KHZ;


    // Number of module/mixing channels
    // Higher numbers offer better polyphony at the expense
    // of more memory and/or CPU usage
    mySystem.mod_channel_count = NUM_CHANNELS;
    mySystem.mix_channel_count = NUM_CHANNELS;
    
    // Assign memory blocks to pointers
    mySystem.module_channels   = (mm_addr)(myData+0);
    mySystem.active_channels   = (mm_addr)(myData+(NUM_CHANNELS*MM_SIZEOF_MODCH));
    mySystem.mixing_channels   = (mm_addr)(myData+(NUM_CHANNELS*(MM_SIZEOF_MODCH
	                                             +MM_SIZEOF_ACTCH)));
    mySystem.mixing_memory     = (mm_addr)myMixingBuffer;
    mySystem.wave_memory       = (mm_addr)(myData+(NUM_CHANNELS*(MM_SIZEOF_MODCH
                                                     +MM_SIZEOF_ACTCH
                                                     +MM_SIZEOF_MIXCH)));
    // Pass soundbank address
    mySystem.soundbank         = (mm_addr)soundbank_bin;

    mmInit( &mySystem );
    irq_init(NULL);
    irq_set(II_VBLANK, vblank_handler, 0);
    irq_enable(II_VBLANK);
}
s32 main() {
    init_maxmod();
    
    // Enable BG 0, 1 and 2, also enable sprites
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_2D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(24) | BG_REG_32x32;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(25) | BG_REG_32x32;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(2) | BG_SBB(26) | BG_REG_32x32 | BG_PRIO(1);
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;

    REG_BLDCNT = BLD_BUILD(BLD_OBJ, BLD_BG2, BLD_STD);

    BFN_SET(REG_BLDCNT, BLD_MODE(1), BLD_MODE);

    // Update blend weights
    REG_BLDALPHA = BLDA_BUILD(0x80/8, 0x70/8);

    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[0][0], blockset, sizeof(blockset) / 4);
    memcpy32(&tile_mem[2][0], bg_chr, sizeof(bg_chr) / 4);
    memcpy16(&se_mem[26][0], bg_tiles, sizeof(bg_tiles) / 2);
    memcpy16(pal_bg_mem, blockPalette, sizeof(blockPalette) / sizeof(COLOR));

    memcpy32(&tile_mem_obj[0][0], player0_icon, sizeof(player0_icon) / 4);
    memcpy32(&tile_mem_obj[0][64], sprites_chr, sizeof(sprites_chr) / 4);
    memcpy16(pal_obj_mem, spritePalette, sizeof(spritePalette) / sizeof(COLOR));
    
    mmStart(MOD_STEREOMA, MM_PLAY_ONCE);

    load_level(stereomadness_ID);

    while(1) {
        key_poll();
        nextSpr = 0;

        // Copy OAM buffer into OAM
        obj_copy(oam_mem, shadow_oam, 128);
        obj_aff_copy(obj_aff_mem, obj_aff_buffer, 32);

        // Clear OAM
        memset32(shadow_oam, ATTR0_HIDE, 256);
        
        // Clear rotation buffer
        memset16(rotation_buffer, 0x0000, NUM_ROT_SLOTS);

        REG_BG0HOFS = REG_BG1HOFS = scroll_x >> 8;
        REG_BG0VOFS = REG_BG1VOFS = scroll_y >> 8;

        REG_BG2HOFS = scroll_x >> 10;
        REG_BG2VOFS = 34 + (scroll_y >> 13);

        if (player_death) reset_level();

        // Run color stuff
        run_col_trigger_changes();

        // Copy palette from buffer
        memcpy32(pal_bg_mem, palette_buffer, 256);
        
        // Run scroll routines
        screen_scroll_load();

        // END OF VBLANK STUFF

        // Run player routines
        if (!player_death) player_main();

        // Run object routines
        display_objects();
        load_next_object();

        // Wait for VSYNC
        VBlankIntrWait();
    }

    return 0;
}
