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
void do_collision_with_objects(u32 check_rotated);

void collision_cube() {
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
        collide_with_map_spikes(coll_x, coll_y, player_width, player_height, layer);

        // If the player is dead, don't bother checking more
        if (player_death) {
            return;
        }

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
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (player_x >> 8) + ((0x10 - player_width) >> 1);
        coll_y = (player_y >> 8) + ((0x10 - player_height) >> 1);
        collide_with_map_spikes(coll_x, coll_y, player_width, player_height, layer);

        // If the player is dead, don't bother checking more
        if (player_death) {
            return;
        }
        
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

            case COL_SPIKE_RIGHT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x04, spk_y + 0x06, 0x03, 0x06
                )) {
                    player_death = TRUE;  
                }
                break;
            
            case COL_SPIKE_LEFT:
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

            case COL_SMALL_SPIKE_RIGHT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x0b, spk_y + 0x06, 0x04, 0x03
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

            // Medium spikes

            case COL_MEDIUM_SPIKE_TOP:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x07, spk_y + 0x02, 0x02, 0x04
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_MEDIUM_SPIKE_BOTTOM:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x07, spk_y + 0x09, 0x02, 0x04
                )) {
                    player_death = TRUE;  
                }
                break;

            case COL_MEDIUM_SPIKE_RIGHT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x09, spk_y + 0x07, 0x04, 0x02
                )) {
                    player_death = TRUE;  
                }
                break;
            
            case COL_MEDIUM_SPIKE_LEFT:
                if (is_colliding(
                    x, y, width, height,
                    spk_x + 0x02, spk_y + 0x07, 0x04, 0x02
                )) {
                    player_death = TRUE;  
                }
                break;
        }
    }
}

