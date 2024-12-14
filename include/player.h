#include <tonc.h>

#define CUBE_WIDTH 0x10
#define CUBE_HEIGHT 0x10

extern u64 player_x;
extern u32 player_y;

extern s16 player_x_speed;
extern s16 player_y_speed;

extern s16 gravity;
extern u8 gravity_dir;

extern u8 speed_portal;

extern u8 gamemode;

extern u8 on_floor;

void player_main();