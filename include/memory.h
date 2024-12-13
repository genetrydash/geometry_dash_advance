#include <tonc.h>

#define MAX_LEVEL_HEIGHT 128
#define LEVEL_BUFFER_WIDTH 32

typedef OBJ_ATTR OAM_SPR;

extern OAM_SPR shadow_oam[128];
extern EWRAM_DATA u16 level_buffer[MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];

extern u8 curr_column;
extern u8 curr_level_height;
extern u16 *level_pointer;