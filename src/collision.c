#include "main.h"
#include "metatiles.h"
#include "physics_defines.h"

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

ARM_CODE u32 run_coll(u32 x, u32 y, u32 layer, u8 side);
ARM_CODE void collide_with_map_spikes(u32 x, u32 y, u32 width, u32 height, u8 layer);
s32 do_center_checks(u32 x, u32 y, u32 width, u32 height, u32 layer);
ARM_CODE void do_collision_with_objects(u32 check_rotated);

ARM_CODE void collision_cube() {
    // Exit if above screen
    if (curr_player.player_y < 0) return;

    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
        coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1);

#ifdef DEBUG
        if (!noclip) collide_with_map_spikes(coll_x, coll_y, curr_player.player_width, curr_player.player_height, layer);
#else
        collide_with_map_spikes(coll_x, coll_y, curr_player.player_width, curr_player.player_height, layer);
#endif

        // If the player is dead, don't bother checking more
        if (player_death) {
            return;
        }

        // Do center hitbox checks
        coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_internal_hitbox_width) >> 1);
        coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_internal_hitbox_height) >> 1);      

#ifdef DEBUG
        if (!noclip) {
            if (do_center_checks(coll_x, coll_y, curr_player.player_internal_hitbox_width, curr_player.player_internal_hitbox_height, layer)) {
                return;
            }
        }
#else
        if (do_center_checks(coll_x, coll_y, curr_player.player_internal_hitbox_width, curr_player.player_internal_hitbox_height, layer)) {
            return;
        }
#endif

        if (curr_player.gravity_dir == GRAVITY_DOWN) {
            if (curr_player.player_y_speed >= 0) {
                // Going down
                coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
                coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1);
                
                if (run_coll(coll_x, coll_y + curr_player.player_height, layer, BOTTOM)) {
                    continue;
                }
                if (run_coll(coll_x + curr_player.player_width, coll_y + curr_player.player_height, layer, BOTTOM)) {
                    continue;
                }
            } else if (curr_player.should_check_ceiling) { {
                    // If ceiling should be checked, check for top collision
                    if (run_coll(coll_x, coll_y, layer, TOP)) {
                        continue;
                    }
                    if (run_coll(coll_x + curr_player.player_width, coll_y, layer, TOP)) {
                        continue;
                    }
                    
                    // Decrement counter
                    curr_player.should_check_ceiling--;
                }
            }
        } else {
            if (curr_player.player_y_speed <= 0) {
                // Going up
                coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
                coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1);

                if (run_coll(coll_x, coll_y, layer, TOP)) {
                    continue;
                }
                if (run_coll(coll_x + curr_player.player_width, coll_y, layer, TOP)) {
                    continue;
                }
            } else if (curr_player.should_check_ceiling) {
                // If ceiling should be checked, check for bottom collision
                if (run_coll(coll_x, coll_y + curr_player.player_height, layer, BOTTOM)) {
                    continue;
                }
                if (run_coll(coll_x + curr_player.player_width, coll_y + curr_player.player_height, layer, BOTTOM)) {
                    continue;
                }

                // Decrement counter
                curr_player.should_check_ceiling--;
            }
        }
    }
}

ARM_CODE void collision_ship_ball_ufo() {
    // Exit if above screen
    if (curr_player.player_y < 0) return;

    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        // Check spikes
        coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
        coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1);

#ifdef DEBUG
        if (!noclip) collide_with_map_spikes(coll_x, coll_y, curr_player.player_width, curr_player.player_height, layer);
#else
        collide_with_map_spikes(coll_x, coll_y, curr_player.player_width, curr_player.player_height, layer);
#endif

        // If the player is dead, don't bother checking more
        if (player_death) {
            return;
        }
        
        // Do center hitbox checks
        coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_internal_hitbox_width) >> 1);
        coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_internal_hitbox_height) >> 1);      

#ifdef DEBUG
        if (!noclip) {
            if (do_center_checks(coll_x, coll_y, curr_player.player_internal_hitbox_width, curr_player.player_internal_hitbox_height, layer)) {
                return;
            }
        }
#else
        if (do_center_checks(coll_x, coll_y, curr_player.player_internal_hitbox_width, curr_player.player_internal_hitbox_height, layer)) {
            return;
        }
