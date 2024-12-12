#include <tonc.h>
#include "main.h"

int main() {
    // Enable BG 1 and 2
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG1 | DCNT_BG2;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(16) | BG_REG_64x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(1) | BG_SBB(18) | BG_REG_64x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;


    oam_init(shadow_oam, 128);
    memcpy32(&tile_mem[4][0], test_pngTiles, test_pngTilesLen / sizeof(u32));
	memcpy16(pal_obj_mem, test_pngPal, test_pngPalLen / sizeof(u16));

	while(1) {
        // Wait for VSYNC
        vid_vsync();
        key_poll();

        nextSpr = 0;

        // Copy OAM buffer into OAM
        oam_copy(oam_mem, shadow_oam, 128);
        
        oam_metaspr(30,30, testSpr); // Test sprite
    }

    return 0;
}