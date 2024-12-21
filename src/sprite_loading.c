#include "sprite_loading.h"
#include "memory.h"
#include "metaspr.h"
#include "player.h"
#include "sprite_routines.h"

struct Object gObject;

u32 *sprite_pointer;

struct ObjectSlot object_buffer[MAX_OBJECTS];

void load_next_object() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied == FALSE) {
            if ((*sprite_pointer & 0xff000000) != 0xff000000) {
                // Get x position
                gObject.x = *sprite_pointer;
                sprite_pointer++;
                // The next word has both the Y position and type, first 16 bits is type and last 16 bits is Y
                // Y position is relative to the level height, so calculate the position from the top left of the entire level buffer,
                // that is, adding ground height minus level height (that calculates the empty space above the level) minus 1. That is in blocks
                // so multiply it by 16 to get a block-pixel value
                gObject.y = (u16)(*sprite_pointer) + ((GROUND_HEIGHT - curr_level_height - 1) << 4);
                gObject.type = (*sprite_pointer) >> 16;
                sprite_pointer++;

                // If the object is a color trigger, then get more attributes (attrib3 is set on activation)
                if (gObject.type == COL_TRIGGER) {
                    gObject.attrib1 = (u16)(*sprite_pointer);  // Frames and channel
                    gObject.attrib2 = (*sprite_pointer) >> 16; // Color
                    sprite_pointer++;
                } else {
                    // Load flip values
                    gObject.attrib1 = (u16)(*sprite_pointer);

                    s32 enable_rotation = gObject.attrib1 & ENABLE_ROTATION_FLAG;
                    if (enable_rotation) {
                        gObject.rotation = ((*sprite_pointer) >> 16);
                    } else {
                        gObject.rotation = 0;
                    }
                    sprite_pointer++;
                }

                // Occupy object slot and init some variables
                object_buffer[index].occupied = TRUE;
                object_buffer[index].activated = FALSE;
                object_buffer[index].object = gObject;
            }
        }
    }
}

void do_collision(struct ObjectSlot *objectSlot);
// This function runs col triggers. It is important that it is done in VBLANK because it acceses palette memory
void run_col_triggers() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            if (object_buffer[index].object.type == COL_TRIGGER) {    
                do_collision(&object_buffer[index]);
            }
        }
    }
}

s32 find_affine_slot(u16 rotation) {
    // Search for already existing values
    for (s32 slot = 0; slot < NUM_ROT_SLOTS; slot++) {
        u16 curr_rot = rotation_buffer[slot];

        if (rotation == curr_rot) return slot;
    }

    // If not found, then allocate one
    for (s32 slot = 0; slot < NUM_ROT_SLOTS; slot++) {
        u16 curr_rot = rotation_buffer[slot];
        
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
            oam_affine_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], hflip, vflip, slot + 4);
            obj_aff_identity(&obj_aff_buffer[slot + 4]);
            obj_aff_rotate(&obj_aff_buffer[slot + 4], rotation);
        } else {
            // Slots are full, so display a normal sprite
            oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], hflip, vflip);
        }
    } else {    
        oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type], hflip, vflip);
    }
}

void display_objects() {
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
                    return;
                }
                // If object's sprite is null, then do not draw anything
                if (obj_sprites[curr_object.type] != NULL) {
                    // If object is inside the screen horizontally, continue
                    if (relative_x < SCREEN_WIDTH + 128) { 
                        // If it hasn't been activated already, check collision
                        if (object_buffer[index].activated == FALSE) {
                            check_obj_collision(index); 
                        }  

                        // If the object is inside the screen vertically, display it
                        if (relative_y > -128 && relative_y < SCREEN_HEIGHT) {
                            do_display(curr_object, relative_x, relative_y, hflip, vflip);
                        }
                    }
                }
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

    u32 obj_x = curr_object.x + offset_x;
    u32 obj_y = curr_object.y + offset_y;

    u32 ply_x = player_x >> 8;
    u32 ply_y = player_y >> 8;

    // Check if a collision has happened
    if (is_colliding(
        ply_x, ply_y, player_width, player_height, 
        obj_x, obj_y, obj_width, obj_height
    )) {
        // If yes, then run the collision routine
        do_collision(&object_buffer[index]);
    }
}