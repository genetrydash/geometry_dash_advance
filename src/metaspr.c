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
    0, // y v_flipped
    0xffff
};

const u16 shipSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_ID(2),
    0,
    0,
    0, // y v_flipped
    0xffff
};

const u16 shipPortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(1) | ATTR2_ID(64),
    -8, // x
    -8, // y
    -8, // y v_flipped
    0xffff
};

const u16 cubePortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(2) | ATTR2_ID(64),
    -8, // x
    -8, // y
    -8, // y v_flipped
    0xffff
};
const u16 bigBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_ID(68) | ATTR2_PRIO(1),
    -24,   // x
    -10,   // y
    -2,    // y v_flipped
    0xffff
};

const u16 mediumBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_ID(196) | ATTR2_PRIO(1),
    -24, // x
    -10, // y
    -10, // y v_flipped
    0xffff
};

const u16 smallBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(0) | ATTR2_ID(76) | ATTR2_PRIO(1),
    -8, // x
    0, // y
    0, // y v_flipped
    0xffff
};

const u16 tinyBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(0) | ATTR2_ID(140) | ATTR2_PRIO(1),
    0, // x
    6, // y
    4, // y v_flipped
    0xffff
};

const u16 bgChainsSpr[] = {
    ATTR0_4BPP | ATTR0_TALL | ATTR0_BLEND,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(0) | ATTR2_ID(142) | ATTR2_PRIO(1),
    0, // x
    -16, // y
    0, // y v_flipped
    0xffff
};

const u16 *obj_sprites[] = {
    NULL,
    shipPortalSpr,
    cubePortalSpr,
    NULL, // COL TRIGGER
    bigBgSpikesSpr,
    mediumBgSpikesSpr,
    smallBgSpikesSpr,
    tinyBgSpikesSpr,
    bgChainsSpr,
};

// In pixels
#define Object_Hitbox(name, hw, hh, hxoff, hyoff) {hw, hh, hxoff, hyoff},

const s16 obj_hitbox[][4] = {
    Object_Hitbox("NONE", 0, 0, 0, 0)
    Object_Hitbox("SHIP_PORTAL", 18, 46, -2, 1)
    Object_Hitbox("CUBE_PORTAL", 18, 46, -2, 1)
    Object_Hitbox("COL_TRIGGER", 0, 0, 0, 0)
};

void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip) {
    u32 i = 0;
    // Continue until end of data
    while (data[i] != 0xffff && nextSpr < 128) {
        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
        data[i],              // ATTR0
        data[i + 1] ^ ATTR1_FLIP(hflip | (vflip << 1)),          // ATTR1
        data[i + 2]);         // ATTR2

        // Set position
        obj_set_pos(newSpr, x + data[i + 3], y + (vflip ? data[i + 5] : data[i + 4]));
        
        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 5 words
        i += 6;
    }
}