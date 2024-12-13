#include <tonc.h>

void collision_main();

#define GROUND_TILE_1 0x88
#define GROUND_TILE_2 0x89
#define GROUND_TILE_3 0x02
#define GROUND_TILE_4 0x06

enum COL_TYPES {
    COL_NONE,
    COL_ALL,
    COL_DEATH,
    COL_SLAB_TOP,
    COL_SLAB_BOTTOM,
};

extern const u16 coll_type_table[];
extern const u16 ground_pattern[];