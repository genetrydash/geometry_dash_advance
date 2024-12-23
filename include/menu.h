#include <tonc.h>

#pragma once

extern u16 game_state;
extern u16 loaded_level_id;

enum GameState {
    STATE_MENU,
    STATE_PLAYING
};

void menu_loop();