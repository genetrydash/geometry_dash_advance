#include "main.h"
#include "sprite_loading.h"
#include "sprite_routines.h"
#include "physics_defines.h"
#include "color.h"

// [gamemode][type]

#define YELLOW_ORB_INDEX 0
#define YELLOW_PAD_INDEX 1
#define PINK_ORB_INDEX 2
#define PINK_PAD_INDEX 3
#define BLUE_ORB_PAD_INDEX 4

const s32 orb_pad_bounces[][GAMEMODE_COUNT][5] = {
    { // Big
        /* Cube */ {CUBE_YELLOW_ORB_JUMP_SPEED, CUBE_YELLOW_PAD_JUMP_SPEED, CUBE_PINK_ORB_JUMP_SPEED, CUBE_PINK_PAD_JUMP_SPEED, CUBE_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ship */ {SHIP_YELLOW_ORB_JUMP_SPEED, SHIP_YELLOW_PAD_JUMP_SPEED, SHIP_PINK_ORB_JUMP_SPEED, SHIP_PINK_PAD_JUMP_SPEED, SHIP_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ball */ {BALL_YELLOW_ORB_JUMP_SPEED, BALL_YELLOW_PAD_JUMP_SPEED, BALL_PINK_ORB_JUMP_SPEED, BALL_PINK_PAD_JUMP_SPEED, BALL_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ufo */  {UFO_YELLOW_ORB_JUMP_SPEED,  UFO_YELLOW_PAD_JUMP_SPEED,  UFO_PINK_ORB_JUMP_SPEED,  UFO_PINK_PAD_JUMP_SPEED,  UFO_BLUE_ORB_PAD_INITIAL_SPEED},
    }, { // Mini
        /* Cube */ {CUBE_MINI_YELLOW_ORB_JUMP_SPEED, CUBE_MINI_YELLOW_PAD_JUMP_SPEED, CUBE_MINI_PINK_ORB_JUMP_SPEED, CUBE_MINI_PINK_PAD_JUMP_SPEED, CUBE_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ship */ {SHIP_MINI_YELLOW_ORB_JUMP_SPEED, SHIP_MINI_YELLOW_PAD_JUMP_SPEED, SHIP_MINI_PINK_ORB_JUMP_SPEED, SHIP_MINI_PINK_PAD_JUMP_SPEED, SHIP_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ball */ {BALL_MINI_YELLOW_ORB_JUMP_SPEED, BALL_MINI_YELLOW_PAD_JUMP_SPEED, BALL_MINI_PINK_ORB_JUMP_SPEED, BALL_MINI_PINK_PAD_JUMP_SPEED, BALL_BLUE_ORB_PAD_INITIAL_SPEED},
        /* Ufo */  {UFO_MINI_YELLOW_ORB_JUMP_SPEED,  UFO_MINI_YELLOW_PAD_JUMP_SPEED,  UFO_MINI_PINK_ORB_JUMP_SPEED,  UFO_MINI_PINK_PAD_JUMP_SPEED,  UFO_BLUE_ORB_PAD_INITIAL_SPEED},
    }
};

void cube_portal(struct ObjectSlot *objectSlot) {
    if (gamemode == GAMEMODE_SHIP) player_y_speed /= 2;
    gamemode = GAMEMODE_CUBE;
    objectSlot->activated = TRUE;
}

void ship_portal(struct ObjectSlot *objectSlot) {
    if (gamemode != GAMEMODE_SHIP) player_y_speed /= 2;
    gamemode = GAMEMODE_SHIP;
    
    set_target_y_scroll(objectSlot->object.y);

    objectSlot->activated = TRUE;
}

void ball_portal(struct ObjectSlot *objectSlot) {
    if (gamemode == GAMEMODE_SHIP) player_y_speed /= 2;
    gamemode = GAMEMODE_BALL;
    
    set_target_y_scroll(objectSlot->object.y);

    objectSlot->activated = TRUE;
}

void ufo_portal(struct ObjectSlot *objectSlot) {
    if (gamemode == GAMEMODE_SHIP) player_y_speed /= 2;
    gamemode = GAMEMODE_UFO;
    
    set_target_y_scroll(objectSlot->object.y);

    objectSlot->activated = TRUE;
}

void blue_gravity_portal(struct ObjectSlot *objectSlot) {
    if (gravity_dir == GRAVITY_UP) {
        player_y_speed /= 2;
        gravity_dir = GRAVITY_DOWN;
        
        ball_rotation_direction = -1;
    }

    objectSlot->activated = TRUE;
}

void yellow_gravity_portal(struct ObjectSlot *objectSlot) {
    if (gravity_dir == GRAVITY_DOWN) {
        player_y_speed /= 2;
        gravity_dir = GRAVITY_UP;

        ball_rotation_direction = 1;
    }

    objectSlot->activated = TRUE;
}

void mirror_portal(struct ObjectSlot *objectSlot) {
    mirror_screen();
    objectSlot->activated = TRUE;
}

void unmirror_portal(struct ObjectSlot *objectSlot) {
    unmirror_screen();
    objectSlot->activated = TRUE;
}

void mini_portal(struct ObjectSlot *objectSlot) {
    player_size = SIZE_MINI;
    objectSlot->activated = TRUE;
}

void big_portal(struct ObjectSlot *objectSlot) {
    player_size = SIZE_BIG;
    objectSlot->activated = TRUE;
}

void speed_portal_half(struct ObjectSlot *objectSlot) {
    speed_id = SPEED_X05;
    objectSlot->activated = TRUE;
}

void speed_portal_1x(struct ObjectSlot *objectSlot) {
    speed_id = SPEED_X1;
    objectSlot->activated = TRUE;
}

void speed_portal_2x(struct ObjectSlot *objectSlot) {
    speed_id = SPEED_X2;
    objectSlot->activated = TRUE;
}

void speed_portal_3x(struct ObjectSlot *objectSlot) {
    speed_id = SPEED_X3;
    objectSlot->activated = TRUE;
}

void speed_portal_4x(struct ObjectSlot *objectSlot) {
    speed_id = SPEED_X4;
    objectSlot->activated = TRUE;
}


void col_trigger(struct ObjectSlot *objectSlot) {
    struct Object col_trigger = objectSlot->object;
    
    u32 is_touch_trigger = col_trigger.rotation & COL_TRIGGER_ROT_VAR_TOUCH_MASK;

    // If the trigger is a touch trigger, then behave like a normal object,
    // else if the player is right of the horizontal center of the trigger, activate the color trigger
    if (is_touch_trigger || (player_x >> SUBPIXEL_BITS) >= (col_trigger.x + 8)) {
        u32 frames = (col_trigger.attrib1 >> COL_TRIGGER_ATTRIB1_FRAMES_SHIFT) + 1; // +1 because 0 = 1
        u32 channel = col_trigger.attrib1 & COL_TRIGGER_ATTRIB1_CHANNEL_MASK;

        u8 copy = col_trigger.attrib3 & 1;
        
        // Save variables into buffer
        switch (channel) {
            case BG:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x00];
                break;
            case GROUND:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x41];
                break;
            case OBJ:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x09];
                break;
            case LINE:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x48];
                break;
            case COL1:
            case COL2:
            case COL3:
            case COL4:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x0D + (channel << 4)];
                break;
        }
        col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE] = TRUE;
        if (copy) {
            u8 copied_channel = col_trigger.attrib3 >> 1;

            switch (copied_channel) {
                case BG:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x00];
                    break;
                case GROUND:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x41];
                    break;
                case OBJ:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x09];
                    break;
                case LINE:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x48];
                    break;
                case P1:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x105];
                    break;
                case P2:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x108];
                    break;
                case COL1:
                case COL2:
                case COL3:
                case COL4:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x0D + (channel << 4)];
                    break;
            }
        } else {
            col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = col_trigger.attrib2;
        }
        col_trigger_buffer[channel][COL_TRIG_BUFF_TOTAL_FRAMES] = frames; // Total frames
        col_trigger_buffer[channel][COL_TRIG_BUFF_CURRENT_FRAMES] = 0;      // Current frame

        // Deoccupy slot
        objectSlot->occupied = FALSE;
    }
}

