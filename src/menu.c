#include <tonc.h>
#include "main.h"
#include "menu.h"
#include "tonc_tte.h"
#include "pusab.h"

u16 game_state;
u16 loaded_level_id;

void menu_loop() {
    // Init OAM and VRAM
    oam_init(shadow_oam, 128);
    memcpy16(palette_buffer, menu_palette, sizeof(menu_palette) / sizeof(COLOR));
    
    memcpy32(pal_bg_mem, palette_buffer, 256);

    tte_init_se(
        0,                      // Background number (BG 0)
        BG_CBB(0) | BG_SBB(31), // BG control (for REG_BGxCNT)
        0,                      // Tile offset (special cattr)
        CLR_WHITE,              // Ink color
        0,                      // BitUnpack offset (on-pixel = 15)
        &pusabFont,             // Default font (sys8)
        NULL);                  // Default renderer (se_drawg_s)

        
    
    tte_set_pos(8,136);
    tte_write("PRESS L R TO CHANGE LEVEL");
    tte_set_pos(8,144);
    tte_write("PRESS A TO START");

    tte_set_pos(8,8);
    tte_write((char *) level_names[loaded_level_id]);
    while (1) {
        key_poll();
        tte_set_pos(8,8);

        if (key_hit(KEY_RIGHT)) {
            if (loaded_level_id == sizeof(loaded_level_id) - 1) {
                loaded_level_id = 0;
            } else {   
                loaded_level_id++;
            }
            tte_erase_line();
            tte_write((char *) level_names[loaded_level_id]);
        }
        if (key_hit(KEY_LEFT)) {
            if (loaded_level_id == 0) {
                loaded_level_id = sizeof(loaded_level_id) - 1;
            } else {   
                loaded_level_id--;
            }
            tte_erase_line();
            tte_write((char *) level_names[loaded_level_id]);
        }

        if (key_hit(KEY_A | KEY_START)) {
            game_state = STATE_PLAYING;
            break;
        }

        // Wait for VSYNC
        VBlankIntrWait();
    }
}