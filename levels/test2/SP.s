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
@ Object 3
   .word 0x4e0 @ x
   .hword 0x1a0 @ y
   .hword 0x2 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 4
   .word 0x4e0 @ x
   .hword 0x1a0 @ y
   .hword 0x36 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 5
   .word 0x4e0 @ x
   .hword 0x1a0 @ y
   .hword 0x1c @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 6
   .word 0x540 @ x
   .hword 0x1a0 @ y
   .hword 0x1 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 7
   .word 0x540 @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
   .byte 0xff
