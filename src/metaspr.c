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
    0,
    0xffff
};

const u16 shipSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_ID(4),
    0,
    0,
    0xffff
};

const u16 emptySpr[] = {
    0xffff
};

const u16 shipPortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(1) | ATTR2_ID(64),
    -8, // x
    -1, // y
    0xffff
};

const u16 cubePortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(2) | ATTR2_ID(64),
    -8, // x
    -1, // y
    0xffff
};

const u16 *obj_sprites[] = {
    emptySpr,
    shipPortalSpr,
    cubePortalSpr
};

// In pixels
#define Object_Hitbox(name, hw, hh, hxoff, hyoff) {hw, hh, hxoff, hyoff},

const s16 obj_hitbox[][4] = {
    Object_Hitbox("NONE", 0, 0, 0, 0)
    Object_Hitbox("SHIP_PORTAL", 18, 46, -2, 1)
    Object_Hitbox("CUBE_PORTAL", 18, 46, -2, 1)
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
        obj_set_pos(newSpr, x + data[i + 3], y + data[i + 4]);
        
        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 4 words
        i += 5;
    }
}