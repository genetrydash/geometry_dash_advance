#include <tonc.h>
#include "main.h"
#include "memory.h"

OAM_SPR shadow_oam[128];
EWRAM_DATA u16 level_buffer[MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];

u8 curr_column;
u8 curr_level_height;
u16 *level_pointer;