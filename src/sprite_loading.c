#include "sprite_loading.h"
#include "memory.h"
#include "metaspr.h"
#include "player.h"
#include "sprite_routines.h"


u32 *sprite_pointer;

struct ObjectSlot object_buffer[MAX_OBJECTS];

ARM_CODE void load_next_object() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied == FALSE) {
            if ((*sprite_pointer & 0xff000000) != 0xff000000) {
                struct Object new_object;
                // Get x position
                new_object.x = *sprite_pointer;
                sprite_pointer++;
                // The next word has both the Y position and type, first 16 bits is type and last 16 bits is Y
                // Y position is relative to the level height, so calculate the position from the top left of the entire level buffer,
                // that is, adding ground height minus level height (that calculates the empty space above the level) minus 1. That is in blocks
                // so multiply it by 16 to get a block-pixel value
                new_object.y = (u16)(*sprite_pointer) + ((GROUND_HEIGHT - curr_level_height - 1) << 4);
                new_object.type = (*sprite_pointer) >> 16;
                sprite_pointer++;

                // If the object is a color trigger, then get more attributes (attrib3 is set on activation)
                if (new_object.type == COL_TRIGGER) {
                    new_object.attrib1 = (u16)(*sprite_pointer);  // Frames and channel
                    new_object.attrib2 = (*sprite_pointer) >> 16; // Color
                    sprite_pointer++;
                    new_object.attrib3 = (u16)(*sprite_pointer);  // Copy channel
                    sprite_pointer++;
                } else {
                    // Load flip values
                    new_object.attrib1 = (u16)(*sprite_pointer);

                    s32 enable_rotation = new_object.attrib1 & ENABLE_ROTATION_FLAG;
                    if (enable_rotation) {
                        new_object.rotation = ((*sprite_pointer) >> 16);
                    } else {
                        new_object.rotation = 0;
                    }
                    sprite_pointer++;
                }

                // Occupy object slot and init some variables
                object_buffer[index].occupied = TRUE;
                object_buffer[index].activated = FALSE;
                object_buffer[index].object = new_object;
            }
        }
    }
}

void do_collision(struct ObjectSlot *objectSlot);
// This function runs col triggers. It is important that it is done in VBLANK because it acceses palette memory

s32 find_affine_slot(u16 rotation) {
    // Search for already existing values
    for (s32 slot = 0; slot < NUM_ROT_SLOTS; slot++) {
        u16 curr_rot = rotation_buffer[slot];

        if (rotation == curr_rot) return slot;
        // If curr_rot is 0, then we are on empty slots
        if (!curr_rot) {
            // Set here rotation
            rotation_buffer[slot] = rotation;

            return slot;
        }
    }

    // Slots are full
    return -1;
}

void do_display(struct Object curr_object, s32 relative_x, s32 relative_y, u8 hflip, u8 vflip) {
    if (curr_object.attrib1 & ENABLE_ROTATION_FLAG) {
        u16 rotation = curr_object.rotation;
        s32 slot = find_affine_slot(rotation);

        if (slot >= 0) {
            // Draw affine sprite
            oam_affine_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], curr_object.rotation, slot + NUM_RESERVED_ROT_SLOTS);
            obj_aff_identity(&obj_aff_buffer[slot + NUM_RESERVED_ROT_SLOTS]);
            obj_aff_rotate(&obj_aff_buffer[slot + NUM_RESERVED_ROT_SLOTS], rotation);
        } else {
            // Slots are full, so display a normal sprite
            oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], hflip, vflip);
        }
    } else {    
        oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], hflip, vflip);
    }
}

void scale_pulsing_objects() {
    obj_aff_identity(&obj_aff_buffer[PULSING_OBJECTS_SLOT]);
    u32 music_volume = 0;

    // Get loudest channel
    for (s32 channel = 0; channel < (NUM_CHANNELS << 4); channel += 0x10) {
        u32 volume = music_data[VOLUME_INDEX + channel];
        if (volume > music_volume) {
            music_volume = volume;
        }
    }

    // Multiply by 2
    music_volume <<= 1;

    u32 value = CLAMP(0x300 - (music_volume), 0x140, 0x300);
    obj_aff_scale(&obj_aff_buffer[4], value, value);
}

