#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "metatiles.h"
#include "physics_defines.h"
#include <maxmod.h>
#include "soundbank.bin.h"
#include "soundbank.h"
#include "menu.h"

void game_loop();
u32 paused_routines();

ALIGN4 u8 myMixingBuffer[MM_MIXLEN_31KHZ];

void vblank_handler() {
    mmVBlank();

    // Only use the update handler on a level
    if (game_state == STATE_PLAYING && frame_finished) {
        if (!player_death) mirror_transition();

        if (swap_queue) swap_screen_dir();

        load_chr_in_buffer();
        unload_chr_in_buffer();

        if (update_flags & UPDATE_OAM) {
            // Copy OAM buffer into OAM
            obj_copy(oam_mem, shadow_oam, 128);
            obj_aff_copy(obj_aff_mem, obj_aff_buffer, 32);
        }

        if (update_flags & UPDATE_SCROLL) {
            // If screen is mirrored, flip screen position so it goes left instead of right
            if (screen_mirrored) {
                REG_BG0HOFS = REG_BG1HOFS = 256 - (((scroll_x >> SUBPIXEL_BITS) - 16) & 0xff);
                REG_BG2HOFS = 256 - ((scroll_x >> (2+SUBPIXEL_BITS)) & 0xff);
            } else {
                REG_BG0HOFS = REG_BG1HOFS = scroll_x >> SUBPIXEL_BITS;
                REG_BG2HOFS = scroll_x >> (2+SUBPIXEL_BITS);
            }

            REG_BG0VOFS = REG_BG1VOFS = scroll_y >> SUBPIXEL_BITS;
            REG_BG2VOFS = 34 + (scroll_y >> (5+SUBPIXEL_BITS));

            // Run scroll routines
            screen_scroll_load();
        }

        if (update_flags & UPDATE_VRAM) {
            // Run color stuff
            run_col_trigger_changes();
            
            // Update particles
            run_particles();

            // Copy palette from buffer
            memcpy32(pal_bg_mem, palette_buffer, 256);
        }

        if (update_flags & CLEAR_OAM_BUFFER) {
            // Clear OAM
            memset32(shadow_oam, ATTR0_HIDE, 256);
            // Clear rotation buffer
            memset16(rotation_buffer, 0x0000, NUM_ROT_SLOTS);
        }
    }

    // Increment global timer
    global_timer++;

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
    // 16KHz software mixing rate, select from mm_mixmode
    mySystem.mixing_mode       = MM_MIX_16KHZ;

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

    // Enable waitstate 3,1
    REG_WAITCNT = 0x4317;

    REG_BLDCNT = BLD_BUILD(BLD_OBJ, BLD_BG2, BLD_STD);

    BFN_SET(REG_BLDCNT, BLD_MODE(1), BLD_MODE);

    // Update blend weights
    REG_BLDALPHA = BLDA_BUILD(0x80/8, 0x70/8);

    while(1) {
        switch (game_state) {
            case STATE_MENU:
                menu_loop();
                break;
            
            case STATE_PLAYING:
                game_loop();
                break;
        }
    }

    return 0;
}

void game_loop() {
    // Fade out
    fade_out();

    mirror_scaling = float2fx(1.0);

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(24) | BG_REG_32x32 | BG_PRIO(0);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(25) | BG_REG_32x32 | BG_PRIO(1);
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(2) | BG_SBB(26) | BG_REG_32x32 | BG_PRIO(2);
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;

    REG_BLDCNT = BLD_BUILD(BLD_OBJ, BLD_BG2, BLD_STD);

    BFN_SET(REG_BLDCNT, BLD_MODE(1), BLD_MODE);

    REG_WININ = WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BLD | WIN_OBJ;
    REG_WINOUT = WIN_BG2;

    REG_WIN0H = SCREEN_WIDTH;
    REG_WIN0V = SCREEN_HEIGHT;


    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[0][0], blockset, sizeof(blockset) / 4);
    memcpy32(&tile_mem[2][0], bg_chr, sizeof(bg_chr) / 4);
    memcpy16(&se_mem[26][0], bg_tiles, sizeof(bg_tiles) / 2);
    memcpy16(palette_buffer, blockPalette, sizeof(blockPalette) / sizeof(COLOR));

    memcpy32(&tile_mem_obj[0][0], player0_icon, sizeof(player0_icon) / 4);
    memcpy16(&palette_buffer[256], spritePalette, sizeof(spritePalette) / sizeof(COLOR));

    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_WIN0;

    load_level(loaded_level_id);

    frame_finished = TRUE;
    fade_in_level();

    while (1) { 
        frame_finished = FALSE;
        key_poll();

        // If pressed start, pause the game
        if (key_hit(KEY_START)) {
            if (paused_routines()) {
                game_state = STATE_MENU;      
                memcpy32(palette_buffer, pal_bg_mem, 256);
                fade_out();
                return;
            }
        }
        
#ifdef DEBUG
        if (key_hit(KEY_SELECT)) {
            debug_mode ^= 1;
            noclip = 0;
        }

        if (debug_mode && key_hit(KEY_L)) {
            noclip ^= 1;
        }
#endif

        nextSpr = 0;

        // Run vertical scroll code
        scroll_screen_vertically();

        s64 last_player_x = player_x;
        // Run player routines
        if (!player_death) player_main();

        // Start the song once the player goes from negative to positive x position
        if ((last_player_x < 0) != (player_x < 0)) mmStart(loaded_song_id, MM_PLAY_ONCE);
        
        if (player_death) reset_level();

        // Run object routines
        load_objects();
        deoccupy_chr_slots();
        display_objects();
        
        
        rotate_saws();
        scale_pulsing_objects();

#ifdef DEBUG
        if (noclip) oam_metaspr(0, 0, debugModeSpr, 0, 0, 0, 0); 
#endif
        sort_oam_by_prio();

        // Mark the frame as finished
        frame_finished = TRUE;
#ifdef DEBUG
        if (debug_mode) {
            // I know this copies more bytes than it should, but some time has to be wasted for the line to cover an entire scanline
            memset32(pal_bg_mem, 0x7fff7fff, 512);
            memcpy32(pal_bg_mem, palette_buffer, 256);
        }
#endif

        // Wait for VSYNC
        VBlankIntrWait();
    }
}

u32 paused_routines() {
    update_flags = UPDATE_NONE;
    // Dim screen
    clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 16);
    mmPause();

    while (1) {
        key_poll();
        
        // Unpause
        if (key_hit(KEY_START)) {
            update_flags = UPDATE_ALL;
            break;
        }

        if (key_hit(KEY_B)) {
            return 1;
        }

        // Wait for VSYNC
        VBlankIntrWait();
    }

    clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 0);

    mmResume();

    return 0;
}
