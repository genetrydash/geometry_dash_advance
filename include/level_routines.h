#include <tonc.h>

#define SCREEN_TRANSITION_FRAMES 31 // 15 + 1 middle + 15
#define SCREEN_TRANSITION_SWITCH_FRAME (SCREEN_TRANSITION_FRAMES >> 1)
#define SCREEN_TRANSITION_HALF SCREEN_TRANSITION_SWITCH_FRAME

#define BOTTOM_SCROLL_LIMIT ((((GROUND_HEIGHT - 1) << (4 + SUBPIXEL_BITS)) + (0x2 << SUBPIXEL_BITS)) - (0x78 << (SUBPIXEL_BITS)))
extern s32 seam_x;
extern s32 seam_y;

extern u8 decompressed_column;

void decompress_first_screen();
void load_level(u32 level_ID);
void screen_scroll_load();
void reset_level();

void fade_out();
void fade_in();
void fade_in_level();

void scroll_screen_vertically();
void set_target_y_scroll(u32 object_y);

void mirror_screen();
void unmirror_screen();
void swap_screen_dir();

void draw_percentage();
void mirror_transition();

void upload_player_chr(u32 gamemode);