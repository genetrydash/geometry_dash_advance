#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "metatiles.h"

s32 main() {
    // Enable BG 0, 1 and 2, also enable sprites
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(24) | BG_REG_32x32;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(25) | BG_REG_32x32;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(2) | BG_SBB(26) | BG_REG_32x32;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;

    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[0][0], blockset, sizeof(blockset) / 4);
    memcpy32(&tile_mem[2][0], bg_chr, sizeof(bg_chr) / 4);
    memcpy16(&se_mem[26][0], bg_tiles, sizeof(bg_tiles) / 2);
    memcpy16(pal_bg_mem, blockPalette, sizeof(blockPalette) / sizeof(COLOR));

    memcpy32(&tile_mem_obj[0][0], player0_icon, sizeof(player0_icon) / 4);
    memcpy32(&tile_mem_obj[0][64], sprites_chr, sizeof(sprites_chr) / 4);
    memcpy16(pal_obj_mem, spritePalette, sizeof(spritePalette) / sizeof(COLOR));

    load_level(stereomadness_ID);
    
    irq_init(NULL);
    irq_add(II_VBLANK, NULL);

    while(1) {
        // Wait for VSYNC
        VBlankIntrWait();
        key_poll();

        nextSpr = 0;

        // Copy OAM buffer into OAM
        obj_copy(oam_mem, shadow_oam, 128);
        obj_aff_copy(obj_aff_mem, obj_aff_buffer, 1);

        // Clear OAM
        memset32(shadow_oam, ATTR0_HIDE, 256);

        REG_BG0HOFS = REG_BG1HOFS = scroll_x >> 8;
        REG_BG0VOFS = REG_BG1VOFS = scroll_y >> 8;

        REG_BG2HOFS = scroll_x >> 10;
        REG_BG2VOFS = 34 + (scroll_y >> 13);

        if (player_death) reset_level();

        // Run color stuff
        run_col_triggers();
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
    }

    return 0;
}
