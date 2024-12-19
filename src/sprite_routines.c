#include "main.h"
#include "sprite_loading.h"
#include "sprite_routines.h"
#include "color.h"

void ship_portal(struct ObjectSlot *objectSlot) {
    gamemode = SHIP;
    objectSlot->activated = TRUE;
}

void cube_portal(struct ObjectSlot *objectSlot) {
    gamemode = CUBE;
    objectSlot->activated = TRUE;
}

void col_trigger(struct ObjectSlot *objectSlot) {
    struct Object col_trigger = objectSlot->object;
    
    // If the player is right of the horizontal center of the trigger, activate the color trigger
    if ((player_x >> 8) >= (col_trigger.x + 8)) {
        u32 frames = (col_trigger.attrib1 >> 3) + 1; // +1 because 0 = 1
        u32 curr_frame = col_trigger.attrib4;
        u32 channel = col_trigger.attrib1 & 0x7;
        
        // Save color on attrib3 depending on color channel, only if we are on the first frame
        if (curr_frame == 0) {
            switch (channel) {
                case BG:
                    col_trigger.attrib3 = palette_buffer[0x00];        // Temp storage for old BG color
                    break;
                case GROUND:
                    col_trigger.attrib3 = palette_buffer[0x41];        // Temp storage for old GROUND color
                    break;
                case OBJ:
                    col_trigger.attrib3 = palette_buffer[0x09];        // Temp storage for old OBJ color
                    break;
                case LINE:
                    col_trigger.attrib3 = palette_buffer[0x48];
                    break;
                case COL1:
                case COL2:
                case COL3:
                case COL4:
                    col_trigger.attrib3 = palette_buffer[0x0D + (channel << 4)];
                    break;

            }
        }

        // Get old and new color
        COLOR new_color = col_trigger.attrib2;
        COLOR old_color = col_trigger.attrib3;
        COLOR lerped_color;

        // Calculate lerped color. If the value is less than 2, then it is an instant color change
        if (frames > 1) {
            u16 lerp_value = (curr_frame << 8) / (frames - 1); // Division, scary stuff
            lerped_color = lerp_color(old_color, new_color, lerp_value);
        } else {
            lerped_color = new_color;
        } 

        // Run code depending on which channel
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

        // If there are frames left, increment frame counter. If not, deoccupy the object slot
        if (frames > curr_frame) {
            col_trigger.attrib4++;
        } else {
            objectSlot->occupied = FALSE;
        }

        // Update object
        objectSlot->object = col_trigger;
    }
}

void do_nothing(UNUSED struct ObjectSlot *objectSlot) {
    // No routine defined
}

const jmp_table routines_jump_table[] = {
    do_nothing,
    ship_portal,
    cube_portal,
    col_trigger
};