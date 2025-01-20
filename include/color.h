#include <tonc.h>

#define NUM_COL_ID_CHANNELS 4

#define BG_COLOR  0x01
#define GROUND_COLOR  0x01

#define LINE_COLOR 0x08
#define OBJ_COLOR 0x0A
#define COL_ID_COLOR 0x07
#define BRIGHTER_COLOR 0x0B

#define PORTAL_WHITE_COLOR 0x112
#define PORTAL_GLOW_COLOR 0x117

#define P1_COLOR 0x106
#define P2_COLOR 0x109

#define BG_OBJ_BLENDING_1 0x08
#define BG_OBJ_BLENDING_2 0x09

#define BG_COL_BLENDING 0x02


#define BG_PAL  0x00
#define GROUND_PAL  0x10
#define LIGHTER_BG_PAL 0x20
#define COL_CHN_PAL 0x30
#define COL_CHN_PAL_LAST (COL_CHN_PAL + 0x10 * NUM_COL_ID_CHANNELS)


void set_bg_color(COLOR *dst, COLOR color);
void set_obj_color(COLOR *dst, COLOR color);
void set_ground_color(COLOR *dst, COLOR color);
void set_line_color(COLOR *dst, COLOR color);
void set_color_channel_color(COLOR *dst, COLOR color, u32 channel);
u16 lerp_color(COLOR color1, COLOR color2, FIXED time);

void run_col_trigger_changes();