#endif


        if (curr_player.player_y_speed >= 0) {
            // Going down
            coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
            coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1);
            
            if (run_coll(coll_x, coll_y + curr_player.player_height, layer, BOTTOM)) {
                continue;
            }
            if (run_coll(coll_x + curr_player.player_width, coll_y + curr_player.player_height, layer, BOTTOM)) {
                continue;
            }
        }
        if (curr_player.player_y_speed <= 0) {
            // Going up
            coll_x = (curr_player.player_x >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_width) >> 1);
            coll_y = (curr_player.player_y >> SUBPIXEL_BITS) + ((0x10 - curr_player.player_height) >> 1) + 1;

            if (run_coll(coll_x, coll_y, layer, TOP)) {
                continue;
            }
            if (run_coll(coll_x + curr_player.player_width, coll_y, layer, TOP)) {
                continue;
            }
        }
    }
}

ARM_CODE u16 obtain_block(u32 x, u32 y, u32 layer) {
    u32 block_x = (x >> 4) & 0x1f; // Get block x in buffer (0-31)
    u32 block_y = y >> 4;          // Get block y in buffer, not capped for easy level vertical extension

    return level_buffer[layer][block_x + block_y * LEVEL_BUFFER_WIDTH];
}

ARM_CODE INLINE u16 obtain_collision_type(u32 x, u32 y, u32 layer) {
    // Obtain the col type from the table, indexed by metatile ID
    return metatiles[obtain_block(x,y,layer)][4];
}

// GD cube has a small square hitbox where if a block collides with, then the player dies
s32 do_center_checks(u32 x, u32 y, u32 width, u32 height, u32 layer) {
    if (run_coll(x, y, layer, CENTER)) {
        player_death = TRUE;
        return TRUE;
    }

    if (run_coll(x + width, y, layer, CENTER)) {
        player_death = TRUE;
        return TRUE;
    }

    if (run_coll(x, y + height, layer, CENTER)) {
        player_death = TRUE;
        return TRUE;
    }

    if (run_coll(x + width, y + height, layer, CENTER)) {
        player_death = TRUE;
        return TRUE;
    }

    return FALSE;
}

const u8 gamemode_max_eject[] = {
    /* Cube */ 0x06,
    /* Ship */ 0x03,
    /* Ball */ 0x06,
    /* Ufo */  0x03,
    /* Wave */ 0x06,
};

