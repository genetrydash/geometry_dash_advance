#include "memory.h"
#include "color.h"
#include "sprite_loading.h"
#include "chr.h"
#include "mgba_log.h"

#define NUM_FACES 6
const COLOR face_colors[][2] = {
    {CLR_CYAN, CLR_BLUE}, // Easy
    {0x03E0, 0x0202}, // Normal
    {0x03FF, 0x01FF}, // Hard
    {0x01DF, 0x001F}, // Harder
    {0x6DFF, 0x785D}, // Insane
    {0x28FF, 0x009C}, // Demon
};

const COLOR menu_bg_colors[] = {
    0x6C00, // Stereo Madness
    0x741D, // Back on Track
    0x3019, // Polargeist
    0x001B, // Dry Out
    0x0177, // Base After Base
    0x02D6, // Can't let go
    0x02C0, // Jumper
    0x5AC0, // Time Machine
    0x5D60, // Cycles
};

const u16 pal_bg_to_spr[] = {
    0x1f0,
    0xffff,
    0x1e0,
    0x1d0,
    0x1c0,
    0x1b0,
    0x1a0,
};

INLINE void copy_bg_pal_to_spr(COLOR *dst, u32 pal) {
    // Copy palette to the sprite equivalent
    u16 equivalent_palette = pal_bg_to_spr[pal >> 4];
    if (equivalent_palette != 0xffff) memcpy16(&dst[equivalent_palette], &dst[pal], 0x0f);
}

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

void menu_set_bg_color(COLOR *dst, COLOR color) {
    dst[0x00] = color;
    dst[BG_PAL + BG_COLOR] = color;
    dst[0x121] = color;
    // Fade to black
    for (u32 index = 2; index < 7; index++) {
        clr_adj_brightness(&dst[index], &dst[index - 1], 1, float2fx(-0.15));
    }

    dst[0x12] = dst[0x122] = dst[0x24] = dst[0x04];

    for (s32 i = 3; i < NUM_FACES + 3; i++) {
        dst[(i << 4) + 0x0e] = dst[0x04];
    }
}

