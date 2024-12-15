#include "main.h"
#include "metatiles.h"

// Ground pattern
const u16 ground_pattern[] = {
    GROUND_TILE_1, GROUND_TILE_2, GROUND_TILE_2, GROUND_TILE_2,
    GROUND_TILE_3, GROUND_TILE_4, GROUND_TILE_4, GROUND_TILE_4
};

// Pixel to check collision on.
u16 coll_x;
u16 coll_y;

// Collision eject
u32 eject = 0;

u32 run_coll(u32 x, u32 y);

void collision_main() {
    // TODO: right side collision and death stuff
    if (!gravity_dir) {
        if (player_y_speed > 0) {
            // Going down
            coll_x = player_x >> 8;
            coll_y = player_y >> 8;
            
            if (run_coll(coll_x, coll_y + CUBE_HEIGHT)) {
                return;
            }
            if (run_coll(coll_x + CUBE_WIDTH, coll_y + CUBE_HEIGHT)) {
                return;
            }
        }
    } else {
        if (player_y_speed < 0) {
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
}

u16 obtain_block(u32 x, u32 y) {
    u32 block_x = (x >> 4) & 0x1f; // Get block x in buffer (0-31)
    u32 block_y = y >> 4;          // Get block y in buffer, not capped for easy level vertical extension

    return level_buffer[block_x + block_y * LEVEL_BUFFER_WIDTH];
}

u16 obtain_collision_type(u32 x, u32 y) {
    // Obtain the col type from the table, indexed by metatile ID
    return metatiles[obtain_block(x,y)][4];
}

u32 col_type_lookup(u16 col_type, u32 x, u32 y) {
    // Positions inside block, top left pixel is [0,0]
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
        // Everything else
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
    return col_type_lookup(col_type, x, y);
}