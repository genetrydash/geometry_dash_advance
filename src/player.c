#include "main.h"

// Position variables, in subpixels
u64 player_x; // gota love giant levels
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
u8 gamemode = 1;

// Cube rotation angle
u16 cube_rotation = 0;

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


// Draw player
u8 x_offset;
u8 y_offset;


#define TOP_SCROLL_Y 0x2c
#define BOTTOM_SCROLL_Y SCREEN_HEIGHT-0x2c

void cube_gamemode();
void ship_gamemode();

void player_main() {    
    // Run collision
    collision_main();

    // Set player speed
    player_x_speed = speed_constants[speed_portal];

    // This scrolls the screen on the y axis
    if (relative_player_y >= BOTTOM_SCROLL_Y && player_y_speed > 0) {
        scroll_y_subacc += player_y_speed & 0xff;
        scroll_y_dir = 1;
        // If there was an overflow, add 1 to scroll y
        if (scroll_y_subacc > 0xff) {
            scroll_y++;
            scroll_y_subacc &= 0xff;
        }
        scroll_y += player_y_speed >> 8;
    } else if (relative_player_y <= TOP_SCROLL_Y && player_y_speed < 0) {
        scroll_y_subacc += player_y_speed & 0xff;
        scroll_y_dir = 0;
        // If there was an overflow, add 1 to scroll y
        if (scroll_y_subacc > 0xff) {
            scroll_y++;
            scroll_y_subacc &= 0xff;
        }
        scroll_y += player_y_speed >> 8;
    }
    
    if (player_x >= 0x5000) {
        scroll_x_subacc += player_x_speed & 0xff;
        // Set relative x to 0x50 so it doesn't jitter in place
        relative_player_x = 0x50;
        // If there was an overflow last frame, add 1 to scroll x
        if (scroll_x_subacc > 0xff) {
            scroll_x++;
            scroll_x_subacc &= 0xff;
        }
        scroll_x += player_x_speed >> 8;
    } else {
        // Calculate relative positions on screen
        relative_player_x = ((player_x >> 8) - scroll_x);
    }

    relative_player_y = ((player_y >> 8) - scroll_y);
    
    x_offset = (cube_rotation >= 0x6000 && cube_rotation < 0xe000 ? 8 : 7);
    y_offset = (cube_rotation >= 0x2000 && cube_rotation < 0xa000 ? 8 : 7);
    

    // Gamemode specific routines
    switch (gamemode) {
        case CUBE:
            cube_gamemode();
            break;
        case SHIP:
            ship_gamemode();
            break;
    }
    obj_aff_identity(&obj_aff_buffer[0]);

    obj_aff_rotate(&obj_aff_buffer[0], cube_rotation);

    // Update player x
    player_x += player_x_speed;

    on_floor = 0;
}

// in subpixels
#define CUBE_GRAVITY 0x6B
#define CUBE_MAX_Y_SPEED 0x600
#define CUBE_JUMP_SPEED 0x590

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

    // If the cube is on the air, rotate, else, snap to nearest 
    if (!on_floor) {
        cube_rotation -= 0x500;
    } else {
        cube_rotation = (cube_rotation + 0x2000) & 0xC000;
    }
    
    // Apply y speed
    player_y += player_y_speed;

    oam_metaspr(relative_player_x - x_offset, relative_player_y - y_offset, playerSpr);
}

// in subpixels
#define SHIP_GRAVITY 0x20
#define SHIP_GRAVITY_HOLDING 0x28
#define SHIP_MAX_Y_SPEED 0x2B0

void ship_gamemode() {
    u8 sign = gravity_dir ? -1 : 1;

    if (key_held(KEY_A | KEY_UP)) {
        cube_rotation = (-(player_y_speed * sign) >> 7) * 0x700; 

        gravity = SHIP_GRAVITY_HOLDING;
        player_y_speed -= gravity * sign;
    } else {
        cube_rotation = (-(player_y_speed * sign) >> 7) * 0x700; 

        gravity = SHIP_GRAVITY;
        player_y_speed += gravity * sign;
    }
    
    player_y_speed = CLAMP(player_y_speed, -SHIP_MAX_Y_SPEED, SHIP_MAX_Y_SPEED);
    
    // Apply y speed
    player_y += player_y_speed;

    oam_metaspr(relative_player_x - x_offset, relative_player_y - y_offset, shipSpr);
}