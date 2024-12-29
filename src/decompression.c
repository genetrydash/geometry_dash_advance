#include "decompression.h"
#include "memory.h"
#include "main.h"
#include "metatiles.h"
#include <maxmod.h>
#include "soundbank.h"
#include "menu.h"
#include "physics_defines.h"
#include "../levels/includes.h"

// RLE variables
u16 value[LEVEL_LAYERS];
s32 length[LEVEL_LAYERS];

u64 bitstream[LEVEL_LAYERS]; // Buffer for the next packed bits
s32 bits_left[LEVEL_LAYERS]; // Track how many bits are left in the current bitstream

// Scroll seam pos
s32 seam_x, seam_y;

// Last decompressed column
u8 decompressed_column;


void screen_scroll_load();
void decompress_column(u32 layer);
void scroll_H(u32 layer);
void increment_column();
void put_ground();
void unpack_rle_packet(u32 layer);

void decompress_first_screen() {
    // Put ground tiles
    put_ground();
    // Decompress the first screen
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        curr_column = 0;
        seam_x = scroll_x >> SUBPIXEL_BITS;
        // Init RLE values for this layer
        unpack_rle_packet(layer);

        for (s32 i = 0; i < 16; i++) {
            decompress_column(layer);
            // Draw this column
            for (s32 j = 0; j < 2; j++) {
                seam_y = (scroll_y >> SUBPIXEL_BITS) - 0x16;
                scroll_H(layer);
                seam_x += 8;
            }
            increment_column();
        }
    }
}

