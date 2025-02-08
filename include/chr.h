#include <tonc.h>
#include "../graphics/includes.h"

#define NUM_PORTAL_PALETTES 6
#define START_OF_OBJECT_CHR 8

#define PARTICLE_VRAM_ID 1024-4
#define COIN_VRAM_ID 1024-48
#define COIN_OFFSET 0x40

extern const COLOR blockPalette[256];
extern const COLOR spritePalette[256];
extern const COLOR menu_palette[64];
extern const COLOR menu_spr_palette[48];
extern const COLOR black_buffer[512];
extern const SCR_ENTRY bg_tiles[1024];

void run_animated_sprites();
void deoccupy_chr_slots();
void load_chr_in_buffer();
void unload_chr_in_buffer();
ARM_CODE void flip_player_colors(u8 *dst, u8 *src, u8 tile_num);
ARM_CODE u32 obtain_flipped_pixel(u32 pixel);