u32 col_type_lookup(u16 col_type, u32 x, u32 y, u8 side) {
    // Positions inside block, top left pixel is [0,0]
    u32 x_inside_block = x & 0x0f;
    u32 y_inside_block = y & 0x0f;

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

        case COL_SLAB_LEFT:
            if (x_inside_block < 0x8) {
                eject = y_inside_block;
                break;
            }
            return 0;

        case COL_SLAB_RIGHT:
            if (x_inside_block >= 0x8) {
                eject = y_inside_block;
                break;
            }
            return 0;

        // Everything else
        default:
            return 0;
    }

    // Set related vars and set new player y position
    
    if (side == TOP) {
        s16 eject_value = (eject | 0xfffffff8) << 8;
        if (eject_value >= -0x0600) {
            if (gravity_dir) {
                // We are resting on the ceiling so allow jumping and stuff
                on_floor = 1;
            }
            
            player_y -= (eject | 0xfffffff8) << 8;
            player_y_speed = 0;
            // Remove subpixels
            player_y &= 0xffffff00;
            scroll_y &= 0xffffff00;
        }
    } else if (side == BOTTOM) {   
        s16 eject_value = eject << 8;
        if (eject_value < 0x0600) {
            if (!gravity_dir) {
                // We are resting on the floor so allow jumping and stuff
                on_floor = 1;
            }
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

void do_collision_with_objects(u32 check_rotated) {
    for (s32 slot = 0; slot < MAX_OBJECTS; slot++) {
        // Check collision only if the slot is occupied
        if (object_buffer[slot].occupied && object_buffer[slot].activated == FALSE) {
            if (check_rotated || !(object_buffer[slot].object.attrib1 & ENABLE_ROTATION_FLAG)) {
                check_obj_collision(slot); 
            }
        }  
    }
}


u32 is_colliding(u32 x1, u32 y1, u32 w1, u32 h1, u32 x2, u32 y2, u32 w2, u32 h2) {
    // Right of object 1 < Left of object 2
    if (x1 + w1 < x2) {
        return FALSE;
    }

    // Left of object 1 > Right of object 2
    if (x1 > x2 + w2) {
        return FALSE;
    }

    // Bottom of object 1 < Top of object 2
    if (y1 + h1 < y2) {
        return FALSE;
    }

    // Top of object 1 > Bottom of object 1
    if (y1 > y2 + h2) {
        return FALSE;
    }

    // If all above is FALSE, then collision has happen
    return TRUE;
}

// Rotated hitbox stuff, all in IWRAM for extra speed

#define SCALE_FACTOR 12
#define FIXED_ONE (1 << SCALE_FACTOR) // 1.0 in fixed-point

// Rotate a point (px, py) around a center (cx, cy) using fixed-point math
ARM_CODE INLINE void rotate_point_fixed(s32 cx, s32 cy, s32 px, s32 py, s16 sin_theta, s16 cos_theta, s32* rx, s32* ry) {
    s32 dx = px - cx;
    s32 dy = py - cy;

    *rx = cx + ((dx * cos_theta - dy * sin_theta) >> SCALE_FACTOR);
    *ry = cy + ((dx * sin_theta + dy * cos_theta) >> SCALE_FACTOR);
}

// Project a rectangle's corners onto an axis and calculate min/max projections
ARM_CODE void project_onto_axis_fixed(s32* corners, s32 ax, s32 ay, s32* min, s32* max) {
    *min = *max = (corners[0] * ax + corners[1] * ay) >> SCALE_FACTOR;

    for (s32 i = 1; i < 4; i++) {
        s32 projection = (corners[i << 1] * ax + corners[(i << 1) + 1] * ay) >> SCALE_FACTOR;
        if (projection < *min) *min = projection;
        if (projection > *max) *max = projection;
    }
}

// Check if projections overlap
ARM_CODE INLINE s32 overlap_on_axis_fixed(s32 min1, s32 max1, s32 min2, s32 max2) {
    return !(max1 < min2 || max2 < min1);
}

// Same as is_colliding but second hitbox supports rotation
ARM_CODE s32 is_colliding_rotated_fixed(s32 x1, s32 y1, s32 w1, s32 h1, s32 x2, s32 y2, s32 w2, s32 h2, s32 orig_x, s32 orig_y, s32 cx2offset, s32 cy2offset, u16 angle) {
    // Center of second rectangle
    s32 cx2 = orig_x + cx2offset;
    s32 cy2 = orig_y + cy2offset;

    // Get sine and cosine for the angle
    s16 sin_theta = lu_sin(angle);
    s16 cos_theta = lu_cos(angle);

    // Calculate the four corners of the rotated rectangle
    s32 corners[8];
    rotate_point_fixed(cx2, cy2, x2, y2, sin_theta, cos_theta, &corners[0], &corners[1]);           // Top-left
    rotate_point_fixed(cx2, cy2, x2 + w2, y2, sin_theta, cos_theta, &corners[2], &corners[3]);      // Top-right
    rotate_point_fixed(cx2, cy2, x2 + w2, y2 + h2, sin_theta, cos_theta, &corners[4], &corners[5]); // Bottom-right
    rotate_point_fixed(cx2, cy2, x2, y2 + h2, sin_theta, cos_theta, &corners[6], &corners[7]);      // Bottom-left

    // Define axes to test
    s32 axes[4][2] = {
        {FIXED_ONE, 0}, {0, FIXED_ONE},                     // Non-rotated rectangle axes
        {corners[2] - corners[0], corners[3] - corners[1]}, // Rotated rectangle edge 1
        {corners[6] - corners[0], corners[7] - corners[1]}  // Rotated rectangle edge 2
    };

    // Project both rectangles onto each axis and check for overlap
    for (s32 i = 0; i < 4; i++) {
        s32 min1, max1, min2, max2;
        s32 rect1_corners[8] = {
            x1, y1, x1 + w1, y1,
            x1 + w1, y1 + h1, x1, y1 + h1
        };

        project_onto_axis_fixed(rect1_corners, axes[i][0], axes[i][1], &min1, &max1);
        project_onto_axis_fixed(corners, axes[i][0], axes[i][1], &min2, &max2);

        if (!overlap_on_axis_fixed(min1, max1, min2, max2)) {
            return FALSE; // Separating axis found, no collision
        }
    }

    return TRUE; // No separating axis, collision detected
}