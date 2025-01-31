#include <tonc.h>

#pragma once

#define NUM_STEPS 4

#define TOTAL_CUTSCENE_FRAMES 60
#define EXIT_CUTSCENE_FRAME 240

// Gamemode IDs
enum GamemodeType {
    GAMEMODE_CUBE,
    GAMEMODE_SHIP,
    GAMEMODE_BALL,
    GAMEMODE_UFO,
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

enum DualStatus {
    DUAL_OFF,
    DUAL_ON
};

enum PlayerID {
    ID_PLAYER_1,
    ID_PLAYER_2
};

struct Player {
    // Position variables, in subpixels
    s64 player_x; // gota love giant levels
    s64 player_y;

    // Player dimensions, in pixels
    u8 player_width;
    u8 player_height;

    u8 player_internal_hitbox_width;
    u8 player_internal_hitbox_height;

    // Speed variables, in subpixels/frame
    s32 player_x_speed;
    s32 player_y_speed;

    // Relative position on screen in pixels
    s16 relative_player_x;
    s16 relative_player_y;

    // Change of y speed
    s16 gravity;

    // Direction of the gravity. 0 : down, 1 : up
    u8 gravity_dir;

    // 0 : big, 1 : mini
    u8 player_size;

    // 0 : on air, 1 : on floor
    u8 on_floor;

    // 0 : not buffering, 1 : buffering
    u8 player_buffering;

    // Current player gamemode
    u8 gamemode;

    // Cube rotation angle
    u16 cube_rotation;

    // - : left | + : right
    s8 ball_rotation_direction;

    // Initial position of player for the curve. In pixels
    u32 cutscene_initial_player_x;
    u32 cutscene_initial_player_y;

    // Only used for cube. If 1, then ceiling doesn't kill player
    u8 should_check_ceiling;

    // Set at the frame the cube changed size
    u8 changed_size_frames;
};
extern u8 player_death;

extern u8 speed_id;

extern u8 dual;

extern FIXED mirror_scaling;

void player_main();
void draw_player();
void set_player_speed();