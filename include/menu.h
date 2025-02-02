#include <tonc.h>

#pragma once

extern u16 game_state;
extern u16 loaded_level_id;

enum GameState {
    STATE_MENU,
    STATE_PLAYING
};

enum MenuDirection {
    MENU_LEFT,
    MENU_RIGHT,
};

void put_star_number(u16 level_id);
void put_coin_sprites(u16 level_id);
void menu_loop();