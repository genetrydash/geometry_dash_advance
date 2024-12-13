#include <tonc.h>
#include "main.h"
#include "memory.h"

// OAM buffer
OAM_SPR shadow_oam[128];

// Level buffer
EWRAM_DATA u16 level_buffer[MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];

// Current block column [0-LEVEL_BUFFER_WIDTH)
u8 curr_column;

// Current level height, in blocks
u8 curr_level_height;

// Pointer to level data for decompression
u16 *level_pointer;