void yellow_orb(struct ObjectSlot *objectSlot) {
    if (player_buffering == ORB_BUFFER_READY) {
        s32 sign = (gravity_dir == GRAVITY_UP) ? 1 : -1;
        player_y_speed = orb_pad_bounces[player_size][gamemode][YELLOW_ORB_INDEX] * sign;
 
        ball_rotation_direction = sign;

        objectSlot->activated = TRUE;
        on_floor = FALSE;
        player_buffering = ORB_BUFFER_END;
    }
}

void yellow_pad(struct ObjectSlot *objectSlot) {
    s32 sign = (gravity_dir == GRAVITY_UP) ? 1 : -1;
    player_y_speed = orb_pad_bounces[player_size][gamemode][YELLOW_PAD_INDEX] * sign;
    on_floor = FALSE;
    objectSlot->activated = TRUE;
}

void blue_orb(struct ObjectSlot *objectSlot) {
    if (player_buffering == ORB_BUFFER_READY) {
        gravity_dir ^= 1;
        s32 sign = (gravity_dir == GRAVITY_UP) ? -1 : 1;

        ball_rotation_direction = sign;
        
        player_y_speed = orb_pad_bounces[player_size][gamemode][BLUE_ORB_PAD_INDEX] * sign;
        objectSlot->activated = TRUE;
        on_floor = FALSE;
        player_buffering = ORB_BUFFER_END;
    }
}

