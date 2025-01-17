#include "level_routines.h"
#include "memory.h"
#include "main.h"
#include "metatiles.h"
#include <maxmod.h>
#include "soundbank.h"
#include "menu.h"
#include "physics_defines.h"
#include "../levels/includes.h"

#define TOP_SCROLL_Y 0x24
#define BOTTOM_SCROLL_Y SCREEN_HEIGHT-0x24

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

            // Swap direction if screen is mirrored
            if (screen_mirrored) {
                x = (SCREENBLOCK_W - 1) - x;
                tile ^= SE_HFLIP;
            }

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

            // Swap direction if screen is mirrored
            if (screen_mirrored) {
                x = (SCREENBLOCK_W - 1) - x;
                tile ^= SE_HFLIP;
            }

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
    player_x = -0x100000;  
    relative_player_x = 0;
    player_y_speed = 0;
    player_size = SIZE_BIG;
    gravity_dir = GRAVITY_DOWN;
    coll_x = 0;
    coll_y = 0;
    player_death = FALSE;
    cube_rotation = 0;

    screen_mirrored = FALSE;
    mirror_scaling = float2fx(1.0);
    transition_frame = 0;
    screen_mirrored_transition = FALSE;

    curr_column = 0;
    on_floor = TRUE;
    bitstream[0] = bitstream[1] = 0;
    bits_left[0] = bits_left[1] = 0;

    cutscene_frame = 0;
    cutscene_initial_player_x = 0;
    cutscene_initial_player_y = 0;
    complete_cutscene = FALSE;

    scroll_x = 0;

    next_free_tile_id = START_OF_OBJECT_CHR;

    memset32(level_buffer, 0x0000, sizeof(level_buffer) / sizeof(u32));
    memset32(chr_slots, 0x0000, (sizeof(struct ObjectCHRSlot) * MAX_OBJECTS) / sizeof(u32));
    memset16(loaded_object_buffer, 0xffff, sizeof(loaded_object_buffer) / sizeof(s16));
    memset16(unloaded_object_buffer, 0xffff, sizeof(unloaded_object_buffer) / sizeof(s16));
    for (u32 index = 0; index < MAX_OBJECTS; index++) {
        chr_slots[index].rom_offset = 0xffffffff;
    }
    memset32(object_buffer, 0x0000, (sizeof(struct ObjectSlot) * MAX_OBJECTS) / sizeof(u32));
    memcpy16(&se_mem[26][0], bg_tiles, sizeof(bg_tiles) / 2);

    REG_BG0HOFS = REG_BG1HOFS = 0;
    REG_BG0VOFS = REG_BG1VOFS = scroll_y >> SUBPIXEL_BITS;
    
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 34 + (scroll_y >> (5 + SUBPIXEL_BITS));

    REG_WIN0H = SCREEN_WIDTH;
    REG_WIN0V = SCREEN_HEIGHT;

    for (u32 index = 0; index < MAX_OBJECTS; index++) {
        object_buffer[index].occupied = FALSE;
    }

    for (u32 channel = 0; channel < CHANNEL_COUNT; channel++) {
        col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE] = FALSE;
    }

    memset32(music_data, 0, sizeof(music_data) / sizeof(u32));

    rotate_saws();
    scale_pulsing_objects();
}

void load_level(u32 level_ID) {
    // Set level pointers
    level_pointer[0] = (u32*) level_defines[level_ID][L1_DATA_INDEX];
    level_pointer[1] = (u32*) level_defines[level_ID][L2_DATA_INDEX];
    sprite_pointer   = (u32*) level_defines[level_ID][SPRITE_DATA_INDEX];
    
    u32 *properties_pointer = (u32*) level_defines[level_ID][LEVEL_PROPERTIES_INDEX];

    // Get level variables
    COLOR bg_color = properties_pointer[BG_COLOR_INDEX];
    COLOR ground_color = properties_pointer[GROUND_COLOR_INDEX];
    gamemode = properties_pointer[GAMEMODE_INDEX];
    speed_id = properties_pointer[SPEED_INDEX];
    curr_level_height = properties_pointer[LEVEL_HEIGHT_INDEX];
    curr_level_width = properties_pointer[LEVEL_WIDTH_INDEX];
    loaded_song_id = properties_pointer[LEVEL_SONG_INDEX];

    // Limit values to safe values
    if (loaded_song_id >= MSL_NSONGS) loaded_song_id = 0;
    if (curr_level_height >= MAX_LEVEL_HEIGHT) curr_level_height = MAX_LEVEL_HEIGHT - 1;
    if (gamemode >= GAMEMODE_COUNT) gamemode = GAMEMODE_CUBE;
    if (speed_id >= NUM_SPEEDS) speed_id = SPEED_X1;

    // Put player on the ground
    player_y = ((GROUND_HEIGHT - 1) << (4 + SUBPIXEL_BITS)) + (0x2 << SUBPIXEL_BITS);  
    scroll_y = BOTTOM_SCROLL_LIMIT;
    intended_scroll_y = BOTTOM_SCROLL_LIMIT;

    // In case the gamemode has the camera restricted, set it there
    // Parameter given is -1 so it is set to the ground instantly
    set_target_y_scroll(-1);

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

void transition_update_spr() {
    nextSpr = 0;
    
    run_particles();
    // Update OAM
    obj_copy(oam_mem, shadow_oam, 128);
    obj_aff_copy(obj_aff_mem, obj_aff_buffer, 32);
    draw_percentage();
    draw_player();
    display_objects();
    rotate_saws();
    scale_pulsing_objects();
    
    // Sort OAM
    sort_oam_by_prio();
}

void fade_out() {
    update_flags = UPDATE_NONE;
    // Fade out
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, frame);
    }
}

