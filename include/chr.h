#include <tonc.h>
#include "../graphics/includes.h"

#define NUM_PORTAL_PALETTES 6
#define START_OF_OBJECT_CHR 8
#define PARTICLE_OFFSET 1020

extern const COLOR blockPalette[96];
extern const COLOR spritePalette[256];
extern const COLOR menu_palette[48];
extern const COLOR black_buffer[512];
extern const SCR_ENTRY bg_tiles[1024];

void run_particles();
void deoccupy_chr_slots();
void load_chr_in_buffer();
void unload_chr_in_buffer();