void blue_pad(struct ObjectSlot *objectSlot) {
    u32 enabled_rotation = (objectSlot->object.attrib1 & ENABLE_ROTATION_FLAG);
    if (!enabled_rotation) {
        // Object is not rotated
        if (gravity_dir != (objectSlot->object.attrib1 & V_FLIP_FLAG)) {
            return;
        }
    } else {
        // Object is rotated
        u16 rotation = (objectSlot->object.rotation);
        if (!gravity_dir) {
            // Gravity goes down
            if (rotation >= 0x4000 && rotation < 0xc000) {
                // Object rotation is between 90 and 270 degrees
                return;
            }
        } else {
            // Gravity goes up
            if (rotation < 0x4000 || rotation >= 0xc000) {
                // Object rotation is less than 90 or greater than 270 degrees
                return;
            }
        }
    }

    // Gravity should change 
    gravity_dir ^= 1;
    s32 sign = (gravity_dir == GRAVITY_UP) ? -1 : 1;

    ball_rotation_direction = sign;

    player_y_speed = orb_pad_bounces[player_size][gamemode][BLUE_ORB_PAD_INDEX] * sign;
    on_floor = FALSE;
    objectSlot->activated = TRUE;
}


void pink_orb(struct ObjectSlot *objectSlot) {
    if (player_buffering == ORB_BUFFER_READY) {
        s32 sign = (gravity_dir == GRAVITY_UP) ? 1 : -1;
        player_y_speed = orb_pad_bounces[player_size][gamemode][PINK_ORB_INDEX] * sign;
        
        ball_rotation_direction = sign;
        
        objectSlot->activated = TRUE;
        on_floor = FALSE;
        player_buffering = ORB_BUFFER_END;
    }
}

void pink_pad(struct ObjectSlot *objectSlot) {
    s32 sign = (gravity_dir == GRAVITY_UP) ? 1 : -1;
    player_y_speed = orb_pad_bounces[player_size][gamemode][PINK_PAD_INDEX] * sign;
    on_floor = FALSE;
    objectSlot->activated = TRUE;
}

void block(UNUSED struct ObjectSlot *objectSlot) {
    // Check if this object is already in the buffer
    for (s32 i = block_object_buffer_offset; i > 0; i--) {
        if (block_object_buffer[i - 1] == (s32 *) objectSlot) {
            return;
        }
    }
    
    // If not, add it
    block_object_buffer[block_object_buffer_offset] = (s32 *) objectSlot;
    block_object_buffer_flags[block_object_buffer_offset++] = COL_FULL;
}