void put_ground() {
    // Put ground column in the first layer, no need to put it in both as l1 will hide l2's ground
    for (u32 ground_column = 0; ground_column < LEVEL_BUFFER_WIDTH; ground_column++) {    
        s32 count = 0;
        // Place a column of blocks
        for (s32 i = GROUND_HEIGHT; i < MAX_LEVEL_HEIGHT; i++) {
            level_buffer[0][ground_column + (i * LEVEL_BUFFER_WIDTH)] = ground_pattern[(count << 2) + (ground_column & 0x3)];
            count++;
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
    for (s32 mt = 0; mt < 16; mt += 1) {
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
    if (decompressed_column != ((scroll_x >> (4+SUBPIXEL_BITS)) & 0xff)) {
        decompress_column(0);
        decompress_column(1);
        decompressed_column += 1;

        increment_column();
    } 
    
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Draw horizontal seam
        seam_x = (scroll_x >> SUBPIXEL_BITS) + SCREEN_WIDTH;
        seam_y = (scroll_y >> SUBPIXEL_BITS) - 0x16;
        
        scroll_H(layer);

        // Draw bottom seam
        seam_x = scroll_x >> SUBPIXEL_BITS;
        seam_y = (scroll_y >> SUBPIXEL_BITS) + SCREEN_HEIGHT + 0x08;
        
        scroll_V(layer);
        
        // Draw top seam
        seam_x = scroll_x >> SUBPIXEL_BITS;
        seam_y = (scroll_y >> SUBPIXEL_BITS) - 0x16;
            
        scroll_V(layer);
    }
}

void unpack_overflow_check(u32 layer, u32 bits_left_check);

#define VALUE_SIZE_BITS 4   // 4 bits for value size
#define COUNT_SIZE_BITS 4   // 4 bits for length size

void unpack_rle_packet(u32 layer) {    

    unpack_overflow_check(layer, VALUE_SIZE_BITS);

    s32 value_length_size = (bitstream[layer] >> (bits_left[layer] - VALUE_SIZE_BITS)) & 0xf;
     bits_left[layer] -= VALUE_SIZE_BITS;
    
    unpack_overflow_check(layer, value_length_size);

    value[layer] = (bitstream[layer] >> (bits_left[layer] - value_length_size)) & ((1 << value_length_size) - 1);
    bits_left[layer] -= value_length_size;
    
    unpack_overflow_check(layer, COUNT_SIZE_BITS);

    s32 count_length_size = (bitstream[layer] >> (bits_left[layer] - COUNT_SIZE_BITS)) & 0xf;
    bits_left[layer] -= COUNT_SIZE_BITS;

    unpack_overflow_check(layer, count_length_size);

    length[layer] = (bitstream[layer] >> (bits_left[layer] - count_length_size)) & ((1 << count_length_size) - 1);
    bits_left[layer] -= count_length_size;
}

void unpack_overflow_check(u32 layer, u32 bits_left_check) {
    if (bits_left[layer] < (s32) bits_left_check) {
        bitstream[layer] = (bitstream[layer] << 32) | *level_pointer[layer];
        bits_left[layer] += 32;

        level_pointer[layer]++;
    }
}

void decompress_column(u32 layer) {
    // RLE decompress an entire column of curr_level_height blocks
    for (s32 i = 0; i < curr_level_height; i++) {
        if (length[layer] < 0) {
            unpack_rle_packet(layer);
        }

        // Put the block on the buffer, exactly curr_level_height blocks above the ground and then i blocks down
        level_buffer[layer][curr_column + (((GROUND_HEIGHT) - curr_level_height + i) * LEVEL_BUFFER_WIDTH)] = value[layer];
        length[layer]--;
    }
}

void set_initial_color(COLOR bg_color, COLOR ground_color) {
    set_bg_color(palette_buffer, bg_color);
    set_ground_color(palette_buffer, ground_color);
}

void reset_variables() {
    player_x = 0;  
    relative_player_x = 0;
    player_y_speed = 0;
    player_size = SIZE_BIG;
    gravity_dir = GRAVITY_DOWN;
    coll_x = 0;
    coll_y = 0;
    player_death = FALSE;
    curr_column = 0;
    on_floor = TRUE;
    bitstream[0] = bitstream[1] = 0;
    bits_left[0] = bits_left[1] = 0;

    scroll_x = 0;

    REG_BG0HOFS = REG_BG1HOFS = 0;
    REG_BG0VOFS = REG_BG1VOFS = scroll_y >> SUBPIXEL_BITS;
    
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 34 + (scroll_y >> (5 + SUBPIXEL_BITS));

    for (u32 index = 0; index < MAX_OBJECTS; index++) {
        object_buffer[index].occupied = FALSE;
    }

    for (u32 channel = 0; channel < CHANNEL_COUNT; channel++) {
        col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE] = FALSE;
    }

    memset32(music_data, 0, sizeof(music_data) / sizeof(u32));

    scale_pulsing_objects();
}

void load_level(u32 level_ID) {
    // Set level pointers
    level_pointer[0] = (u32*) level_defines[level_ID][0];
    level_pointer[1] = (u32*) level_defines[level_ID][1];
    sprite_pointer   = (u32*) level_defines[level_ID][2];
    
    // Get level variables
    COLOR bg_color = level_defines[level_ID][3][0];
    COLOR ground_color = level_defines[level_ID][3][1];
    gamemode = level_defines[level_ID][3][2];
    speed_id = level_defines[level_ID][3][3];
    curr_level_height = level_defines[level_ID][3][4];
    loaded_song_id = level_defines[level_ID][3][5];

    // Limit values to safe values
    if (loaded_song_id >= MSL_NSONGS) loaded_song_id = 0;
    if (curr_level_height >= MAX_LEVEL_HEIGHT) curr_level_height = MAX_LEVEL_HEIGHT - 1;
    if (gamemode >= GAMEMODE_COUNT) gamemode = GAMEMODE_CUBE;
    if (speed_id >= NUM_SPEEDS) speed_id = SPEED_X1;

    // Put player on the ground
    player_y = ((GROUND_HEIGHT - 1) << (4 + SUBPIXEL_BITS)) + (0x2 << SUBPIXEL_BITS);  
    scroll_y = (player_y) - (0x70 << (SUBPIXEL_BITS));

    // Copy palettes into the buffer
    memcpy16(palette_buffer, blockPalette, sizeof(blockPalette) / sizeof(COLOR));
    memcpy16(&palette_buffer[256], spritePalette, sizeof(spritePalette) / sizeof(COLOR));

    // Set BG and ground colors
    set_initial_color(bg_color, ground_color);

    // Reset gameplay vars
    reset_variables();
    
    // Set seam position and decompress the first screen
    seam_x = scroll_x >> SUBPIXEL_BITS;
    seam_y = scroll_y >> SUBPIXEL_BITS;
    
    decompress_first_screen();

    decompressed_column = 0;
    
    // Load objects
    load_objects(); 
}

void fade_out() {
    // Fade out
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, frame);
    }
}

void fade_in_level() {
    // Fade in
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        key_poll();
        
        nextSpr = 0;

        // Update OAM
        obj_copy(oam_mem, shadow_oam, 128);
        obj_aff_copy(obj_aff_mem, obj_aff_buffer, 32);
        
        // Run object routines
        display_objects();
        
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 32 - frame);
    }
}

void fade_in() {
    // Fade in
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        key_poll();
        
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 32 - frame);
    }
}

void reset_level() {
    mmStop();
    // Wait a bit before fading
    for (s32 frame = 0; frame < 30; frame++) {
        VBlankIntrWait();
    }

    fade_out();

    oam_init(shadow_oam, 128);
    load_level(loaded_level_id);

    fade_in_level();
    
    mmStart(loaded_song_id, MM_PLAY_ONCE);
}