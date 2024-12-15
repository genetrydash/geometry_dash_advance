#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "metatiles.h"

// in pixels
u64 scroll_x = 0;
u32 scroll_y = 0;

// both variables are in subpixels
u16 scroll_x_subacc = 0;
u16 scroll_y_subacc = 0;

// 0 : up | 1 : down
s8 scroll_y_dir = 0;

s32 main() {
    // Enable BG 0, 1 and 2, also enable sprites
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(16) | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(17) | BG_REG_32x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(1) | BG_SBB(18) | BG_REG_32x32;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;

    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[0][0], blockset, 16*1024 / sizeof(u32));
	memcpy16(pal_bg_mem, blockPalette, sizeof(blockPalette) / sizeof(u16));

    memcpy32(&tile_mem[4][0], cube_pngTiles, cube_pngTilesLen / sizeof(u32));
    memcpy32(&tile_mem[4][4], portal_pngTiles, portal_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, cube_pngPal, 16);
	memcpy16(&pal_obj_mem[16], portal_pngPal, 8);

    // TODO: put this in a function and call it on death, also unhardcode it
    level_pointer[0] = (u16*) &stereomadness_l1_level_data;
    level_pointer[1] = (u16*) &stereomadness_l2_level_data;
    
    // Level height
    curr_level_height = STEREOMADNESS_LEVEL_HEIGHT;

    player_y = ((GROUND_HEIGHT - 1) << 12);
    scroll_y = ((player_y) - 0x7000) >> 8;

    // Set seam position 
    seam_x = scroll_x;
    seam_y = scroll_y;
    
    decompress_first_screen();

    decompressed_column = 0;

	while(1) {
        // Wait for VSYNC
        vid_vsync();
        key_poll();

        nextSpr = 0;

        // Copy OAM buffer into OAM
        obj_copy(oam_mem, shadow_oam, 128);
        obj_aff_copy(obj_aff_mem, obj_aff_buffer, 1);

        // Run player routines
        player_main();

		REG_BG0HOFS = REG_BG1HOFS = scroll_x;
		REG_BG0VOFS = REG_BG1VOFS = scroll_y;

        // Run scroll routines
        screen_scroll_load();
    }

    return 0;
}
