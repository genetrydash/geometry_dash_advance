.section .rodata
.global blockset
.global player0_icon
.align 2
blockset:
    .incbin "graphics/tileset.chr"

player0_icon:
    .incbin "graphics/player.chr"