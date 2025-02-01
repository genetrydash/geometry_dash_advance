#include <tonc.h>

#pragma once

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

struct RGB555 {
    u8 red;
    u8 green;
    u8 blue;
};

struct HSV {
    FIXED_16 hue;
    FIXED_16 saturation;
    FIXED_16 value;
};

extern const COLOR face_colors[][2];

ARM_CODE struct HSV rgb_to_hsv(struct RGB555 rgb);
ARM_CODE struct RGB555 hsv_to_rgb(struct HSV hsv);
ARM_CODE COLOR calculate_lbg(COLOR bg, COLOR p1);

void update_lbg_palette(COLOR *dst);
void set_bg_color(COLOR *dst, COLOR color);
void set_obj_color(COLOR *dst, COLOR color);
void set_ground_color(COLOR *dst, COLOR color);
void set_line_color(COLOR *dst, COLOR color);
void set_color_channel_color(COLOR *dst, COLOR color, u32 channel);
void set_face_color(COLOR *dst, COLOR first_face_color, COLOR last_face_color);
u16 lerp_color(COLOR color1, COLOR color2, FIXED time);

void run_col_trigger_changes();