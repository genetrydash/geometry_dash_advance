#include <tonc.h>
#include "main.h"
#include "memory.h"

uint scroll_x = 0, scroll_y = 0;
uint scroll_x_for_decompression;
char scroll_x_dir = 0;
char scroll_y_dir = 0;

int value;
int length;

int seam_x, seam_y;

void screen_scroll_load();
void decompress_column();
void scroll_H();

int main() {
    // Enable BG 1 and 2
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(16) | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(1) | BG_SBB(18) | BG_REG_64x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;


    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[4][0], test_pngTiles, test_pngTilesLen / sizeof(u32));
    memcpy32(&tile_mem[0][0], metatiles_pngTiles, metatiles_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, test_pngPal, test_pngPalLen / sizeof(u16));
	memcpy16(pal_bg_mem, metatiles_pngPal, metatiles_pngPalLen / sizeof(u16));

    level_pointer = (u16*) &cantletgo_level_data;

    seam_x = scroll_x;
    seam_y = scroll_y;

    // Set RLE initial values
    value = *level_pointer;
    level_pointer++;
    length = *level_pointer;
    level_pointer++;

    curr_level_height = CANTLETGO_LEVEL_HEIGHT;

    for (int i = 0; i < 16; i++) {
        decompress_column();
        for (int j = 0; j < 4; j++) {
            scroll_H();
            seam_x += 4;
        }
    }

    scroll_x_for_decompression = 0;

	while(1) {
        // Wait for VSYNC
        vid_vsync();
        key_poll();

        nextSpr = 0;

        // Copy OAM buffer into OAM
        oam_copy(oam_mem, shadow_oam, 128);
        scroll_x += key_tri_horz();
		scroll_y += key_tri_vert();

        scroll_x_dir = (key_tri_horz() == 1 ? 1 : 0);
        scroll_y_dir = (key_tri_vert() == 1 ? 1 : 0);

		REG_BG0HOFS = scroll_x;
		REG_BG0VOFS = scroll_y;

        screen_scroll_load();
        
        oam_metaspr(30,30, testSpr); // Test sprite
    }

    return 0;
}

#define SSB_MAP_WIDTH CANTLETGO_LEVEL_WIDTH

#define SSB_WIDTH 16
#define SSB_HEIGHT 16
#define SSB_SIZE SSB_WIDTH * SSB_HEIGHT

#define SSB_HOR_SIZE SSB_MAP_WIDTH * SSB_SIZE

void scroll_H() {
    for (int i = 0; i < 12; i += 1) {
        for (int j = 0; j < 2; j++) {
            int metatile_x = (seam_x >> 4) & 0x1f;
            int metatile_y = (seam_y >> 4);

            int metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];

            int x = (seam_x >> 3) & 0x1f;
            int y = (seam_y >> 3) & 0x1f;
            int tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_y += 8;
        }
    }   
}

void scroll_V() {
    for (int i = 0; i < 16; i += 1) {
        for (int j = 0; j < 2; j++) {
            int metatile_x = (seam_x >> 4) & 0x1f;
            int metatile_y = (seam_y >> 4);

            int metatile = level_buffer[metatile_x + (metatile_y * LEVEL_BUFFER_WIDTH)];
            
            int x = (seam_x >> 3) & 0x1f;
            int y = (seam_y >> 3) & 0x1f;
            int tile = metatiles_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
    if (scroll_x_for_decompression < (scroll_x & 0xfffffff0)) {
        decompress_column();
        scroll_x_for_decompression += 16;
    } 
    if (scroll_x_dir) {
        seam_x = scroll_x + SCREEN_WIDTH;
        seam_y = scroll_y;
        
        scroll_H();
    } else {
        seam_x = scroll_x - 8;
        seam_y = scroll_y;
        
        scroll_H();
    }

    if (scroll_y_dir) {
        seam_x = scroll_x;
        seam_y = scroll_y + SCREEN_HEIGHT;
        
        scroll_V();
    } else {
        seam_x = scroll_x;
        seam_y = scroll_y - 8;
        
        scroll_V();
    }
}

void decompress_column() {
    for (int i = 0; i < curr_level_height; i++) {
        if (length == 0) {
            value = *level_pointer;
            level_pointer++;
            length = *level_pointer;
            level_pointer++;
        }

        level_buffer[curr_column + (i * LEVEL_BUFFER_WIDTH)] = value;
        length--;
        
    }
    curr_column++;
    if (curr_column >= LEVEL_BUFFER_WIDTH) curr_column = 0;
}