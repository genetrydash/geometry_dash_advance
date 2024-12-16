#include <tonc.h>
#include "main.h"
#include "memory.h"

// Next sprite slot in OAM
u8 nextSpr = 0;

const u16 playerSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | 0,
    0,
    0xffff
};

const u16 shipSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | 4,
    0,
    0xffff
};

const u16 *obj_sprites[] = {
    playerSpr,
    shipSpr
};

// TODO: figure out affine sprites
void oam_metaspr(u16 x, u8 y, const u16 *data) {
    u32 i = 0;
    // Continue until end of data
    while (data[i] != 0xffff && i < 128) {
        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
        data[i],              // ATTR0
        data[i + 1],          // ATTR1
        data[i + 2]);         // ATTR2

        // Set position
        obj_set_pos(newSpr, x + (data[i + 1] & 0x1ff), y + (data[i] & 0xff));
        
        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 4 words
        i += 4;
    }
}