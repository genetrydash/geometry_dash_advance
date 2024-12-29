#include <tonc.h>
#include "main.h"
#include "memory.h"

#define CENTER(x,y) ((x & 0xff) << 8) | (y & 0xff)

// Next sprite slot in OAM
u8 nextSpr = 0;

const u16 debugModeSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_ID(330),
    0,
    0,
    0,
    0xffff
};

// Player

const u16 playerSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | 0,
    0,
    0,
    CENTER(8, 8),
    0xffff
};

const u16 shipSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_ID(2),
    0,
    0,
    CENTER(8, 8),
    0xffff
};

const u16 shipFlippedSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_ID(4),
    0,
    0,
    CENTER(8, 8),
    0xffff
};

const u16 ballSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_ID(6),
    0,
    0,
    CENTER(8, 8),
    0xffff
};

// Portals

const u16 cubePortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(2) | ATTR2_ID(64),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

const u16 shipPortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(1) | ATTR2_ID(64),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

const u16 ballPortalSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(5) | ATTR2_ID(64),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

const u16 gravityPortalBlueSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(3) | ATTR2_ID(80),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

const u16 gravityPortalYellowSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(4) | ATTR2_ID(80),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

const u16 sizePortalPinkSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(1) | ATTR2_ID(84),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};


const u16 sizePortalGreenSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_32x64,
    ATTR2_PALBANK(2) | ATTR2_ID(84),
    -8, // x
    -24, // y
    CENTER(8, 8),
    0xffff
};

// Orbs and pads

const u16 yellowOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(172),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

const u16 yellowPadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_ID(288),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

const u16 blueOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(2) | ATTR2_ID(172),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

const u16 bluePadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2) | ATTR2_ID(288),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

const u16 pinkOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(3) | ATTR2_ID(172),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

const u16 pinkPadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(3) | ATTR2_ID(288),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff
};

// Deco 

const u16 bigBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_ID(68) | ATTR2_PRIO(1),
    -24,   // x
    -10,   // y
    CENTER(8, 8),
    0xffff
};

const u16 mediumBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_ID(196) | ATTR2_PRIO(1),
    -24, // x
    -10, // y
    CENTER(8, 8),
    0xffff
};

const u16 smallBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(0) | ATTR2_ID(76) | ATTR2_PRIO(1),
    -8, // x
    0,  // y
    CENTER(8, 8),
    0xffff
};

const u16 tinyBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(0) | ATTR2_ID(140) | ATTR2_PRIO(1),
    0, // x
    6, // y
    CENTER(8, 8),
    0xffff
};

const u16 bigBgCloudSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_ID(304) | ATTR2_PRIO(1),
    -24,   // x
    -10,   // y
    CENTER(8, 8),
    0xffff
};

const u16 smallBgCloudSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(0) | ATTR2_ID(326) | ATTR2_PRIO(1),
    -8, // x
    0,  // y
    CENTER(8, 8),
    0xffff
};

const u16 bgChainsSpr[] = {
    ATTR0_4BPP | ATTR0_TALL | ATTR0_BLEND,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(0) | ATTR2_ID(142) | ATTR2_PRIO(1),
    0,   // x
    -16, // y
    CENTER(8, 8),
    0xffff
};

const u16 largePulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(270),
    0, // x
    -16, // y
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(1) | ATTR2_ID(236),
    0, // x
    -8, // y
    CENTER(8, 8),

    0xffff
};
const u16 mediumPulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(270),
    0,  // x
    -8, // y
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_ID(268),
    0, // x
    0, // y
    CENTER(8, 8),

    0xffff
};
const u16 smallPulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(270),
    0, // x
    0, // y
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(1) | ATTR2_ID(300),
    0, // x
    8, // y
    CENTER(8, 8),
    0xffff
};

const u16 circlePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(334),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 circunferencePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(270),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 diamondPulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(324),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 starPulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(330),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 squarePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_ID(322),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

// Spikes
const u16 spike_V[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_ID(384),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 spike_H[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_ID(386),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 halfSpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_ID(388),
    0, // x
    8, // y
    CENTER(8, 8),
    0xffff,
};

const u16 halfSpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_ID(390),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 mediumSpike_V[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_ID(392),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 mediumSpike_H[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_ID(394),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 groundSpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_ID(420),
    0, // x
    8, // y
    CENTER(8, 8),
    0xffff,
};

const u16 groundSpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_ID(391),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
};

const u16 groundWavySpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_ID(352),
    0, // x
    8, // y
    CENTER(8, 8),
    0xffff,
};

