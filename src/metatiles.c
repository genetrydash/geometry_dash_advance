#include "metatiles.h"
#include "collision.h"

#define Metatile(name, tl, tr, bl, br, col) {tl, tr, bl, br, col},

#define H_FLIP 1
#define V_FLIP 1

// Goes like this TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, COL_TYPE
const SCR_ENTRY metatiles[][5] = {
    Metatile("AIR",            SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_UP",       SE_BUILD(0x53, 0, 0, 0), SE_BUILD(0x54, 0, 0, 0), SE_BUILD(0x55, 0, 0, 0), SE_BUILD(0x56, 0, 0, 0), COL_DEATH)
    Metatile("BASIC_BLOCK",    SE_BUILD(0x0e, 0, 0, 0), SE_BUILD(0x0f, 0, 0, 0), SE_BUILD(0x10, 0, 0, 0), SE_BUILD(0x11, 0, 0, 0), COL_ALL)
    
    Metatile("CHK_FULL",       SE_BUILD(0x01, 0, 0, 0),           SE_BUILD(0x01, 0, H_FLIP, 0),      SE_BUILD(0x01, 0, 0, V_FLIP),      SE_BUILD(0x01, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_SIDE_UP",    SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x03, 0, 0, 0),           SE_BUILD(0x03, 0, H_FLIP, 0),      COL_ALL)
    Metatile("CHK_SIDE_DOWN",  SE_BUILD(0x03, 0, 0, V_FLIP),      SE_BUILD(0x03, 0, H_FLIP, V_FLIP), SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_SIDE_LEFT",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x05, 0, 0, 0),           SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x05, 0, 0, V_FLIP),      COL_ALL)
    Metatile("CHK_SIDE_RIGHT", SE_BUILD(0x05, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x05, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_TL",  SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x07, 0, 0, 0),           COL_ALL)
    Metatile("CHK_CORNER_TR",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x07, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_BL",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x07, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_BR",  SE_BUILD(0x07, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CRN_INS_TL", SE_BUILD(0x08, 0, 0, 0),           SE_BUILD(0x05, 0, 0, 0),           SE_BUILD(0x03, 0, 0, 0),           SE_BUILD(0x09, 0, 0, 0),           COL_ALL)
    Metatile("CHK_CRN_INS_TR", SE_BUILD(0x05, 0, H_FLIP, 0),      SE_BUILD(0x08, 0, H_FLIP, 0),      SE_BUILD(0x09, 0, H_FLIP, 0),      SE_BUILD(0x03, 0, H_FLIP, 0),      COL_ALL)
    Metatile("CHK_CRN_INS_BL", SE_BUILD(0x03, 0, 0, V_FLIP),      SE_BUILD(0x09, 0, 0, V_FLIP),      SE_BUILD(0x08, 0, 0, V_FLIP),      SE_BUILD(0x05, 0, 0, V_FLIP),      COL_ALL)
    Metatile("CHK_CRN_INS_BR", SE_BUILD(0x09, 0, H_FLIP, V_FLIP), SE_BUILD(0x03, 0, H_FLIP, V_FLIP), SE_BUILD(0x05, 0, H_FLIP, V_FLIP), SE_BUILD(0x08, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_TOP", SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_BOT", SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_LFT", SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_RGT", SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_SIDE_V",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_SIDE_H",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_FILLER",     SE_BUILD(0x0a, 0, 0, 0),           SE_BUILD(0x0a, 0, H_FLIP, 0),      SE_BUILD(0x0a, 0, 0, V_FLIP),      SE_BUILD(0x0a, 0, H_FLIP, V_FLIP), COL_NONE)
    
    Metatile("SPIKE_DOWN",         SE_BUILD(0x55, 0, 0, V_FLIP), SE_BUILD(0x56, 0, 0, V_FLIP), SE_BUILD(0x53, 0, 0, V_FLIP), SE_BUILD(0x54, 0, 0, V_FLIP), COL_NONE)
    Metatile("SPIKE_RIGHT",        SE_BUILD(0x57, 0, 0, 0),      SE_BUILD(0x58, 0, 0, 0),      SE_BUILD(0x59, 0, 0, 0),      SE_BUILD(0x5a, 0, 0, 0),      COL_NONE)
    Metatile("SPIKE_LEFT",         SE_BUILD(0x58, 0, H_FLIP, 0), SE_BUILD(0x57, 0, H_FLIP, 0), SE_BUILD(0x5a, 0, H_FLIP, 0), SE_BUILD(0x59, 0, H_FLIP, 0), COL_NONE)
    Metatile("SMALL_SPIKE_UP",     SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x5b, 0, 0, 0),      SE_BUILD(0x5c, 0, 0, 0),      COL_NONE)
    Metatile("SMALL_SPIKE_DOWN",   SE_BUILD(0x5b, 0, 0, V_FLIP), SE_BUILD(0x5c, 0, 0, V_FLIP), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("SMALL_SPIKE_RIGHT",  SE_BUILD(0x5d, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x5e, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("SMALL_SPIKE_LEFT",   SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x5d, 0, H_FLIP, 0), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x5e, 0, H_FLIP, 0), COL_NONE)
    Metatile("GROUND_SPIKE_UP",    SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x5f, 0, 0, 0),      SE_BUILD(0x60, 0, 0, 0),      COL_NONE)
    Metatile("GROUND_SPIKE_DOWN",  SE_BUILD(0x5f, 0, 0, V_FLIP), SE_BUILD(0x60, 0, 0, V_FLIP), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("GROUND_SPIKE_RIGHT", SE_BUILD(0x61, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x62, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("GROUND_SPIKE_LEFT",  SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x61, 0, H_FLIP, 0), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x62, 0, H_FLIP, 0), COL_NONE)
    Metatile("MEDIUM_SPIKE_UP",    SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("MEDIUM_SPIKE_DOWN",  SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("MEDIUM_SPIKE_RIGHT", SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("MEDIUM_SPIKE_LEFT",  SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    
    Metatile("CHK_CORNER_TL",  SE_BUILD(0x0B, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0), SE_BUILD(0x04, 0, 0, V_FLIP), SE_BUILD(0x07, 0, 0, 0),           COL_NONE)
    Metatile("CHK_CORNER_TR",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x0B, 0, H_FLIP, 0), SE_BUILD(0x07, 0, H_FLIP, 0), SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_NONE)
    Metatile("CHK_CORNER_BL",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x07, 0, 0, V_FLIP), SE_BUILD(0x0B, 0, 0, V_FLIP), SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_NONE)
    Metatile("CHK_CORNER_BR",  SE_BUILD(0x07, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, 0), SE_BUILD(0x02, 0, 0, V_FLIP), SE_BUILD(0x0B, 0, H_FLIP, V_FLIP), COL_NONE)
    
    Metatile("BASIC_BLOCK_DARK",    SE_BUILD(0x26, 0, 0, 0), SE_BUILD(0x27, 0, 0, 0), SE_BUILD(0x28, 0, 0, 0), SE_BUILD(0x29, 0, 0, 0), COL_ALL)
    
    Metatile("SLAB_UP",    SE_BUILD(0x4e, 0, 0, 0), SE_BUILD(0x4f, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_SLAB_TOP)
    Metatile("SLAB_DOWN",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x4e, 0, 0, V_FLIP), SE_BUILD(0x4f, 0, 0, V_FLIP), COL_SLAB_BOTTOM)
    Metatile("SLAB_LEFT",  SE_BUILD(0x50, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x51, 0, 0, 0),      SE_BUILD(0x00, 0, 0, 0),      COL_NONE)
    Metatile("SLAB_RIGHT", SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x50, 0, H_FLIP, 0), SE_BUILD(0x00, 0, 0, 0),      SE_BUILD(0x51, 0, H_FLIP, 0), COL_NONE)

    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)


    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x30
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x38
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x40
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x48
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x50
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x58
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x60
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x68
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x70
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x78
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x80
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x88
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x90
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0x98
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xA0
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xA8
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",    SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    
    
    Metatile("GROUND_1",    SE_BUILD(0x180, 4, 0, 0), SE_BUILD(0x181, 4, 0, 0), SE_BUILD(0x190, 4, 0, 0), SE_BUILD(0x191, 4, 0, 0), COL_ALL) // 0xB0
    Metatile("GROUND_2",    SE_BUILD(0x181, 4, 0, 0), SE_BUILD(0x181, 4, 0, 0), SE_BUILD(0x191, 4, 0, 0), SE_BUILD(0x191, 4, 0, 0), COL_ALL)
    Metatile("GROUND_3",    SE_BUILD(0x181, 4, 0, 0), SE_BUILD(0x182, 4, 0, 0), SE_BUILD(0x191, 4, 0, 0), SE_BUILD(0x192, 4, 0, 0), COL_ALL)
    Metatile("CEILING_1",   SE_BUILD(0x1f0, 4, 0, V_FLIP), SE_BUILD(0x1f1, 4, 0, V_FLIP), SE_BUILD(0x1e0, 4, 0, V_FLIP), SE_BUILD(0x1e1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_2",   SE_BUILD(0x1f1, 4, 0, V_FLIP), SE_BUILD(0x1f1, 4, 0, V_FLIP), SE_BUILD(0x1e1, 4, 0, V_FLIP), SE_BUILD(0x1e1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_3",   SE_BUILD(0x1f1, 4, 0, V_FLIP), SE_BUILD(0x1f2, 4, 0, V_FLIP), SE_BUILD(0x1e1, 4, 0, V_FLIP), SE_BUILD(0x1e2, 4, 0, V_FLIP), COL_ALL)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xB8
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_4",    SE_BUILD(0x1a0, 4, 0, 0), SE_BUILD(0x1a1, 4, 0, 0), SE_BUILD(0x1b0, 4, 0, 0), SE_BUILD(0x1b1, 4, 0, 0), COL_ALL) // 0xC0
    Metatile("GROUND_5",    SE_BUILD(0x1a1, 4, 0, 0), SE_BUILD(0x1a1, 4, 0, 0), SE_BUILD(0x1b1, 4, 0, 0), SE_BUILD(0x1b1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_6",    SE_BUILD(0x1a1, 4, 0, 0), SE_BUILD(0x1a2, 4, 0, 0), SE_BUILD(0x1b1, 4, 0, 0), SE_BUILD(0x1b2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_4",   SE_BUILD(0x1d0, 4, 0, V_FLIP), SE_BUILD(0x1d1, 4, 0, V_FLIP), SE_BUILD(0x1c0, 4, 0, V_FLIP), SE_BUILD(0x1c1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_5",   SE_BUILD(0x1d1, 4, 0, V_FLIP), SE_BUILD(0x1d1, 4, 0, V_FLIP), SE_BUILD(0x1c1, 4, 0, V_FLIP), SE_BUILD(0x1c1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_6",   SE_BUILD(0x1d1, 4, 0, V_FLIP), SE_BUILD(0x1d2, 4, 0, V_FLIP), SE_BUILD(0x1c1, 4, 0, V_FLIP), SE_BUILD(0x1c2, 4, 0, V_FLIP), COL_ALL)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xC8
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)

    Metatile("GROUND_7",    SE_BUILD(0x1c0, 4, 0, 0), SE_BUILD(0x1c1, 4, 0, 0), SE_BUILD(0x1d0, 4, 0, 0), SE_BUILD(0x1d1, 4, 0, 0), COL_ALL) // 0xD0
    Metatile("GROUND_8",    SE_BUILD(0x1c1, 4, 0, 0), SE_BUILD(0x1c1, 4, 0, 0), SE_BUILD(0x1d1, 4, 0, 0), SE_BUILD(0x1d1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_9",    SE_BUILD(0x1c1, 4, 0, 0), SE_BUILD(0x1c2, 4, 0, 0), SE_BUILD(0x1d1, 4, 0, 0), SE_BUILD(0x1d2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_7",   SE_BUILD(0x1b0, 4, 0, V_FLIP), SE_BUILD(0x1b1, 4, 0, V_FLIP), SE_BUILD(0x1a0, 4, 0, V_FLIP), SE_BUILD(0x1a1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_8",   SE_BUILD(0x1b1, 4, 0, V_FLIP), SE_BUILD(0x1b1, 4, 0, V_FLIP), SE_BUILD(0x1a1, 4, 0, V_FLIP), SE_BUILD(0x1a1, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_9",   SE_BUILD(0x1b1, 4, 0, V_FLIP), SE_BUILD(0x1b2, 4, 0, V_FLIP), SE_BUILD(0x1a1, 4, 0, V_FLIP), SE_BUILD(0x1a2, 4, 0, V_FLIP), COL_ALL)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xD8
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
   
    Metatile("GROUND_A",    SE_BUILD(0x1e0, 4, 0, 0), SE_BUILD(0x1e1, 4, 0, 0), SE_BUILD(0x1f0, 4, 0, 0), SE_BUILD(0x1f1, 4, 0, 0), COL_ALL) // 0xE0
    Metatile("GROUND_B",    SE_BUILD(0x1e1, 4, 0, 0), SE_BUILD(0x1e1, 4, 0, 0), SE_BUILD(0x1f1, 4, 0, 0), SE_BUILD(0x1f1, 4, 0, 0), COL_ALL)
    Metatile("GROUND_C",    SE_BUILD(0x1e1, 4, 0, 0), SE_BUILD(0x1e2, 4, 0, 0), SE_BUILD(0x1f1, 4, 0, 0), SE_BUILD(0x1f2, 4, 0, 0), COL_ALL)
    Metatile("CEILING_A",   SE_BUILD(0x190, 4, 0, V_FLIP), SE_BUILD(0x191, 4, 0, V_FLIP), SE_BUILD(0x180, 4, 0, V_FLIP), SE_BUILD(0x181, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_B",   SE_BUILD(0x191, 4, 0, V_FLIP), SE_BUILD(0x191, 4, 0, V_FLIP), SE_BUILD(0x181, 4, 0, V_FLIP), SE_BUILD(0x181, 4, 0, V_FLIP), COL_ALL)
    Metatile("CEILING_C",   SE_BUILD(0x191, 4, 0, V_FLIP), SE_BUILD(0x192, 4, 0, V_FLIP), SE_BUILD(0x181, 4, 0, V_FLIP), SE_BUILD(0x182, 4, 0, V_FLIP), COL_ALL)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE) // 0xE8
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    Metatile("EMPTY",       SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), SE_BUILD(0, 0, 0, 0), COL_NONE)
    
};