// Set BG color on the 4 color palettes
void set_bg_color(COLOR *dst, COLOR color) {
    // Set BG color
    dst[0x00] = color;
    dst[BG_PAL + BG_COLOR] = color;

    dst[LIGHTER_BG_PAL + BG_COLOR] = color;
    
    // Adjust brighter color
    adjust_brighter_color(dst, BG_PAL);
    
    // Fade to black
    for (u32 index = 2; index < 7; index++) {
        clr_adj_brightness(&dst[index], &dst[index - 1], 1, float2fx(-0.15));
    }

    blend_bg_and_obj(dst, BG_PAL);
    
    // Copy pal into sprites
    copy_bg_pal_to_spr(dst, BG_PAL);

    // Update lbg
    update_lbg_palette(dst);

    for (u32 pal = COL_CHN_PAL; pal < COL_CHN_PAL_LAST; pal += 0x10) {  
        // Blend col
        dst[BG_COLOR + pal] = color;
        blend_bg_and_col(dst, pal);
        blend_bg_and_obj(dst, pal);

        // Adjust brighter color
        adjust_brighter_color(dst, pal);

        // Copy pal into sprites
        copy_bg_pal_to_spr(dst, pal);
    }
    
    // Portal colors also have a glow on them
    clr_blend(&dst[BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[PORTAL_GLOW_COLOR], 1, 0x0f);

    u32 loops = (PORTAL_GLOW_COLOR + 0x10) + ((NUM_PORTAL_PALETTES - 1) << 4);
    for (u32 pal = (PORTAL_GLOW_COLOR + 0x10) ; pal < loops; pal += 0x10) {
        dst[pal] = dst[PORTAL_GLOW_COLOR]; 
    }
}

void update_lbg_palette(COLOR *dst) {
    // Get LBG color
    COLOR lbg = calculate_lbg(dst[BG_PAL + BG_COLOR], dst[P1_COLOR]);
    dst[LIGHTER_BG_PAL + COL_ID_COLOR] = lbg;

    // Blend both bg and lbg
    u32 blend_value = 0x1f / (COL_ID_COLOR - BG_COL_BLENDING + 1);
    for (u32 col = 0; col < 5; col++) {
        clr_blend(&dst[BG_PAL + BG_COLOR], &dst[LIGHTER_BG_PAL + COL_ID_COLOR], &dst[LIGHTER_BG_PAL + BG_COL_BLENDING + col], 1, blend_value);
        blend_value += 0x1f / (COL_ID_COLOR - BG_COL_BLENDING + 1);
    }

    // Adjust brighter color
    adjust_brighter_color(dst, LIGHTER_BG_PAL);
    
    // Blend BG and OBJ
    blend_bg_and_obj(dst, LIGHTER_BG_PAL);

    // Copy pal into sprites
    copy_bg_pal_to_spr(dst, LIGHTER_BG_PAL);
}

void adjust_brighter_color(COLOR *dst, u32 pal) {
    clr_blend(&dst[BG_PAL + BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[pal + BRIGHTER_COLOR], 1, 0x0a);
    clr_blend(&dst[BG_PAL + BG_COLOR], &dst[PORTAL_WHITE_COLOR], &dst[pal + BRIGHTER_COLOR + 1], 1, 0x10);
}

ARM_CODE COLOR calculate_lbg(COLOR bg, COLOR p1) {
    // Get RGB structs
    struct RGB555 bg_rgb;
    struct RGB555 p1_rgb;

    // Set color components to both structs
    BGR_TO_STRUCT(bg, bg_rgb)
    BGR_TO_STRUCT(p1, p1_rgb)
    
    // Convert into HSV
    struct HSV hsv = rgb_to_hsv(bg_rgb);

    // Subtract 0.40 to saturation (GD uses 0.20, but it also has translucency, GBA can't have that)
    hsv.saturation -= FLOAT_TO_FIXED(0.40f);
    hsv.saturation = CLAMP(hsv.saturation, 0, FIXED_MULTIPLIER + 1);
    
    // Add 0.40 to saturation
    hsv.value += FLOAT_TO_FIXED(0.40f);
    hsv.value = CLAMP(hsv.value, 0, FIXED_MULTIPLIER + 1);

    // Convert back to RGB
    struct RGB555 lbg_rgb = hsv_to_rgb(hsv);

    // Get multiplier
    FIXED_16 multiplier = FIXED_DIV(bg_rgb.red + bg_rgb.green + bg_rgb.blue, 18);
    
    // If below 1.0, don't modify LBG
    if (multiplier < FIXED_MULTIPLIER) {
        lbg_rgb.red = FROM_FIXED(FIXED_MUL(TO_FIXED(lbg_rgb.red), multiplier) + FIXED_MUL(TO_FIXED(p1_rgb.red), FIXED_MULTIPLIER - multiplier));
        lbg_rgb.green = FROM_FIXED(FIXED_MUL(TO_FIXED(lbg_rgb.green), multiplier) + FIXED_MUL(TO_FIXED(p1_rgb.green), FIXED_MULTIPLIER - multiplier));
        lbg_rgb.blue = FROM_FIXED(FIXED_MUL(TO_FIXED(lbg_rgb.blue), multiplier) + FIXED_MUL(TO_FIXED(p1_rgb.blue), FIXED_MULTIPLIER - multiplier));
    }

    // Return BGR555 color
    return RGB15_SAFE(lbg_rgb.red, lbg_rgb.green, lbg_rgb.blue);
}

void set_obj_color(COLOR *dst, COLOR color) {
    // BG
    dst[OBJ_COLOR] = color;
    blend_bg_and_obj(dst, BG_PAL);
    copy_bg_pal_to_spr(dst, BG_PAL);

    // LBG
    dst[LIGHTER_BG_PAL + OBJ_COLOR] = color;
    blend_bg_and_obj(dst, LIGHTER_BG_PAL);
    copy_bg_pal_to_spr(dst, LIGHTER_BG_PAL);

    for (u32 pal = COL_CHN_PAL; pal < COL_CHN_PAL_LAST; pal += 0x10) {
        // Set BG color
        dst[OBJ_COLOR + pal] = color;
        
        blend_bg_and_obj(dst, pal);
        
        // Copy pal into sprites
        copy_bg_pal_to_spr(dst, pal);
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
    
    copy_bg_pal_to_spr(dst, pal);
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

#define FIRST_FACE_PAL 0x30
#define FIRST_FACE_COLOR 0x2
#define LAST_FACE_COLOR  0xb

void set_face_palettes(COLOR *dst) {
    s32 difficulty = 0;
    for (s32 pal = FIRST_FACE_PAL; pal < (FIRST_FACE_PAL + (NUM_FACES * 0x10)); pal += 0x10) {    
        s32 value = 0;
        dst[pal + 0x01] = CLR_WHITE;
        dst[pal + 0x0d] = CLR_RED;
        for (s32 id = FIRST_FACE_COLOR; id <= LAST_FACE_COLOR; id++) {
            clr_blend(&face_colors[difficulty][0], &face_colors[difficulty][1], &dst[pal + id], 1, value);
            value += 0x1f / (LAST_FACE_COLOR - FIRST_FACE_COLOR + 1);
        }
        difficulty++;
    }
}

#define MAX_3(a,b,c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
#define MIN_3(a,b,c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));

ARM_CODE struct HSV rgb_to_hsv(struct RGB555 rgb) {
    struct HSV hsv_return;
    FIXED_16 r = TO_FIXED(rgb.red) / 31;
    FIXED_16 g = TO_FIXED(rgb.green) / 31;
    FIXED_16 b = TO_FIXED(rgb.blue) / 31;

    FIXED_16 max = MAX_3(r, g, b);
    FIXED_16 min = MIN_3(r, g, b);
    FIXED_16 delta = max - min;

    FIXED_16 hue, saturation, value;

    // Calculate hue
    if (delta == 0) {
        hue = 0;
    } else {
        if (max == r) {
            hue = FIXED_DIV(g - b, delta) * 60;
        } else if (max == g) {
            hue = FIXED_DIV(b - r, delta) * 60 + TO_FIXED(120);
        } else { // max == b
            hue = FIXED_DIV(r - g, delta) * 60 + TO_FIXED(240);
        }
    }

    // Normalize hue to 0-360
    if (hue < 0) hue += TO_FIXED(360);

    // Calculate saturation
    if (max == 0) {
        saturation = 0;
    } else {
        saturation = FIXED_MULTIPLIER - FIXED_DIV(min, max);
    }


    // Calculate value (simply max)
    value = max;

    hsv_return.hue = hue;
    hsv_return.saturation = saturation;
    hsv_return.value = value;
    return hsv_return;
}   

#define MAX_MULT_VALUE (FIXED_MULTIPLIER - 1)
ARM_CODE struct RGB555 hsv_to_rgb(struct HSV hsv) {
    struct RGB555 rgb_struct;
    if (hsv.saturation == 0) {
        u8 value_5 = FROM_FIXED(hsv.value * 31);
        rgb_struct.red = value_5;
        rgb_struct.green = value_5;
        rgb_struct.blue = value_5;
        return rgb_struct;
    }

    FIXED_16 r,g,b;
    FIXED hue_mult = hsv.hue / 360;
    
    // Get sector [0-5]
    FIXED_16 sector = FROM_FIXED(hue_mult * 6);

    // Get fraction by subtracting original value to floored value [0-1]
    FIXED_16 fraction = (hue_mult * 6) - TO_FIXED(sector);

    // Get some values
    FIXED_16 p = FIXED_MUL(hsv.value, FIXED_MULTIPLIER - hsv.saturation);
    FIXED_16 q = FIXED_MUL(hsv.value, FIXED_MULTIPLIER - FIXED_MUL(hsv.saturation, fraction));
    FIXED_16 t = FIXED_MUL(hsv.value, FIXED_MULTIPLIER - FIXED_MUL(hsv.saturation, FIXED_MULTIPLIER - fraction));

    // Assign RGB based on sector
    switch (sector) {
        case 0: // Red to Yellow
            r = hsv.value; g = t; b = p;
            break;
        case 1: // Yellow to Green
            r = q; g = hsv.value; b = p;
            break;
        case 2: // Green to Cyan
            r = p; g = hsv.value; b = t;
            break;
        case 3: // Cyan to Blue
            r = p; g = q; b = hsv.value;
            break;
        case 4: // Blue to Magenta
            r = t; g = p; b = hsv.value;
            break;
        case 5: // Magenta to Red
            r = hsv.value; g = p; b = q;
            break;
        default:
            r = 0; g = 0; b = 0; // Shouldn't happen
            break;
    }

    // Convert 0-1 scale to 0-31
    rgb_struct.red = FROM_FIXED(r * 31);
    rgb_struct.green = FROM_FIXED(g * 31);
    rgb_struct.blue = FROM_FIXED(b * 31);

    return rgb_struct;
}