const u16 groundWavySpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_ID(396),
    0, // x
    0, // y
    CENTER(8, 8),
    0xffff,
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
    yellowOrbSpr,
    yellowPadSpr,
    mediumPulsingCircleSpr,
    smallPulsingCircleSpr,
    largePulsingCircleSpr,
    gravityPortalBlueSpr,
    gravityPortalYellowSpr,
    blueOrbSpr,
    bluePadSpr,
    pinkOrbSpr,
    pinkPadSpr,
    circlePulsingSpr,
    circunferencePulsingSpr,
    diamondPulsingSpr,
    starPulsingSpr,
    bigBgCloudSpr,
    smallBgCloudSpr,
    ballPortalSpr,
    squarePulsingSpr,
    sizePortalPinkSpr,
    sizePortalGreenSpr,

    // Spikes
    spike_V,
    spike_H,
    halfSpike_V,
    halfSpike_H,
    mediumSpike_V,
    mediumSpike_H,
    groundSpike_V,
    groundSpike_H,
    groundWavySpike_V,
    groundWavySpike_H,
};

const u8 spr_width_height_table[] = {
    0x08, 0x08, // 8x8
    0x10, 0x10, // 16x16
    0x20, 0x20, // 32x32
    0x40, 0x40, // 64x64

    0x10, 0x08, // 16x8
    0x20, 0x08, // 32x8
    0x20, 0x10, // 32x16
    0x40, 0x20, // 64x32

    0x08, 0x10, // 8x16
    0x08, 0x20, // 8x32
    0x10, 0x20, // 16x32
    0x20, 0x40, // 32x64
};

void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip) {
    u32 i = 0;
    // Continue until end of data
    while (data[i] != 0xffff && nextSpr < 128) {
        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
            data[i],                                           // ATTR0
            data[i + 1] ^ ((data[i] & ATTR0_AFF) ? 0 : ATTR1_FLIP(hflip | (vflip << 1))),    // ATTR1
            data[i + 2]);                                      // ATTR2
        
        u8 wh_index = ((data[i] & ATTR0_SHAPE_MASK) >> 12) | ((data[i + 1] & ATTR1_SIZE_MASK) >> 14);
        
        u8 width = spr_width_height_table[wh_index << 1];
        u8 height = spr_width_height_table[(wh_index << 1) + 1];
        
        s16 offset_x = data[i + 3];
        s16 offset_y = data[i + 4];
        s8 center_x = data[i + 5] >> 8;
        s8 center_y = data[i + 5] & 0xff;

        if (hflip) {
            offset_x = center_x - (offset_x - center_x + width); 
        }

        if (vflip) {
            offset_y = center_y - (offset_y - center_y + height); 
        }

        // Set position
        obj_set_pos(newSpr, x + offset_x, y + offset_y);
        
        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 6 words
        i += 6;
    }
}
void oam_affine_metaspr(u16 x, u8 y, const u16 *data, u16 rotation, u8 aff_id) {
    u32 i = 0;
    // Continue until end of data
    while (data[i] != 0xffff && nextSpr < 128) {
        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
            data[i] | ATTR0_AFF | ATTR0_AFF_DBL,                                     // ATTR0
            (data[i + 1] | ((data[i+1] & ATTR1_AFF_ID_MASK) ? 0 : ATTR1_AFF_ID(aff_id))), // ATTR1
            data[i + 2]);                                                            // ATTR2

        u8 wh_index = ((data[i] & ATTR0_SHAPE_MASK) >> 12) | ((data[i + 1] & ATTR1_SIZE_MASK) >> 14);

        u8 width = spr_width_height_table[wh_index << 1];
        u8 height = spr_width_height_table[(wh_index << 1) + 1];
        
        s16 offset_x = data[i + 3];
        s16 offset_y = data[i + 4];
        s8 center_x = data[i + 5] >> 8;
        s8 center_y = data[i + 5] & 0xff;

        // Trigonometric functions give a 20:12 fixed value
        s32 sin_theta = lu_sin(rotation); 
        s32 cos_theta = lu_cos(rotation);

        s32 relative_x = offset_x - center_x;
        s32 relative_y = offset_y - center_y;

        s32 relative_x_centered = relative_x + (width >> 1);
        s32 relative_y_centered = relative_y + (height >> 1);
        
        // Divide by 4096 to get back to pixels
        s32 rotated_x = ((s64)(relative_x_centered * cos_theta) - (s64)(relative_y_centered * sin_theta)) / 4096;
        s32 rotated_y = ((s64)(relative_y_centered * cos_theta) + (s64)(relative_x_centered * sin_theta)) / 4096;
        
        s32 total_x = x + (center_x - (width >> 1)) + rotated_x - (width >> 1);
        s32 total_y = y + (center_y - (height >> 1)) + rotated_y - (height >> 1);
        
        // Set position
        obj_set_pos(newSpr, total_x, total_y);
        
        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 6 words
        i += 6;
    }
}