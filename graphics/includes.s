.section .rodata
.global blockset
.global player0_icon
.global sprites_chr
.align 2
blockset:
    .incbin "graphics/tileset.chr"

player0_icon:
    .incbin "graphics/player.chr"

sprites_chr:
    .incbin "graphics/sprites.chr"
    