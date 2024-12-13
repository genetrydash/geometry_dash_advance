#include "main.h"

// Position variables, in subpixels
u32 player_x;
u32 player_y;

// Speed variables, in subpixels/frame
s16 player_x_speed;
s16 player_y_speed;

// Relative position on screen in pixels
u16 relative_player_x;
u16 relative_player_y;

s16 gravity;
u8 gravity_dir;

u8 on_floor;

// Current player gamemode
u8 gamemode;

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
// in subpixels
const u16 speed_constants[] = {
    0x23B, // x0.5
    0x2C4, // x1
    0x371, // x2
    0x429, // x3
    0x51E  // x4
};

// Current speed portal
u8 speed_portal = SPEED_X1;

// in subpixels
#define CUBE_GRAVITY 0x6B
#define CUBE_MAX_Y_SPEED 0x600
#define CUBE_JUMP_SPEED 0x590

void cube_gamemode();
void ship_gamemode();

void player_main() {    
    // Run collision
    collision_main();

    // Set player speed
    player_x_speed = speed_constants[speed_portal];
    
    // Convert subpixels to pixels
    scroll_x = scroll_x_subacc >> 8;

    // This scrolls the screen on the y axis
    if (relative_player_y >= SCREEN_HEIGHT-0x28 && player_y_speed > 0) {
        scroll_y_subacc += player_y_speed;
        scroll_y_dir = 1;
    } else if (relative_player_y <= 0x28 && player_y_speed < 0) {
        scroll_y_subacc += player_y_speed;
        scroll_y_dir = 0;
    }
    
    // Convert subpixels to pixels
    scroll_y = scroll_y_subacc >> 8;
    
    if (player_x >= 0x5000) {
        scroll_x_subacc += player_x_speed;
        // Set relative x to 0x50 so it doesn't jitter in place
        relative_player_x = 0x50;
    } else {
        // Calculate relative positions on screen
        relative_player_x = ((player_x >> 8) - (scroll_x_subacc >> 8));
    }
    relative_player_y = ((player_y >> 8) - (scroll_y_subacc >> 8));

    // Draw player
    oam_metaspr(relative_player_x, relative_player_y, playerSpr);

    // Gamemode specific routines
    switch (gamemode) {
        case CUBE:
            cube_gamemode();
            break;
        case SHIP:
            ship_gamemode();
            break;
    }

    // Update player x
    player_x += player_x_speed;
}


void cube_gamemode() {
    gravity = CUBE_GRAVITY;
    
    // Depending on which direction the gravity points, apply gravity and cap speed in one direction or in the other
    if (gravity_dir) {
        player_y_speed -= gravity;
        if (player_y_speed < -CUBE_MAX_Y_SPEED) player_y_speed = -CUBE_MAX_Y_SPEED;
    } else {
        player_y_speed += gravity;
        if (player_y_speed > CUBE_MAX_Y_SPEED) player_y_speed = CUBE_MAX_Y_SPEED;
    }

    // If on floor and holding A or UP, jump
    if (on_floor && key_held(KEY_A | KEY_UP)) {
        player_y_speed += (gravity_dir ? CUBE_JUMP_SPEED : -CUBE_JUMP_SPEED);
    }
    
    // Apply y speed
    player_y += player_y_speed;
}

void ship_gamemode() {
    // TODO: ship gamemode
}