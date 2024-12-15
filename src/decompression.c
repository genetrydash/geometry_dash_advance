#include "decompression.h"
#include "memory.h"
#include "main.h"
#include "metatiles.h"

// RLE variables
s32 value[LEVEL_LAYERS];
s32 length[LEVEL_LAYERS];

// Scroll seam pos
s32 seam_x, seam_y;

// Last decompressed column
u8 decompressed_column;


void screen_scroll_load();
void decompress_column(u32 layer);
void scroll_H(u32 layer);
void increment_column();
void put_ground_column();

void decompress_first_screen() {
    // Decompress the first screen
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        curr_column = 0;
        seam_x = scroll_x;
        // Init RLE values for this layer
        value[layer] = *level_pointer[layer];
        level_pointer[layer]++;
        length[layer] = *level_pointer[layer];
        level_pointer[layer]++;

        for (s32 i = 0; i < 16; i++) {
            decompress_column(layer);
            put_ground_column();
            // Draw this column
            for (s32 j = 0; j < 2; j++) {
                seam_y = scroll_y;
                scroll_H(layer);
                seam_x += 8;
            }
            increment_column();
        }
    }
}

void put_ground_column() {
    // Put ground column in the first layer, no need to put it in both as l1  will hide l2's ground
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
            se_plot(&se_mem[24 + layer][0], x, y, tile);
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
            se_plot(&se_mem[24 + layer][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
    // If the scroll x value changed block position, decompress a new column in both layers
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