ARM_CODE u32 col_type_lookup(u16 col_type, u32 x, u32 y, u8 side) {
    // Positions inside block, top left pixel is [0,0]
    u32 x_inside_block = x & 0x0f;
    u32 y_inside_block = y & 0x0f;

    switch (col_type) {
        case COL_FLOOR_CEIL:
        case COL_FULL:
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

    // Set related vars and set new player y position, only if this is not a center check
    
    if (side == TOP) {
        s32 eject_value = (eject | 0xfffffff8) << SUBPIXEL_BITS;
        s32 max_eject = gamemode_max_eject[curr_player.gamemode];
        if (col_type == COL_FLOOR_CEIL) max_eject = 0x10;
        if (eject_value >= -(max_eject << SUBPIXEL_BITS)) {
            if (curr_player.gravity_dir == GRAVITY_UP) {
                // We are resting on the ceiling so allow jumping and stuff
                curr_player.on_floor = 1;
            }
            
            curr_player.player_y -= eject_value;
            curr_player.player_y_speed = 0;

            // Remove subpixels
            curr_player.player_y &= ~0xffff;
            scroll_y &= ~0xffff;
        }
    } else if (side == BOTTOM) {   
        s32 eject_value = eject << SUBPIXEL_BITS;
        s32 max_eject = gamemode_max_eject[curr_player.gamemode];
        if (col_type == COL_FLOOR_CEIL) max_eject = 0x10;
        if (eject_value < (max_eject << SUBPIXEL_BITS)) {
            if (curr_player.gravity_dir == GRAVITY_DOWN) {
                // We are resting on the floor so allow jumping and stuff
                curr_player.on_floor = 1;
            }
            curr_player.player_y -= eject_value;
            curr_player.player_y_speed = 0;

            // Remove subpixels
            curr_player.player_y &= ~0xffff;
            scroll_y &= ~0xffff;
        }
    }
   
    return 1;
}

ARM_CODE s32 collision_with_block_obj(u32 x, u32 y, u8 side) {
    for (s32 i = block_object_buffer_offset; i > 0; i--) {
        struct ObjectSlot slot = *((struct ObjectSlot *) block_object_buffer[i - 1]);
        
        u32 obj_x = slot.object.x;
        u32 obj_y = slot.object.y;
        u32 obj_width = obj_hitbox[slot.object.type][0];
        u32 obj_height = obj_hitbox[slot.object.type][1];

        // Check if this pixel is inside the object hitbox
        if (is_colliding(x, y, 1, 1, obj_x, obj_y, obj_width, obj_height)) {
            // Relative positions
            x = x - obj_x;
            y = y - obj_y;

            // Set old player y pos to get the displacement later
            u64 old_player_y = curr_player.player_y;

            // This always returns TRUE
            col_type_lookup(block_object_buffer_flags[i - 1], x, y, side);
            
            // Update coll_y with the displacement that has occured
            coll_y += old_player_y - curr_player.player_y;

            return TRUE;
        }
        
    }
    return FALSE;
}

ARM_CODE u32 run_coll(u32 x, u32 y, u32 layer, u8 side) {
    if(collision_with_block_obj(x, y, side)) {
        // Return TRUE only if this is a center hitbox check, as this is needed for death to ocurr
        return side == CENTER;
    }
    
    u16 col_type = obtain_collision_type(x, y, layer);
    return col_type_lookup(col_type, x, y, side);
}

ARM_CODE void do_collision_with_objects(u32 check_rotated) {
    for (s32 slot = 0; slot < MAX_OBJECTS; slot++) {
        // Check collision only if the slot is occupied
        struct ObjectSlot curr_object = object_buffer[slot];
        // If is occupied and it hasn't been activated yet, continue
        if (curr_object.occupied && curr_object.activated[curr_player_id] == FALSE) {
            // If it is at most 128 pixels offscreen of the right side, continue
            s32 relative_x = curr_object.object.x - ((scroll_x >> SUBPIXEL_BITS) & 0xffffffff);
            if (relative_x < SCREEN_WIDTH + 128) {
                // Check if this object is a touch col trigger, if so, check collision
                if (curr_object.object.type == COL_TRIGGER && curr_object.object.rotation & COL_TRIGGER_ROT_VAR_TOUCH_MASK) {
                    check_obj_collision(slot); 
                } 
                // If it has collision and it is marked to collide with rotated objects, continue
                // If it is not marked, check if the object is rotated, if not, continue
                else if (curr_object.has_collision && (check_rotated || !(curr_object.object.attrib1 & ENABLE_ROTATION_FLAG))) {
                    check_obj_collision(slot); 
                }
            }
        }  
    }
}


ARM_CODE u32 is_colliding(u32 x1, u32 y1, u32 w1, u32 h1, u32 x2, u32 y2, u32 w2, u32 h2) {
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

ARM_CODE u32 is_colliding_circle(u32 cx1, u32 cy1, u32 r1, u32 cx2, u32 cy2, u32 r2) {
    s32 distance_x = (cx2 - cx1);
    s32 distance_y = (cy2 - cy1);

    // Squared to avoid square roots
    s32 obj_distance = distance_x*distance_x + distance_y*distance_y;
    s32 radius_sum = (r1 + r2)*(r1 + r2);

    return obj_distance < radius_sum;
}

// Rotated hitbox stuff, all in IWRAM for extra speed

#define SCALE_FACTOR 8
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
    s16 sin_theta = lu_sin(angle) / 16;
    s16 cos_theta = lu_cos(angle) / 16;

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

void col_spike_top_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x07, spk_y + 0x05, 0x02, 0x06
    )) {
        player_death = TRUE;
    }
}

void col_spike_left_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x05, spk_y + 0x07, 0x06, 0x02
    )) {
        player_death = TRUE;
    }
}

void col_small_spike_top(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y + 0x02, 0x04, 0x03
    )) {
        player_death = TRUE;
    }
}

void col_small_spike_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y + 0x0b, 0x04, 0x03
    )) {
        player_death = TRUE;
    }
}

void col_small_spike_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x0b, spk_y + 0x06, 0x04, 0x03
    )) {
        player_death = TRUE;
    }
}

void col_small_spike_left(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x02, spk_y + 0x06, 0x04, 0x03
    )) {
        player_death = TRUE;
    }
}

void col_medium_spike_top(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x07, spk_y + 0x02, 0x02, 0x04
    )) {
        player_death = TRUE; 
    }
}

void col_medium_spike_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x07, spk_y + 0x09, 0x02, 0x04
    )) {
        player_death = TRUE;
    }
}

void col_medium_spike_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x09, spk_y + 0x07, 0x04, 0x02
    )) {
        player_death = TRUE;
    }
}

void col_medium_spike_left(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x02, spk_y + 0x07, 0x04, 0x02
    )) {
        player_death = TRUE;
    }
}

void col_ground_spike_top(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y - 0x02, 0x04, 0x06
    )) {
        player_death = TRUE;
    }
}

void col_ground_spike_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y + 0x0c, 0x04, 0x06
    )) {
        player_death = TRUE;
    }
}

void col_ground_spike_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x0c, spk_y + 0x06, 0x06, 0x04
    )) {
        player_death = TRUE;
    }
}

