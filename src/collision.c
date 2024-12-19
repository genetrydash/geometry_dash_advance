#include "main.h"
#include "metatiles.h"

// Ground pattern
const u16 ground_pattern[] = {
    GROUND_TILE_1, GROUND_TILE_2, GROUND_TILE_2, GROUND_TILE_3,
    GROUND_TILE_4, GROUND_TILE_5, GROUND_TILE_5, GROUND_TILE_6,
    GROUND_TILE_7, GROUND_TILE_8, GROUND_TILE_8, GROUND_TILE_9,
    GROUND_TILE_A, GROUND_TILE_B, GROUND_TILE_B, GROUND_TILE_C,
};

// Pixel to check collision on.
u32 coll_x;
u32 coll_y;

// Collision eject
u32 eject = 0;

enum COL_SIDES {
    TOP,
    BOTTOM,
    CENTER
};

u32 run_coll(u32 x, u32 y, u32 layer, u8 side);
void collide_with_map_spikes(u32 x, u32 y, u32 width, u32 height, u8 layer);
void do_center_checks(u32 x, u32 y, u32 width, u32 height, u32 layer);

void collision_cube() {
    on_floor = 0;
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
        collide_with_map_spikes(coll_x, coll_y, player_width, player_height, layer);

        // Do center hitbox checks
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
        
        do_center_checks(coll_x + 5, coll_y + 5, 4, 4, layer);

        if (!gravity_dir) {
            if (player_y_speed >= 0) {
                // Going down
                coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
                coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
                
                if (run_coll(coll_x, coll_y + player_height, layer, BOTTOM)) {
                    continue;
                }
                if (run_coll(coll_x + player_width, coll_y + player_height, layer, BOTTOM)) {
                    continue;
                }
            }
        } else {
            if (player_y_speed <= 0) {
                // Going up
                coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
                coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);

                if (run_coll(coll_x, coll_y, layer, TOP)) {
                    continue;
                }
                if (run_coll(coll_x + player_width, coll_y, layer, TOP)) {
                    continue;
                }
            }
        }
    }
}

void collision_ship() {
    on_floor = 0;
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
        collide_with_map_spikes(coll_x, coll_y, player_width, player_height, layer);
        
        // Do center hitbox checks
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);

        do_center_checks(coll_x + 5, coll_y + 5, 4, 4, layer);

        if (player_y_speed >= 0) {
            // Going down
            coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
            coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
            
            if (run_coll(coll_x, coll_y + player_height, layer, BOTTOM)) {
                continue;
            }
            if (run_coll(coll_x + player_width, coll_y + player_height, layer, BOTTOM)) {
                continue;
            }
        }
        if (player_y_speed <= 0) {
            // Going up
            coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
            coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);

            if (run_coll(coll_x, coll_y, layer, TOP)) {
                continue;
            }
            if (run_coll(coll_x + player_width, coll_y, layer, TOP)) {
                continue;
            }
        }
    }
}

u16 obtain_block(u32 x, u32 y, u32 layer) {
    u32 block_x = (x >> 4) & 0x1f; // Get block x in buffer (0-31)
    u32 block_y = y >> 4;          // Get block y in buffer, not capped for easy level vertical extension

    return level_buffer[layer][block_x + block_y * LEVEL_BUFFER_WIDTH];
}

u16 obtain_collision_type(u32 x, u32 y, u32 layer) {
    // Obtain the col type from the table, indexed by metatile ID
    return metatiles[obtain_block(x,y,layer)][4];
}

