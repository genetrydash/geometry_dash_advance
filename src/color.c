#include "color.h"

#define BG_COLOR  0x00
#define OBJ_COLOR 0x09

#define BG_OBJ_BLENDING_1 0x07
#define BG_OBJ_BLENDING_2 0x08
INLINE void blend_bg_and_obj(u32 pal) {
    // Blend both BG and OBJ colors and put it on palette slot 0x07 and 0x08
    clr_blend(&pal_bg_mem[pal], &pal_bg_mem[OBJ_COLOR + pal], &pal_bg_mem[BG_OBJ_BLENDING_1 + pal], 1, 0x0a);
    clr_blend(&pal_bg_mem[pal], &pal_bg_mem[OBJ_COLOR + pal], &pal_bg_mem[BG_OBJ_BLENDING_2 + pal], 1, 0x15);
}

// Set BG color on the 4 color palettes
void set_bg_color(COLOR color) {
    for (u32 pal = 0; pal < 0x40; pal += 0x10) {
        // Set BG color
        pal_bg_mem[pal] = color;

        // Adjust brightness for each color
        for (u32 index = 1; index < 6; index++) {
            clr_adj_brightness(&pal_bg_mem[index + pal], &pal_bg_mem[index - 1 + pal], 1, float2fx(-0.15));
        }
        
        blend_bg_and_obj(pal);
    }
}

void set_obj_color(COLOR color) {
    for (u32 pal = 0; pal < 0x40; pal += 0x10) {
        // Set BG color
        pal_bg_mem[OBJ_COLOR + pal] = color;
        
        blend_bg_and_obj(pal);
    }
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