#include <tonc.h>
#ifndef SPR_LOADING_H
#define SPR_LOADING_H

#define MAX_OBJECTS 32

struct Object {
    u32 x;
    u16 y;
    u16 type;
};

struct ObjectSlot {
    u8 occupied;
    u8 activated;
    struct Object object;
};

enum Obj_Types {
    NONE,
    SHIP_PORTAL,
    CUBE_PORTAL,
    OBJ_COUNT
};

extern struct Object gObject;
extern u32 *sprite_pointer;
extern struct ObjectSlot object_buffer[MAX_OBJECTS];


void load_next_object();
void display_objects();
void check_obj_collision(u32 index);
#endif