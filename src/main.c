#include <tonc.h>
#include "main.h"
#include "memory.h"

// in pixels
u64 scroll_x = 0;
u32 scroll_y = 0;
u8 decompressed_column;

// both variables are in subpixels
u16 scroll_x_subacc = 0;
u16 scroll_y_subacc = 0;

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

    REG_BG1CNT  = BG_CBB(1) | BG_SBB(18) | BG_REG_32x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;

    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[0][0], metatiles_pngTiles, metatiles_pngTilesLen / sizeof(u32));
	memcpy16(pal_bg_mem, blockPalette, sizeof(blockPalette) / sizeof(u16));

    memcpy32(&tile_mem[4][0], cube_pngTiles, cube_pngTilesLen / sizeof(u32));
    memcpy32(&tile_mem[4][4], portal_pngTiles, portal_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, cube_pngPal, 16);
	memcpy16(&pal_obj_mem[16], portal_pngPal, 8);

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

    player_y = ((GROUND_HEIGHT - 1) << 12);
    scroll_y = ((player_y) - 0x7000) >> 8;

    for (s32 i = 0; i < 16; i++) {
        decompress_column();
        for (s32 j = 0; j < 2; j++) {
            seam_y = scroll_y;
            scroll_H();
            seam_x += 8;
        }
    }

    decompressed_column = 0;

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

void scroll_H() {
    for (s32 mt = 0; mt < 12; mt += 1) {
        for (s32 vtile = 0; vtile < 2; vtile++) {
            // Get metatile positions from seam
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);

            // Get metatile from the buffer
            s32 metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];

            // Get tile position from the seam
            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;

            // Obtain tile from the metatile table
            s32 tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            // Put tile and advance to next tile
            se_plot(&se_mem[16][0], x, y, tile);
            seam_y += 8;
        }
    }   
}

void scroll_V() {
    for (s32 mt = 0; mt < 16; mt += 1) {
        for (s32 htile = 0; htile < 2; htile++) {
            // Get metatile positions from seam
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);
            
            // Get metatile from the buffer
            s32 metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];
            
            // Get tile position from the seam
            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;

            // Obtain tile from the metatile table
            s32 tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            // Put tile and advance to next tile
            se_plot(&se_mem[16][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
    // If the scroll x value changed block position, decompress a new column
    if (decompressed_column != ((scroll_x >> 4) & 0xff)) {
        decompress_column();
        decompressed_column += 1;
    } 
    
    // Draw horizontal seam
    seam_x = scroll_x + SCREEN_WIDTH;
    seam_y = scroll_y;
    
    scroll_H();

    // Draw bottom seam
    seam_x = scroll_x;
    seam_y = scroll_y + SCREEN_HEIGHT;
    
    scroll_V();
    
    // Draw top seam
    seam_x = scroll_x;
    seam_y = scroll_y - 8;
        
    scroll_V();
}

void decompress_column() {
    // RLE decompress an entire column of curr_level_height blocks
    for (s32 i = 0; i < curr_level_height; i++) {
        if (length == 0) {
            // If next RLE packet is ready, start with it
            value = *level_pointer;
            level_pointer++;
            length = *level_pointer;
            level_pointer++;
        }

        // Put the block on the buffer, exactly curr_level_height blocks above the ground and then i blocks down
        level_buffer[curr_column + (((GROUND_HEIGHT) - curr_level_height + i) * LEVEL_BUFFER_WIDTH)] = value;
        length--;
    }

    // Put ground
    for (s32 i = GROUND_HEIGHT; i < MAX_LEVEL_HEIGHT; i++) {
        if (i == GROUND_HEIGHT) {
            // If we are at the first row of blocks, use the top row blocks
            level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[curr_column & 0x3];
        } else {
            // Else, the middle ground blocks
            level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[4 + (curr_column & 0x3)];
        }
    }

    // Increment for the next column of metatiles
    curr_column++;

    // If we are past the buffer width, go back to the start of it
    if (curr_column >= LEVEL_BUFFER_WIDTH) curr_column = 0;
}