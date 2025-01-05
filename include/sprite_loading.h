#include <tonc.h>
#ifndef SPR_LOADING_H
#define SPR_LOADING_H

#define MAX_OBJECTS 64
#define NUM_ROT_SLOTS 27 // 5 are reserved to saws, music pulsing circles, and both players
#define NUM_RESERVED_ROT_SLOTS 32 - NUM_ROT_SLOTS 

#define PULSING_OBJECTS_SLOT 4
#define VOLUME_INDEX 550

#define H_FLIP_FLAG (1 << 1)
#define V_FLIP_FLAG (1 << 0)
#define ENABLE_ROTATION_FLAG (1 << 2)

#define CIRCLE_HITBOX_FLAG (1 << 0)

// Saw flags
#define IS_SAW_FLAG          (1 << 1)
#define SAW_ROT_BIT 2
#define SAW_CLOCKWISE        (0 << SAW_ROT_BIT)
#define SAW_COUNTERCLOCKWISE (1 << SAW_ROT_BIT)
#define SAW_ROT_FLAG         (1 << SAW_ROT_BIT)

struct Object {
    u32 x;
    u16 y;
    u16 type;
    u16 attrib1;
    u16 attrib2;
    u16 attrib3;
    u16 rotation;
};

struct ObjectSlot {
    u8 occupied;
    u8 activated;
    u8 has_collision;
    struct Object object;
};

enum OrbBufferStates {
    NO_ORB_BUFFER,
    ORB_BUFFER_READY,
    ORB_BUFFER_END
};

extern u32 *sprite_pointer;
extern struct ObjectSlot object_buffer[MAX_OBJECTS];


void load_objects();
void display_objects();
void scale_pulsing_objects();
void rotate_saws();
#endif