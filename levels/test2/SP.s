@ Sprite Data Export

.section .rodata
.align 2
.global test2_spr_data
.hidden test2_spr_data
test2_spr_data:
@ Object 1
   .word 0x10 @ x
   .hword 0x1a0 @ y
   .hword 0x1 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 2
   .word 0x2f0 @ x
   .hword 0x190 @ y
   .hword 0x1a @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
   .byte 0xff
