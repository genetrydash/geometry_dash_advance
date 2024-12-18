#include <tonc.h>

void collision_cube();
void collision_ship();

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
    COL_DEATH,
    COL_SLAB_TOP,
    COL_SLAB_BOTTOM,
};

extern const u16 ground_pattern[];