void fade_out_level() {
    update_flags = UPDATE_NONE;
    // Fade out
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        key_poll();
        
        transition_update_spr();
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, frame);
    }
}

void fade_in_level() {
    update_flags = UPDATE_OAM;
    // Fade in
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        key_poll();
        
        transition_update_spr();

        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 32 - frame);
    }
    
    update_flags = UPDATE_ALL;
}

void fade_in() {
    update_flags = UPDATE_NONE;
    // Fade in
    for (s32 frame = 0; frame <= 32; frame += 4) {
        VBlankIntrWait();
        key_poll();
        
        clr_blend_fast(palette_buffer, (COLOR*) black_buffer, pal_bg_mem, 512, 32 - frame);
    }
    update_flags = UPDATE_ALL;
}

void reset_level() {
    mmStop();
    update_flags = UPDATE_OAM | UPDATE_SCROLL;
    
    nextSpr = 0;
    draw_percentage();
    draw_player();
    display_objects();
    rotate_saws();
    scale_pulsing_objects();
    // Sort OAM
    sort_oam_by_prio();

    // Wait a bit before fading
    for (s32 frame = 0; frame < 30; frame++) {
        VBlankIntrWait();
        key_poll();
        
        transition_update_spr();
    }

    fade_out_level();

    oam_init(shadow_oam, 128);
    load_level(loaded_level_id);

    frame_finished = TRUE;

    fade_in_level();
}
u64 approach_value_asympthotic(u64 current, u64 target, u32 multiplier);
u64 approach_value(u64 current, u64 target, s32 inc, s32 dec);

void scroll_screen_vertically() {
    if (gamemode == GAMEMODE_CUBE) {
        // This scrolls the screen on the y axis
        if (relative_player_y + 16 >= BOTTOM_SCROLL_Y) {
            scroll_y_dir = 1;
            
            if (player_y_speed > 0) {
                intended_scroll_y += player_y_speed;
            }
        } else if (relative_player_y <= TOP_SCROLL_Y) { 
            scroll_y_dir = 0;

            if (player_y_speed < 0) {
                intended_scroll_y += player_y_speed;
            }
        }
        
        if (intended_scroll_y < 0) intended_scroll_y = 0;
        if (intended_scroll_y > BOTTOM_SCROLL_LIMIT) intended_scroll_y = BOTTOM_SCROLL_LIMIT;

        scroll_y = approach_value_asympthotic(scroll_y, intended_scroll_y, 0x6000);
    } else {
        intended_scroll_y = scroll_y;
        scroll_y = approach_value(scroll_y, target_scroll_y, 0x10000, 0x10000);
    }
}

const u8 gamemode_screen_y_offset[] = {
    /* Ship */ 0xa0,
    /* Ball */ 0x90,
    /* Ufo */  0xa0,
};

void set_target_y_scroll(u32 object_y) {
    u32 intended_pos_y = object_y - 0x40;
    u32 offset = gamemode_screen_y_offset[gamemode - 1];
    
    if (intended_pos_y > ((GROUND_HEIGHT) << 4) - offset) intended_pos_y = ((GROUND_HEIGHT) << 4) - offset;

    target_scroll_y = (intended_pos_y & ~0xf) << SUBPIXEL_BITS;
}

// Screen mirror stuff

void mirror_screen() {
    if (!screen_mirrored_transition) {
        screen_mirrored_transition = TRUE;
    }
}
void unmirror_screen() {
    if (screen_mirrored_transition) {
        screen_mirrored_transition = FALSE;
    }
}

