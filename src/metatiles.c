#include "metatiles.h"
#include "collision.h"

#define Metatile(name, tl, tr, bl, br, col) {tl, tr, bl, br, col},

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

    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
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

    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
};