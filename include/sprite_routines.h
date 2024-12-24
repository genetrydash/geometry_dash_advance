#include <tonc.h>

#pragma once

typedef void (*jmp_table)();
extern const jmp_table routines_jump_table[];
extern const s16 obj_hitbox[][6];

enum ObjTypes {
    NONE,

    SHIP_PORTAL,
    CUBE_PORTAL,

    COL_TRIGGER,
    BIG_BG_SPIKES,
    MEDIUM_BG_SPIKES,
    SMALL_BG_SPIKES,
    TINY_BG_SPIKES,
    BG_CHAINS,

    YELLOW_ORB,
    YELLOW_PAD,

    MEDIUM_PULSING_CIRCLE,
    SMALL_PULSING_CIRCLE,
    LARGE_PULSING_CIRCLE,
    
    BLUE_GRAVITY_PORTAL,
    YELLOW_GRAVITY_PORTAL,
    OBJ_COUNT
};


enum ColorChannels {
    COL1,
    COL2,
    COL3,
    COL4,
    BG,
    GROUND,
    OBJ,
    LINE,
    CHANNEL_COUNT,
    P1 = CHANNEL_COUNT,
    P2,
    TOTAL_CHANNEL_COUNT  
};