// GD cube has a small square hitbox where if a block collides with, then the player dies
void do_center_checks(u32 x, u32 y, u32 width, u32 height, u32 layer) {
    if (run_coll(x, y, layer, CENTER)) {
        player_death = TRUE;
        return;
    }

    if (run_coll(x + width, y, layer, CENTER)) {
        player_death = TRUE;
        return;
    }

    if (run_coll(x, y + height, layer, CENTER)) {
        player_death = TRUE;
        return;
    }

    if (run_coll(x + width, y + height, layer, CENTER)) {
        player_death = TRUE;
        return;
    }
}
// This function iterates through spikes that the player is touching and applies collision to it
void collide_with_map_spikes(u32 x, u32 y, u32 width, u32 height, u8 layer) {
    // Iterate through 4 metatiles, forming a 2x2 metatile square
    // As the cube won't be bigger than a single 16x16 metatile, the cube can touch up to 4 metatiles
    for (u32 side = 0; side < 4; side++) {
        // Get offset from the starting block
        u32 x_offset = (side & 1) ? 0x10 : 0;
        u32 y_offset = (side & 2) ? 0x10 : 0;

        u32 col_type = obtain_collision_type(x + x_offset, y + y_offset, layer);

        // Spikes origin is in the top left pixel, aka 0,0 inside the metatile
        u32 spk_x = (x + x_offset) & 0xfffffff0;
        u32 spk_y = (y + y_offset) & 0xfffffff0;

        switch (col_type) {
            // Normal spikes
            case COL_SPIKE_TOP:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x06, spk_y + 0x04, 0x03, 0x06
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_SPIKE_BOTTOM:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x06, spk_y + 0x05, 0x03, 0x06
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_SPIKE_LEFT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x04, spk_y + 0x06, 0x03, 0x06
                )) {
                    player_death = TRUE;  
                }
                break;
            
            case COL_SPIKE_RIGHT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x05, spk_y + 0x06, 0x03, 0x06
                )) {
                    player_death = TRUE;  
                }
                break;

            // Small spikes
            case COL_SMALL_SPIKE_TOP:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x06, spk_y + 0x02, 0x04, 0x03
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_SMALL_SPIKE_BOTTOM:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x06, spk_y + 0x0b, 0x04, 0x03
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_SMALL_SPIKE_LEFT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x02, spk_y + 0x06, 0x04, 0x03
                )) {
                    player_death = TRUE;  
                }
                break;
            
            case COL_SMALL_SPIKE_RIGHT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x0b, spk_y + 0x06, 0x04, 0x03
                )) {
                    player_death = TRUE;  
                }
                break;
        }
    }
}

u32 col_type_lookup(u16 col_type, u32 x, u32 y, u8 side) {
    // Positions inside block, top left pixel is [0,0]
    UNUSED u32 x_inside_block = x & 0x0f;
    u32 y_inside_block = y & 0x0f;

    // TODO: death col types
    switch (col_type) {
        case COL_NONE:
            return 0;
        case COL_ALL:
            eject = y_inside_block;
            break;
        case COL_SLAB_TOP:
            if (y_inside_block < 0x8) {
                eject = y_inside_block & 0x07;
                break;
            }
            return 0;
        case COL_SLAB_BOTTOM:
            if (y_inside_block >= 0x8) {
                eject = y_inside_block - 0x08;
                break;
            }
            return 0;

        // Everything else
        default:
            return 0;
    }

    // Set related vars and set new player y position
    
    if (side == TOP) {
        if (gravity_dir) {
            // We are resting on the ceiling so allow jumping and stuff
            on_floor = 1;
        }
        s16 eject_value = (eject | 0xfffffff8) << 8;
        if (eject_value >= -0x0600) {
            player_y -= (eject | 0xfffffff8) << 8;
            player_y_speed = 0;
            // Remove subpixels
            player_y &= 0xffffff00;
            scroll_y &= 0xffffff00;
        }
    } else if (side == BOTTOM) {   
        if (!gravity_dir) {
            // We are resting on the floor so allow jumping and stuff
            on_floor = 1;
        }
        s16 eject_value = eject << 8;
        if (eject_value < 0x0600) {
            player_y -= eject_value;
            player_y_speed = 0;
            // Remove subpixels
            player_y &= 0xffffff00;
            scroll_y &= 0xffffff00;
        }
    }
   

    return 1;
}

u32 run_coll(u32 x, u32 y, u32 layer, u8 side) {
    u16 col_type = obtain_collision_type(x, y, layer);
    return col_type_lookup(col_type, x, y, side);
}