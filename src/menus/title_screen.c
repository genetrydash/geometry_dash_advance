#include <tonc.h>
#include "main.h"
#include "level_select.h"
#include "tonc_tte.h"
#include "pusab.h"
#include "posprintf.h"
#include <maxmod.h>
#include "soundbank.bin.h"
#include "soundbank.h"
#include "physics_defines.h"
#include <string.h>
#include <ctype.h>
#include "color.h"

EWRAM_DATA u32 title_screen_color_index = 0;
EWRAM_DATA u16 title_screen_color_transition_backup[6];
void title_screen_loop() {
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(26) | BG_REG_32x32 | BG_PRIO(0);
    REG_BG0HOFS = 8;
    REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(27) | BG_REG_32x32 | BG_PRIO(1);
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(0) | BG_SBB(28) | BG_REG_32x32 | BG_PRIO(2);
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 96;

    memset32(palette_buffer, 0, 256);
    memcpy16(palette_buffer, menu_palette, sizeof(menu_palette) / sizeof(COLOR));
    palette_buffer[0x24] = palette_buffer[0];

    memcpy32(&tile_mem[0][0], square_background_chr, sizeof(square_background_chr) / 8);
    memcpy32(&tile_mem[0][256], title_screen_chr, sizeof(title_screen_chr) / 8);
    memcpy32(&se_mem[26][0], title_screen_l0_tilemap, sizeof(title_screen_l0_tilemap) / sizeof(u32));
    memcpy32(&se_mem[27][0], title_screen_l1_tilemap, sizeof(title_screen_l1_tilemap) / sizeof(u32));
    memcpy32(&se_mem[28][0], square_background_tilemap, sizeof(square_background_tilemap) / sizeof(u32));
    
    // Restore bg color
    memcpy16(&col_trigger_buffer[0], title_screen_color_transition_backup, 6);
    do_menu_color_transition();

    scroll_x = 0;

    fade_in();
    while (1) {
        key_poll();
    
        REG_BG1HOFS = scroll_x >> SUBPIXEL_BITS;
        REG_BG2HOFS = scroll_x >> (2+SUBPIXEL_BITS);

        // Level select
        if (key_hit(KEY_A)) {
            game_state = STATE_LEVEL_SELECT;
            break;
        }
        
        // Sound test
        if (key_hit(KEY_SELECT)) {
            game_state = STATE_SOUND_TEST;
            break;
        }

        // Do scroll
        scroll_x += SPEED_1x;

        do_menu_color_transition();
        
        // Copy palette from buffer
        memcpy32(pal_bg_mem, palette_buffer, 256);

        // If the current transition ended, start a new one to the next color
        if (!col_trigger_buffer[0][COL_TRIG_BUFF_ACTIVE]) {
            col_trigger_buffer[0][COL_TRIG_BUFF_ACTIVE] = TRUE;
            col_trigger_buffer[0][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[BG_COLOR];
            col_trigger_buffer[0][COL_TRIG_BUFF_NEW_COLOR] = menu_bg_colors[title_screen_color_index % (sizeof(menu_bg_colors) / sizeof(COLOR))];
            col_trigger_buffer[0][COL_TRIG_BUFF_TOTAL_FRAMES] = 240;
            col_trigger_buffer[0][COL_TRIG_BUFF_CURRENT_FRAMES] = 0;
            title_screen_color_index++;
        }

        // Wait for VSYNC
        VBlankIntrWait();
    }
    
    memcpy16(title_screen_color_transition_backup, &col_trigger_buffer[0], 6);
    fade_out();
}