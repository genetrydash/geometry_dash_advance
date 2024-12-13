#include <tonc.h>
#include "main.h"
#include "memory.h"

// in pixels
u32 scroll_x = 0;
u32 scroll_y = 0;
u32 scroll_x_for_decompression;

// both variables are in subpixels
u32 scroll_x_subacc = 0;
u32 scroll_y_subacc = 0;

// 0 : up | 1 : down
s8 scroll_y_dir = 0;

// RLE variables
s32 value;
s32 length;

// Scroll seam pos
s32 seam_x, seam_y;

void screen_scroll_load();
void decompress_column();
void scroll_H();

s32 main() {
    // Enable BG 0 and 1, also enable sprites
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(16) | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(1) | BG_SBB(18) | BG_REG_64x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;

    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[4][0], cube_pngTiles, cube_pngTilesLen / sizeof(u32));
    memcpy32(&tile_mem[0][0], metatiles_pngTiles, metatiles_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, cube_pngPal, cube_pngPalLen / sizeof(u16));
	memcpy16(pal_bg_mem, metatiles_pngPal, metatiles_pngPalLen / sizeof(u16));

    // TODO: put this in a function and call it on death, also unhardcode it
    level_pointer = (u16*) &stereomadness_level_data;

    // Set seam position 
    seam_x = scroll_x;
    seam_y = scroll_y;

    // Set RLE initial values
    value = *level_pointer;
    level_pointer++;
    length = *level_pointer;
    level_pointer++;

    // Level height
    curr_level_height = STEREOMADNESS_LEVEL_HEIGHT;

    player_y = (curr_level_height << 12) - 0x10;
    scroll_y_subacc = player_y - 0x8000;
    scroll_y = scroll_y_subacc >> 8;

    for (s32 i = 0; i < 16; i++) {
        decompress_column();
        for (s32 j = 0; j < 2; j++) {
            seam_y = scroll_y;
            scroll_H();
            seam_x += 8;
        }
    }

    scroll_x_for_decompression = 0;

	while(1) {
        // Wait for VSYNC
        vid_vsync();
        key_poll();

        nextSpr = 0;

        // Copy OAM buffer into OAM
        oam_copy(oam_mem, shadow_oam, 128);

        // Run player routines
        player_main();

		REG_BG0HOFS = scroll_x;
		REG_BG0VOFS = scroll_y;

        // Run scroll routines
        screen_scroll_load();
    }

    return 0;
}

#define SSB_MAP_WIDTH CANTLETGO_LEVEL_WIDTH

#define SSB_WIDTH 16
#define SSB_HEIGHT 16
#define SSB_SIZE SSB_WIDTH * SSB_HEIGHT

#define SSB_HOR_SIZE SSB_MAP_WIDTH * SSB_SIZE

void scroll_H() {
    for (s32 i = 0; i < 12; i += 1) {
        for (s32 j = 0; j < 2; j++) {
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);

            s32 metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];

            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;
            s32 tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_y += 8;
        }
    }   
}

void scroll_V() {
    for (s32 i = 0; i < 16; i += 1) {
        for (s32 j = 0; j < 2; j++) {
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);

            s32 metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];
            
            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;
            s32 tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
    if (scroll_x_for_decompression < (scroll_x & 0xfffffff0)) {
        decompress_column();
        scroll_x_for_decompression += 16;
    } 

    seam_x = scroll_x + SCREEN_WIDTH;
    seam_y = scroll_y;
    
    scroll_H();
    

    if (scroll_y_dir) {
        seam_x = scroll_x;
        seam_y = scroll_y + SCREEN_HEIGHT;
        
        scroll_V();
    } else {
        seam_x = scroll_x;
        seam_y = scroll_y - 8;
        
        scroll_V();
    }
}

void decompress_column() {
    for (s32 i = 0; i < curr_level_height; i++) {
        if (length == 0) {
            value = *level_pointer;
            level_pointer++;
            length = *level_pointer;
            level_pointer++;
        }

        level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = value;
        length--;
    }

    for (s32 i = curr_level_height; i < MAX_LEVEL_HEIGHT; i++) {
        if (i == curr_level_height) {
            level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[curr_column & 0x3];
        } else {
            level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[4 + (curr_column & 0x3)];
        }
    }
    curr_column++;
    if (curr_column >= LEVEL_BUFFER_WIDTH) curr_column = 0;
}