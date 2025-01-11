#include <tonc.h>
#ifndef SPR_LOADING_H
#define SPR_LOADING_H

#define MAX_OBJECTS 64
#define NUM_ROT_SLOTS 27 // 5 are reserved to saws, music pulsing circles, and both players
#define NUM_RESERVED_ROT_SLOTS 32 - NUM_ROT_SLOTS 

#define AFF_SLOT_P1 0
#define AFF_SLOT_P2 1
#define AFF_SLOT_CLOCKWISE 2
#define AFF_SLOT_COUNTERCLOCKWISE 3
#define AFF_SLOT_PULSING 4

#define VOLUME_INDEX 550

#define H_FLIP_FLAG (1 << 1)
#define V_FLIP_FLAG (1 << 0)
#define ENABLE_ROTATION_FLAG (1 << 2)

#define CIRCLE_HITBOX_FLAG (1 << 0)

// Rotating flags (used by saws and objects that rotate continously)
#define IS_ROTATING_FLAG          (1 << 1)
#define ROTATING_OBJ_BIT 2
#define ROTATING_CLOCKWISE        (0 << ROTATING_OBJ_BIT)
#define ROTATING_COUNTERCLOCKWISE (1 << ROTATING_OBJ_BIT)
#define ROTATING_DIRECTION_BIT    (1 << ROTATING_OBJ_BIT)

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

struct ObjectCHRSlot {
    u8 occupied;
    u8 object_slot;
    u8 tile_num;
    u32 rom_offset;
    u16 vram_offset;
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
void object_tile_data_load(u16 object_type);

IWRAM_CODE void sort_oam_by_prio();
#endif