void slab(UNUSED struct ObjectSlot *objectSlot) {
    // Check if this object is already in the buffer
    for (s32 i = block_object_buffer_offset; i > 0; i--) {
        if (block_object_buffer[i - 1] == (s32 *) objectSlot) {
            return;
        }
    }

    // If not, add it
    block_object_buffer[block_object_buffer_offset] = (s32 *) objectSlot;
    block_object_buffer_flags[block_object_buffer_offset++] = COL_SLAB_TOP;
}

void do_nothing(UNUSED struct ObjectSlot *objectSlot) {
    // No routine defined
}

void kill_player(struct ObjectSlot *objectSlot) {
#ifdef DEBUG
    if (!noclip) player_death = TRUE;
#else
    player_death = TRUE;
#endif
    objectSlot->activated = TRUE;
}

const jmp_table routines_jump_table[] = {
    do_nothing,
    ship_portal,
    cube_portal,
    col_trigger,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    yellow_orb,
    yellow_pad,
    do_nothing,
    do_nothing,
    do_nothing,
    blue_gravity_portal,
    yellow_gravity_portal,
    blue_orb,
    blue_pad,
    pink_orb,
    pink_pad,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    ball_portal,
    do_nothing,
    mini_portal,
    big_portal,

    // Spikes
    
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,
    kill_player,

    // Saws

    kill_player,
    kill_player,
    kill_player,

    // Block and slab
    block,
    slab,

    mirror_portal,
    unmirror_portal,

    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,

    do_nothing,

    // Speeeeed
    speed_portal_half,
    speed_portal_1x,
    speed_portal_2x,
    speed_portal_3x,
    speed_portal_4x,

    ufo_portal,

    // Square deco   
    do_nothing,
    do_nothing,
    do_nothing,
};

// In pixels
#define Object_Hitbox_Rectangle(name, hw, hh, hxoff, hyoff, center_x, center_y) {hw, hh, hxoff, hyoff, center_x, center_y},
#define Object_Hitbox_Circle(name, is_saw, radius, hxoff, hyoff, center_x, center_y) {0x8000 | is_saw, radius, hxoff, hyoff, center_x, center_y},

