#include <tonc.h>

extern u8 nextSpr;
extern const u16 playerSpr[];
extern const u16 shipSpr[];
extern const u16 *obj_sprites[];
extern const s16 obj_hitbox[][4];

void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip);
void oam_affine_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip, u8 aff_id);