#include "sprite_loading.h"
#include "memory.h"
#include "metaspr.h"

struct Object {
    u32 x;
    u16 y;
    u16 type;
};

struct ObjectSlots {
    u8 occupied;
    struct Object object;
};

struct Object gObject;

u32 *sprite_pointer;

struct ObjectSlots object_buffer[MAX_OBJECTS];

void load_next_object() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied == FALSE) {
            if ((*sprite_pointer & 0xff000000) != 0xff000000) {
                gObject.x = *sprite_pointer;
                sprite_pointer++;
                gObject.y = (u16) (*sprite_pointer);
                gObject.type = (*sprite_pointer) >> 16;
                sprite_pointer++;

                object_buffer[index].occupied = TRUE;
                object_buffer[index].object = gObject;
            }
        }
    }
}

void display_objects() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            struct Object curr_object = object_buffer[index].object;

            s32 relative_x = curr_object.x - (scroll_x & 0xffffffff);
            s32 relative_y = curr_object.y - ((scroll_y & 0xffff) - ((GROUND_HEIGHT - curr_level_height) << 4));

            // Unload object
            if (relative_x < -128) {
                object_buffer[index].occupied = FALSE;
            }
            // If between bounds of screen, display
            if (relative_y > -128 && relative_y < SCREEN_HEIGHT) {
                if (relative_x < SCREEN_WIDTH) { 
                    oam_metaspr(relative_x, relative_y, obj_sprites[curr_object.type]);
                }
            }
        }
    }
}