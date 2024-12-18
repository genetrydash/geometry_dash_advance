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

                // If the object is a color trigger, then get more attributes
                if (gObject.type == COL_TRIGGER) {
                    gObject.attrib1 = (u16)(*sprite_pointer);  // Frames and channel
                    gObject.attrib2 = (*sprite_pointer) >> 16; // Color
                    gObject.attrib4 = 0;                       // Temp storage for current transition frame
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

void display_objects() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            struct Object curr_object = object_buffer[index].object;

            // Calculate the relative positions
            s32 relative_x = curr_object.x - ((scroll_x >> 8) & 0xffffffff);
            s32 relative_y = curr_object.y - ((scroll_y >> 8) & 0xffff);

            // Unload object in case that it is 128 pixels left to the screen if not a trigger
            if (curr_object.type != COL_TRIGGER) {
                if (relative_x < -128) {
                    object_buffer[index].occupied = FALSE;
                }
            }
            // If object's sprite is null, then do not draw anything
            if (obj_sprites[curr_object.type] != NULL) {
                // If object is inside the screen horizontally, continue
                if (relative_x < SCREEN_WIDTH) { 
                    // If it hasn't been activated already, check collision
                    if (object_buffer[index].activated == FALSE) {
                        check_obj_collision(index); 
                    }  

                    // If the object is inside the screen vertically, display it
                    if (relative_y > -128 && relative_y < SCREEN_HEIGHT) {
                        oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type]);
                    }
                }
            } else {
                // If there is no sprite associated, then just check for collision
                if (object_buffer[index].activated == FALSE) {
                    check_obj_collision(index); 
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

    // Check if the object is a trigger, then run collision always
    if (curr_object.type == COL_TRIGGER) {
        do_collision(&object_buffer[index]);
    } else {
        u16 obj_width = obj_hitbox[curr_object.type][0];
        u16 obj_height = obj_hitbox[curr_object.type][1];
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
}