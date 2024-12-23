#include <tonc.h>

typedef void (*jmp_table)();
extern const jmp_table routines_jump_table[];

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
    OBJ_COUNT
};