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
    0, // id offset
    0,
    0xffff
};

// Player

const u16 playerSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_PRIO(1),
    0,
    0,
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 shipSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_PRIO(1),
    0,
    0,
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 ballSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF | ATTR0_AFF_DBL,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(0),
    ATTR2_PALBANK(0) | ATTR2_PRIO(1),
    0,
    0,
    0, // id offset
    CENTER(8, 8),
    0xffff
};

// Portals

const u16 cubePortalSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_32x32,
    ATTR2_PALBANK(2),
    -8, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(2),
    -8, // x
    16, // y
    32, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    -5, // x
    16,  // y
    8, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 shipPortalSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_32x32,
    ATTR2_PALBANK(1),
    -8, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(1),
    -8, // x
    16, // y
    32, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    -5, // x
    16,  // y
    8, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 ballPortalSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_32x32,
    ATTR2_PALBANK(5),
    -8, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(5),
    -8, // x
    16, // y
    32, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(5) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(5) | ATTR2_PRIO(1),
    -5, // x
    16,  // y
    8, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 gravityPortalBlueSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(3) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(3) | ATTR2_PRIO(1),
    -5, // x
    16, // y
    8, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(3),
    11, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(3),
    11, // x
    16, // y
    24, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 gravityPortalYellowSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(4) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(4) | ATTR2_PRIO(1),
    -5, // x
    16, // y
    8, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(4),
    11, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(4),
    11, // x
    16, // y
    24, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 sizePortalPinkSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    -5, // x
    16, // y
    8, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(1),
    11, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1),
    11, // x
    16, // y
    24, // id offset
    CENTER(8, 8),
    0xffff
};


const u16 sizePortalGreenSpr[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    -5, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    -5, // x
    16, // y
    8, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(2),
    11, // x
    -16, // y
    16, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2),
    11, // x
    16, // y
    24, // id offset
    CENTER(8, 8),
    0xffff
};

// Orbs and pads

const u16 yellowOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 yellowPadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_BLEND,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_ID(1020) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 blueOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 bluePadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_BLEND,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(2) | ATTR2_ID(1020) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 pinkOrbSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(3) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 pinkPadSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(3) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_BLEND,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(3) | ATTR2_ID(1020) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

// Deco 

const u16 bigBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    -24,   // x
    -10,   // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 mediumBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    -24, // x
    -10, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 smallBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    -8, // x
    0,  // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 tinyBgSpikesSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    0, // x
    6, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 bigBgCloudSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_64x32,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    -24,   // x
    -10,   // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 smallBgCloudSpr[] = {
    ATTR0_4BPP | ATTR0_WIDE | ATTR0_BLEND,
    ATTR1_SIZE_32x16,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    -8, // x
    0,  // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 bgChainsSpr[] = {
    ATTR0_4BPP | ATTR0_TALL | ATTR0_BLEND,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(0) | ATTR2_PRIO(2),
    0,   // x
    -16, // y
    0, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 largePulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    -16, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x32,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    -8, // y
    4, // id offset
    CENTER(8, 8),

    0xffff
};
const u16 mediumPulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0,  // x
    -8, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    6, // id offset
    CENTER(8, 8),

    0xffff
};
const u16 smallPulsingCircleSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    8, // y
    8, // id offset
    CENTER(8, 8),
    0xffff
};

