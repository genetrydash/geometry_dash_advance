#include "sprite_loading.h"
#include "memory.h"
#include "metaspr.h"
#include "player.h"

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
                gObject.y = (u16)(*sprite_pointer) + ((GROUND_HEIGHT - curr_level_height - 1) << 4);
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
            s32 relative_y = curr_object.y - (scroll_y & 0xffff);

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

u32 is_colliding(u32 x1, u32 y1, u32 w1, u32 h1, u32 x2, u32 y2, u32 w2, u32 h2) {
    if (x1 + w1 < x2) {
        return FALSE;
    }

    if (x1 > x2 + w2) {
        return FALSE;
    }

    if (y1 + h1 < y2) {
        return FALSE;
    }

    if (y1 > y2 + h2) {
        return FALSE;
    }

    // If all above is FALSE, then collision has happen
    return TRUE;
}

void do_collision(u16 obj_type) {
    switch (obj_type) {
        case NONE: 
            break;
        case SHIP_PORTAL:
            gamemode = SHIP;
            break;
        case CUBE_PORTAL:
            gamemode = CUBE;
            break;
        default: 
            break;
    }
}

void check_obj_collision() {
    for (s32 index = 0; index < MAX_OBJECTS; index++) {
        if (object_buffer[index].occupied) {
            struct Object curr_object = object_buffer[index].object;

            u16 obj_width = obj_hitbox[curr_object.type][0];
            u16 obj_height = obj_hitbox[curr_object.type][1];
            s16 offset_x = obj_hitbox[curr_object.type][2];
            s16 offset_y = obj_hitbox[curr_object.type][3];

            u32 obj_x = curr_object.x + offset_x;
            u32 obj_y = curr_object.y + offset_y;

            u32 ply_x = player_x >> 8;
            u32 ply_y = player_y >> 8;

            if (is_colliding(
                ply_x, ply_y, player_width, player_height, 
                obj_x, obj_y, obj_width, obj_height
            )) {
                do_collision(curr_object.type);
            }
        }
    }
}