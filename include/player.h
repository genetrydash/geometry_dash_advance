#include <tonc.h>

#define NUM_STEPS 4

// Gamemode IDs
enum GamemodeType {
    GAMEMODE_CUBE,
    GAMEMODE_SHIP,
    GAMEMODE_BALL,
    GAMEMODE_COUNT
};

// Portal speed IDs
enum SpeedID {
    SPEED_X05,
    SPEED_X1,
    SPEED_X2,
    SPEED_X3,
    SPEED_X4,
    NUM_SPEEDS
};

enum GravityDir {
    GRAVITY_DOWN,
    GRAVITY_UP
};

enum PlayerSize {
    SIZE_BIG,
    SIZE_MINI
};

extern s64 player_x;
extern u64 player_y;

extern u16 relative_player_x;
extern u16 relative_player_y;

extern u8 player_width;
extern u8 player_height;

extern u8 player_internal_hitbox_width;
extern u8 player_internal_hitbox_height;

extern s32 player_x_speed;
extern s32 player_y_speed;

extern s16 gravity;
extern u8 gravity_dir;

extern u8 player_size;

extern u8 player_death;

extern u8 speed_id;

extern u8 gamemode;

extern u8 on_floor;

extern u8 player_buffering;

extern s8 ball_rotation_direction;

extern FIXED mirror_scaling;

void player_main();
void draw_player();