void col_ground_spike_left(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x - 0x02, spk_y + 0x06, 0x06, 0x04
    )) {
        player_death = TRUE;
    }
}

void col_ground_wavy_spike_top(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y, 0x04, 0x04
    )) {
        player_death = TRUE; 
    }
}

void col_ground_wavy_spike_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x06, spk_y + 0x0c, 0x04, 0x04
    )) {
        player_death = TRUE; 
    }
}

void col_ground_wavy_spike_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x0c, spk_y + 0x06, 0x04, 0x04
    )) {
        player_death = TRUE;
    }
}

void col_ground_wavy_spike_left(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x , spk_y + 0x06, 0x04, 0x04
    )) {
        player_death = TRUE;
    }
}

void col_ground_bush_spike_top(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x04, spk_y - 0x03, 0x08, 0x0a
    )) {
        player_death = TRUE;  
    }
}

void col_ground_bush_spike_bottom(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x04, spk_y + 0x09, 0x08, 0x0a
    )) {
        player_death = TRUE;
    }
}

void col_ground_bush_spike_right(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x + 0x09, spk_y + 0x04, 0x0a, 0x08
    )) {
        player_death = TRUE;
    }
}

void col_ground_bush_spike_left(u32 x, u32 y, u32 width, u32 height, u32 spk_x, u32 spk_y) {
    if (is_colliding(
        x, y, width, height,
        spk_x - 0x03, spk_y + 0x04, 0x0a, 0x08
    )) {
        player_death = TRUE;  
    }
}

void not_an_spike(UNUSED u32 x, UNUSED u32 y, UNUSED u32 width, UNUSED u32 height, UNUSED u32 spk_x, UNUSED u32 spk_y) {
    // not an spike so do nothing
}

const jmp_table spike_coll_jump_table[] = {
    not_an_spike, // COL_NONE
    not_an_spike, // COL_FULL
    not_an_spike, // COL_FLOOR_CEIL
    
    col_spike_top_bottom, // COL_SPIKE_TOP
    col_spike_top_bottom, // COL_SPIKE_BOTTOM
    col_spike_left_right, // COL_SPIKE_RIGHT
    col_spike_left_right, // COL_SPIKE_LEFT

    col_small_spike_top,    // COL_SMALL_SPIKE_TOP
    col_small_spike_bottom, // COL_SMALL_SPIKE_BOTTOM
    col_small_spike_right,  // COL_SMALL_SPIKE_RIGHT
    col_small_spike_left,   // COL_SMALL_SPIKE_LEFT

    col_medium_spike_top,    // COL_MEDIUM_SPIKE_TOP
    col_medium_spike_bottom, // COL_MEDIUM_SPIKE_BOTTOM
    col_medium_spike_right,  // COL_MEDIUM_SPIKE_RIGHT
    col_medium_spike_left,   // COL_MEDIUM_SPIKE_LEFT

    not_an_spike, // COL_SLAB_TOP
    not_an_spike, // COL_SLAB_BOTTOM
    not_an_spike, // COL_SLAB_LEFT
    not_an_spike, // COL_SLAB_RIGHT

    col_ground_spike_top,    // COL_GROUND_SPIKE_TOP
    col_ground_spike_bottom, // COL_GROUND_SPIKE_BOTTOM
    col_ground_spike_right,  // COL_GROUND_SPIKE_RIGHT
    col_ground_spike_left,   // COL_GROUND_SPIKE_LEFT

    col_ground_wavy_spike_top,    // COL_GROUND_WAVY_SPIKE_TOP
    col_ground_wavy_spike_bottom, // COL_GROUND_WAVY_SPIKE_BOTTOM
    col_ground_wavy_spike_right,  // COL_GROUND_WAVY_SPIKE_RIGHT
    col_ground_wavy_spike_left,   // COL_GROUND_WAVY_SPIKE_LEFT

    col_ground_bush_spike_top,    // COL_GROUND_BUSH_SPIKE_TOP
    col_ground_bush_spike_bottom, // COL_GROUND_BUSH_SPIKE_BOTTOM
    col_ground_bush_spike_right,  // COL_GROUND_BUSH_SPIKE_RIGHT
    col_ground_bush_spike_left,   // COL_GROUND_BUSH_SPIKE_LEFT
};

// This function iterates through spikes that the player is touching and applies collision to it
ARM_CODE void collide_with_map_spikes(u32 x, u32 y, u32 width, u32 height, u8 layer) {
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

        if (col_type < COL_TYPES_COUNT) {
            spike_coll_jump_table[col_type](x, y, width, height, spk_x, spk_y);
        }
    }
}