ARM_CODE void swap_screen_dir() {
    // LEVEL_LAYERS + 1 because the background also has to be mirrored
    for (s32 layer = 0; layer < LEVEL_LAYERS + 1; layer++) {
        // Copy tilemap into buffer
        SCR_ENTRY *mirror_screen_buffer = (SCR_ENTRY *) &vram_copy_buffer;
        memcpy32(mirror_screen_buffer, &se_mem[24 + layer], (SCREENBLOCK_W * SCREENBLOCK_H) / 2);

        s32 y_pos = 0;
        for (s32 y = 0; y < SCREENBLOCK_H; y++) {
            for (s32 x = 0; x < SCREENBLOCK_W; x++) {
                // Mirror tilemap columns
                se_mem[24 + layer][((SCREENBLOCK_W - 1) - x) + y_pos] = mirror_screen_buffer[x + y_pos] ^ SE_HFLIP;
            }
            y_pos += SCREENBLOCK_W;
        }
    }
    
    swap_queue = FALSE;
}

void calculate_trans_window_pos();

void mirror_transition() {
    if (screen_mirrored_transition) {
        if (transition_frame < SCREEN_TRANSITION_FRAMES - 1) {
            transition_frame += 1;

            // If halfway through the transition, flip screen
            if (transition_frame == SCREEN_TRANSITION_SWITCH_FRAME) {
                mirror_scaling = float2fx(-1.0);
                screen_mirrored = TRUE;
                swap_queue = TRUE;
            }
            
            calculate_trans_window_pos();
        }
    } else {
        if (transition_frame > 0) {
            transition_frame -= 1;

            // If halfway through the transition, flip screen
            if (transition_frame == SCREEN_TRANSITION_SWITCH_FRAME) {
                mirror_scaling = float2fx(1.0);
                screen_mirrored = FALSE;
                swap_queue = TRUE;
            }

            calculate_trans_window_pos();
        }
    }
}

void calculate_trans_window_pos() {
    u8 right;
    u8 left;

    // Set window sides depending on current frame
    if (transition_frame < SCREEN_TRANSITION_SWITCH_FRAME) {
        right = SCREEN_WIDTH - (transition_frame * 8);
        left = (transition_frame * 8);
    } else if (transition_frame == SCREEN_TRANSITION_SWITCH_FRAME) {
        right = SCREEN_WIDTH / 2;
        left = SCREEN_WIDTH / 2;
    } else {
        right = ((transition_frame - SCREEN_TRANSITION_HALF) * 8) + (SCREEN_WIDTH / 2);
        left = (SCREEN_WIDTH / 2) - ((transition_frame - SCREEN_TRANSITION_HALF) * 8);
    }

    // Set window side position
    REG_WIN0H = (left << 8) | right;
}

u64 approach_value_asympthotic(u64 current, u64 target, u32 multiplier) {
    s64 diff = (target - current);
    return (current + ((diff * multiplier) / SUBPIXEL_MULTIPLIER));
}

u64 approach_value(u64 current, u64 target, s32 inc, s32 dec) {
    s64 dist = (target - current);
    if (dist > 0) { // current < target
        current = ((dist >  inc) ? (current + inc) : target);
    } else if (dist < 0) { // current > target
        current = ((dist < -dec) ? (current - dec) : target);
    }
    return current;
}

#define FIRST_NUMBER_ID 998
#define PERCENTAGE_SYMBOL_ID 1008

void draw_percentage() {
    // Progress number in level
    u32 percentage;
    if (player_x < 0) {
        percentage = 0;
    } else if (curr_level_width == 0) {
        percentage = 100;
    } else {
        percentage = ((((u32) player_x) / curr_level_width) * 100) >> 20;
    }
    
    if (percentage >= 100) {
        oam_metaspr(108, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + 1, 0, TRUE);
        oam_metaspr(116, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + 0, 0, TRUE);
        oam_metaspr(124, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + 0, 0, TRUE);
        oam_metaspr(132, 8, numberSpr, FALSE, FALSE, PERCENTAGE_SYMBOL_ID, 0, TRUE);
    } else if (percentage >= 10) {
        oam_metaspr(112, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + (percentage / 10), 0, TRUE);
        oam_metaspr(120, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + (percentage % 10), 0, TRUE);
        oam_metaspr(128, 8, numberSpr, FALSE, FALSE, PERCENTAGE_SYMBOL_ID, 0, TRUE);
    } else {
        oam_metaspr(116, 8, numberSpr, FALSE, FALSE, FIRST_NUMBER_ID + percentage, 0, TRUE);
        oam_metaspr(124, 8, numberSpr, FALSE, FALSE, PERCENTAGE_SYMBOL_ID, 0, TRUE);
    }
}