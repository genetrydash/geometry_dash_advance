#include <tonc.h>

void collision_cube();
void collision_ship();

#define GROUND_TILE_1 2
#define GROUND_TILE_2 2
#define GROUND_TILE_3 2
#define GROUND_TILE_4 2

enum COL_TYPES {
    COL_NONE,
    COL_ALL,
    COL_DEATH,
    COL_SLAB_TOP,
    COL_SLAB_BOTTOM,
};

extern const u16 ground_pattern[];