#include <tonc.h>

#define SPRITE_CHR_COPY_FROM_METATILE (u32)(-2)
#define SPRITE_NO_CHR (u32)(-1)

#define TILE_OFFSET_MASK 0x3ff
#define PRIORITY_MASK 0x1c00

extern u8 nextSpr;
extern const u16 debugModeSpr[];
extern const u16 playerSpr[];
extern const u16 shipSpr[];
extern const u16 ballSpr[];
extern const u16 *obj_sprites[];
extern const u32 obj_chr_offset[][2];

ARM_CODE void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip, u16 tile_id, u8 priority);
ARM_CODE void oam_affine_metaspr(u16 x, u8 y, const u16 *data, u16 rotation, u8 aff_id, u8 dbl, u16 tile_id, u8 priority);