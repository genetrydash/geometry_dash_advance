@ Level Data Export
@ Compressed using RLE

.section .rodata
.align 2
.global test_l2_level_data
.hidden test_l2_level_data
test_l2_level_data:
    .word 0b00000000000000001111101111001100 @ 0x0000fbcc
    .word 0b10000000000000000000000000000000 @ 0x80000000
