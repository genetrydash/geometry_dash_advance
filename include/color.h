#include <tonc.h>

void set_bg_color(COLOR color);
void set_obj_color(COLOR color);
void set_ground_color(COLOR color);
void set_line_color(COLOR color);
void set_color_channel_color(COLOR color, u32 channel);
u16 lerp_color(COLOR color1, COLOR color2, FIXED time);