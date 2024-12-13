#include "main.h"

// Collision types indexed by metatile ID
const u16 coll_type_table[] = {
    COL_NONE, COL_ALL,      COL_ALL,  COL_SLAB_BOTTOM, COL_NONE,  COL_NONE,  COL_ALL,   COL_NONE, // 0x0000-0x0007
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0008-0x000f
    COL_ALL,  COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_ALL,   COL_ALL,  // 0x0010-0x0017
    COL_NONE, COL_SLAB_TOP, COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0018-0x001f
    COL_ALL,  COL_ALL,      COL_ALL,  COL_ALL,         COL_ALL,   COL_ALL,   COL_ALL,   COL_ALL,  // 0x0020-0x0027
    COL_ALL,  COL_ALL,      COL_ALL,  COL_ALL,         COL_ALL,   COL_ALL,   COL_ALL,   COL_NONE, // 0x0028-0x002f
    COL_ALL,  COL_ALL,      COL_ALL,  COL_ALL,         COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0030-0x0037
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0038-0x003f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0040-0x0047
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0048-0x004f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0050-0x0057
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0058-0x005f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0060-0x0067
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0068-0x006f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0070-0x0077
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0078-0x007f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0080-0x0087
    COL_ALL,  COL_ALL,      COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0088-0x008f
    COL_NONE, COL_NONE,     COL_NONE, COL_NONE,        COL_NONE,  COL_NONE,  COL_NONE,  COL_NONE, // 0x0090-0x0097
};

// Ground pattern
const u16 ground_pattern[] = {
    GROUND_TILE_1, GROUND_TILE_2, GROUND_TILE_2, GROUND_TILE_2,
    GROUND_TILE_3, GROUND_TILE_4, GROUND_TILE_4, GROUND_TILE_4
};

u16 coll_x;
u16 coll_y;

u32 coll_pushed_y;

u32 run_coll(u32 x, u32 y) ;

void collision_main() {
    // TODO: right side collision and death stuff
    if (!gravity_dir) {
        // Going down
        coll_x = player_x >> 8;
        coll_y = player_y >> 8;
        
        if (run_coll(coll_x, coll_y + CUBE_HEIGHT)) {
            return;
        }
        if (run_coll(coll_x + CUBE_WIDTH, coll_y + CUBE_HEIGHT)) {
            return;
        }
    } else {
        // Going up
        coll_x = player_x >> 8;
        coll_y = player_y >> 8;

        if (run_coll(coll_x, coll_y)) {
            return;
        }
        if (run_coll(coll_x + CUBE_WIDTH, coll_y)) {
            return;
        }
    }
}

u16 obtain_block(u32 x, u32 y) {
    u32 block_x = (x >> 4) & 0x1f; // Get block x in buffer (0-31)
    u32 block_y = y >> 4;          // Get block y in buffer, not capped for easy level vertical extension

    return level_buffer[block_x + block_y * LEVEL_BUFFER_WIDTH];
}

u16 obtain_collision_type(u32 x, u32 y) {
    return coll_type_table[obtain_block(x,y)];
}
u32 eject = 0;

u32 col_type_lookup(u16 col_type, u32 x, u32 y) {
    u32 x_inside_block = (x & 0x0f);
    u32 y_inside_block = (y & 0x0f);

    // TODO: death col types
    switch (col_type) {
        case COL_NONE:
            return 0;
        case COL_ALL:
            eject = y_inside_block;
            break;
        case COL_SLAB_TOP:
            if (y_inside_block < 0x8) {
                eject = y_inside_block;
                break;
            }
            return 0;
        case COL_SLAB_BOTTOM:
            if (y_inside_block >= 0x8) {
                eject = y_inside_block - 0x08;
                break;
            }
            return 0;
        default:
            return 0;
    }

    // Set related vars and set new player y position
    player_y_speed = 0;
    player_y &= 0xffffff00;
    player_y -= eject << 8;

    // We are on the floor so allow jumping and stuff
    on_floor = 1;
    return 1;
}

u32 run_coll(u32 x, u32 y) {
    u16 col_type = obtain_collision_type(x, y);
    if (!col_type_lookup(col_type, x, y)) {
        // If nothing was detected, no floor
        on_floor = 0;
        return 0;
    }
    return 1;
}