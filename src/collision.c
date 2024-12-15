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

enum COL_SIDES {
    TOP,
    BOTTOM,
    RIGHT
};

u32 run_coll(u32 x, u32 y, u32 layer, u8 side);
void collision_cube();
void collision_ship();

void collision_main() {
    // TODO: right side collision and death stuff
    switch (gamemode) {
        case CUBE:
            collision_cube();
            break;
        case SHIP:
            collision_ship();
            break;
    }
}

void collision_cube() {
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        if (!gravity_dir) {
            if (player_y_speed >= 0) {
                // Going down
                coll_x = player_x >> 8;
                coll_y = player_y >> 8;
                
                if (run_coll(coll_x, coll_y + CUBE_HEIGHT, layer, BOTTOM)) {
                    return;
                }
                if (run_coll(coll_x + CUBE_WIDTH, coll_y + CUBE_HEIGHT, layer, BOTTOM)) {
                    return;
                }
            }
        } else {
            if (player_y_speed <= 0) {
                // Going up
                coll_x = player_x >> 8;
                coll_y = player_y >> 8;

                if (run_coll(coll_x, coll_y, layer, TOP)) {
                    return;
                }
                if (run_coll(coll_x + CUBE_WIDTH, coll_y, layer, TOP)) {
                    return;
                }
            }
        }
    }
}

void collision_ship() {
    for (u32 layer = 0; layer < LEVEL_LAYERS; layer++) {
        if (player_y_speed >= 0) {
            // Going down
            coll_x = player_x >> 8;
            coll_y = (player_y >> 8) + ((0x10 - SHIP_HEIGHT) >> 1);
            
            if (run_coll(coll_x, coll_y + SHIP_HEIGHT, layer, BOTTOM)) {
                return;
            }
            if (run_coll(coll_x + SHIP_WIDTH, coll_y + SHIP_HEIGHT, layer, BOTTOM)) {
                return;
            }
        }
        if (player_y_speed <= 0) {
            // Going up
            coll_x = player_x >> 8;
            coll_y = (player_y >> 8) + ((0x10 - SHIP_HEIGHT) >> 1);

            if (run_coll(coll_x, coll_y, layer, TOP)) {
                return;
            }
            if (run_coll(coll_x + SHIP_WIDTH, coll_y, layer, TOP)) {
                return;
            }
        }
    }
}

u16 obtain_block(u32 x, u32 y, u32 layer) {
    u32 block_x = (x >> 4) & 0x1f; // Get block x in buffer (0-31)
    u32 block_y = y >> 4;          // Get block y in buffer, not capped for easy level vertical extension

    return level_buffer[layer][block_x + block_y * LEVEL_BUFFER_WIDTH];
}

u16 obtain_collision_type(u32 x, u32 y, u32 layer) {
    // Obtain the col type from the table, indexed by metatile ID
    return metatiles[obtain_block(x,y,layer)][4];
}

u32 col_type_lookup(u16 col_type, u32 x, u32 y, u8 side) {
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
                eject = y_inside_block & 0x07;
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
    if (side == TOP) {
        player_y -= (eject | 0xfffffff8) << 8;
    } else if (side == BOTTOM) {   
        player_y -= eject << 8;
    }

    // We are on the floor so allow jumping and stuff
    on_floor = 1;
    return 1;
}

u32 run_coll(u32 x, u32 y, u32 layer, u8 side) {
    u16 col_type = obtain_collision_type(x, y, layer);
    return col_type_lookup(col_type, x, y, side);
}