#include <tonc.h>
#include "main.h"

int scroll_x = 0, scroll_y = 0;
char scroll_x_dir = 0;
char scroll_y_dir = 0;

void screen_scroll_load();

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
    memcpy32(&tile_mem[0][0], test_map_pngTiles, test_map_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, test_pngPal, test_pngPalLen / sizeof(u16));
	memcpy16(pal_bg_mem, test_map_pngPal, test_map_pngPalLen / sizeof(u16));
	memcpy32(&se_mem[16][0], test_map_pngMetaTiles, test_map_pngMetaTilesLen / sizeof(u32));
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

#define SSB_MAP_WIDTH 57

#define SSB_WIDTH 16
#define SSB_HEIGHT 16
#define SSB_SIZE SSB_WIDTH * SSB_HEIGHT

#define SSB_HOR_SIZE SSB_MAP_WIDTH * SSB_SIZE

int seam_x, seam_y;

void scroll_H() {
    for (int i = 0; i < 16; i += 1) {
        for (int j = 0; j < 2; j++) {
            int metatile_x = (seam_x >> 4) & 0xf;
            int metatile_y = (seam_y >> 4) & 0xf;

            int metatile = test_map_pngMetaMap[metatile_x + (metatile_y * SSB_WIDTH) + (SSB_SIZE * (seam_x >> 8)) + (SSB_HOR_SIZE * (seam_y >> 8))];

            int x = (seam_x >> 3) & 0x1f;
            int y = (seam_y >> 3) & 0x1f;
            int tile = test_map_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_y += 8;
        }
    }   
}

void scroll_V() {
    for (int i = 0; i < 16; i += 1) {
        for (int j = 0; j < 2; j++) {
            int metatile_x = (seam_x >> 4) & 0xf;
            int metatile_y = (seam_y >> 4) & 0xf;

            int metatile = test_map_pngMetaMap[metatile_x + (metatile_y * SSB_WIDTH) + (SSB_SIZE * (seam_x >> 8)) + (SSB_HOR_SIZE * (seam_y >> 8))];
            
            int x = (seam_x >> 3) & 0x1f;
            int y = (seam_y >> 3) & 0x1f;
            int tile = test_map_pngMetaTiles[(metatile << 2) | (x & 1) | ((y & 1) << 1)];

            se_plot(&se_mem[16][0], x, y, tile);
            seam_x += 8;
        }
    }
}

void screen_scroll_load() {
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