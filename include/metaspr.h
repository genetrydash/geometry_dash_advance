#include <tonc.h>

extern u8 nextSpr;
extern const u16 debugModeSpr[];
extern const u16 playerSpr[];
extern const u16 shipSpr[];
extern const u16 shipFlippedSpr[];
extern const u16 ballSpr[];
extern const u16 *obj_sprites[];

void oam_metaspr(u16 x, u8 y, const u16 *data, u8 hflip, u8 vflip);
void oam_affine_metaspr(u16 x, u8 y, const u16 *data, u16 rotation, u8 aff_id);