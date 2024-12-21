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
        u32 channel = col_trigger.attrib1 & 0x7;
        
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
        col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = col_trigger.attrib2;
        col_trigger_buffer[channel][COL_TRIG_BUFF_TOTAL_FRAMES] = frames; // Total frames
        col_trigger_buffer[channel][COL_TRIG_BUFF_CURRENT_FRAMES] = 0;      // Current frame

        // Deoccupy slot
        objectSlot->occupied = FALSE;
    }
}

void do_nothing(UNUSED struct ObjectSlot *objectSlot) {
    // No routine defined
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
};