ARM_CODE void display_objects() {
    // Pulsing objects size changes
    scale_pulsing_objects();

    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            struct Object curr_object = object_buffer[index].object;
            
            // Color triggers are handler earlier in the frame
            if (curr_object.type != COL_TRIGGER) {
                // Calculate the relative positions
                s32 relative_x = curr_object.x - ((scroll_x >> 8) & 0xffffffff);
                s32 relative_y = curr_object.y - ((scroll_y >> 8) & 0xffff);

                u8 hflip = (curr_object.attrib1 & H_FLIP_FLAG) >> 1;
                u8 vflip = curr_object.attrib1 & V_FLIP_FLAG;

                // Unload object in case that it is 128 pixels left to the screen
                if (relative_x < -128) {
                    object_buffer[index].occupied = FALSE;
                    continue;
                }
                // If object's sprite is null, then do not draw anything
                if (obj_sprites[curr_object.type] != NULL) {
                    // If object is inside the screen horizontally, continue
                    if (relative_x < SCREEN_WIDTH + 128) { 
                        // If the object is inside the screen vertically, display it
                        if (relative_y > -128 && relative_y < SCREEN_HEIGHT) {
                            do_display(curr_object, relative_x, relative_y, hflip, vflip);
                        }
                    }
                }
            } else {
                // If a color trigger, then just run collision
                do_collision(&object_buffer[index]);
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
ARM_CODE s32 is_colliding_rotated_fixed(s32 x1, s32 y1, s32 w1, s32 h1, s32 x2, s32 y2, s32 w2, s32 h2, u16 offset_y, u16 angle) {
    // Center of second rectangle
    s32 cx2 = x2 + (w2 >> 1);
    s32 cy2 = y2 + (h2 >> 1) + offset_y;

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

void do_collision(struct ObjectSlot *objectSlot) {
    // Check collision type and run code related to it
    u16 obj_type = objectSlot->object.type;
    
    // Make sure we don't index the table out of bounds
    if (obj_type >= OBJ_COUNT) obj_type = 0;

    // Jump to the routine assigned to this object type
    routines_jump_table[obj_type](objectSlot);
}

void check_obj_collision(u32 index) {
    struct Object curr_object = object_buffer[index].object;

    u16 obj_width = obj_hitbox[curr_object.type][0];
    u16 obj_height = obj_hitbox[curr_object.type][1];

    // If the hitbox is 0x0, then there is no hitbox
    if ((obj_width | obj_height) == 0) {
        return;
    }

    s16 offset_x = obj_hitbox[curr_object.type][2];
    s16 offset_y = obj_hitbox[curr_object.type][3];

    s16 center_x = obj_hitbox[curr_object.type][4];
    s16 center_y = obj_hitbox[curr_object.type][5];

    if (curr_object.attrib1 & H_FLIP_FLAG) {
        offset_x = center_x - (offset_x - center_x + obj_width); 
    }

    if (curr_object.attrib1 & V_FLIP_FLAG) {
        offset_y = center_y - (offset_y - center_y + obj_height); 
    }

    u32 obj_x = curr_object.x + offset_x;
    u32 obj_y = curr_object.y + offset_y;

    u32 ply_x = player_x >> 8;
    u32 ply_y = player_y >> 8;

    if (curr_object.attrib1 & ENABLE_ROTATION_FLAG) {
        // Check if a collision has happened
        if (is_colliding_rotated_fixed(
            ply_x, ply_y, player_width, player_height, 
            obj_x, obj_y, obj_width, obj_height, (offset_y >> 1), curr_object.rotation
        )) {
            // If yes, then run the collision routine
            do_collision(&object_buffer[index]);
        }   
    } else {
        // Check if a collision has happened
        if (is_colliding(
            ply_x, ply_y, player_width, player_height, 
            obj_x, obj_y, obj_width, obj_height
        )) {
            // If yes, then run the collision routine
            do_collision(&object_buffer[index]);
        }   
    }
}