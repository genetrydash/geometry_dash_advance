#include "color.h"

#define BG_COLOR  0x00
#define OBJ_COLOR 0x09
#define COLOR_ID_COL 0x0D

#define BG_OBJ_BLENDING_1 0x07
#define BG_OBJ_BLENDING_2 0x08

#define BG_COL_BLENDING_1 0x0A
#define BG_COL_BLENDING_2 0x0B
#define BG_COL_BLENDING_3 0x0C
INLINE void blend_bg_and_obj(COLOR *dst, u32 pal) {
    // Blend both BG and OBJ colors and put it on palette slot 0x07 and 0x08
    clr_blend(&dst[pal], &dst[OBJ_COLOR + pal], &dst[BG_OBJ_BLENDING_1 + pal], 1, 0x0a);
    clr_blend(&dst[pal], &dst[OBJ_COLOR + pal], &dst[BG_OBJ_BLENDING_2 + pal], 1, 0x15);
}

INLINE void blend_bg_and_col(COLOR *dst, u32 pal) {
    // Blend both BG and COL colors and put it on palette slot 0x0A, 0x0B and 0x0C
    clr_blend(&dst[pal], &dst[COLOR_ID_COL + pal], &dst[BG_COL_BLENDING_1 + pal], 1, 0x0a);
    clr_blend(&dst[pal], &dst[COLOR_ID_COL + pal], &dst[BG_COL_BLENDING_2 + pal], 1, 0x10);
    clr_blend(&dst[pal], &dst[COLOR_ID_COL + pal], &dst[BG_COL_BLENDING_3 + pal], 1, 0x15);
}

// Set BG color on the 4 color palettes
void set_bg_color(COLOR *dst, COLOR color) {
    for (u32 pal = 0; pal < 0x40; pal += 0x10) {
        // Set BG color
        dst[pal] = color;

        // Adjust brightness for each color
        for (u32 index = 1; index < 6; index++) {
            clr_adj_brightness(&dst[index + pal], &dst[index - 1 + pal], 1, float2fx(-0.15));
        }
        
        blend_bg_and_obj(dst, pal);
        blend_bg_and_col(dst, pal);
    }
    
    // Portal colors also have a glow on them
    clr_blend(&dst[0], &dst[0x112], &dst[0x117], 1, 0x0f);
    clr_blend(&dst[0], &dst[0x122], &dst[0x127], 1, 0x0f);
}

void set_obj_color(COLOR *dst, COLOR color) {
    for (u32 pal = 0; pal < 0x40; pal += 0x10) {
        // Set BG color
        dst[OBJ_COLOR + pal] = color;
        
        blend_bg_and_obj(dst, pal);
        blend_bg_and_col(dst, pal);
    }
}

// Set ground color on the ground palette
void set_ground_color(COLOR *dst, COLOR color) {
    // Set ground color
    dst[0x40] = color;
    dst[0x41] = color;

    // Adjust brightness for each color
    for (u32 index = 2; index < 7; index++) {
        clr_adj_brightness(&dst[index + 0x40], &dst[index - 1 + 0x40], 1, float2fx(-0.15));
    }
}

// Set line color
void set_line_color(COLOR *dst, COLOR color) {
    dst[0x48] = color;
}


// Set color channel of an specific palette
void set_color_channel_color(COLOR *dst, COLOR color, u32 channel) {
    // Set ground color
    dst[0x0D + (channel << 4)] = color;

    blend_bg_and_col(dst, channel);
}


// Lerp between two BGR555 colors. Time is a value between 0 and 256 (both inclusive) and it is a fixed point value so 0 = 0.0, 128 = 0.5 and 256 = 1.0
u16 lerp_color(COLOR color1, COLOR color2, FIXED time) {
    // Cap value to 1.0
    if (time > 0x100) time = 0x100;

    // Extract components
    u32 r1 = color1 & 0x1F;
    u32 g1 = (color1 >> 5) & 0x1F;
    u32 b1 = (color1 >> 10) & 0x1F;
    
    u32 r2 = color2 & 0x1F;
    u32 g2 = (color2 >> 5) & 0x1F;
    u32 b2 = (color2 >> 10) & 0x1F;

    // Interpolate components
    u32 red_lerp   = (r1 * (0x100 - time) + r2 * time) >> 8;
    u32 green_lerp = (g1 * (0x100 - time) + g2 * time) >> 8;
    u32 blue_lerp  = (b1 * (0x100 - time) + b2 * time) >> 8;

    // Combine into a single BGR555 value
    return (blue_lerp << 10) | (green_lerp << 5) | red_lerp;
}