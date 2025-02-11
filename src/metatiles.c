#include "metatiles.h"
#include "collision.h"

#define Metatile(name, top_left_tile, top_right_tile, bottom_left_tile, bottom_right_tile, collision_type) {top_left_tile, top_right_tile, bottom_left_tile, bottom_right_tile, collision_type},

#define TILE(id, PALBANK, hflip, vflip) SE_BUILD(id, PALBANK, hflip, vflip)

#define H 1
#define V 1

// Goes like this TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, COL_TYPE
const SCR_ENTRY metatiles[][5] = {
    Metatile("AIR",            TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_UP",       TILE(0x53, 0, 0, 0), TILE(0x54, 0, 0, 0), TILE(0x55, 0, 0, 0), TILE(0x56, 0, 0, 0), COL_SPIKE_TOP)
    Metatile("BASIC_BLOCK",    TILE(0x0e, 0, 0, 0), TILE(0x0f, 0, 0, 0), TILE(0x10, 0, 0, 0), TILE(0x11, 0, 0, 0), COL_FULL)
    
    Metatile("CHK_FULL",       TILE(0x01, 0, 0, 0), TILE(0x01, 0, H, 0), TILE(0x01, 0, 0, V), TILE(0x01, 0, H, V), COL_FULL)
    Metatile("CHK_SIDE_UP",    TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x03, 0, 0, 0), TILE(0x03, 0, H, 0), COL_FULL)
    Metatile("CHK_SIDE_DOWN",  TILE(0x03, 0, 0, V), TILE(0x03, 0, H, V), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_SIDE_LEFT",  TILE(0x04, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x04, 0, 0, V), TILE(0x05, 0, 0, V), COL_FULL)
    Metatile("CHK_SIDE_RIGHT", TILE(0x05, 0, H, 0), TILE(0x04, 0, H, 0), TILE(0x05, 0, H, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_TL",  TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x07, 0, 0, 0), COL_FULL)
    Metatile("CHK_CORNER_TR",  TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x07, 0, H, 0), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_BL",  TILE(0x04, 0, 0, 0), TILE(0x07, 0, 0, V), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_CORNER_BR",  TILE(0x07, 0, H, V), TILE(0x04, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_CRN_INS_TL", TILE(0x08, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, 0), COL_FULL)
    Metatile("CHK_CRN_INS_TR", TILE(0x05, 0, H, 0), TILE(0x08, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, 0), COL_FULL)
    Metatile("CHK_CRN_INS_BL", TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, V), TILE(0x08, 0, 0, V), TILE(0x05, 0, 0, V), COL_FULL)
    Metatile("CHK_CRN_INS_BR", TILE(0x09, 0, H, V), TILE(0x03, 0, H, V), TILE(0x05, 0, H, V), TILE(0x08, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_TOP", TILE(0x06, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_BOT", TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_LFT", TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_DB_CRN_RGT", TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_FULL)
    Metatile("CHK_DB_SIDE_V",  TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_FULL)
    Metatile("CHK_DB_SIDE_H",  TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_FULL)
    Metatile("CHK_FILLER",     TILE(0x0a, 0, 0, 0), TILE(0x0a, 0, H, 0), TILE(0x0a, 0, 0, V), TILE(0x0a, 0, H, V), COL_NONE)
    
    Metatile("SPIKE_DOWN",         TILE(0x55, 0, 0, V), TILE(0x56, 0, 0, V), TILE(0x53, 0, 0, V), TILE(0x54, 0, 0, V), COL_SPIKE_BOTTOM)
    Metatile("SPIKE_RIGHT",        TILE(0x57, 0, 0, 0), TILE(0x58, 0, 0, 0), TILE(0x59, 0, 0, 0), TILE(0x5a, 0, 0, 0), COL_SPIKE_LEFT)
    Metatile("SPIKE_LEFT",         TILE(0x58, 0, H, 0), TILE(0x57, 0, H, 0), TILE(0x5a, 0, H, 0), TILE(0x59, 0, H, 0), COL_SPIKE_RIGHT)
    Metatile("SMALL_SPIKE_BOTTOM", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5b, 0, 0, 0), TILE(0x5c, 0, 0, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("SMALL_SPIKE_TOP",    TILE(0x5b, 0, 0, V), TILE(0x5c, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("SMALL_SPIKE_LEFT",  TILE(0x5d, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0), TILE(0x5d, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, H, 0), COL_GROUND_SPIKE_RIGHT)
    Metatile("GROUND_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5f, 0, 0, 0), TILE(0x60, 0, 0, 0), COL_GROUND_SPIKE_BOTTOM)
    Metatile("GROUND_SPIKE_TOP",   TILE(0x5f, 0, 0, V), TILE(0x60, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_SPIKE_TOP)
    Metatile("GROUND_SPIKE_LEFT", TILE(0x61, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_SPIKE_LEFT)
    Metatile("GROUND_SPIKE_RIGHT",  TILE(0x00, 0, 0, 0), TILE(0x61, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, H, 0), COL_SMALL_SPIKE_RIGHT)
    Metatile("MEDIUM_SPIKE_BOTTOM",TILE(0x63, 0, 0, 0), TILE(0x63, 0, H, 0), TILE(0x64, 0, 0, 0), TILE(0x65, 0, 0, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("MEDIUM_SPIKE_TOP",   TILE(0x64, 0, 0, V), TILE(0x65, 0, 0, V), TILE(0x63, 0, 0, V), TILE(0x63, 0, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("MEDIUM_SPIKE_LEFT", TILE(0x67, 0, 0, 0), TILE(0x66, 0, 0, 0), TILE(0x68, 0, 0, 0), TILE(0x66, 0, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("MEDIUM_SPIKE_RIGHT",  TILE(0x66, 0, H, 0), TILE(0x67, 0, H, 0), TILE(0x66, 0, H, V), TILE(0x68, 0, H, 0), COL_MEDIUM_SPIKE_RIGHT)
    
    Metatile("CHK_CORNER_TL", TILE(0x0B, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, 0), COL_NONE)
    Metatile("CHK_CORNER_TR", TILE(0x05, 0, H, 0), TILE(0x0B, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, 0), COL_NONE)
    Metatile("CHK_CORNER_BL", TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, V), TILE(0x0B, 0, 0, V), TILE(0x05, 0, 0, V), COL_NONE)
    Metatile("CHK_CORNER_BR", TILE(0x09, 0, H, V), TILE(0x03, 0, H, V), TILE(0x05, 0, H, V), TILE(0x0B, 0, H, V), COL_NONE)
    
    Metatile("BASIC_BLOCK_DARK", TILE(0x26, 0, 0, 0), TILE(0x27, 0, 0, 0), TILE(0x28, 0, 0, 0), TILE(0x29, 0, 0, 0), COL_FULL)
    
    Metatile("SLAB_UP",            TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("SLAB_DOWN",          TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, V), TILE(0x4f, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("SLAB_LEFT",          TILE(0x50, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("SLAB_RIGHT",         TILE(0x00, 0, 0, 0), TILE(0x50, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, H, 0), COL_NONE)
    Metatile("SLAB_DOWN_FLIPPED",  TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), COL_SLAB_BOTTOM)

    Metatile("GROUND_WAVY_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x6f, 0, 0, 0), TILE(0x6f, 0, 0, 0), COL_GROUND_WAVY_SPIKE_BOTTOM) // 0x30
    Metatile("GROUND_WAVY_SPIKE_TOP",   TILE(0x6f, 0, 0, V), TILE(0x6f, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_WAVY_SPIKE_TOP)
    Metatile("GROUND_WAVY_SPIKE_LEFT",  TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_GROUND_WAVY_SPIKE_LEFT)
    Metatile("GROUND_WAVY_SPIKE_RIGHT", TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), COL_GROUND_WAVY_SPIKE_RIGHT)

    Metatile("BASIC_BLOCK_BOTTOM",     TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x0f, 0, 0, 0), COL_SLAB_BOTTOM)
    Metatile("BASIC_BLOCK_TOP",        TILE(0x10, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("BASIC_BLOCK_RIGHT",      TILE(0x00, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x10, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("BASIC_BLOCK_LEFT_RIGHT", TILE(0x0f, 0, 0, 0), TILE(0x0e, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x10, 0, 0, 0), COL_FULL)
    Metatile("BASIC_BLOCK_LEFT",       TILE(0x0f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x11, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT) // 0x38

    Metatile("ENDING_WALL",  TILE(0x00, 0, 0, 0), TILE(0x04, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x04, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("INVISIBLE_FLOOR_CEIL",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_FLOOR_CEIL)

    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("X_FULL",       TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_FULL) // 0x40
    Metatile("X_SIDE_UP",    TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_SIDE_DOWN",  TILE(0x19, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x17, 0, 0, V), TILE(0x18, 0, 0, V), COL_FULL)
    Metatile("X_SIDE_LEFT",  TILE(0x1b, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_SIDE_RIGHT", TILE(0x1c, 0, H, 0), TILE(0x1b, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_FULL)
    Metatile("X_CORNER_TL",  TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_CORNER_TR",  TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_FULL)
    Metatile("X_CORNER_BL",  TILE(0x1d, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x13, 0, 0, V), TILE(0x18, 0, 0, V), COL_FULL)
    Metatile("X_CORNER_BR",  TILE(0x1a, 0, H, V), TILE(0x1d, 0, H, V), TILE(0x18, 0, H, V), TILE(0x13, 0, H, V), COL_FULL) // 0x48
    Metatile("X_INS_CRN_TL", TILE(0x1e, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_TR", TILE(0x22, 0, 0, 0), TILE(0x1f, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_BL", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x20, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_FULL)
    Metatile("X_INS_CRN_BR", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x21, 0, 0, 0), COL_FULL)
    Metatile("X_FILLER",     TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_NONE)
    Metatile("X_DB_CRN_TOP", TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_FULL)
    Metatile("X_DB_CRN_BOT", TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_FULL)
        
    Metatile("X_DB_CRN_LFT", TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_FULL) // 0x50
    Metatile("X_DB_CRN_RGT", TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x24, 0, H, 0), TILE(0x15, 0, H, 0), COL_FULL)
    Metatile("X_DB_SIDE_V",  TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_FULL)
    Metatile("X_DB_SIDE_H",  TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x12, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_FULL)
    
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x58
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("+_FULL",       TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x2c, 0, 0, 0), TILE(0x2d, 0, 0, 0), COL_FULL) // 0x60
    Metatile("+_SIDE_UP",    TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_SIDE_DOWN",  TILE(0x30, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2e, 0, 0, V), TILE(0x2f, 0, 0, V), COL_FULL)
    Metatile("+_SIDE_LEFT",  TILE(0x32, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_SIDE_RIGHT", TILE(0x33, 0, H, 0), TILE(0x32, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_FULL)
    Metatile("+_CORNER_TL",  TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_FULL)
    Metatile("+_CORNER_TR",  TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_FULL)
    Metatile("+_CORNER_BL",  TILE(0x34, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2f, 0, 0, V), COL_FULL)
    Metatile("+_CORNER_BR",  TILE(0x31, 0, H, V), TILE(0x34, 0, H, V), TILE(0x2f, 0, H, V), TILE(0x2a, 0, H, V), COL_FULL) // 0x68
    Metatile("+_FILLER",     TILE(0x35, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_NONE)
    Metatile("+_DB_CRN_TOP", TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_FULL)
    Metatile("+_DB_CRN_BOT", TILE(0x34, 0, 0, V), TILE(0x36, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2b, 0, 0, V), COL_FULL)
    Metatile("+_DB_CRN_LFT", TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x2c, 0, 0, 0), TILE(0x37, 0, 0, 0), COL_FULL)
    Metatile("+_DB_CRN_RGT", TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x39, 0, 0, 0), TILE(0x2d, 0, 0, 0), COL_FULL)
    Metatile("+_DB_SIDE_V",  TILE(0x32, 0, 0, 0), TILE(0x38, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_FULL)
    Metatile("+_DB_SIDE_H",  TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x39, 0, 0, 0), TILE(0x37, 0, 0, 0), COL_FULL)
    
    Metatile("BLK_FULL",        TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL) // 0x70
    Metatile("BLK_SIDE_TOP",    TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_SIDE_BOTTOM", TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)
    Metatile("BLK_SIDE_LEFT",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_SIDE_RIGHT",  TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_CORNER_TL",   TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_CORNER_TR",   TILE(0x3c, 0, H, 0), TILE(0x3b, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_CORNER_BL",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)
    Metatile("BLK_CORNER_BR",   TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL) // 0x78
    Metatile("BLK_INS_CRN_TL",  TILE(0x3e, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_TR",  TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_BL",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, 0, V), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_INS_CRN_BR",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, V, H), COL_FULL)
    Metatile("BLK_FILLER",      TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_FULL)
    Metatile("BLK_DB_CRN_TOP",  TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_DB_CRN_BOT",  TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL)

    Metatile("BLK_DB_CRN_LFT",  TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL) // 0x80
    Metatile("BLK_DB_CRN_RGT",  TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_FULL)
    Metatile("BLK_DB_SIDE_H",   TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_FULL)
    Metatile("BLK_DB_SIDE_V",   TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_FULL)

    Metatile("BLK_FILLER_NO_COLL", TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_NONE)
    
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x88
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("BRICKS_FULL",        TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x41, 0, 0, 0), COL_FULL) // 0x90
    Metatile("BRICKS_SIDE_TOP",    TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_BOTTOM", TILE(0x43, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x42, 0, 0, V), TILE(0x42, 0, H, V), COL_FULL)
    Metatile("BRICKS_SIDE_LEFT",   TILE(0x45, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_RIGHT",  TILE(0x46, 0, H, 0), TILE(0x45, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_FULL)
    Metatile("BRICKS_CORNER_TL",   TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_CORNER_TR",   TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_FULL)
    Metatile("BRICKS_CORNER_BL",   TILE(0x47, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x42, 0, H, V), COL_FULL)
    Metatile("BRICKS_CORNER_BR",   TILE(0x44, 0, H, V), TILE(0x47, 0, H, V), TILE(0x42, 0, 0, V), TILE(0x3f, 0, H, V), COL_FULL) // 0x98
    Metatile("BRICKS_INS_CRN_TL",  TILE(0x48, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_INS_CRN_TR",  TILE(0x46, 0, H, 0), TILE(0x48, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_INS_CRN_BL",  TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x49, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_INS_CRN_BR",  TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x4a, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_FILLER",      TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_DB_CRN_TOP",  TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_DB_CRN_BOT",  TILE(0x47, 0, 0, V), TILE(0x4b, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x3f, 0, H, V), COL_FULL)

    Metatile("BRICKS_DB_CRN_LFT",  TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_FULL) // 0xA0
    Metatile("BRICKS_DB_CRN_RGT",  TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x4c, 0, H, 0), TILE(0x40, 0, H, 0), COL_FULL)
    Metatile("BRICKS_SIDE_H",      TILE(0x45, 0, 0, 0), TILE(0x45, 0, H, 0), TILE(0x45, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_FULL)
    Metatile("BRICKS_SIDE_V",      TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x4d, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_FULL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0xA8
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("GROUND_1",    TILE(0x180, 1, 0, 0), TILE(0x181, 1, 0, 0), TILE(0x190, 1, 0, 0), TILE(0x191, 1, 0, 0), COL_FLOOR_CEIL) // 0xB0
    Metatile("GROUND_2",    TILE(0x181, 1, 0, 0), TILE(0x181, 1, 0, 0), TILE(0x191, 1, 0, 0), TILE(0x191, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_3",    TILE(0x181, 1, 0, 0), TILE(0x182, 1, 0, 0), TILE(0x191, 1, 0, 0), TILE(0x192, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_1",   TILE(0x1f0, 1, 0, V), TILE(0x1f1, 1, 0, V), TILE(0x1e0, 1, 0, V), TILE(0x1e1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_2",   TILE(0x1f1, 1, 0, V), TILE(0x1f1, 1, 0, V), TILE(0x1e1, 1, 0, V), TILE(0x1e1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_3",   TILE(0x1f1, 1, 0, V), TILE(0x1f2, 1, 0, V), TILE(0x1e1, 1, 0, V), TILE(0x1e2, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("WAVY_SLAB_SINGLE_TOP", TILE(0x69, 0, 0, 0), TILE(0x6e, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("WAVY_SLAB_START_TOP",  TILE(0x6a, 0, 0, 0), TILE(0x6b, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x6d, 0, 0, 0), COL_SLAB_TOP)
    Metatile("WAVY_SLAB_MIDDLE_TOP", TILE(0x6c, 0, 0, 0), TILE(0x6c, 0, 0, 0), TILE(0x6d, 0, 0, 0), TILE(0x6d, 0, 0, 0), COL_SLAB_TOP) // 0xB8
    Metatile("WAVY_SLAB_END_TOP",    TILE(0x6c, 0, 0, 0), TILE(0x6e, 0, 0, 0), TILE(0x6d, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)

    Metatile("WAVY_SLAB_SINGLE_BOTTOM", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x69, 0, 0, V), TILE(0x6e, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_START_BOTTOM",  TILE(0x00, 0, 0, 0), TILE(0x6d, 0, 0, V), TILE(0x6a, 0, 0, V), TILE(0x6b, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_MIDDLE_BOTTOM", TILE(0x6d, 0, 0, V), TILE(0x6d, 0, 0, V), TILE(0x6c, 0, 0, V), TILE(0x6c, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("WAVY_SLAB_END_BOTTOM",    TILE(0x6d, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x6c, 0, 0, V), TILE(0x6e, 0, 0, V), COL_SLAB_BOTTOM)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_4",    TILE(0x1a0, 1, 0, 0), TILE(0x1a1, 1, 0, 0), TILE(0x1b0, 1, 0, 0), TILE(0x1b1, 1, 0, 0), COL_FLOOR_CEIL) // 0xC0
    Metatile("GROUND_5",    TILE(0x1a1, 1, 0, 0), TILE(0x1a1, 1, 0, 0), TILE(0x1b1, 1, 0, 0), TILE(0x1b1, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_6",    TILE(0x1a1, 1, 0, 0), TILE(0x1a2, 1, 0, 0), TILE(0x1b1, 1, 0, 0), TILE(0x1b2, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_4",   TILE(0x1d0, 1, 0, V), TILE(0x1d1, 1, 0, V), TILE(0x1c0, 1, 0, V), TILE(0x1c1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_5",   TILE(0x1d1, 1, 0, V), TILE(0x1d1, 1, 0, V), TILE(0x1c1, 1, 0, V), TILE(0x1c1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_6",   TILE(0x1d1, 1, 0, V), TILE(0x1d2, 1, 0, V), TILE(0x1c1, 1, 0, V), TILE(0x1c2, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("WAVY_SLAB_SINGLE_LEFT", TILE(0x70, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, H, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT)
    Metatile("WAVY_SLAB_START_LEFT",  TILE(0x71, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x72, 0, H, 0), TILE(0x74, 0, H, 0), COL_SLAB_LEFT)
    Metatile("WAVY_SLAB_MIDDLE_LEFT", TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), COL_SLAB_LEFT) // 0xC8
    Metatile("WAVY_SLAB_END_LEFT",    TILE(0x73, 0, H, 0), TILE(0x74, 0, H, 0), TILE(0x75, 0, H, 0), TILE(0x00, 0, 0, 0), COL_SLAB_LEFT)

    Metatile("WAVY_SLAB_SINGLE_RIGHT", TILE(0x00, 0, 0, 0), TILE(0x70, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_START_RIGHT",  TILE(0x00, 0, 0, 0), TILE(0x71, 0, 0, 0), TILE(0x74, 0, 0, 0), TILE(0x72, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_MIDDLE_RIGHT", TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("WAVY_SLAB_END_RIGHT",    TILE(0x74, 0, 0, 0), TILE(0x73, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x75, 0, 0, 0), COL_SLAB_RIGHT)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_7",    TILE(0x1c0, 1, 0, 0), TILE(0x1c1, 1, 0, 0), TILE(0x1d0, 1, 0, 0), TILE(0x1d1, 1, 0, 0), COL_FLOOR_CEIL) // 0xD0
    Metatile("GROUND_8",    TILE(0x1c1, 1, 0, 0), TILE(0x1c1, 1, 0, 0), TILE(0x1d1, 1, 0, 0), TILE(0x1d1, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_9",    TILE(0x1c1, 1, 0, 0), TILE(0x1c2, 1, 0, 0), TILE(0x1d1, 1, 0, 0), TILE(0x1d2, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_7",   TILE(0x1b0, 1, 0, V), TILE(0x1b1, 1, 0, V), TILE(0x1a0, 1, 0, V), TILE(0x1a1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_8",   TILE(0x1b1, 1, 0, V), TILE(0x1b1, 1, 0, V), TILE(0x1a1, 1, 0, V), TILE(0x1a1, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_9",   TILE(0x1b1, 1, 0, V), TILE(0x1b2, 1, 0, V), TILE(0x1a1, 1, 0, V), TILE(0x1a2, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("BUSH_GROUND_SPIKE_1_BOTTOM", TILE(0x80, 0, 0, 0), TILE(0x81, 0, 0, 0), TILE(0x90, 0, 0, 0), TILE(0x91, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_2_BOTTOM", TILE(0x82, 0, 0, 0), TILE(0x83, 0, 0, 0), TILE(0x92, 0, 0, 0), TILE(0x93, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_3_BOTTOM", TILE(0x84, 0, 0, 0), TILE(0x85, 0, 0, 0), TILE(0x94, 0, 0, 0), TILE(0x95, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM) // 0xD8
    Metatile("BUSH_GROUND_SPIKE_4_BOTTOM", TILE(0x86, 0, 0, 0), TILE(0x87, 0, 0, 0), TILE(0x96, 0, 0, 0), TILE(0x97, 0, 0, 0), COL_GROUND_BUSH_SPIKE_BOTTOM)
    Metatile("BUSH_GROUND_SPIKE_1_TOP",    TILE(0x90, 0, 0, V), TILE(0x91, 0, 0, V), TILE(0x80, 0, 0, V), TILE(0x81, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_2_TOP",    TILE(0x92, 0, 0, V), TILE(0x93, 0, 0, V), TILE(0x82, 0, 0, V), TILE(0x83, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_3_TOP",    TILE(0x94, 0, 0, V), TILE(0x95, 0, 0, V), TILE(0x84, 0, 0, V), TILE(0x85, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)
    Metatile("BUSH_GROUND_SPIKE_4_TOP",    TILE(0x96, 0, 0, V), TILE(0x97, 0, 0, V), TILE(0x86, 0, 0, V), TILE(0x87, 0, 0, V), COL_GROUND_BUSH_SPIKE_TOP)

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
   
    Metatile("GROUND_A",    TILE(0x1e0, 1, 0, 0), TILE(0x1e1, 1, 0, 0), TILE(0x1f0, 1, 0, 0), TILE(0x1f1, 1, 0, 0), COL_FLOOR_CEIL) // 0xE0
    Metatile("GROUND_B",    TILE(0x1e1, 1, 0, 0), TILE(0x1e1, 1, 0, 0), TILE(0x1f1, 1, 0, 0), TILE(0x1f1, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("GROUND_C",    TILE(0x1e1, 1, 0, 0), TILE(0x1e2, 1, 0, 0), TILE(0x1f1, 1, 0, 0), TILE(0x1f2, 1, 0, 0), COL_FLOOR_CEIL)
    Metatile("CEILING_A",   TILE(0x190, 1, 0, V), TILE(0x191, 1, 0, V), TILE(0x180, 1, 0, V), TILE(0x181, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_B",   TILE(0x191, 1, 0, V), TILE(0x191, 1, 0, V), TILE(0x181, 1, 0, V), TILE(0x181, 1, 0, V), COL_FLOOR_CEIL)
    Metatile("CEILING_C",   TILE(0x191, 1, 0, V), TILE(0x192, 1, 0, V), TILE(0x181, 1, 0, V), TILE(0x182, 1, 0, V), COL_FLOOR_CEIL)

    Metatile("BUSH_GROUND_SPIKE_1_LEFT",  TILE(0x88, 0, 0, 0), TILE(0x89, 0, 0, 0), TILE(0x98, 0, 0, 0), TILE(0x99, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_2_LEFT",  TILE(0x8a, 0, 0, 0), TILE(0x8b, 0, 0, 0), TILE(0x9a, 0, 0, 0), TILE(0x9b, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_3_LEFT",  TILE(0x8c, 0, 0, 0), TILE(0x8d, 0, 0, 0), TILE(0x9c, 0, 0, 0), TILE(0x9d, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT) // 0xE8
    Metatile("BUSH_GROUND_SPIKE_4_LEFT",  TILE(0x8e, 0, 0, 0), TILE(0x8f, 0, 0, 0), TILE(0x9e, 0, 0, 0), TILE(0x9f, 0, 0, 0), COL_GROUND_BUSH_SPIKE_LEFT)
    Metatile("BUSH_GROUND_SPIKE_1_RIGHT", TILE(0x89, 0, H, 0), TILE(0x88, 0, H, 0), TILE(0x99, 0, H, 0), TILE(0x98, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_2_RIGHT", TILE(0x8b, 0, H, 0), TILE(0x8a, 0, H, 0), TILE(0x9b, 0, H, 0), TILE(0x9a, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_3_RIGHT", TILE(0x8d, 0, H, 0), TILE(0x8c, 0, H, 0), TILE(0x9d, 0, H, 0), TILE(0x9c, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)
    Metatile("BUSH_GROUND_SPIKE_4_RIGHT", TILE(0x8f, 0, H, 0), TILE(0x8e, 0, H, 0), TILE(0x9f, 0, H, 0), TILE(0x9e, 0, H, 0), COL_GROUND_BUSH_SPIKE_RIGHT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("1.6_SIDE_BLOCK_TOP", TILE(0xa0, 0, 0, 0), TILE(0xa0, 0, H, 0), TILE(0xb0, 0, 0, 0), TILE(0xb0, 0, H, 0), COL_FULL) // 0xF0
    Metatile("1.6_SIDE_BLOCK_BOT", TILE(0xb0, 0, 0, V), TILE(0xb0, 0, H, V), TILE(0xa0, 0, 0, V), TILE(0xa0, 0, H, V), COL_FULL)
    Metatile("1.6_SIDE_BLOCK_LFT", TILE(0xa2, 0, H, 0), TILE(0xa1, 0, H, 0), TILE(0xa2, 0, H, V), TILE(0xa1, 0, H, V), COL_FULL)
    Metatile("1.6_SIDE_BLOCK_RGT", TILE(0xa1, 0, 0, 0), TILE(0xa2, 0, 0, 0), TILE(0xa1, 0, 0, V), TILE(0xa2, 0, 0, V), COL_FULL)

    Metatile("1.6_SIDE_TOP", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_FULL)
    Metatile("1.6_SIDE_BOT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_SIDE_LFT", TILE(0xa4, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xa4, 0, 0, 0), TILE(0xa5, 0, 0, 0), COL_FULL)
    Metatile("1.6_SIDE_RGT", TILE(0xa5, 0, H, 0), TILE(0xa4, 0, H, 0), TILE(0xa5, 0, H, 0), TILE(0xa4, 0, H, 0), COL_FULL)

    Metatile("1.6_CORNER_TL", TILE(0xa6, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa4, 0, 0, 0), TILE(0xb4, 0, 0, 0), COL_FULL) // 0xF8
    Metatile("1.6_CORNER_TR", TILE(0xa3, 0, H, 0), TILE(0xa6, 0, H, 0), TILE(0xb4, 0, H, 0), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_CORNER_BL", TILE(0xa4, 0, 0, V), TILE(0xb4, 0, 0, V), TILE(0xa6, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_CORNER_BR", TILE(0xb4, 0, H, V), TILE(0xa4, 0, H, V), TILE(0xa3, 0, H, V), TILE(0xa6, 0, H, V), COL_FULL)

    Metatile("1.6_INS_CRN_TL", TILE(0xb7, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb5, 0, 0, 0), COL_FULL)
    Metatile("1.6_INS_CRN_TR", TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, 0), TILE(0xb5, 0, H, 0), TILE(0xb3, 0, H, 0), COL_FULL)
    Metatile("1.6_INS_CRN_BL", TILE(0xb3, 0, 0, V), TILE(0xb5, 0, 0, V), TILE(0xb7, 0, 0, V), TILE(0xa5, 0, 0, V), COL_FULL)
    Metatile("1.6_INS_CRN_BR", TILE(0xb5, 0, H, V), TILE(0xb3, 0, H, V), TILE(0xa5, 0, H, V), TILE(0xb7, 0, H, V), COL_FULL)

    Metatile("1.6_SIDE_TOP_NO_OUT", TILE(0xb1, 0, 0, 0), TILE(0xb1, 0, 0, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_NONE) // 0x100
    Metatile("1.6_SIDE_BOT_NO_OUT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xb1, 0, 0, V), TILE(0xb1, 0, 0, V), COL_NONE)
    Metatile("1.6_SIDE_LFT_NO_OUT", TILE(0xb2, 0, H, 0), TILE(0xa5, 0, 0, 0), TILE(0xb2, 0, H, 0), TILE(0xa5, 0, 0, 0), COL_NONE)
    Metatile("1.6_SIDE_RGY_NO_OUT", TILE(0xa5, 0, H, 0), TILE(0xb2, 0, 0, 0), TILE(0xa5, 0, H, 0), TILE(0xb2, 0, 0, 0), COL_NONE)

    Metatile("1.6_DBL_CRN_TOP", TILE(0xa6, 0, 0, 0), TILE(0xa6, 0, H, 0), TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_DBL_CRN_BOT", TILE(0xa4, 0, 0, V), TILE(0xa4, 0, H, V), TILE(0xa6, 0, 0, V), TILE(0xa6, 0, H, V), COL_FULL)
    Metatile("1.6_DBL_CRN_LFT", TILE(0xa6, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa6, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_DBL_CRN_RGT", TILE(0xa3, 0, H, 0), TILE(0xa6, 0, H, 0), TILE(0xa3, 0, H, V), TILE(0xa6, 0, H, V), COL_FULL)

    Metatile("1.6_DBL_SIDE_V", TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), TILE(0xa4, 0, 0, 0), TILE(0xa4, 0, H, 0), COL_FULL) // 0x108
    Metatile("1.6_DBL_SIDE_H", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)

    Metatile("1.6_DBL_INS_CRN_TOP", TILE(0xb7, 0, 0, 0), TILE(0xb7, 0, H, 0), TILE(0xb3, 0, 0, 0), TILE(0xb3, 0, 0, 0), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_BOT", TILE(0xb3, 0, 0, V), TILE(0xb3, 0, 0, V), TILE(0xb7, 0, 0, V), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_LFT", TILE(0xb7, 0, 0, 0), TILE(0xa5, 0, 0, 0), TILE(0xb7, 0, 0, V), TILE(0xa5, 0, 0, 0), COL_FULL)
    Metatile("1.6_DBL_INS_CRN_RGT", TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, 0), TILE(0xa5, 0, H, 0), TILE(0xb7, 0, H, V), COL_FULL)

    Metatile("1.6_BLOCK",     TILE(0xa6, 0, 0, 0), TILE(0xa6, 0, H, 0), TILE(0xa6, 0, 0, V), TILE(0xa6, 0, H, V), COL_FULL)
    Metatile("1.6_BLOCK_ALT", TILE(0xa7, 0, 0, 0), TILE(0xa7, 0, H, 0), TILE(0xa7, 0, 0, V), TILE(0xa7, 0, H, V), COL_FULL)

    Metatile("1.6_FILLER", TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), TILE(0xa8, 0, 0, 0), COL_NONE) // 0x110

    Metatile("1.6_SID_INS_CRN_H_TL", TILE(0xb4, 0, H, V), TILE(0xb7, 0, H, 0), TILE(0xa3, 0, 0, V), TILE(0xa3, 0, 0, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_TR", TILE(0xb7, 0, 0, 0), TILE(0xb4, 0, 0, V), TILE(0xa3, 0, H, V), TILE(0xa3, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_BL", TILE(0xa3, 0, 0, 0), TILE(0xa3, 0, 0, 0), TILE(0xb4, 0, H, 0), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_H_BR", TILE(0xa3, 0, H, 0), TILE(0xa3, 0, H, 0), TILE(0xb7, 0, 0, V), TILE(0xb4, 0, 0, 0), COL_FULL)

    Metatile("1.6_SID_INS_CRN_V_TL", TILE(0xb4, 0, H, V), TILE(0xa4, 0, H, 0), TILE(0xb7, 0, 0, V), TILE(0xa4, 0, H, 0), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_TR", TILE(0xa4, 0, 0, 0), TILE(0xb4, 0, 0, V), TILE(0xa4, 0, 0, 0), TILE(0xb7, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_BL", TILE(0xb7, 0, 0, 0), TILE(0xa4, 0, H, V), TILE(0xb4, 0, H, 0), TILE(0xa4, 0, H, V), COL_FULL)
    Metatile("1.6_SID_INS_CRN_V_BR", TILE(0xa4, 0, 0, V), TILE(0xb7, 0, H, 0), TILE(0xa4, 0, 0, V), TILE(0xb4, 0, 0, 0), COL_FULL) // 0x118

    Metatile("1.6_SLAB_BLOCK_TOP", TILE(0xa9, 0, 0, 0), TILE(0xa9, 0, H, 0), TILE(0xaa, 0, 0, V), TILE(0xaa, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_BOT", TILE(0xaa, 0, 0, 0), TILE(0xaa, 0, H, 0), TILE(0xa9, 0, 0, V), TILE(0xa9, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_LFT", TILE(0xa9, 0, 0, 0), TILE(0xaa, 0, H, 0), TILE(0xa9, 0, 0, V), TILE(0xaa, 0, H, V), COL_FULL)
    Metatile("1.6_SLAB_BLOCK_RGT", TILE(0xaa, 0, 0, 0), TILE(0xa9, 0, H, 0), TILE(0xaa, 0, 0, V), TILE(0xa9, 0, H, V), COL_FULL)

    Metatile("1.6_SLAB_CRN_TL",    TILE(0xab, 0, 0, 0), TILE(0xac, 0, 0, 0), TILE(0xbb, 0, 0, 0), TILE(0xbc, 0, 0, 0), COL_FULL)
    Metatile("1.6_SLAB_CRN_TR",    TILE(0xac, 0, H, 0), TILE(0xab, 0, H, 0), TILE(0xbc, 0, H, 0), TILE(0xbb, 0, H, 0), COL_FULL)
    Metatile("1.6_SLAB_CRN_BL",    TILE(0xbb, 0, 0, V), TILE(0xbc, 0, 0, V), TILE(0xab, 0, 0, V), TILE(0xac, 0, 0, V), COL_FULL)
    Metatile("1.6_SLAB_CRN_BR",    TILE(0xbc, 0, H, V), TILE(0xbb, 0, H, V), TILE(0xac, 0, H, V), TILE(0xab, 0, H, V), COL_FULL) // 0x120

    Metatile("1.6_SLAB_SIDE_TOP", TILE(0xad, 0, 0, 0), TILE(0xad, 0, H, 0), TILE(0xbd, 0, 0, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_BOT", TILE(0xbd, 0, 0, V), TILE(0xbd, 0, H, V), TILE(0xad, 0, 0, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_LFT", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_RGT", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SIDE_H_TL", TILE(0xad, 0, 0, 0), TILE(0xae, 0, 0, 0), TILE(0xbd, 0, 0, 0), TILE(0xbe, 0, 0, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_TR", TILE(0xae, 0, H, 0), TILE(0xad, 0, H, 0), TILE(0xbe, 0, H, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_BL", TILE(0xbd, 0, 0, V), TILE(0xbe, 0, 0, V), TILE(0xad, 0, 0, V), TILE(0xae, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_H_BR", TILE(0xbe, 0, H, V), TILE(0xbd, 0, H, V), TILE(0xae, 0, H, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM) // 0x128
    Metatile("1.6_SLAB_SIDE_V_TL", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xbf, 0, H, 0), TILE(0xba, 0, H, 0), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_TR", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xba, 0, 0, 0), TILE(0xbf, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_SIDE_V_BL", TILE(0xbf, 0, H, V), TILE(0xba, 0, H, V), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_BR", TILE(0xba, 0, 0, V), TILE(0xbf, 0, 0, V), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SIDE_H_TL_ALT", TILE(0xc0, 0, 0, 0), TILE(0xc1, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd1, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_TR_ALT", TILE(0xc1, 0, 0, 0), TILE(0xc0, 0, H, 0), TILE(0xd1, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SIDE_H_BL_ALT", TILE(0xd0, 0, 0, V), TILE(0xd1, 0, H, V), TILE(0xc0, 0, 0, V), TILE(0xc1, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SIDE_H_BR_ALT", TILE(0xd1, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xc1, 0, 0, V), TILE(0xc0, 0, H, V), COL_SLAB_BOTTOM) // 0x130
    Metatile("1.6_SLAB_SIDE_V_TL_ALT", TILE(0xcb, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcd, 0, H, V), TILE(0xcc, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_TR_ALT", TILE(0xca, 0, 0, 0), TILE(0xcb, 0, 0, 0), TILE(0xcc, 0, 0, V), TILE(0xcd, 0, 0, V), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_SIDE_V_BL_ALT", TILE(0xcd, 0, H, 0), TILE(0xcc, 0, H, 0), TILE(0xcb, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SIDE_V_BR_ALT", TILE(0xcc, 0, 0, 0), TILE(0xcd, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcb, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_MED_TOP", TILE(0xc2, 0, 0, 0), TILE(0xc2, 0, H, 0), TILE(0xd2, 0, 0, 0), TILE(0xd2, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_MED_BOT", TILE(0xd2, 0, 0, V), TILE(0xd2, 0, H, V), TILE(0xc2, 0, 0, V), TILE(0xc2, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_MED_LFT", TILE(0xc7, 0, H, 0), TILE(0xc6, 0, H, 0), TILE(0xc7, 0, H, V), TILE(0xc6, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_MED_RGT", TILE(0xc6, 0, 0, 0), TILE(0xc7, 0, 0, 0), TILE(0xc6, 0, 0, V), TILE(0xc7, 0, 0, V), COL_SLAB_RIGHT) // 0x138

    Metatile("1.6_SLAB_TINY_TOP", TILE(0xb8, 0, 0, 0), TILE(0xb8, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TINY_TOP)
    Metatile("1.6_SLAB_TINY_BOT", TILE(0xd0, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xb8, 0, 0, V), TILE(0xb8, 0, H, V), COL_SLAB_TINY_BOTTOM)
    Metatile("1.6_SLAB_TINY_LFT", TILE(0xcf, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcf, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_TINY_LEFT)
    Metatile("1.6_SLAB_TINY_RGT", TILE(0xca, 0, 0, 0), TILE(0xcf, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcf, 0, 0, V), COL_SLAB_TINY_RIGHT)
    
    Metatile("1.6_SLAB_CORNER_H_TL", TILE(0xc4, 0, 0, 0), TILE(0xc5, 0, 0, 0), TILE(0xd4, 0, 0, 0), TILE(0xd5, 0, 0, 0), COL_SLAB_MED_TOP)
    Metatile("1.6_SLAB_CORNER_H_TR", TILE(0xc5, 0, H, 0), TILE(0xc4, 0, H, 0), TILE(0xd5, 0, H, 0), TILE(0xd4, 0, H, 0), COL_SLAB_MED_TOP)
    Metatile("1.6_SLAB_CORNER_H_BL", TILE(0xd4, 0, 0, V), TILE(0xd5, 0, 0, V), TILE(0xc4, 0, 0, V), TILE(0xc5, 0, 0, V), COL_SLAB_MED_BOTTOM)
    Metatile("1.6_SLAB_CORNER_H_BR", TILE(0xd5, 0, H, V), TILE(0xd4, 0, H, V), TILE(0xc5, 0, H, V), TILE(0xc4, 0, H, V), COL_SLAB_MED_BOTTOM) // 0x140
    Metatile("1.6_SLAB_CORNER_V_TL", TILE(0xd7, 0, H, 0), TILE(0xd6, 0, H, 0), TILE(0xce, 0, H, 0), TILE(0xd5, 0, 0, 0), COL_SLAB_MED_LEFT)
    Metatile("1.6_SLAB_CORNER_V_TR", TILE(0xd6, 0, 0, 0), TILE(0xd7, 0, 0, 0), TILE(0xd5, 0, H, 0), TILE(0xce, 0, 0, 0), COL_SLAB_MED_RIGHT)
    Metatile("1.6_SLAB_CORNER_V_BL", TILE(0xce, 0, H, V), TILE(0xd5, 0, 0, V), TILE(0xd7, 0, H, V), TILE(0xd6, 0, H, V), COL_SLAB_MED_LEFT)
    Metatile("1.6_SLAB_CORNER_V_BR", TILE(0xd5, 0, H, V), TILE(0xce, 0, 0, V), TILE(0xd6, 0, 0, V), TILE(0xd7, 0, 0, V), COL_SLAB_MED_RIGHT)

    Metatile("1.6_SLAB_CORNER_BIG_H_TL", TILE(0xc3, 0, H, 0), TILE(0xad, 0, H, 0), TILE(0xd3, 0, H, 0), TILE(0xbd, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_CORNER_BIG_H_TR", TILE(0xad, 0, 0, 0), TILE(0xc3, 0, 0, 0), TILE(0xbd, 0, 0, 0), TILE(0xd3, 0, 0, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_CORNER_BIG_H_BL", TILE(0xd3, 0, H, V), TILE(0xbd, 0, H, V), TILE(0xc3, 0, H, V), TILE(0xad, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_CORNER_BIG_H_BR", TILE(0xbd, 0, 0, V), TILE(0xd3, 0, 0, V), TILE(0xad, 0, 0, V), TILE(0xc3, 0, 0, V), COL_SLAB_BOTTOM) // 0x148
    Metatile("1.6_SLAB_CORNER_BIG_V_TL", TILE(0xaf, 0, H, 0), TILE(0xb9, 0, H, 0), TILE(0xc9, 0, H, 0), TILE(0xc8, 0, H, 0), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_CORNER_BIG_V_TR", TILE(0xb9, 0, 0, 0), TILE(0xaf, 0, 0, 0), TILE(0xc8, 0, 0, 0), TILE(0xc9, 0, 0, 0), COL_SLAB_RIGHT)
    Metatile("1.6_SLAB_CORNER_BIG_V_BL", TILE(0xc9, 0, H, V), TILE(0xc8, 0, H, V), TILE(0xaf, 0, H, V), TILE(0xb9, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_CORNER_BIG_V_BR", TILE(0xc8, 0, 0, V), TILE(0xc9, 0, 0, V), TILE(0xb9, 0, 0, V), TILE(0xaf, 0, 0, V), COL_SLAB_RIGHT)

    Metatile("1.6_SLAB_SINGLE_TOP", TILE(0xc0, 0, 0, 0), TILE(0xc0, 0, H, 0), TILE(0xd0, 0, 0, 0), TILE(0xd0, 0, H, 0), COL_SLAB_TOP)
    Metatile("1.6_SLAB_SINGLE_BOT", TILE(0xd0, 0, 0, V), TILE(0xd0, 0, H, V), TILE(0xc0, 0, 0, V), TILE(0xc0, 0, H, V), COL_SLAB_BOTTOM)
    Metatile("1.6_SLAB_SINGLE_LFT", TILE(0xcb, 0, H, 0), TILE(0xca, 0, H, 0), TILE(0xcb, 0, H, V), TILE(0xca, 0, H, V), COL_SLAB_LEFT)
    Metatile("1.6_SLAB_SINGLE_RGT", TILE(0xca, 0, 0, 0), TILE(0xcb, 0, 0, 0), TILE(0xca, 0, 0, V), TILE(0xcb, 0, 0, V), COL_SLAB_RIGHT) // 0x150

    Metatile("1.6_WAVE_LFT",       TILE(0xda, 2, 0, 0), TILE(0xdb, 2, 0, 0), TILE(0xea, 2, 0, 0), TILE(0xeb, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_MIDDLE",    TILE(0xdc, 2, 0, 0), TILE(0xdd, 2, 0, 0), TILE(0xeb, 2, 0, 0), TILE(0xeb, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_RGT",       TILE(0xde, 2, 0, 0), TILE(0xdf, 2, 0, 0), TILE(0xeb, 2, 0, 0), TILE(0xec, 2, 0, 0), COL_NONE)
    Metatile("1.6_WAVE_LFT_UD",    TILE(0xea, 2, 0, V), TILE(0xeb, 2, 0, V), TILE(0xda, 2, 0, V), TILE(0xdb, 2, 0, V), COL_NONE)
    Metatile("1.6_WAVE_MIDDLE_UD", TILE(0xeb, 2, 0, V), TILE(0xeb, 2, 0, V), TILE(0xdc, 2, 0, V), TILE(0xdd, 2, 0, V), COL_NONE)
    Metatile("1.6_WAVE_RGT_UD",    TILE(0xeb, 2, 0, V), TILE(0xec, 2, 0, V), TILE(0xde, 2, 0, V), TILE(0xdf, 2, 0, V), COL_NONE)

    Metatile("1.6_SPIKE_UP",            TILE(0xed, 0, 0, 0), TILE(0xed, 0, H, 0), TILE(0xfd, 0, 0, 0), TILE(0xfd, 0, H, 0), COL_SPIKE_TOP)
    Metatile("1.6_SPIKE_DOWN",          TILE(0xfd, 0, 0, V), TILE(0xfd, 0, H, V), TILE(0xed, 0, 0, V), TILE(0xed, 0, H, V), COL_SPIKE_BOTTOM) // 0x158
    Metatile("1.6_SPIKE_LEFT",          TILE(0xe7, 0, 0, 0), TILE(0xe8, 0, 0, 0), TILE(0xe7, 0, 0, V), TILE(0xe8, 0, 0, V), COL_SPIKE_LEFT)
    Metatile("1.6_SPIKE_RIGHT",         TILE(0xe8, 0, H, 0), TILE(0xe7, 0, H, 0), TILE(0xe8, 0, H, V), TILE(0xe7, 0, H, V), COL_SPIKE_RIGHT)
    Metatile("1.6_SMALL_SPIKE_BOTTOM",  TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0xef, 0, 0, 0), TILE(0xef, 0, H, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("1.6_SMALL_SPIKE_TOP",     TILE(0xef, 0, 0, V), TILE(0xef, 0, H, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("1.6_SMALL_SPIKE_LEFT",    TILE(0xe9, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0xe9, 0, 0, V), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("1.6_SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0), TILE(0xe9, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0xe9, 0, H, V), COL_SMALL_SPIKE_RIGHT)
    Metatile("1.6_MEDIUM_SPIKE_BOTTOM", TILE(0xee, 0, 0, 0), TILE(0xee, 0, H, 0), TILE(0xfe, 0, 0, 0), TILE(0xff, 0, 0, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("1.6_MEDIUM_SPIKE_TOP",    TILE(0xfe, 0, 0, V), TILE(0xff, 0, 0, V), TILE(0xee, 0, 0, V), TILE(0xee, 0, H, V), COL_MEDIUM_SPIKE_TOP) // 0x160
    Metatile("1.6_MEDIUM_SPIKE_LEFT",   TILE(0xf7, 0, 0, 0), TILE(0xf8, 0, 0, 0), TILE(0xf9, 0, 0, 0), TILE(0xf8, 0, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("1.6_MEDIUM_SPIKE_RIGHT",  TILE(0xf8, 0, H, 0), TILE(0xf7, 0, H, 0), TILE(0xf8, 0, H, V), TILE(0xf9, 0, H, 0), COL_MEDIUM_SPIKE_RIGHT)

    Metatile("FAKE_SPIKE_UP",            TILE(0xe0, 0, 0, 0),  TILE(0xe1, 0, 0, 0),  TILE(0xf0, 0, 0, 0),  TILE(0xf1, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SPIKE_DOWN",          TILE(0xf0, 0, 0, V),  TILE(0xf1, 0, 0, V),  TILE(0xe0, 0, 0, V),  TILE(0xe1, 0, 0, V),  COL_NONE)
    Metatile("FAKE_SPIKE_LEFT",          TILE(0x100, 0, 0, 0), TILE(0x101, 0, 0, 0), TILE(0x110, 0, 0, 0), TILE(0x111, 0, 0, 0), COL_NONE)
    Metatile("FAKE_SPIKE_RIGHT",         TILE(0x101, 0, H, 0), TILE(0x100, 0, H, 0), TILE(0x111, 0, H, 0), TILE(0x110, 0, H, 0), COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_BOTTOM",  TILE(0x00, 0, 0, 0),  TILE(0x00, 0, 0, 0),  TILE(0xf2, 0, 0, 0),  TILE(0xf3, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_TOP",     TILE(0xf2, 0, 0, V),  TILE(0xf3, 0, 0, V),  TILE(0x00, 0, 0, 0),  TILE(0x00, 0, 0, 0),  COL_NONE) // 0x168
    Metatile("FAKE_SMALL_SPIKE_LEFT",    TILE(0xe2, 0, 0, 0),  TILE(0x00, 0, 0, 0),  TILE(0xe3, 0, 0, 0),  TILE(0x00, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0),  TILE(0xe2, 0, H, 0),  TILE(0x00, 0, 0, 0),  TILE(0xe3, 0, H, 0),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_BOTTOM", TILE(0xe4, 0, 0, 0),  TILE(0xe4, 0, H, 0),  TILE(0xf4, 0, 0, 0),  TILE(0xf5, 0, 0, 0),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_TOP",    TILE(0xf4, 0, 0, V),  TILE(0xf5, 0, 0, V),  TILE(0xe4, 0, 0, V),  TILE(0xe4, 0, H, V),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_LEFT",   TILE(0xe6, 0, 0, 0),  TILE(0xe5, 0, 0, 0),  TILE(0xf6, 0, 0, 0),  TILE(0xe5, 0, 0, V),  COL_NONE)
    Metatile("FAKE_MEDIUM_SPIKE_RIGHT",  TILE(0xe5, 0, H, 0),  TILE(0xe6, 0, H, 0),  TILE(0xe5, 0, H, V),  TILE(0xf6, 0, H, 0),  COL_NONE)

    Metatile("1.6_EA_MIDDLE_SLAB",    TILE(0x106, 0, 0, 0), TILE(0x106, 0, H, 0), TILE(0x116, 0, 0, 0), TILE(0x116, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_MIDDLE_SLAB_UD", TILE(0x116, 0, 0, V), TILE(0x116, 0, H, V), TILE(0x106, 0, 0, V), TILE(0x106, 0, H, V), COL_EA_SLAB_TOP) // 0x170

    Metatile("1.6_EA_CORNER_BR", TILE(0x108, 0, 0, 0), TILE(0x109, 0, 0, 0), TILE(0x118, 0, 0, 0), TILE(0x119, 0, 0, 0), COL_EA_CORNER_SLAB_BOTTOM_RIGHT)
    Metatile("1.6_EA_CORNER_BL", TILE(0x109, 0, H, 0), TILE(0x108, 0, H, 0), TILE(0x119, 0, H, 0), TILE(0x118, 0, H, 0), COL_EA_CORNER_SLAB_BOTTOM_LEFT) 
    Metatile("1.6_EA_CORNER_TR", TILE(0x118, 0, 0, V), TILE(0x119, 0, 0, V), TILE(0x108, 0, 0, V), TILE(0x109, 0, 0, V), COL_EA_CORNER_SLAB_TOP_RIGHT)
    Metatile("1.6_EA_CORNER_TL", TILE(0x119, 0, H, V), TILE(0x118, 0, H, V), TILE(0x109, 0, H, V), TILE(0x108, 0, H, V), COL_EA_CORNER_SLAB_TOP_LEFT)

    Metatile("1.6_EA_INS_CRN_BR", TILE(0xfa, 0, 0, 0),  TILE(0xfb, 0, 0, 0),  TILE(0x117, 0, 0, 0), TILE(0xfc, 0, 0, 0),  COL_EA_CORNER_INSIDE_SLAB_BOTTOM_RIGHT)
    Metatile("1.6_EA_INS_CRN_BL", TILE(0xfb, 0, H, 0),  TILE(0xfa, 0, H, 0),  TILE(0xfc, 0, H, 0),  TILE(0x117, 0, H, 0), COL_EA_CORNER_INSIDE_SLAB_BOTTOM_LEFT)
    Metatile("1.6_EA_INS_CRN_TR", TILE(0x117, 0, 0, V), TILE(0xfc, 0, 0, V),  TILE(0xfa, 0, 0, V),  TILE(0xfb, 0, 0, V),  COL_EA_CORNER_INSIDE_SLAB_TOP_RIGHT)
    Metatile("1.6_EA_INS_CRN_TL", TILE(0xfc, 0, H, V),  TILE(0x117, 0, H, V), TILE(0xfb, 0, H, V),  TILE(0xfa, 0, H, V),  COL_EA_CORNER_INSIDE_SLAB_TOP_LEFT) // 0x178

    Metatile("1.6_EA_ALIGNER_BL", TILE(0x102, 0, 0, 0), TILE(0x103, 0, 0, 0), TILE(0x112, 0, 0, 0), TILE(0x113, 0, 0, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_ALIGNER_BR", TILE(0x103, 0, H, 0), TILE(0x102, 0, H, 0), TILE(0x113, 0, H, 0), TILE(0x112, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_ALIGNER_TL", TILE(0x112, 0, 0, V), TILE(0x113, 0, 0, V), TILE(0x102, 0, 0, V), TILE(0x103, 0, 0, V), COL_EA_SLAB_TOP)
    Metatile("1.6_EA_ALIGNER_TR", TILE(0x113, 0, H, V), TILE(0x112, 0, H, V), TILE(0x103, 0, H, V), TILE(0x102, 0, H, V), COL_EA_SLAB_TOP)

    Metatile("1.6_EA_SLAB",    TILE(0x107, 0, 0, 0), TILE(0x107, 0, H, 0), TILE(0x117, 0, 0, 0), TILE(0x117, 0, H, 0), COL_EA_SLAB_BOTTOM)
    Metatile("1.6_EA_SLAB_UD", TILE(0x117, 0, 0, V), TILE(0x117, 0, H, V), TILE(0x107, 0, 0, V), TILE(0x107, 0, H, V), COL_EA_SLAB_TOP)

    Metatile("1.6_EA_UNALIGNED_SLAB_V_TR", TILE(0x104, 0, 0, 0), TILE(0x105, 0, 0, 0), TILE(0x114, 0, 0, 0), TILE(0x115, 0, 0, 0), COL_EA_SLAB_RIGHT)
    Metatile("1.6_EA_UNALIGNED_SLAB_V_TL", TILE(0x105, 0, H, 0), TILE(0x104, 0, H, 0), TILE(0x115, 0, H, 0), TILE(0x114, 0, H, 0), COL_EA_SLAB_LEFT) // 0x180
    Metatile("1.6_EA_UNALIGNED_SLAB_V_BR", TILE(0x114, 0, 0, V), TILE(0x115, 0, 0, V), TILE(0x104, 0, 0, V), TILE(0x105, 0, 0, V), COL_EA_SLAB_RIGHT)
    Metatile("1.6_EA_UNALIGNED_SLAB_V_BL", TILE(0x115, 0, H, V), TILE(0x114, 0, H, V), TILE(0x105, 0, H, V), TILE(0x104, 0, H, V), COL_EA_SLAB_LEFT)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x188
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x190
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0x198
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
};