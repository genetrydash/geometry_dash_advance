#include "sprite_loading.h"
#include "memory.h"
#include "metaspr.h"
#include "player.h"
#include "sprite_routines.h"
#include "physics_defines.h"
#include "collision.h"


u32 *sprite_pointer;

struct ObjectSlot object_buffer[MAX_OBJECTS];

ARM_CODE void load_objects() {
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
            obj_aff_rotate_inv(&obj_aff_buffer[slot + NUM_RESERVED_ROT_SLOTS], rotation);
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
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            struct Object curr_object = object_buffer[index].object;
            
            // Color triggers are handler earlier in the frame
            if (curr_object.type != COL_TRIGGER) {
                // Calculate the relative positions
                s32 relative_x = curr_object.x - ((scroll_x >> SUBPIXEL_BITS) & 0xffffffff);
                s32 relative_y = curr_object.y - ((scroll_y >> SUBPIXEL_BITS) & 0xffff);

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

    u32 ply_x = player_x >> SUBPIXEL_BITS;
    u32 ply_y = player_y >> SUBPIXEL_BITS;

    if (curr_object.attrib1 & ENABLE_ROTATION_FLAG) {
        // Check if a collision has happened
        if (is_colliding_rotated_fixed(
            ply_x, ply_y, player_width, player_height, 
            obj_x, obj_y, obj_width, obj_height, curr_object.x, curr_object.y, center_x, center_y, curr_object.rotation
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