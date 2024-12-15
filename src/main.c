#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "metatiles.h"

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
s32 value[LEVEL_LAYERS];
s32 length[LEVEL_LAYERS];

// Scroll seam pos
s32 seam_x, seam_y;

void screen_scroll_load();
void decompress_column(u32 layer);
void scroll_H(u32 layer);
void increment_column();
void put_ground_column();

s32 main() {
    // Enable BG 0 and 1, also enable sprites
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
    
    // Set RLE initial values
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        curr_column = 0;
        seam_x = scroll_x;
        value[layer] = *level_pointer[layer];
        level_pointer[layer]++;
        length[layer] = *level_pointer[layer];
        level_pointer[layer]++;

        for (s32 i = 0; i < 16; i++) {
            decompress_column(layer);
            put_ground_column();
            for (s32 j = 0; j < 2; j++) {
                seam_y = scroll_y;
                scroll_H(layer);
                seam_x += 8;
            }
            increment_column();
        }
    }

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
void put_ground_column() {
    // Put ground
    for (s32 i = GROUND_HEIGHT; i < MAX_LEVEL_HEIGHT; i++) {
        if (i == GROUND_HEIGHT) {
            // If we are at the first row of blocks, use the top row blocks
            level_buffer[0][curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[curr_column & 0x3];
        } else {
            // Else, the middle ground blocks
            level_buffer[0][curr_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[4 + (curr_column & 0x3)];
        }
    }
}
void increment_column() {
    // Increment for the next column of metatiles
    curr_column++;

    // If we are past the buffer width, go back to the start of it
    if (curr_column >= LEVEL_BUFFER_WIDTH) curr_column = 0;
}

void scroll_H(u32 layer) {
    for (s32 mt = 0; mt < 12; mt += 1) {
        for (s32 vtile = 0; vtile < 2; vtile++) {
            // Get metatile positions from seam
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);

            // Get metatile from the buffer
            s32 metatile = level_buffer[layer][metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];

            // Get tile position from the seam
            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;

            // Obtain tile from the metatile table
            s32 tile = metatiles[metatile][(x & 1) | ((y & 1) << 1)];

            // Put tile and advance to next tile
            se_plot(&se_mem[16 + layer][0], x, y, tile);
            seam_y += 8;
        }
    }   
}

void scroll_V(u32 layer) {
    for (s32 mt = 0; mt < 16; mt += 1) {
        for (s32 htile = 0; htile < 2; htile++) {
            // Get metatile positions from seam
            s32 metatile_x = (seam_x >> 4) & 0x1f;
            s32 metatile_y = (seam_y >> 4);
            
            // Get metatile from the buffer
            s32 metatile = level_buffer[layer][metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];
            
            // Get tile position from the seam
            s32 x = (seam_x >> 3) & 0x1f;
            s32 y = (seam_y >> 3) & 0x1f;

            // Obtain tile from the metatile table
            s32 tile = metatiles[metatile][(x & 1) | ((y & 1) << 1)];

            // Put tile and advance to next tile
            se_plot(&se_mem[16 + layer][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
    // If the scroll x value changed block position, decompress a new column
    if (decompressed_column != ((scroll_x >> 4) & 0xff)) {
        decompress_column(0);
        decompress_column(1);
        put_ground_column();
        decompressed_column += 1;

        increment_column();
    } 
    
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Draw horizontal seam
        seam_x = scroll_x + SCREEN_WIDTH;
        seam_y = scroll_y;
        
        scroll_H(layer);

        // Draw bottom seam
        seam_x = scroll_x;
        seam_y = scroll_y + SCREEN_HEIGHT;
        
        scroll_V(layer);
        
        // Draw top seam
        seam_x = scroll_x;
        seam_y = scroll_y - 8;
            
        scroll_V(layer);
    }
}

void decompress_column(u32 layer) {
    // RLE decompress an entire column of curr_level_height blocks
    for (s32 i = 0; i < curr_level_height; i++) {
        if (length[layer] == 0) {
            // If next RLE packet is ready, start with it
            value[layer] = *level_pointer[layer];
            level_pointer[layer]++;
            length[layer] = *level_pointer[layer];
            level_pointer[layer]++;
        }

        // Put the block on the buffer, exactly curr_level_height blocks above the ground and then i blocks down
        level_buffer[layer][curr_column + (((GROUND_HEIGHT) - curr_level_height + i) * LEVEL_BUFFER_WIDTH)] = value[layer];
        length[layer]--;
    }
}