const s16 obj_hitbox[][6] = {
    Object_Hitbox_Rectangle("NONE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("SHIP_PORTAL", 20, 46, -2, -15, 8, 8)
    Object_Hitbox_Rectangle("CUBE_PORTAL", 20, 46, -2, -15, 8, 8)
    Object_Hitbox_Rectangle("COL_TRIGGER", 16, 16, 0, 0, 8, 8)
    Object_Hitbox_Rectangle("BIG_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("MEDIUM_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("SMALL_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("TINY_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("BG_CHAIN", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("YELLOW_ORB", 20, 20, -2, -2, 8, 8)
    Object_Hitbox_Rectangle("YELLOW_PAD", 14, 2, 1, 14, 8, 8)
    Object_Hitbox_Rectangle("MEDIUM_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("SMALL_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("LARGE_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("BLUE_GRAVITY_PORTAL", 14, 40, 1, -12, 8, 8)
    Object_Hitbox_Rectangle("YELLOW_GRAVITY_PORTAL", 14, 40, 1, -12, 8, 8)
    Object_Hitbox_Rectangle("BLUE_ORB", 20, 20, -2, -2, 8, 8)
    Object_Hitbox_Rectangle("BLUE_PAD", 14, 2, 1, 14, 8, 8)
    Object_Hitbox_Rectangle("PINK_ORB", 20, 20, -2, -2, 8, 8)
    Object_Hitbox_Rectangle("PINK_PAD", 14, 2, 1, 14, 8, 8)
    Object_Hitbox_Rectangle("PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("PULSING_CIRCUNFERENCE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("PULSING_DIAMOND", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("PULSING_STAR", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("BIG_BG_CLOUDS", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("SMALL_BG_CLOUDS", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("BALL_PORTAL", 20, 46, -2, -15, 8, 8)
    Object_Hitbox_Rectangle("PULSING_SQUARE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("MINI_PORTAL", 16, 48, 0, -16, 8, 8)
    Object_Hitbox_Rectangle("BIG_PORTAL",  16, 48, 0, -16, 8, 8)

    Object_Hitbox_Rectangle("SPIKE_V", 2, 6, 7, 5, 8, 8)
    Object_Hitbox_Rectangle("SPIKE_H", 6, 2, 5, 7, 8, 8)
    Object_Hitbox_Rectangle("HALF_SPIKE_V", 4, 3, 6, 12, 8, 8)
    Object_Hitbox_Rectangle("HALF_SPIKE_H", 3, 4, 2, 6, 8, 8)
    Object_Hitbox_Rectangle("MEDIUM_SPIKE_V", 2, 4, 7, 9, 8, 8)
    Object_Hitbox_Rectangle("MEDIUM_SPIKE_H", 4, 2, 2, 7, 8, 8)
    Object_Hitbox_Rectangle("GROUND_SPIKE_V", 4, 3, 6, 12, 8, 8)
    Object_Hitbox_Rectangle("GROUND_SPIKE_H", 3, 4, 2, 6, 8, 8)
    Object_Hitbox_Rectangle("GROUND_WAVY_SPIKE_V", 4, 3, 6, 12, 8, 8)
    Object_Hitbox_Rectangle("GROUND_WAVY_SPIKE_H", 3, 4, 2, 6, 8, 8)

    Object_Hitbox_Circle("SAW_BIG", TRUE, 16, 0, 0, 8, 8)
    Object_Hitbox_Circle("SAW_MEDIUM", TRUE, 12, 0, 0, 8, 8)
    Object_Hitbox_Circle("SAW_SMALL", TRUE, 7, 0, 0, 8, 8)

    Object_Hitbox_Rectangle("BASIC_BLOCK", 16, 16, 0, 0, 8, 8)
    Object_Hitbox_Rectangle("BASIC_SLAB", 16, 8, 0, 0, 8, 8)
    
    Object_Hitbox_Rectangle("ORANGE_MIRROR_PORTAL", 26, 48, -3, -16, 8, 8)
    Object_Hitbox_Rectangle("BLUE_MIRROR_PORTAL"  , 26, 48, -3, -16, 8, 8)
    
    Object_Hitbox_Circle("SAW_DECO_BIG", TRUE, 0, 0, 0, 0, 0)
    Object_Hitbox_Circle("SAW_DECO_MEDIUM", TRUE, 0, 0, 0, 0, 0)
    Object_Hitbox_Circle("SAW_DECO_SMALL", TRUE, 0, 0, 0, 0, 0)
    Object_Hitbox_Circle("SAW_DECO_TINY", TRUE, 0, 0, 0, 0, 0)

    Object_Hitbox_Rectangle("PULSING_NOTE", 0, 0, 0, 0, 0, 0)

    Object_Hitbox_Rectangle("SPEED_PORTAL_HALF", 18, 24, -1, -4,  8, 8)
    Object_Hitbox_Rectangle("SPEED_PORTAL_1x", 16, 30, 0, -7, 8, 8)
    Object_Hitbox_Rectangle("SPEED_PORTAL_2x",  28, 30, -6, -7, 8, 8)
    Object_Hitbox_Rectangle("SPEED_PORTAL_3x",  34, 30, -9, -7, 8, 8)
    Object_Hitbox_Rectangle("SPEED_PORTAL_4x",  36, 30, -10, -7, 8, 8)

    Object_Hitbox_Rectangle("UFO_PORTAL", 20, 46, -2, -15, 8, 8)

    
    Object_Hitbox_Rectangle("BIG_BG_SQUARES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("MEDIUM_BG_SQUARES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox_Rectangle("SMALL_BG_SQUARES", 0, 0, 0, 0, 0, 0)
};

#undef Object_Hitbox