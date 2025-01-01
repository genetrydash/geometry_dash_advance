.section .rodata
.global blockset
.global player0_icon
.global sprites_chr
.global bg_chr
.global menu_chr
.global orb_pad_particles
.align 2
blockset:
    .incbin "graphics/tileset.chr"

player0_icon:
    .incbin "graphics/player.chr"

sprites_chr:
    .incbin "graphics/sprites.chr"

bg_chr:
    .incbin "graphics/background.chr"

menu_chr:
    .incbin "graphics/menu.chr"

orb_pad_particles:
    .incbin "graphics/orb_particles.chr"


    