const u16 circlePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 circunferencePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 diamondPulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 starPulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 squarePulsingSpr[] = {
    ATTR0_4BPP | ATTR0_SQUARE | ATTR0_AFF,
    ATTR1_SIZE_16x16 | ATTR1_AFF_ID(4),
    ATTR2_PALBANK(1) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

// Spikes
const u16 spike_V[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 spike_H[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 halfSpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    8, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 halfSpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 mediumSpike_V[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 mediumSpike_H[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 groundSpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    8, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 groundSpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 groundWavySpike_V[] = {
    ATTR0_4BPP | ATTR0_WIDE,
    ATTR1_SIZE_8x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    8, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 groundWavySpike_H[] = {
    ATTR0_4BPP | ATTR0_TALL,
    ATTR1_SIZE_16x8,
    ATTR2_PALBANK(15) | ATTR2_PRIO(1),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),
    0xffff,
};

const u16 sawBig[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_64x64,
    ATTR2_PALBANK(15) | ATTR2_PRIO(2),
    -24, // x
    -24, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 sawMedium[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_32x32,
    ATTR2_PALBANK(15) | ATTR2_PRIO(2),
    -8, // x
    -8, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

const u16 sawSmall[] = {
    ATTR0_4BPP | ATTR0_SQUARE,
    ATTR1_SIZE_16x16,
    ATTR2_PALBANK(15) | ATTR2_PRIO(2),
    0, // x
    0, // y
    0, // id offset
    CENTER(8, 8),

    0xffff
};

ROM_DATA const u16 *obj_sprites[] = {
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

    // Saws 
    sawBig,
    sawMedium,
    sawSmall
};

#define CHR_SLOT(name, rom, vram) {rom, vram},

const u32 obj_chr_offset[][2] = {
    CHR_SLOT("NONE", 0xffffffff,0)
    CHR_SLOT("SHIP_PORTAL", 0x00, 0x28)
    CHR_SLOT("CUBE_PORTAL", 0x00, 0x28)
    CHR_SLOT("COL_TRIGGER", 0xffffffff,0)

    CHR_SLOT("BIG_BG_SPIKES", 0x80, 0x20)
    CHR_SLOT("MEDIUM_BG_SPIKES", 0xa0, 0x20)
    CHR_SLOT("SMALL_BG_SPIKES", 0x70, 0x8)
    CHR_SLOT("TINY_BG_SPIKES", 0x78, 0x2)

    CHR_SLOT("BG_CHAIN", 0x100, 0x8)
    
    CHR_SLOT("YELLOW_ORB", 0x130, 0x4)
    CHR_SLOT("YELLOW_PAD", 0x140, 0x4)

    CHR_SLOT("MEDIUM_PULSING_CIRCLE", 0xf0, 0xc)
    CHR_SLOT("SMALL_PULSING_CIRCLE", 0xf0, 0xc)
    CHR_SLOT("LARGE_PULSING_CIRCLE", 0xf0, 0xc)

    CHR_SLOT("BLUE_GRAVITY_PORTAL", 0x30, 0x1c)
    CHR_SLOT("YELLOW_GRAVITY_PORTAL", 0x30, 0x1c)

    CHR_SLOT("BLUE_ORB", 0x130, 0x4)
    CHR_SLOT("BLUE_PAD", 0x140, 0x4)
    CHR_SLOT("PINK_ORB", 0x130, 0x4)
    CHR_SLOT("PINK_PAD", 0x140, 0x4)

    CHR_SLOT("PULSING_CIRCLE", 0x120, 0x4)
    CHR_SLOT("PULSING_CIRCUNFERENCE", 0xf0,  0xc)
    CHR_SLOT("PULSING_DIAMOND", 0x118, 0x4)
    CHR_SLOT("PULSING_STAR", 0x11c, 0x4)

    CHR_SLOT("BIG_BG_CLOUDS", 0xc0, 0x20)
    CHR_SLOT("SMALL_BG_CLOUDS", 0xe0, 0x8)

    CHR_SLOT("BALL_PORTAL", 0x00, 0x28)

    CHR_SLOT("PULSING_SQUARE", 0x114, 0x4)

    CHR_SLOT("MINI_PORTAL", 0x50, 0x20)
    CHR_SLOT("BIG_PORTAL", 0x50, 0x20)

    // Spikes

    CHR_SLOT("SPIKE_V", 0x160, 0x4)
    CHR_SLOT("SPIKE_H", 0x164, 0x4)
    CHR_SLOT("HALF_SPIKE_V", 0x154, 0x2)
    CHR_SLOT("HALF_SPIKE_H", 0x156, 0x2)
    CHR_SLOT("MEDIUM_SPIKE_V", 0x168, 0x4)
    CHR_SLOT("MEDIUM_SPIKE_H", 0x15c, 0x4)
    CHR_SLOT("GROUND_SPIKE_V", 0x152, 0x2)
    CHR_SLOT("GROUND_SPIKE_H", 0x158, 0x2)
    CHR_SLOT("GROUND_WAVY_SPIKE_V", 0x150, 0x2)
    CHR_SLOT("GROUND_WAVY_SPIKE_H", 0x15a, 0x2)

    // Saws

    CHR_SLOT("SAW_BIG", 0x190, 0x40)
    CHR_SLOT("SAW_MEDIUM", 0x180, 0x10)
    CHR_SLOT("SAW_SMALL", 0x170, 0x4)
};
#undef CHR_SLOT

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

ARM_CODE void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip, u16 tile_id) {
    u32 i = 0;
    u16 offset;
    // Continue until end of data
    while (data[i] != 0xffff && nextSpr < 128) {
        // Add offset
        offset = tile_id + data[i + 5];

        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
            data[i],                                           // ATTR0
            data[i + 1] ^ ((data[i] & ATTR0_AFF) ? 0 : ATTR1_FLIP(hflip | (vflip << 1))),    // ATTR1
            data[i + 2] | (data[i+2] & ATTR2_ID_MASK ? 0 : offset & 0x3ff));                                      // ATTR2
        
        u8 wh_index = ((data[i] & ATTR0_SHAPE_MASK) >> 12) | ((data[i + 1] & ATTR1_SIZE_MASK) >> 14);
        
        u8 width = spr_width_height_table[wh_index << 1];
        u8 height = spr_width_height_table[(wh_index << 1) + 1];
        
        s16 offset_x = data[i + 3];
        s16 offset_y = data[i + 4];
        s8 center_x = data[i + 6] >> 8;
        s8 center_y = data[i + 6] & 0xff;

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
        // Also increment sprite index by 7 words
        i += 7;
    }
}
ARM_CODE void oam_affine_metaspr(u16 x, u8 y, const u16 *data, u16 rotation, u8 aff_id, u8 dbl, u16 tile_id) {
    u32 i = 0;
    u16 offset;
    // Continue until end of data
    while (data[i] != 0xffff && nextSpr < 128) {
        // Add offset
        offset = tile_id + data[i + 5];
        // Get next sprite slot
        OAM_SPR *newSpr = &shadow_oam[nextSpr];
        // Set attributes
        obj_set_attr(newSpr, 
            data[i] | ATTR0_AFF | (dbl ? ATTR0_AFF_DBL : 0),                                     // ATTR0
            (data[i + 1] | ((data[i+1] & ATTR1_AFF_ID_MASK) ? 0 : ATTR1_AFF_ID(aff_id))), // ATTR1
            data[i + 2] | (data[i+1] & ATTR2_ID_MASK ? 0 : offset & 0x3ff));                                                            // ATTR2

        u8 wh_index = ((data[i] & ATTR0_SHAPE_MASK) >> 12) | ((data[i + 1] & ATTR1_SIZE_MASK) >> 14);

        u8 width = spr_width_height_table[wh_index << 1];
        u8 height = spr_width_height_table[(wh_index << 1) + 1];
       
        s16 offset_x = data[i + 3];
        s16 offset_y = data[i + 4];
        s8 center_x = data[i + 6] >> 8;
        s8 center_y = data[i + 6] & 0xff;

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

        s32 total_x = x + (center_x - (width >> 1)) + rotated_x - (dbl ? (width >> 1) : 0);
        s32 total_y = y + (center_y - (height >> 1)) + rotated_y - (dbl ? (height >> 1) : 0);
        
        // Set position
        obj_set_pos(newSpr, total_x, total_y);
        
        // Add offset
        offset = tile_id + data[i + 5];

        // Increment into next sprite
        nextSpr++;
        // Also increment sprite index by 7 words
        i += 7;
    }
}