#include "color.h"
#include "sprite_loading.h"
#include "memory.h"
#include "chr.h"

INLINE void blend_bg_and_obj(COLOR *dst, u32 pal) {
    // Blend both BG and OBJ colors and put it on palette slot 0x07 and 0x08
    clr_blend(&dst[pal + BG_COLOR], &dst[OBJ_COLOR + pal], &dst[BG_OBJ_BLENDING_1 + pal], 1, 0x0a);
    clr_blend(&dst[pal + BG_COLOR], &dst[OBJ_COLOR + pal], &dst[BG_OBJ_BLENDING_2 + pal], 1, 0x15);
}

INLINE void blend_bg_and_col(COLOR *dst, u32 pal) {
    u32 blend_value = 0x1f / (COL_ID_COLOR - BG_COL_BLENDING + 1);
    for (u32 col = 0; col < 5; col++) {
        clr_blend(&dst[pal + 0x01], &dst[COL_ID_COLOR + pal], &dst[BG_COL_BLENDING + col + pal], 1, blend_value);
        blend_value += 0x1f / (COL_ID_COLOR - BG_COL_BLENDING + 1);
    }
}

// Set BG color on the 4 color palettes
void set_bg_color(COLOR *dst, COLOR color) {
    // Set BG color
    dst[0x00] = color;
    dst[BG_PAL + BG_COLOR] = color;

    dst[LIGHTER_BG_PAL + BG_COLOR] = color;
    
    // Adjust brighter color
    clr_blend(&dst[BG_PAL + BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[BRIGHTER_COLOR], 1, 0x15);
    
    blend_bg_and_obj(dst, BG_PAL);
    
    // Fade to black
    for (u32 index = 2; index < 7; index++) {
        clr_adj_brightness(&dst[index], &dst[index - 1], 1, float2fx(-0.15));
    }

    // Fade to white (lighter bg color)
    for (u32 index = 2; index < 8; index++) {
        clr_adj_brightness(&dst[LIGHTER_BG_PAL + index], &dst[LIGHTER_BG_PAL + index - 1], 1, float2fx(0.10));
    }
    
    // Adjust brighter color
    clr_blend(&dst[BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[LIGHTER_BG_PAL + BRIGHTER_COLOR], 1, 0x15);
    
    blend_bg_and_obj(dst, LIGHTER_BG_PAL);

    for (u32 pal = COL_CHN_PAL; pal < COL_CHN_PAL_LAST; pal += 0x10) {  
        // Blend col
        dst[BG_COLOR + pal] = color;
        blend_bg_and_col(dst, pal);
        blend_bg_and_obj(dst, pal);

        // Adjust brighter color
        clr_blend(&dst[BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[pal + BRIGHTER_COLOR], 1, 0x15);
    }

    // Copy first palette to last palette of sprites
    memcpy16(&dst[0x1f0], &dst[BG_PAL], 0x0a);
    
    // Portal colors also have a glow on them
    clr_blend(&dst[0], &dst[PORTAL_WHITE_COLOR], &dst[PORTAL_GLOW_COLOR], 1, 0x0f);

    u32 loops = (PORTAL_GLOW_COLOR + 0x10) + ((NUM_PORTAL_PALETTES - 1) << 4);
    for (u32 pal = (PORTAL_GLOW_COLOR + 0x10) ; pal < loops; pal += 0x10) {
        dst[pal] = dst[PORTAL_GLOW_COLOR]; 
    }
}

void set_obj_color(COLOR *dst, COLOR color) {
    dst[OBJ_COLOR] = color;
    blend_bg_and_obj(dst, BG_PAL);

    dst[LIGHTER_BG_PAL + OBJ_COLOR] = color;
    blend_bg_and_obj(dst, LIGHTER_BG_PAL);

    for (u32 pal = COL_CHN_PAL; pal < COL_CHN_PAL_LAST; pal += 0x10) {
        // Set BG color
        dst[OBJ_COLOR + pal] = color;
        
        blend_bg_and_obj(dst, pal);
    }
}

// Set ground color on the ground palette
void set_ground_color(COLOR *dst, COLOR color) {
    // Set ground color
    dst[GROUND_PAL + GROUND_COLOR] = color;

    // Adjust brightness for each color
    for (u32 index = 2; index < 7; index++) {
        clr_adj_brightness(&dst[index + GROUND_PAL], &dst[index - 1 + GROUND_PAL], 1, float2fx(-0.15));
    }
}

// Set line color
void set_line_color(COLOR *dst, COLOR color) {
    dst[GROUND_PAL + LINE_COLOR] = color;
}


// Set color channel of an specific palette
void set_color_channel_color(COLOR *dst, COLOR color, u32 channel) {
    // Set col
    u32 pal = (channel << 4) + COL_CHN_PAL;
    dst[COL_ID_COLOR + pal] = color;

    blend_bg_and_col(dst, pal);
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

// This function runs col triggers. It is important that it is done in VBLANK because it acceses palette memory
void run_col_trigger_changes() {
    for (s32 channel = 0; channel < CHANNEL_COUNT; channel++) {
        if (col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE]) {
            COLOR old_color = col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR];
            COLOR new_color = col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR];
            u16 frames      = col_trigger_buffer[channel][COL_TRIG_BUFF_TOTAL_FRAMES];
            u16 curr_frame  = col_trigger_buffer[channel][COL_TRIG_BUFF_CURRENT_FRAMES];

            COLOR lerped_color;

            // Calculate lerped color. If the value is less than 2, then it is an instant color change
            if (frames > 1) {
                u16 lerp_value = (curr_frame << 8) / (frames - 1); // Division, scary stuff
                lerped_color = lerp_color(old_color, new_color, lerp_value);
            } else {
                lerped_color = new_color;
            } 

            // Run code depending on which channel is the trigger modifying
            switch (channel) {
                case BG:
                    set_bg_color(palette_buffer, lerped_color);
                    break;
                case GROUND:
                    set_ground_color(palette_buffer, lerped_color);
                    break;
                case OBJ:
                    set_obj_color(palette_buffer, lerped_color);
                    break;
                case LINE:
                    set_line_color(palette_buffer, lerped_color);
                    break;
                case COL1:
                case COL2:
                case COL3:
                case COL4:
                    set_color_channel_color(palette_buffer, lerped_color, channel);
                    break;
            }

            col_trigger_buffer[channel][COL_TRIG_BUFF_CURRENT_FRAMES] = ++curr_frame;

            // If we reached total frames, then deactivate color change
            if (curr_frame >= frames) {
                col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE] = FALSE;
            }
        }
    }
}