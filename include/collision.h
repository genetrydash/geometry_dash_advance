#include <tonc.h>
#include "memory.h"

#define GROUND_TILE_1 0xb0
#define GROUND_TILE_2 0xb1
#define GROUND_TILE_3 0xb2

#define GROUND_TILE_4 0xc0
#define GROUND_TILE_5 0xc1
#define GROUND_TILE_6 0xc2

#define GROUND_TILE_7 0xd0
#define GROUND_TILE_8 0xd1
#define GROUND_TILE_9 0xd2

#define GROUND_TILE_A 0xe0
#define GROUND_TILE_B 0xe1
#define GROUND_TILE_C 0xe2

enum COL_TYPES {
    COL_NONE,
    COL_ALL,
    COL_SPIKE_TOP,
    COL_SPIKE_BOTTOM,
    COL_SPIKE_RIGHT,
    COL_SPIKE_LEFT,
    COL_SMALL_SPIKE_TOP,
    COL_SMALL_SPIKE_BOTTOM,
    COL_SMALL_SPIKE_RIGHT,
    COL_SMALL_SPIKE_LEFT,
    COL_MEDIUM_SPIKE_TOP,
    COL_MEDIUM_SPIKE_BOTTOM,
    COL_MEDIUM_SPIKE_RIGHT,
    COL_MEDIUM_SPIKE_LEFT,
    COL_SLAB_TOP,
    COL_SLAB_BOTTOM,
};

extern const u16 ground_pattern[];

extern u32 coll_x;
extern u32 coll_y;

void collision_cube();
void collision_ship();
void do_collision_with_objects();
void check_obj_collision(u32 index);
u32 is_colliding(u32 x1, u32 y1, u32 w1, u32 h1, u32 x2, u32 y2, u32 w2, u32 h2);
ARM_CODE s32 is_colliding_rotated_fixed(s32 x1, s32 y1, s32 w1, s32 h1, s32 x2, s32 y2, s32 w2, s32 h2, s32 orig_x, s32 orig_y, s32 cx2offset, s32 cy2offset, u16 angle);