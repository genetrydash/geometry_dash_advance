#include <tonc.h>

#define CUBE_WIDTH 0x10
#define CUBE_HEIGHT 0x10

#define SHIP_WIDTH 0x10
#define SHIP_HEIGHT 0x0c

// Gamemode IDs
enum GAMEMODE_TYPE {
    CUBE,
    SHIP
};

// Portal speed IDs
enum SPEEDS {
    SPEED_X05,
    SPEED_X1,
    SPEED_X2,
    SPEED_X3,
    SPEED_X4,
};

extern u64 player_x;
extern u32 player_y;

extern u16 player_width;
extern u16 player_height;

extern s16 player_x_speed;
extern s16 player_y_speed;

extern s16 gravity;
extern u8 gravity_dir;

extern u8 speed_portal;

extern u8 gamemode;

extern u8 on_floor;

void player_main();