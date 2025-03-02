.section .rodata
.global blockset
.global icon_0
.global sprites_chr
.global square_background_chr
.global circle_background_chr
.global line_background_chr
.global checkerboard_background_chr
.global menu_chr
.global animated_sprites
.global level_text_chr
.global level_complete_screen
.global grounds
    
.align 2
blockset:
    .incbin "graphics/tileset.chr"

icon_0:
    .incbin "graphics/player.chr"

sprites_chr:
    .incbin "graphics/sprites.chr"

menu_chr:
    .incbin "graphics/menu.chr"

animated_sprites:
    .incbin "graphics/animated_sprites.chr"

level_text_chr:
    .incbin "graphics/level_text.chr"

level_complete_screen:
    .incbin "graphics/level_complete_screen.chr"

grounds:
    .incbin "graphics/grounds.chr"

square_background_chr:
    .incbin "graphics/backgrounds/square_background.chr"
    
circle_background_chr:
    .incbin "graphics/backgrounds/circle_background.chr"
    
line_background_chr:
    .incbin "graphics/backgrounds/line_background.chr"
    
checkerboard_background_chr:
    .incbin "graphics/backgrounds/checkerboard_background.chr"

@ I put it there because gcc won't keep it
.align 4
save_string:
    .ascii "SRAM_Vnnn"
    