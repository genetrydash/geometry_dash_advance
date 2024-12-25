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
    Metatile("BASIC_BLOCK",    TILE(0x0e, 0, 0, 0), TILE(0x0f, 0, 0, 0), TILE(0x10, 0, 0, 0), TILE(0x11, 0, 0, 0), COL_ALL)
    
    Metatile("CHK_FULL",       TILE(0x01, 0, 0, 0), TILE(0x01, 0, H, 0), TILE(0x01, 0, 0, V), TILE(0x01, 0, H, V), COL_ALL)
    Metatile("CHK_SIDE_UP",    TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x03, 0, 0, 0), TILE(0x03, 0, H, 0), COL_ALL)
    Metatile("CHK_SIDE_DOWN",  TILE(0x03, 0, 0, V), TILE(0x03, 0, H, V), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_ALL)
    Metatile("CHK_SIDE_LEFT",  TILE(0x04, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x04, 0, 0, V), TILE(0x05, 0, 0, V), COL_ALL)
    Metatile("CHK_SIDE_RIGHT", TILE(0x05, 0, H, 0), TILE(0x04, 0, H, 0), TILE(0x05, 0, H, V), TILE(0x04, 0, H, V), COL_ALL)
    Metatile("CHK_CORNER_TL",  TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x07, 0, 0, 0), COL_ALL)
    Metatile("CHK_CORNER_TR",  TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x07, 0, H, 0), TILE(0x04, 0, H, V), COL_ALL)
    Metatile("CHK_CORNER_BL",  TILE(0x04, 0, 0, 0), TILE(0x07, 0, 0, V), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_ALL)
    Metatile("CHK_CORNER_BR",  TILE(0x07, 0, H, V), TILE(0x04, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_ALL)
    Metatile("CHK_CRN_INS_TL", TILE(0x08, 0, 0, 0), TILE(0x05, 0, 0, 0), TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, 0), COL_ALL)
    Metatile("CHK_CRN_INS_TR", TILE(0x05, 0, H, 0), TILE(0x08, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, 0), COL_ALL)
    Metatile("CHK_CRN_INS_BL", TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, V), TILE(0x08, 0, 0, V), TILE(0x05, 0, 0, V), COL_ALL)
    Metatile("CHK_CRN_INS_BR", TILE(0x09, 0, H, V), TILE(0x03, 0, H, V), TILE(0x05, 0, H, V), TILE(0x08, 0, H, V), COL_ALL)
    Metatile("CHK_DB_CRN_TOP", TILE(0x06, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_ALL)
    Metatile("CHK_DB_CRN_BOT", TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x06, 0, H, V), COL_ALL)
    Metatile("CHK_DB_CRN_LFT", TILE(0x06, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x06, 0, 0, V), TILE(0x02, 0, H, V), COL_ALL)
    Metatile("CHK_DB_CRN_RGT", TILE(0x02, 0, 0, 0), TILE(0x06, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x06, 0, H, V), COL_ALL)
    Metatile("CHK_DB_SIDE_V",  TILE(0x04, 0, 0, 0), TILE(0x04, 0, H, 0), TILE(0x04, 0, 0, V), TILE(0x04, 0, H, V), COL_ALL)
    Metatile("CHK_DB_SIDE_H",  TILE(0x02, 0, 0, 0), TILE(0x02, 0, H, 0), TILE(0x02, 0, 0, V), TILE(0x02, 0, H, V), COL_ALL)
    Metatile("CHK_FILLER",     TILE(0x0a, 0, 0, 0), TILE(0x0a, 0, H, 0), TILE(0x0a, 0, 0, V), TILE(0x0a, 0, H, V), COL_NONE)
    
    Metatile("SPIKE_DOWN",         TILE(0x55, 0, 0, V), TILE(0x56, 0, 0, V), TILE(0x53, 0, 0, V), TILE(0x54, 0, 0, V), COL_SPIKE_BOTTOM)
    Metatile("SPIKE_RIGHT",        TILE(0x57, 0, 0, 0), TILE(0x58, 0, 0, 0), TILE(0x59, 0, 0, 0), TILE(0x5a, 0, 0, 0), COL_SPIKE_LEFT)
    Metatile("SPIKE_LEFT",         TILE(0x58, 0, H, 0), TILE(0x57, 0, H, 0), TILE(0x5a, 0, H, 0), TILE(0x59, 0, H, 0), COL_SPIKE_RIGHT)
    Metatile("SMALL_SPIKE_BOTTOM", TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5b, 0, 0, 0), TILE(0x5c, 0, 0, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("SMALL_SPIKE_TOP",    TILE(0x5b, 0, 0, V), TILE(0x5c, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("SMALL_SPIKE_LEFT",  TILE(0x5d, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("SMALL_SPIKE_RIGHT",   TILE(0x00, 0, 0, 0), TILE(0x5d, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x5e, 0, H, 0), COL_SMALL_SPIKE_RIGHT)
    Metatile("GROUND_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x5f, 0, 0, 0), TILE(0x60, 0, 0, 0), COL_SMALL_SPIKE_BOTTOM)
    Metatile("GROUND_SPIKE_TOP",   TILE(0x5f, 0, 0, V), TILE(0x60, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("GROUND_SPIKE_LEFT", TILE(0x61, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("GROUND_SPIKE_RIGHT",  TILE(0x00, 0, 0, 0), TILE(0x61, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x62, 0, H, 0), COL_SMALL_SPIKE_RIGHT)
    Metatile("MEDIUM_SPIKE_BOTTOM",TILE(0x63, 0, 0, 0), TILE(0x63, 0, H, 0), TILE(0x64, 0, 0, 0), TILE(0x65, 0, 0, 0), COL_MEDIUM_SPIKE_BOTTOM)
    Metatile("MEDIUM_SPIKE_TOP",   TILE(0x64, 0, 0, V), TILE(0x65, 0, 0, V), TILE(0x63, 0, 0, V), TILE(0x63, 0, H, V), COL_MEDIUM_SPIKE_TOP)
    Metatile("MEDIUM_SPIKE_LEFT", TILE(0x67, 0, 0, 0), TILE(0x66, 0, 0, 0), TILE(0x68, 0, 0, 0), TILE(0x66, 0, 0, V), COL_MEDIUM_SPIKE_LEFT)
    Metatile("MEDIUM_SPIKE_RIGHT",  TILE(0x66, 0, H, 0), TILE(0x67, 0, H, 0), TILE(0x66, 0, H, V), TILE(0x68, 0, H, 0), COL_MEDIUM_SPIKE_RIGHT)
    
    Metatile("CHK_CORNER_TL", TILE(0x0B, 0, 0, 0), TILE(0x05, 0, H, 0), TILE(0x03, 0, 0, V), TILE(0x09, 0, 0, 0), COL_NONE)
    Metatile("CHK_CORNER_TR", TILE(0x05, 0, 0, 0), TILE(0x0B, 0, H, 0), TILE(0x09, 0, H, 0), TILE(0x03, 0, H, V), COL_NONE)
    Metatile("CHK_CORNER_BL", TILE(0x03, 0, 0, 0), TILE(0x09, 0, 0, V), TILE(0x0B, 0, 0, V), TILE(0x05, 0, H, V), COL_NONE)
    Metatile("CHK_CORNER_BR", TILE(0x09, 0, H, V), TILE(0x04, 0, H, 0), TILE(0x05, 0, 0, V), TILE(0x0B, 0, H, V), COL_NONE)
    
    Metatile("BASIC_BLOCK_DARK", TILE(0x26, 0, 0, 0), TILE(0x27, 0, 0, 0), TILE(0x28, 0, 0, 0), TILE(0x29, 0, 0, 0), COL_ALL)
    
    Metatile("SLAB_UP",            TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SLAB_TOP)
    Metatile("SLAB_DOWN",          TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, V), TILE(0x4f, 0, 0, V), COL_SLAB_BOTTOM)
    Metatile("SLAB_LEFT",          TILE(0x50, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("SLAB_RIGHT",         TILE(0x00, 0, 0, 0), TILE(0x50, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x51, 0, H, 0), COL_NONE)
    Metatile("SLAB_DOWN_FLIPPED",  TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x4e, 0, 0, 0), TILE(0x4f, 0, 0, 0), COL_SLAB_BOTTOM)

    Metatile("GROUND_WAVY_SPIKE_BOTTOM",TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x6f, 0, 0, 0), TILE(0x6f, 0, 0, 0), COL_SMALL_SPIKE_BOTTOM) // 0x30
    Metatile("GROUND_WAVY_SPIKE_TOP",   TILE(0x6f, 0, 0, V), TILE(0x6f, 0, 0, V), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_TOP)
    Metatile("GROUND_WAVY_SPIKE_LEFT",  TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_SMALL_SPIKE_LEFT)
    Metatile("GROUND_WAVY_SPIKE_RIGHT", TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), TILE(0x00, 0, 0, 0), TILE(0x76, 0, H, 0), COL_SMALL_SPIKE_RIGHT)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE) // 0x38
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), TILE(0x00, 0, 0, 0), COL_NONE)

    Metatile("X_FULL",       TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_ALL) // 0x40
    Metatile("X_SIDE_UP",    TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_SIDE_DOWN",  TILE(0x19, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x17, 0, 0, V), TILE(0x18, 0, 0, V), COL_ALL)
    Metatile("X_SIDE_LEFT",  TILE(0x1b, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_SIDE_RIGHT", TILE(0x1c, 0, H, 0), TILE(0x1b, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_ALL)
    Metatile("X_CORNER_TL",  TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_CORNER_TR",  TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x1a, 0, H, 0), TILE(0x1d, 0, H, 0), COL_ALL)
    Metatile("X_CORNER_BL",  TILE(0x1d, 0, 0, V), TILE(0x1a, 0, 0, V), TILE(0x13, 0, 0, V), TILE(0x18, 0, 0, V), COL_ALL)
    Metatile("X_CORNER_BR",  TILE(0x1a, 0, H, V), TILE(0x1d, 0, H, V), TILE(0x18, 0, H, V), TILE(0x13, 0, H, V), COL_ALL) // 0x48
    Metatile("X_INS_CRN_TL", TILE(0x1e, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_INS_CRN_TR", TILE(0x22, 0, 0, 0), TILE(0x1f, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_INS_CRN_BL", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x20, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_ALL)
    Metatile("X_INS_CRN_BR", TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x21, 0, 0, 0), COL_ALL)
    Metatile("X_FILLER",     TILE(0x22, 0, 0, 0), TILE(0x1c, 0, 0, 0), TILE(0x19, 0, 0, 0), TILE(0x1a, 0, 0, 0), COL_NONE)
    Metatile("X_DB_CRN_TOP", TILE(0x13, 0, 0, 0), TILE(0x14, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_ALL)
    Metatile("X_DB_CRN_BOT", TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x16, 0, 0, 0), COL_ALL)
        
    Metatile("X_DB_CRN_LFT", TILE(0x13, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x15, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_ALL) // 0x50
    Metatile("X_DB_CRN_RGT", TILE(0x18, 0, H, 0), TILE(0x13, 0, H, 0), TILE(0x24, 0, H, 0), TILE(0x15, 0, H, 0), COL_ALL)
    Metatile("X_DB_SIDE_V",  TILE(0x1b, 0, 0, 0), TILE(0x25, 0, 0, 0), TILE(0x1d, 0, 0, 0), TILE(0x23, 0, 0, 0), COL_ALL)
    Metatile("X_DB_SIDE_H",  TILE(0x17, 0, 0, 0), TILE(0x18, 0, 0, 0), TILE(0x12, 0, 0, 0), TILE(0x24, 0, 0, 0), COL_ALL)
    
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

    Metatile("+_FULL",       TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x2c, 0, 0, 0), TILE(0x2d, 0, 0, 0), COL_ALL) // 0x60
    Metatile("+_SIDE_UP",    TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_ALL)
    Metatile("+_SIDE_DOWN",  TILE(0x30, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2e, 0, 0, V), TILE(0x2f, 0, 0, V), COL_ALL)
    Metatile("+_SIDE_LEFT",  TILE(0x32, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_ALL)
    Metatile("+_SIDE_RIGHT", TILE(0x33, 0, H, 0), TILE(0x32, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_ALL)
    Metatile("+_CORNER_TL",  TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_ALL)
    Metatile("+_CORNER_TR",  TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_ALL)
    Metatile("+_CORNER_BL",  TILE(0x34, 0, 0, V), TILE(0x31, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2f, 0, 0, V), COL_ALL)
    Metatile("+_CORNER_BR",  TILE(0x31, 0, H, V), TILE(0x34, 0, H, V), TILE(0x2f, 0, H, V), TILE(0x2a, 0, H, V), COL_ALL) // 0x68
    Metatile("+_FILLER",     TILE(0x35, 0, 0, 0), TILE(0x33, 0, 0, 0), TILE(0x30, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_NONE)
    Metatile("+_DB_CRN_TOP", TILE(0x2a, 0, 0, 0), TILE(0x2b, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_ALL)
    Metatile("+_DB_CRN_BOT", TILE(0x34, 0, 0, V), TILE(0x36, 0, 0, V), TILE(0x2a, 0, 0, V), TILE(0x2b, 0, 0, V), COL_ALL)
    Metatile("+_DB_CRN_LFT", TILE(0x2a, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x31, 0, 0, 0), COL_ALL)
    Metatile("+_DB_CRN_RGT", TILE(0x2f, 0, H, 0), TILE(0x2a, 0, H, 0), TILE(0x31, 0, H, 0), TILE(0x34, 0, H, 0), COL_ALL)
    Metatile("+_DB_SIDE_V",  TILE(0x32, 0, 0, 0), TILE(0x38, 0, 0, 0), TILE(0x34, 0, 0, 0), TILE(0x36, 0, 0, 0), COL_ALL)
    Metatile("+_DB_SIDE_H",  TILE(0x2e, 0, 0, 0), TILE(0x2f, 0, 0, 0), TILE(0x39, 0, 0, 0), TILE(0x37, 0, 0, 0), COL_ALL)
    
    Metatile("BLK_FULL",        TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_ALL) // 0x70
    Metatile("BLK_SIDE_TOP",    TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_SIDE_BOTTOM", TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_ALL)
    Metatile("BLK_SIDE_LEFT",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_SIDE_RIGHT",  TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_ALL)
    Metatile("BLK_CORNER_TL",   TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_CORNER_TR",   TILE(0x3c, 0, H, 0), TILE(0x3b, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_ALL)
    Metatile("BLK_CORNER_BL",   TILE(0x3d, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_ALL)
    Metatile("BLK_CORNER_BR",   TILE(0x3a, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_ALL) // 0x78
    Metatile("BLK_INS_CRN_TL",  TILE(0x3e, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_INS_CRN_TR",  TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, H, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_INS_CRN_BL",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, 0, V), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_INS_CRN_BR",  TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3e, 0, V, H), COL_ALL)
    Metatile("BLK_FILLER",      TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), TILE(0x3a, 0, 0, 0), COL_ALL)
    Metatile("BLK_DB_CRN_TOP",  TILE(0x3b, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_ALL)
    Metatile("BLK_DB_CRN_BOT",  TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3b, 0, 0, V), TILE(0x3b, 0, H, V), COL_ALL)

    Metatile("BLK_DB_CRN_LFT",  TILE(0x3b, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, 0, V), TILE(0x3c, 0, 0, V), COL_ALL) // 0x80
    Metatile("BLK_DB_CRN_RGT",  TILE(0x3c, 0, 0, 0), TILE(0x3b, 0, H, 0), TILE(0x3c, 0, 0, V), TILE(0x3b, 0, H, V), COL_ALL)
    Metatile("BLK_DB_SIDE_H",   TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), TILE(0x3d, 0, 0, 0), TILE(0x3d, 0, H, 0), COL_ALL)
    Metatile("BLK_DB_SIDE_V",   TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, 0), TILE(0x3c, 0, 0, V), TILE(0x3c, 0, 0, V), COL_ALL)

    Metatile("EMPTY",    TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
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

    
    
    Metatile("BRICKS_FULL",        TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x41, 0, 0, 0), COL_ALL) // 0x90
    Metatile("BRICKS_SIDE_TOP",    TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_SIDE_BOTTOM", TILE(0x43, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x42, 0, 0, V), TILE(0x42, 0, H, V), COL_ALL)
    Metatile("BRICKS_SIDE_LEFT",   TILE(0x45, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_SIDE_RIGHT",  TILE(0x46, 0, H, 0), TILE(0x45, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_ALL)
    Metatile("BRICKS_CORNER_TL",   TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_CORNER_TR",   TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x44, 0, H, 0), TILE(0x47, 0, H, 0), COL_ALL)
    Metatile("BRICKS_CORNER_BL",   TILE(0x47, 0, 0, V), TILE(0x44, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x42, 0, H, V), COL_ALL)
    Metatile("BRICKS_CORNER_BR",   TILE(0x44, 0, H, V), TILE(0x47, 0, H, V), TILE(0x42, 0, 0, V), TILE(0x3f, 0, H, V), COL_ALL) // 0x98
    Metatile("BRICKS_INS_CRN_TL",  TILE(0x48, 0, 0, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_INS_CRN_TR",  TILE(0x46, 0, H, 0), TILE(0x48, 0, H, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_INS_CRN_BL",  TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x49, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_INS_CRN_BR",  TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x4a, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_FILLER",      TILE(0x46, 0, H, 0), TILE(0x46, 0, 0, 0), TILE(0x43, 0, 0, 0), TILE(0x44, 0, 0, 0), COL_NONE)
    Metatile("BRICKS_DB_CRN_TOP",  TILE(0x3f, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x47, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_DB_CRN_BOT",  TILE(0x47, 0, 0, V), TILE(0x4b, 0, 0, V), TILE(0x3f, 0, 0, V), TILE(0x3f, 0, H, V), COL_ALL)

    Metatile("BRICKS_DB_CRN_LFT",  TILE(0x3f, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x40, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_ALL) // 0xA0
    Metatile("BRICKS_DB_CRN_RGT",  TILE(0x42, 0, 0, 0), TILE(0x3f, 0, H, 0), TILE(0x4c, 0, H, 0), TILE(0x40, 0, H, 0), COL_ALL)
    Metatile("BRICKS_SIDE_H",      TILE(0x45, 0, 0, 0), TILE(0x45, 0, H, 0), TILE(0x45, 0, 0, 0), TILE(0x4b, 0, 0, 0), COL_ALL)
    Metatile("BRICKS_SIDE_V",      TILE(0x42, 0, 0, 0), TILE(0x42, 0, H, 0), TILE(0x4d, 0, 0, 0), TILE(0x4c, 0, 0, 0), COL_ALL)

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

    
    
    Metatile("GROUND_1",    TILE(0x180, 4, 0, 0), TILE(0x181, 4, 0, 0), TILE(0x190, 4, 0, 0), TILE(0x191, 4, 0, 0), COL_ALL) // 0xB0
    Metatile("GROUND_2",    TILE(0x181, 4, 0, 0), TILE(0x181, 4, 0, 0), TILE(0x191, 4, 0, 0), TILE(0x191, 4, 0, 0), COL_ALL)
    Metatile("GROUND_3",    TILE(0x181, 4, 0, 0), TILE(0x182, 4, 0, 0), TILE(0x191, 4, 0, 0), TILE(0x192, 4, 0, 0), COL_ALL)
    Metatile("CEILING_1",   TILE(0x1f0, 4, 0, V), TILE(0x1f1, 4, 0, V), TILE(0x1e0, 4, 0, V), TILE(0x1e1, 4, 0, V), COL_ALL)
    Metatile("CEILING_2",   TILE(0x1f1, 4, 0, V), TILE(0x1f1, 4, 0, V), TILE(0x1e1, 4, 0, V), TILE(0x1e1, 4, 0, V), COL_ALL)
    Metatile("CEILING_3",   TILE(0x1f1, 4, 0, V), TILE(0x1f2, 4, 0, V), TILE(0x1e1, 4, 0, V), TILE(0x1e2, 4, 0, V), COL_ALL)

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

    Metatile("GROUND_4",    TILE(0x1a0, 4, 0, 0), TILE(0x1a1, 4, 0, 0), TILE(0x1b0, 4, 0, 0), TILE(0x1b1, 4, 0, 0), COL_ALL) // 0xC0
    Metatile("GROUND_5",    TILE(0x1a1, 4, 0, 0), TILE(0x1a1, 4, 0, 0), TILE(0x1b1, 4, 0, 0), TILE(0x1b1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_6",    TILE(0x1a1, 4, 0, 0), TILE(0x1a2, 4, 0, 0), TILE(0x1b1, 4, 0, 0), TILE(0x1b2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_4",   TILE(0x1d0, 4, 0, V), TILE(0x1d1, 4, 0, V), TILE(0x1c0, 4, 0, V), TILE(0x1c1, 4, 0, V), COL_ALL)
    Metatile("CEILING_5",   TILE(0x1d1, 4, 0, V), TILE(0x1d1, 4, 0, V), TILE(0x1c1, 4, 0, V), TILE(0x1c1, 4, 0, V), COL_ALL)
    Metatile("CEILING_6",   TILE(0x1d1, 4, 0, V), TILE(0x1d2, 4, 0, V), TILE(0x1c1, 4, 0, V), TILE(0x1c2, 4, 0, V), COL_ALL)

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

    Metatile("GROUND_7",    TILE(0x1c0, 4, 0, 0), TILE(0x1c1, 4, 0, 0), TILE(0x1d0, 4, 0, 0), TILE(0x1d1, 4, 0, 0), COL_ALL) // 0xD0
    Metatile("GROUND_8",    TILE(0x1c1, 4, 0, 0), TILE(0x1c1, 4, 0, 0), TILE(0x1d1, 4, 0, 0), TILE(0x1d1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_9",    TILE(0x1c1, 4, 0, 0), TILE(0x1c2, 4, 0, 0), TILE(0x1d1, 4, 0, 0), TILE(0x1d2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_7",   TILE(0x1b0, 4, 0, V), TILE(0x1b1, 4, 0, V), TILE(0x1a0, 4, 0, V), TILE(0x1a1, 4, 0, V), COL_ALL)
    Metatile("CEILING_8",   TILE(0x1b1, 4, 0, V), TILE(0x1b1, 4, 0, V), TILE(0x1a1, 4, 0, V), TILE(0x1a1, 4, 0, V), COL_ALL)
    Metatile("CEILING_9",   TILE(0x1b1, 4, 0, V), TILE(0x1b2, 4, 0, V), TILE(0x1a1, 4, 0, V), TILE(0x1a2, 4, 0, V), COL_ALL)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0xD8
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
   
    Metatile("GROUND_A",    TILE(0x1e0, 4, 0, 0), TILE(0x1e1, 4, 0, 0), TILE(0x1f0, 4, 0, 0), TILE(0x1f1, 4, 0, 0), COL_ALL) // 0xE0
    Metatile("GROUND_B",    TILE(0x1e1, 4, 0, 0), TILE(0x1e1, 4, 0, 0), TILE(0x1f1, 4, 0, 0), TILE(0x1f1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_C",    TILE(0x1e1, 4, 0, 0), TILE(0x1e2, 4, 0, 0), TILE(0x1f1, 4, 0, 0), TILE(0x1f2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_A",   TILE(0x190, 4, 0, V), TILE(0x191, 4, 0, V), TILE(0x180, 4, 0, V), TILE(0x181, 4, 0, V), COL_ALL)
    Metatile("CEILING_B",   TILE(0x191, 4, 0, V), TILE(0x191, 4, 0, V), TILE(0x181, 4, 0, V), TILE(0x181, 4, 0, V), COL_ALL)
    Metatile("CEILING_C",   TILE(0x191, 4, 0, V), TILE(0x192, 4, 0, V), TILE(0x181, 4, 0, V), TILE(0x182, 4, 0, V), COL_ALL)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE) // 0xE8
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), TILE(0, 0, 0, 0), COL_NONE)
};