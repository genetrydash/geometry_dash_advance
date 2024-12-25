@ Sprite Data Export

.section .rodata
.align 2
.global test_spr_data
.hidden test_spr_data
test_spr_data:
@ Object 1
   .word 0x10
   .hword 0x190
   .hword 0x1a
   .hword 0x0
   .hword 0
@ Object 2
   .word 0x70
   .hword 0x1b0
   .hword 0xa
   .hword 0x0
   .hword 0
@ Object 3
   .word 0xc0
   .hword 0x1a0
   .hword 0x9
   .hword 0x0
   .hword 0
   .byte 0xff
