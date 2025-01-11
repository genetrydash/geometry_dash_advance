@ Sprite Data Export

.section .rodata
.align 2
.global xstep_spr_data
.hidden xstep_spr_data
xstep_spr_data:
@ Object 1
   .word 0xa0 @ x
   .hword 0x150 @ y
   .hword 0x3 @ type
   .hword 0x964 @ changes BG for 300 frames
   .hword 0x4600 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 2
   .word 0xa0 @ x
   .hword 0x160 @ y
   .hword 0x3 @ type
   .hword 0x965 @ changes GROUND for 300 frames
   .hword 0x2100 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 3
   .word 0x130 @ x
   .hword 0x1a0 @ y
   .hword 0xd @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 4
   .word 0x150 @ x
   .hword 0x1a0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 5
   .word 0x168 @ x
   .hword 0x1b0 @ y
   .hword 0x20 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 6
   .word 0x190 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 7
   .word 0x190 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 8
   .word 0x19d @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 9
   .word 0x1ad @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 10
   .word 0x1bd @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 11
   .word 0x1d0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 12
   .word 0x1e0 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 13
   .word 0x200 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 14
   .word 0x220 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 15
   .word 0x228 @ x
   .hword 0x170 @ y
   .hword 0xf @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 16
   .word 0x230 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 17
   .word 0x240 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 18
   .word 0x240 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 19
   .word 0x250 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 20
   .word 0x268 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 21
   .word 0x270 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 22
   .word 0x290 @ x
   .hword 0x148 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 23
   .word 0x290 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 24
   .word 0x294 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 25
   .word 0x2b0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 26
   .word 0x2d0 @ x
   .hword 0x158 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 27
   .word 0x2d0 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 28
   .word 0x2d0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 29
   .word 0x2f0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 30
   .word 0x300 @ x
   .hword 0x180 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 31
   .word 0x340 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 32
   .word 0x348 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 33
   .word 0x350 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 34
   .word 0x390 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 35
   .word 0x398 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 36
   .word 0x3a0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 37
   .word 0x3d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 38
   .word 0x3e0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 39
   .word 0x410 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 40
   .word 0x418 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 41
   .word 0x420 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 42
   .word 0x460 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 43
   .word 0x460 @ x
   .hword 0x1a8 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 44
   .word 0x480 @ x
   .hword 0x1a0 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 45
   .word 0x480 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 46
   .word 0x498 @ x
   .hword 0x1b4 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 47
   .word 0x4a8 @ x
   .hword 0x1b0 @ y
   .hword 0x20 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 48
   .word 0x4c0 @ x
   .hword 0x110 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7c4d @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 49
   .word 0x4c0 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x5008 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 50
   .word 0x4c0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 51
   .word 0x4c0 @ x
   .hword 0x190 @ y
   .hword 0x1a @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 52
   .word 0x4e0 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 53
   .word 0x500 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 54
   .word 0x500 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 55
   .word 0x530 @ x
   .hword 0x170 @ y
   .hword 0xe @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 56
   .word 0x568 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 57
   .word 0x570 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 58
   .word 0x5a0 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 59
   .word 0x5b0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 60
   .word 0x5c0 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 61
   .word 0x5c0 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 62
   .word 0x5f0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 63
   .word 0x5f8 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 64
   .word 0x600 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 65
   .word 0x600 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 66
   .word 0x600 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 67
   .word 0x620 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 68
   .word 0x630 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 69
   .word 0x630 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 70
   .word 0x630 @ x
   .hword 0x170 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 71
   .word 0x630 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 72
   .word 0x650 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 73
   .word 0x660 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 74
   .word 0x660 @ x
   .hword 0x147 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 75
   .word 0x660 @ x
   .hword 0x156 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 76
   .word 0x660 @ x
   .hword 0x165 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 77
   .word 0x680 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 78
   .word 0x690 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 79
   .word 0x690 @ x
   .hword 0x190 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 80
   .word 0x698 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 81
   .word 0x6a0 @ x
   .hword 0x190 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 82
   .word 0x6b0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 83
   .word 0x6c8 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 84
   .word 0x6d0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 85
   .word 0x6d0 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 86
   .word 0x6d0 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 87
   .word 0x700 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 88
   .word 0x700 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 89
   .word 0x720 @ x
   .hword 0x150 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 90
   .word 0x730 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 91
   .word 0x730 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 92
   .word 0x748 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 93
   .word 0x760 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 94
   .word 0x760 @ x
   .hword 0x168 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 95
   .word 0x760 @ x
   .hword 0x178 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 96
   .word 0x760 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 97
   .word 0x778 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 98
   .word 0x790 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 99
   .word 0x7b0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 100
   .word 0x7d0 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 101
   .word 0x7d0 @ x
   .hword 0x190 @ y
   .hword 0xf @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 102
   .word 0x7d0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 103
   .word 0x7f0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 104
   .word 0x808 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 105
   .word 0x810 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 106
   .word 0x82c @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 107
   .word 0x838 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 108
   .word 0x848 @ x
   .hword 0x160 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 109
   .word 0x850 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 110
   .word 0x858 @ x
   .hword 0x150 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 111
   .word 0x858 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 112
   .word 0x858 @ x
   .hword 0x160 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 113
   .word 0x858 @ x
   .hword 0x170 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 114
   .word 0x858 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 115
   .word 0x868 @ x
   .hword 0x160 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 116
   .word 0x878 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 117
   .word 0x880 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 118
   .word 0x888 @ x
   .hword 0x190 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 119
   .word 0x898 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 120
   .word 0x898 @ x
   .hword 0x180 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 121
   .word 0x898 @ x
   .hword 0x190 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 122
   .word 0x898 @ x
   .hword 0x1a0 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 123
   .word 0x898 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 124
   .word 0x8a0 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 125
   .word 0x8a8 @ x
   .hword 0x190 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 126
   .word 0x8b0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 127
   .word 0x8c0 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 128
   .word 0x8c8 @ x
   .hword 0x160 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 129
   .word 0x8d0 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 130
   .word 0x8d8 @ x
   .hword 0x150 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 131
   .word 0x8d8 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 132
   .word 0x8d8 @ x
   .hword 0x160 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 133
   .word 0x8d8 @ x
   .hword 0x170 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 134
   .word 0x8e0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 135
   .word 0x8e8 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 136
   .word 0x8e8 @ x
   .hword 0x160 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 137
   .word 0x910 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 138
   .word 0x920 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 139
   .word 0x938 @ x
   .hword 0x1a0 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 140
   .word 0x940 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 141
   .word 0x944 @ x
   .hword 0x140 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 142
   .word 0x948 @ x
   .hword 0x190 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 143
   .word 0x948 @ x
   .hword 0x1a0 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 144
   .word 0x948 @ x
   .hword 0x1b0 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 145
   .word 0x950 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 146
   .word 0x958 @ x
   .hword 0x1a0 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 147
   .word 0x970 @ x
   .hword 0x140 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 148
   .word 0x970 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 149
   .word 0x980 @ x
   .hword 0x1a0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 150
   .word 0x990 @ x
   .hword 0x180 @ y
   .hword 0x1 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 151
   .word 0x9a0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 152
   .word 0x9a8 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 153
   .word 0x9c0 @ x
   .hword 0x130 @ y
   .hword 0x3 @ type
   .hword 0x12c4 @ changes BG for 600 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 154
   .word 0x9c0 @ x
   .hword 0x140 @ y
   .hword 0x3 @ type
   .hword 0x12c5 @ changes GROUND for 600 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 155
   .word 0x9cc @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 156
   .word 0x9e0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 157
   .word 0x9ec @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 158
   .word 0x9f0 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 159
   .word 0xa00 @ x
   .hword 0x140 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 160
   .word 0xa00 @ x
   .hword 0x1a0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 161
   .word 0xa10 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 162
   .word 0xa10 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 163
   .word 0xa20 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 164
   .word 0xa38 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 165
   .word 0xa40 @ x
   .hword 0x138 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 166
   .word 0xa40 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 167
   .word 0xa50 @ x
   .hword 0x128 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 168
   .word 0xa50 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 169
   .word 0xa50 @ x
   .hword 0x138 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 170
   .word 0xa50 @ x
   .hword 0x148 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 171
   .word 0xa60 @ x
   .hword 0x138 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 172
   .word 0xa60 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 173
   .word 0xa68 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 174
   .word 0xa80 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 175
   .word 0xa90 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 176
   .word 0xa90 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 177
   .word 0xaa0 @ x
   .hword 0x140 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 178
   .word 0xaa0 @ x
   .hword 0x1a0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 179
   .word 0xab0 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 180
   .word 0xab0 @ x
   .hword 0x1b0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 181
   .word 0xac0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 182
   .word 0xad0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 183
   .word 0xae0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 184
   .word 0xae0 @ x
   .hword 0x178 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 185
   .word 0xaf0 @ x
   .hword 0x168 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 186
   .word 0xaf0 @ x
   .hword 0x168 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 187
   .word 0xaf0 @ x
   .hword 0x178 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 188
   .word 0xaf0 @ x
   .hword 0x188 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 189
   .word 0xaf0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 190
   .word 0xb00 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 191
   .word 0xb00 @ x
   .hword 0x178 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 192
   .word 0xb10 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 193
   .word 0xb20 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 194
   .word 0xb30 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 195
   .word 0xb38 @ x
   .hword 0x1a5 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 196
   .word 0xb40 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 197
   .word 0xb48 @ x
   .hword 0x195 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 198
   .word 0xb48 @ x
   .hword 0x1a5 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 199
   .word 0xb48 @ x
   .hword 0x1b5 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 200
   .word 0xb58 @ x
   .hword 0x1a5 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 201
   .word 0xb58 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 202
   .word 0xb60 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 203
   .word 0xb70 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 204
   .word 0xb80 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 205
   .word 0xb90 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 206
   .word 0xb90 @ x
   .hword 0x1a0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 207
   .word 0xba0 @ x
   .hword 0x140 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 208
   .word 0xba0 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 209
   .word 0xbb0 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 210
   .word 0xbc0 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 211
   .word 0xbc0 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 212
   .word 0xbe0 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 213
   .word 0xbe0 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 214
   .word 0xc00 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 215
   .word 0xc00 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 216
   .word 0xc20 @ x
   .hword 0x130 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 217
   .word 0xc20 @ x
   .hword 0x170 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 218
   .word 0xc30 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 219
   .word 0xc40 @ x
   .hword 0x140 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 220
   .word 0xc40 @ x
   .hword 0x190 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 221
   .word 0xc50 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 222
   .word 0xc50 @ x
   .hword 0x1a0 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 223
   .word 0xc60 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 224
   .word 0xc78 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 225
   .word 0xc80 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 226
   .word 0xc80 @ x
   .hword 0x175 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 227
   .word 0xc90 @ x
   .hword 0x165 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 228
   .word 0xc90 @ x
   .hword 0x165 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 229
   .word 0xc90 @ x
   .hword 0x175 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 230
   .word 0xc90 @ x
   .hword 0x185 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 231
   .word 0xca0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 232
   .word 0xca0 @ x
   .hword 0x175 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 233
   .word 0xca0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 234
   .word 0xcc0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 235
   .word 0xcc0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 236
   .word 0xcc7 @ x
   .hword 0x1b0 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 237
   .word 0xcd7 @ x
   .hword 0x1a0 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 238
   .word 0xcd7 @ x
   .hword 0x1b0 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 239
   .word 0xce0 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 240
   .word 0xce7 @ x
   .hword 0x1b0 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 241
   .word 0xd00 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 242
   .word 0xd08 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 243
   .word 0xd10 @ x
   .hword 0x175 @ y
   .hword 0x25 @ type
   .hword 0x2 @ bg layer 0 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 244
   .word 0xd20 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 245
   .word 0xd20 @ x
   .hword 0x165 @ y
   .hword 0x24 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 246
   .word 0xd20 @ x
   .hword 0x165 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 247
   .word 0xd20 @ x
   .hword 0x175 @ y
   .hword 0x1b @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 248
   .word 0xd20 @ x
   .hword 0x185 @ y
   .hword 0x24 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 249
   .word 0xd30 @ x
   .hword 0x175 @ y
   .hword 0x25 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 250
   .word 0xd30 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 251
   .word 0xd40 @ x
   .hword 0x160 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 252
   .word 0xd50 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 253
   .word 0xd70 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 254
   .word 0xd70 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 255
   .word 0xd90 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 256
   .word 0xd90 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 257
   .word 0xdb0 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 258
   .word 0xdb0 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 259
   .word 0xdd0 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 260
   .word 0xdd0 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 261
   .word 0xdf0 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 262
   .word 0xdf0 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 263
   .word 0xe10 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 264
   .word 0xe10 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 265
   .word 0xe30 @ x
   .hword 0x150 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 266
   .word 0xe30 @ x
   .hword 0x180 @ y
   .hword 0x16 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 267
   .word 0xe50 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 268
   .word 0xe54 @ x
   .hword 0x168 @ y
   .hword 0x2 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 269
   .word 0xe60 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 270
   .word 0xe80 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 271
   .word 0xea0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 272
   .word 0xeb8 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 273
   .word 0xed0 @ x
   .hword 0x1a0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 274
   .word 0xef0 @ x
   .hword 0x170 @ y
   .hword 0xf @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 275
   .word 0xef8 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 276
   .word 0xef8 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 277
   .word 0xf18 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 278
   .word 0xf18 @ x
   .hword 0x140 @ y
   .hword 0x2b @ type
   .hword 0x0 @ bg layer 0   
   .hword 2 @ metatile ID appareance
@ Object 279
   .word 0xf18 @ x
   .hword 0x150 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 280
   .word 0xf28 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 281
   .word 0xf30 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 282
   .word 0xf48 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 283
   .word 0xf48 @ x
   .hword 0x160 @ y
   .hword 0x2b @ type
   .hword 0x0 @ bg layer 0   
   .hword 2 @ metatile ID appareance
@ Object 284
   .word 0xf48 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 285
   .word 0xf60 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 286
   .word 0xf80 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 287
   .word 0xf8a @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 288
   .word 0xf90 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 289
   .word 0xf90 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 290
   .word 0xf9a @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 291
   .word 0xfc0 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 292
   .word 0xfe8 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 293
   .word 0xff0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 294
   .word 0x1000 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 295
   .word 0x1020 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 296
   .word 0x1028 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 297
   .word 0x1048 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 298
   .word 0x1060 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 299
   .word 0x1070 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 300
   .word 0x1080 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 301
   .word 0x10b0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 302
   .word 0x10c0 @ x
   .hword 0x110 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 303
   .word 0x10c0 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 304
   .word 0x10d0 @ x
   .hword 0x110 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 305
   .word 0x10e0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 306
   .word 0x1100 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 307
   .word 0x1100 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 308
   .word 0x1110 @ x
   .hword 0x150 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 309
   .word 0x1120 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 310
   .word 0x1130 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 311
   .word 0x1150 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 312
   .word 0x1150 @ x
   .hword 0x140 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 313
   .word 0x1160 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 314
   .word 0x1160 @ x
   .hword 0x180 @ y
   .hword 0xf @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 315
   .word 0x1160 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 316
   .word 0x1190 @ x
   .hword 0x100 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 317
   .word 0x1190 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 318
   .word 0x11a0 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 319
   .word 0x11c0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 320
   .word 0x11d0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 321
   .word 0x11f0 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 322
   .word 0x11f0 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 323
   .word 0x1200 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 324
   .word 0x1200 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 325
   .word 0x1230 @ x
   .hword 0x1a0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 326
   .word 0x1240 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 327
   .word 0x1250 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 328
   .word 0x1260 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 329
   .word 0x1270 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 330
   .word 0x1270 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 331
   .word 0x1280 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 332
   .word 0x1280 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 333
   .word 0x1280 @ x
   .hword 0x1a0 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 334
   .word 0x1290 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 335
   .word 0x1290 @ x
   .hword 0x140 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 336
   .word 0x1290 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 337
   .word 0x1290 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 338
   .word 0x1290 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 339
   .word 0x12a0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 340
   .word 0x12a0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 341
   .word 0x12a0 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 342
   .word 0x12a0 @ x
   .hword 0x1a0 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 343
   .word 0x12b0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 344
   .word 0x12b0 @ x
   .hword 0x140 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 345
   .word 0x12b0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 346
   .word 0x12b0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 347
   .word 0x12c0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 348
   .word 0x12c0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 349
   .word 0x12c0 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 350
   .word 0x12c0 @ x
   .hword 0x1a0 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 351
   .word 0x12c0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 352
   .word 0x12d0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 353
   .word 0x12d0 @ x
   .hword 0x140 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 354
   .word 0x12d0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 355
   .word 0x12d0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 356
   .word 0x12d8 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 357
   .word 0x12e0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 358
   .word 0x12e0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 359
   .word 0x12e0 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 360
   .word 0x12e0 @ x
   .hword 0x1a0 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 361
   .word 0x12e0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 362
   .word 0x12e8 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 363
   .word 0x12f0 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 364
   .word 0x12f0 @ x
   .hword 0x140 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 365
   .word 0x12f0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 366
   .word 0x12f0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 367
   .word 0x12f8 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 368
   .word 0x1300 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 369
   .word 0x1300 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 370
   .word 0x1300 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 371
   .word 0x1300 @ x
   .hword 0x1a0 @ y
   .hword 0x15 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 372
   .word 0x1300 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 373
   .word 0x1308 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x400c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 374
   .word 0x1310 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 375
   .word 0x1310 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 376
   .word 0x1310 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 377
   .word 0x1318 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x541f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 378
   .word 0x1320 @ x
   .hword 0xb0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 379
   .word 0x1320 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1002 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 380
   .word 0x1328 @ x
   .hword 0x160 @ y
   .hword 0x1 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 381
   .word 0x132c @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 382
   .word 0x1330 @ x
   .hword 0xb0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 383
   .word 0x1330 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 384
   .word 0x1350 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 385
   .word 0x1360 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 386
   .word 0x1360 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 387
   .word 0x1370 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 388
   .word 0x1380 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 389
   .word 0x1380 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 390
   .word 0x1380 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 391
   .word 0x1388 @ x
   .hword 0x148 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 392
   .word 0x1388 @ x
   .hword 0x188 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 393
   .word 0x13a0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 394
   .word 0x13a8 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 395
   .word 0x13b0 @ x
   .hword 0x134 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 396
   .word 0x13b0 @ x
   .hword 0x19c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 397
   .word 0x13c0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 398
   .word 0x13d0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 399
   .word 0x13d0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 400
   .word 0x13d0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 401
   .word 0x13e0 @ x
   .hword 0x194 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 402
   .word 0x13e4 @ x
   .hword 0x140 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 403
   .word 0x13f0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 404
   .word 0x1400 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 405
   .word 0x1404 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 406
   .word 0x1410 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 407
   .word 0x1430 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 408
   .word 0x1430 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 409
   .word 0x1440 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 410
   .word 0x1450 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 411
   .word 0x1450 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 412
   .word 0x1460 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 413
   .word 0x1460 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 414
   .word 0x1470 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 415
   .word 0x1480 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 416
   .word 0x1480 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 417
   .word 0x1490 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 418
   .word 0x14a0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 419
   .word 0x14b0 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 420
   .word 0x14c0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 421
   .word 0x14d0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 422
   .word 0x14e0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 423
   .word 0x14e0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 424
   .word 0x14f0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 425
   .word 0x1500 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 426
   .word 0x1500 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 427
   .word 0x1500 @ x
   .hword 0x190 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 428
   .word 0x1500 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 429
   .word 0x1510 @ x
   .hword 0x15c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 430
   .word 0x1530 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 431
   .word 0x1530 @ x
   .hword 0x1a4 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 432
   .word 0x1530 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 433
   .word 0x1540 @ x
   .hword 0x148 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 434
   .word 0x1560 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 435
   .word 0x1560 @ x
   .hword 0x19c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 436
   .word 0x1570 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 437
   .word 0x1570 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 438
   .word 0x1580 @ x
   .hword 0x17c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 439
   .word 0x1590 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 440
   .word 0x1590 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1004 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 441
   .word 0x15a0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 442
   .word 0x15a0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 443
   .word 0x15b0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 444
   .word 0x15b0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 445
   .word 0x15c0 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 446
   .word 0x15c0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 447
   .word 0x15d0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 448
   .word 0x15d0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 449
   .word 0x15d0 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 450
   .word 0x15d0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 451
   .word 0x15e0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 452
   .word 0x15e0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 453
   .word 0x15e0 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 454
   .word 0x15f0 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 455
   .word 0x15f0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 456
   .word 0x1610 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 457
   .word 0x1610 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 458
   .word 0x1620 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 459
   .word 0x1620 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 460
   .word 0x1620 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 461
   .word 0x1620 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 462
   .word 0x1630 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 463
   .word 0x1630 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 464
   .word 0x1630 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 465
   .word 0x1630 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 466
   .word 0x1640 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 467
   .word 0x1650 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 468
   .word 0x1650 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 469
   .word 0x1660 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 470
   .word 0x1660 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 471
   .word 0x1670 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 472
   .word 0x1670 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 473
   .word 0x1670 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 474
   .word 0x1670 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 475
   .word 0x1680 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 476
   .word 0x1690 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 477
   .word 0x1690 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 478
   .word 0x16a0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 479
   .word 0x16a0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 480
   .word 0x16b0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 481
   .word 0x16b0 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 482
   .word 0x16b0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 483
   .word 0x16c0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 484
   .word 0x16c0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 485
   .word 0x16c0 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 486
   .word 0x16d0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 487
   .word 0x16d0 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 488
   .word 0x16d0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 489
   .word 0x16e0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 490
   .word 0x16f0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 491
   .word 0x16f0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 492
   .word 0x1700 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 493
   .word 0x1704 @ x
   .hword 0x15c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 494
   .word 0x1710 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 495
   .word 0x1710 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 496
   .word 0x1710 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 497
   .word 0x1720 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 498
   .word 0x1730 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 499
   .word 0x1730 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 500
   .word 0x1730 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 501
   .word 0x1740 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 502
   .word 0x1750 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 503
   .word 0x1750 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 504
   .word 0x1750 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 505
   .word 0x1750 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 506
   .word 0x175c @ x
   .hword 0x178 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 507
   .word 0x1760 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 508
   .word 0x1770 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 509
   .word 0x1770 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 510
   .word 0x1780 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 511
   .word 0x1780 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 512
   .word 0x1780 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 513
   .word 0x1784 @ x
   .hword 0x164 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 514
   .word 0x1790 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 515
   .word 0x17a0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 516
   .word 0x17a0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 517
   .word 0x17a0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 518
   .word 0x17b0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 519
   .word 0x17b0 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 520
   .word 0x17b0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 521
   .word 0x17c0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 522
   .word 0x17c0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 523
   .word 0x17c0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 524
   .word 0x17c0 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 525
   .word 0x17d0 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 526
   .word 0x17d0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 527
   .word 0x17d0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 528
   .word 0x17e0 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 529
   .word 0x17f0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 530
   .word 0x17f0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1002 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 531
   .word 0x1800 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 532
   .word 0x1810 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 533
   .word 0x1810 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 534
   .word 0x1810 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 535
   .word 0x1820 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 536
   .word 0x1820 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 537
   .word 0x1820 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 538
   .word 0x1820 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 539
   .word 0x1838 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 540
   .word 0x1840 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 541
   .word 0x1840 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 542
   .word 0x1840 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 543
   .word 0x1850 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 544
   .word 0x1860 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 545
   .word 0x1860 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 546
   .word 0x1870 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 547
   .word 0x1870 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 548
   .word 0x1870 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 549
   .word 0x1890 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 550
   .word 0x1890 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 551
   .word 0x18a0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 552
   .word 0x18a0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 553
   .word 0x18a0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 554
   .word 0x18a0 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 555
   .word 0x18a0 @ x
   .hword 0x160 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 556
   .word 0x18c0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 557
   .word 0x18c0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 558
   .word 0x18c0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 559
   .word 0x18c8 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 560
   .word 0x18d0 @ x
   .hword 0x158 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 561
   .word 0x18f0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 562
   .word 0x18f0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 563
   .word 0x1900 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 564
   .word 0x1900 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 565
   .word 0x1900 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 566
   .word 0x1910 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 567
   .word 0x1920 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 568
   .word 0x1920 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 569
   .word 0x1920 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 570
   .word 0x1930 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 571
   .word 0x1930 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 572
   .word 0x1930 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 573
   .word 0x1940 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 574
   .word 0x1950 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 575
   .word 0x1950 @ x
   .hword 0x140 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 576
   .word 0x1960 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 577
   .word 0x1960 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 578
   .word 0x1960 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 579
   .word 0x1960 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 580
   .word 0x1960 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 581
   .word 0x1980 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 582
   .word 0x1990 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 583
   .word 0x1990 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 584
   .word 0x19a0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 585
   .word 0x19a0 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 586
   .word 0x19b0 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 587
   .word 0x19b0 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 588
   .word 0x19b0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 589
   .word 0x19c0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7cb2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 590
   .word 0x19c0 @ x
   .hword 0x15c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 591
   .word 0x19c0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 592
   .word 0x19d0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4809 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 593
   .word 0x19d0 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 594
   .word 0x19e0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 595
   .word 0x19f0 @ x
   .hword 0x158 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 596
   .word 0x1a00 @ x
   .hword 0x120 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 597
   .word 0x1a00 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 598
   .word 0x1a10 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 599
   .word 0x1a10 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 600
   .word 0x1a18 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 601
   .word 0x1a20 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 602
   .word 0x1a20 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 603
   .word 0x1a30 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 604
   .word 0x1a30 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 605
   .word 0x1a40 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 606
   .word 0x1a50 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 607
   .word 0x1a50 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1004 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 608
   .word 0x1a60 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 609
   .word 0x1a70 @ x
   .hword 0x148 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 610
   .word 0x1a70 @ x
   .hword 0x164 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 611
   .word 0x1a70 @ x
   .hword 0x188 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 612
   .word 0x1aa0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 613
   .word 0x1aa0 @ x
   .hword 0x154 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 614
   .word 0x1ab0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 615
   .word 0x1ab0 @ x
   .hword 0x138 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 616
   .word 0x1ab0 @ x
   .hword 0x178 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 617
   .word 0x1ad4 @ x
   .hword 0x15c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 618
   .word 0x1af0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 619
   .word 0x1af0 @ x
   .hword 0x148 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 620
   .word 0x1af0 @ x
   .hword 0x188 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 621
   .word 0x1b00 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 622
   .word 0x1b00 @ x
   .hword 0x174 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 623
   .word 0x1b30 @ x
   .hword 0x158 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 624
   .word 0x1b30 @ x
   .hword 0x198 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 625
   .word 0x1b38 @ x
   .hword 0x178 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 626
   .word 0x1b70 @ x
   .hword 0x148 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 627
   .word 0x1b70 @ x
   .hword 0x168 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 628
   .word 0x1b70 @ x
   .hword 0x188 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 629
   .word 0x1b88 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 630
   .word 0x1b98 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 631
   .word 0x1bb0 @ x
   .hword 0x148 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 632
   .word 0x1bb0 @ x
   .hword 0x188 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 633
   .word 0x1bb4 @ x
   .hword 0x164 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 634
   .word 0x1bf0 @ x
   .hword 0x138 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 635
   .word 0x1bf0 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 636
   .word 0x1bf0 @ x
   .hword 0x178 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 637
   .word 0x1c18 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 638
   .word 0x1c20 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 639
   .word 0x1c30 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 640
   .word 0x1c30 @ x
   .hword 0x148 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 641
   .word 0x1c30 @ x
   .hword 0x168 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 642
   .word 0x1c50 @ x
   .hword 0x120 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 643
   .word 0x1c70 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x74b9 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 644
   .word 0x1c70 @ x
   .hword 0x138 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 645
   .word 0x1c70 @ x
   .hword 0x158 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 646
   .word 0x1c70 @ x
   .hword 0x178 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 647
   .word 0x1c80 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x4811 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 648
   .word 0x1cbc @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7da2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 649
   .word 0x1cbc @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x5 @ changes GROUND for 0 frames
   .hword 0x6520 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 650
   .word 0x1cc0 @ x
   .hword 0x168 @ y
   .hword 0x2 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 651
   .word 0x1cc4 @ x
   .hword 0x168 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 652
   .word 0x1ccc @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7c57 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 653
   .word 0x1ccc @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x6411 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 654
   .word 0x1cd0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 655
   .word 0x1ce0 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 656
   .word 0x1d10 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 657
   .word 0x1d37 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 658
   .word 0x1d44 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 659
   .word 0x1d50 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xc5f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 660
   .word 0x1d50 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x40c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 661
   .word 0x1d50 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 662
   .word 0x1d51 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 663
   .word 0x1d60 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 664
   .word 0x1d60 @ x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 665
   .word 0x1d80 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 666
   .word 0x1d80 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 667
   .word 0x1d80 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 668
   .word 0x1da0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 669
   .word 0x1da0 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 670
   .word 0x1da0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 671
   .word 0x1da0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 672
   .word 0x1dc0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 673
   .word 0x1dc0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 674
   .word 0x1dd0 @ x
   .hword 0x150 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 675
   .word 0x1dd0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 676
   .word 0x1de0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 677
   .word 0x1df0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xbbf @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 678
   .word 0x1df0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x2d8 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 679
   .word 0x1df0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 680
   .word 0x1df0 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 681
   .word 0x1e00 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 682
   .word 0x1e10 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 683
   .word 0x1e20 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 684
   .word 0x1e30 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 685
   .word 0x1e40 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 686
   .word 0x1e60 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 687
   .word 0x1e80 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xbec @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 688
   .word 0x1e80 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x308 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 689
   .word 0x1e80 @ x
   .hword 0x180 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 690
   .word 0x1e90 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 691
   .word 0x1ea0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 692
   .word 0x1ec0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 693
   .word 0x1ed0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 694
   .word 0x1ee0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 695
   .word 0x1f04 @ x
   .hword 0x150 @ y
   .hword 0x22 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 696
   .word 0x1f10 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 697
   .word 0x1f20 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x2fe2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 698
   .word 0x1f20 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1aa0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 699
   .word 0x1f20 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 700
   .word 0x1f20 @ x
   .hword 0x160 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 701
   .word 0x1f30 @ x
   .hword 0x90 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 702
   .word 0x1f56 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 703
   .word 0x1f56 @ x
   .hword 0x180 @ y
   .hword 0x2b @ type
   .hword 0x0 @ bg layer 0   
   .hword 2 @ metatile ID appareance
@ Object 704
   .word 0x1f56 @ x
   .hword 0x190 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 705
   .word 0x1f60 @ x
   .hword 0xc0 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 706
   .word 0x1f60 @ x
   .hword 0xd0 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 707
   .word 0x1f60 @ x
   .hword 0xe0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 708
   .word 0x1f76 @ x
   .hword 0x1a0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 709
   .word 0x1f86 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 710
   .word 0x1f90 @ x
   .hword 0x90 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 711
   .word 0x1f93 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 712
   .word 0x1fb0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7d22 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 713
   .word 0x1fb0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x58a0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 714
   .word 0x1fb8 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 715
   .word 0x1fb8 @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 716
   .word 0x1fb8 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 717
   .word 0x1fd0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 718
   .word 0x1fd0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 719
   .word 0x1fd0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 720
   .word 0x2000 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 721
   .word 0x2000 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 722
   .word 0x2000 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 723
   .word 0x2008 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 724
   .word 0x2010 @ x
   .hword 0x196 @ y
   .hword 0xf @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 725
   .word 0x2030 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 726
   .word 0x2038 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 727
   .word 0x2052 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 728
   .word 0x2052 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 729
   .word 0x2052 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 730
   .word 0x2058 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 731
   .word 0x2060 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7c5c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 732
   .word 0x2060 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x5c14 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 733
   .word 0x2060 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 734
   .word 0x2080 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 735
   .word 0x2091 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 736
   .word 0x2091 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 737
   .word 0x2091 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 738
   .word 0x20b0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 739
   .word 0x20c0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 740
   .word 0x20e0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 741
   .word 0x20e0 @ x
   .hword 0x150 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 742
   .word 0x20e0 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 743
   .word 0x20f0 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x505f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 744
   .word 0x20f0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x3818 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 745
   .word 0x20f0 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 746
   .word 0x20f0 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 747
   .word 0x2110 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 748
   .word 0x2130 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 749
   .word 0x2130 @ x
   .hword 0x140 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 750
   .word 0x2130 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 751
   .word 0x2140 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 752
   .word 0x2170 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 753
   .word 0x2180 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xc5f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 754
   .word 0x2180 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x40c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 755
   .word 0x2190 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 756
   .word 0x21a0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 757
   .word 0x21c0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 758
   .word 0x21d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 759
   .word 0x21e0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 760
   .word 0x21f0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 761
   .word 0x2200 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 762
   .word 0x2200 @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 763
   .word 0x2200 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 764
   .word 0x2200 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 765
   .word 0x2220 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xabf @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 766
   .word 0x2220 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x1d6 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 767
   .word 0x2220 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 768
   .word 0x2220 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 769
   .word 0x2230 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 770
   .word 0x2240 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 771
   .word 0x2250 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 772
   .word 0x2270 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 773
   .word 0x2270 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 774
   .word 0x2298 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 775
   .word 0x22c0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0xbf1 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 776
   .word 0x22c0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x2cb @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 777
   .word 0x22c0 @ x
   .hword 0x190 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 778
   .word 0x22c0 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 779
   .word 0x22c0 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 780
   .word 0x22e8 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 781
   .word 0x2300 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 782
   .word 0x2300 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 783
   .word 0x2300 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 784
   .word 0x2308 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 785
   .word 0x2330 @ x
   .hword 0x1b0 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 786
   .word 0x2350 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x27e2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 787
   .word 0x2350 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x16c0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 788
   .word 0x2350 @ x
   .hword 0x150 @ y
   .hword 0xf @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 789
   .word 0x2350 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 790
   .word 0x2360 @ x
   .hword 0x110 @ y
   .hword 0xc @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 791
   .word 0x2360 @ x
   .hword 0x120 @ y
   .hword 0xc @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 792
   .word 0x2368 @ x
   .hword 0x1b0 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 793
   .word 0x2370 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 794
   .word 0x2370 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 795
   .word 0x2380 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 796
   .word 0x23a0 @ x
   .hword 0x130 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 797
   .word 0x23c8 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 798
   .word 0x23d8 @ x
   .hword 0x130 @ y
   .hword 0x11 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 799
   .word 0x23f0 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x6be2 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 800
   .word 0x23f0 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x4ae0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 801
   .word 0x23f0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 802
   .word 0x2413 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 803
   .word 0x2470 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 804
   .word 0x2480 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7c42 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 805
   .word 0x2480 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x5c00 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 806
   .word 0x2490 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 807
   .word 0x24c0 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 808
   .word 0x24d0 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 809
   .word 0x24f0 @ x
   .hword 0x1b0 @ y
   .hword 0x11 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 810
   .word 0x2520 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x7c3a @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 811
   .word 0x2520 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0x95 @ changes GROUND for 18 frames
   .hword 0x5812 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 812
   .word 0x2520 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 813
   .word 0x2520 @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 814
   .word 0x25c0 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 815
   .word 0x25d8 @ x
   .hword 0x130 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 816
   .word 0x25dc @ x
   .hword 0x150 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 817
   .word 0x25e8 @ x
   .hword 0x130 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 818
   .word 0x25f8 @ x
   .hword 0x130 @ y
   .hword 0x1e @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 819
   .word 0x2650 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x6c53 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 820
   .word 0x2650 @ x
   .hword 0xd0 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 821
   .word 0x2650 @ x
   .hword 0x148 @ y
   .hword 0x1a @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 822
   .word 0x2660 @ x
   .hword 0xc0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x3c0c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 823
   .word 0x2670 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 824
   .word 0x2680 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 825
   .word 0x2690 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 826
   .word 0x26a0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x6c53 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 827
   .word 0x26a0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 828
   .word 0x26b0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x3c0c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 829
   .word 0x26b0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 830
   .word 0x26c0 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 831
   .word 0x26c8 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 832
   .word 0x26d8 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 833
   .word 0x26e0 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 834
   .word 0x26ea @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x6c53 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 835
   .word 0x26f0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 836
   .word 0x26fa @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x3c0c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 837
   .word 0x2710 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 838
   .word 0x2718 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 839
   .word 0x2720 @ x
   .hword 0x144 @ y
   .hword 0xe @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 840
   .word 0x2740 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 841
   .word 0x2740 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 842
   .word 0x2750 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 843
   .word 0x2760 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 844
   .word 0x2770 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 845
   .word 0x2770 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 846
   .word 0x2780 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 847
   .word 0x2787 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x6c53 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 848
   .word 0x2797 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x3c0c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 849
   .word 0x2798 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 850
   .word 0x2798 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 851
   .word 0x27a0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 852
   .word 0x27c0 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 853
   .word 0x27d0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 854
   .word 0x27d0 @ x
   .hword 0x170 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 855
   .word 0x27d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 856
   .word 0x27e0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 857
   .word 0x27e0 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 858
   .word 0x2800 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 859
   .word 0x2820 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x6c53 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 860
   .word 0x2820 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 861
   .word 0x2820 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 862
   .word 0x2820 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 863
   .word 0x2830 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x3c0c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 864
   .word 0x2860 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 865
   .word 0x2870 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 866
   .word 0x2870 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 867
   .word 0x2880 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 868
   .word 0x2888 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 869
   .word 0x28a0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 870
   .word 0x28b9 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 871
   .word 0x28c0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 872
   .word 0x28c9 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 873
   .word 0x28d0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 874
   .word 0x28e0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 875
   .word 0x2906 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 876
   .word 0x2910 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 877
   .word 0x2910 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 878
   .word 0x2916 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 879
   .word 0x2920 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 880
   .word 0x2940 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 881
   .word 0x2940 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 882
   .word 0x2950 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 883
   .word 0x2950 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 884
   .word 0x2950 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 885
   .word 0x2960 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 886
   .word 0x2968 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 887
   .word 0x2980 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 888
   .word 0x2990 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 889
   .word 0x29a0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 890
   .word 0x29b0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 891
   .word 0x29b0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 892
   .word 0x29c0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 893
   .word 0x29c0 @ x
   .hword 0x130 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 894
   .word 0x29c0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 895
   .word 0x29c8 @ x
   .hword 0x180 @ y
   .hword 0x7 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 896
   .word 0x29e0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 897
   .word 0x29e0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 898
   .word 0x29e8 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 899
   .word 0x29e8 @ x
   .hword 0x160 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 900
   .word 0x29e8 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 901
   .word 0x29ea @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 902
   .word 0x29fa @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 903
   .word 0x2a10 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 904
   .word 0x2a13 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 905
   .word 0x2a13 @ x
   .hword 0x130 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 906
   .word 0x2a13 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 907
   .word 0x2a20 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 908
   .word 0x2a3d @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 909
   .word 0x2a3d @ x
   .hword 0x160 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 910
   .word 0x2a3d @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 911
   .word 0x2a40 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 912
   .word 0x2a60 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 913
   .word 0x2a60 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 914
   .word 0x2a70 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 915
   .word 0x2a96 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 916
   .word 0x2a9c @ x
   .hword 0x160 @ y
   .hword 0xf @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 917
   .word 0x2aa0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 918
   .word 0x2aa0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 919
   .word 0x2aa6 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 920
   .word 0x2ad0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x5c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 921
   .word 0x2ad0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 922
   .word 0x2ad0 @ x
   .hword 0x130 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 923
   .word 0x2ad0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 924
   .word 0x2ae0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x380f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 925
   .word 0x2ae0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 926
   .word 0x2ae0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 927
   .word 0x2b10 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 928
   .word 0x2b10 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 929
   .word 0x2b1b @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 930
   .word 0x2b2b @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 931
   .word 0x2b30 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 932
   .word 0x2b30 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 933
   .word 0x2b50 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 934
   .word 0x2b50 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 935
   .word 0x2b60 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 936
   .word 0x2b60 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 937
   .word 0x2b69 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 938
   .word 0x2b70 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 939
   .word 0x2b79 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 940
   .word 0x2b80 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 941
   .word 0x2ba0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 942
   .word 0x2bab @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 943
   .word 0x2bb0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 944
   .word 0x2bbb @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 945
   .word 0x2bc0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 946
   .word 0x2c10 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 947
   .word 0x2c10 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 948
   .word 0x2c40 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 949
   .word 0x2c40 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 950
   .word 0x2c50 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 951
   .word 0x2c60 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 952
   .word 0x2c60 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 953
   .word 0x2c60 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 954
   .word 0x2c60 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 955
   .word 0x2c70 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 956
   .word 0x2c80 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 957
   .word 0x2c90 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 958
   .word 0x2ca0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 959
   .word 0x2ca0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 960
   .word 0x2ca0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 961
   .word 0x2cc0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 962
   .word 0x2cd0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 963
   .word 0x2cd0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 964
   .word 0x2cdd @ x
   .hword 0x124 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 965
   .word 0x2cdd @ x
   .hword 0x134 @ y
   .hword 0x10 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 966
   .word 0x2cdd @ x
   .hword 0x144 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 967
   .word 0x2cf0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 968
   .word 0x2d00 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 969
   .word 0x2d00 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 970
   .word 0x2d10 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 971
   .word 0x2d10 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 972
   .word 0x2d20 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 973
   .word 0x2d30 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 974
   .word 0x2d30 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 975
   .word 0x2d40 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 976
   .word 0x2d50 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 977
   .word 0x2d50 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 978
   .word 0x2d50 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 979
   .word 0x2d70 @ x
   .hword 0x14e @ y
   .hword 0xf @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 980
   .word 0x2d80 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 981
   .word 0x2d80 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 982
   .word 0x2d90 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 983
   .word 0x2d90 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 984
   .word 0x2d90 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 985
   .word 0x2db0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 986
   .word 0x2db0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 987
   .word 0x2dd0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 988
   .word 0x2dd0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 989
   .word 0x2dd0 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 990
   .word 0x2dd0 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 991
   .word 0x2dd0 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 992
   .word 0x2de0 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 993
   .word 0x2df0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 994
   .word 0x2e00 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 995
   .word 0x2e20 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 996
   .word 0x2e20 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 997
   .word 0x2e20 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 998
   .word 0x2e20 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 999
   .word 0x2e30 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1000
   .word 0x2e30 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1001
   .word 0x2e30 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1002
   .word 0x2e50 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1003
   .word 0x2e70 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1004
   .word 0x2e70 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1005
   .word 0x2e70 @ x
   .hword 0x160 @ y
   .hword 0x9 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1006
   .word 0x2e70 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1007
   .word 0x2e80 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1008
   .word 0x2ea0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1009
   .word 0x2eb0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1010
   .word 0x2eb5 @ x
   .hword 0xef @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x245b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1011
   .word 0x2ec0 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1012
   .word 0x2ec5 @ x
   .hword 0xef @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x100f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1013
   .word 0x2ed0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1014
   .word 0x2ee0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1015
   .word 0x2ee0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1016
   .word 0x2f00 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1017
   .word 0x2f00 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1018
   .word 0x2f18 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1019
   .word 0x2f20 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1020
   .word 0x2f30 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1021
   .word 0x2f40 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1022
   .word 0x2f50 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x1e4 @ changes BG for 60 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1023
   .word 0x2f50 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1024
   .word 0x2f70 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1025
   .word 0x2f70 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1026
   .word 0x2f70 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1027
   .word 0x2f80 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1028
   .word 0x2fa0 @ x
   .hword 0x110 @ y
   .hword 0x4 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1029
   .word 0x2fa0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1030
   .word 0x2fb0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1031
   .word 0x2fb0 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1032
   .word 0x2fd0 @ x
   .hword 0x110 @ y
   .hword 0x5 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1033
   .word 0x2fd0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1034
   .word 0x2fe0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1035
   .word 0x2fe8 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1036
   .word 0x2ff0 @ x
   .hword 0x148 @ y
   .hword 0x1 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1037
   .word 0x2ff4 @ x
   .hword 0x148 @ y
   .hword 0xe @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1038
   .word 0x2ff8 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1039
   .word 0x3010 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1040
   .word 0x3020 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1041
   .word 0x3020 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1042
   .word 0x3040 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1043
   .word 0x3049 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1044
   .word 0x3050 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1045
   .word 0x3050 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1046
   .word 0x3059 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1047
   .word 0x3060 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1048
   .word 0x3070 @ x
   .hword 0x130 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1049
   .word 0x3070 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1050
   .word 0x3070 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1051
   .word 0x3080 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1052
   .word 0x3080 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1053
   .word 0x3080 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1054
   .word 0x3090 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1055
   .word 0x3098 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1056
   .word 0x3098 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1057
   .word 0x30a0 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1058
   .word 0x30a0 @ x
   .hword 0x110 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1059
   .word 0x30a0 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1060
   .word 0x30a0 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1061
   .word 0x30a8 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1062
   .word 0x30a8 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1063
   .word 0x30c0 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1064
   .word 0x30d0 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1065
   .word 0x30d0 @ x
   .hword 0x120 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1066
   .word 0x30d0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1067
   .word 0x30d0 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1068
   .word 0x30f0 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1069
   .word 0x30f0 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1070
   .word 0x30f0 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1071
   .word 0x3100 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1072
   .word 0x3100 @ x
   .hword 0x180 @ y
   .hword 0x7 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1073
   .word 0x3110 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1074
   .word 0x3110 @ x
   .hword 0x100 @ y
   .hword 0x7 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1075
   .word 0x3110 @ x
   .hword 0x130 @ y
   .hword 0x7 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1076
   .word 0x3119 @ x
   .hword 0xe2 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1077
   .word 0x3120 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1078
   .word 0x3120 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1079
   .word 0x3129 @ x
   .hword 0xe2 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1080
   .word 0x3130 @ x
   .hword 0x140 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1081
   .word 0x3130 @ x
   .hword 0x180 @ y
   .hword 0x7 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1082
   .word 0x3140 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1083
   .word 0x3140 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1084
   .word 0x315c @ x
   .hword 0x120 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1085
   .word 0x315c @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1086
   .word 0x3170 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1087
   .word 0x3170 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1088
   .word 0x3170 @ x
   .hword 0x158 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1089
   .word 0x3170 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1090
   .word 0x3188 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1091
   .word 0x3188 @ x
   .hword 0x170 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1092
   .word 0x318c @ x
   .hword 0x17c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1093
   .word 0x3190 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1094
   .word 0x3190 @ x
   .hword 0x110 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1095
   .word 0x3190 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1096
   .word 0x3198 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1097
   .word 0x3198 @ x
   .hword 0x170 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1098
   .word 0x31b0 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1099
   .word 0x31b0 @ x
   .hword 0x158 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1100
   .word 0x31b0 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1101
   .word 0x31b5 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1102
   .word 0x31c0 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1103
   .word 0x31c0 @ x
   .hword 0x120 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1104
   .word 0x31c0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1105
   .word 0x31c5 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1106
   .word 0x31d0 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1107
   .word 0x31dc @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1108
   .word 0x31e0 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1109
   .word 0x31f0 @ x
   .hword 0x130 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1110
   .word 0x31f0 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1111
   .word 0x3200 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1112
   .word 0x3200 @ x
   .hword 0x158 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1113
   .word 0x3200 @ x
   .hword 0x170 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1114
   .word 0x3200 @ x
   .hword 0x188 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1115
   .word 0x3218 @ x
   .hword 0x140 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1116
   .word 0x3220 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1117
   .word 0x3220 @ x
   .hword 0x120 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1118
   .word 0x3228 @ x
   .hword 0x140 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1119
   .word 0x3240 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1120
   .word 0x3240 @ x
   .hword 0x158 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1121
   .word 0x3240 @ x
   .hword 0x170 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1122
   .word 0x3240 @ x
   .hword 0x188 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1123
   .word 0x3240 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1124
   .word 0x3250 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1125
   .word 0x3250 @ x
   .hword 0x130 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1126
   .word 0x3260 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1127
   .word 0x3260 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1128
   .word 0x3268 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1129
   .word 0x3270 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1130
   .word 0x3280 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1131
   .word 0x3290 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1132
   .word 0x3298 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1133
   .word 0x32b0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1134
   .word 0x32b0 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1135
   .word 0x32b0 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1136
   .word 0x32b0 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1137
   .word 0x32b0 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1138
   .word 0x32c0 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1139
   .word 0x32c0 @ x
   .hword 0x180 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1140
   .word 0x32c8 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1141
   .word 0x32d8 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1142
   .word 0x32e0 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1143
   .word 0x32e8 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1144
   .word 0x32f0 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1145
   .word 0x32f0 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1146
   .word 0x32f0 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1147
   .word 0x32f0 @ x
   .hword 0x148 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1148
   .word 0x32f0 @ x
   .hword 0x170 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1149
   .word 0x32f8 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x94 @ changes BG for 18 frames
   .hword 0x6e82 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1150
   .word 0x3310 @ x
   .hword 0x150 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1151
   .word 0x3318 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1152
   .word 0x3320 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1153
   .word 0x3338 @ x
   .hword 0x138 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1154
   .word 0x3340 @ x
   .hword 0x178 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1155
   .word 0x3340 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1156
   .word 0x3350 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1157
   .word 0x3358 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1158
   .word 0x3358 @ x
   .hword 0x190 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1159
   .word 0x3360 @ x
   .hword 0x140 @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1160
   .word 0x3360 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1161
   .word 0x3370 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1162
   .word 0x3370 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1163
   .word 0x3378 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1164
   .word 0x3378 @ x
   .hword 0x190 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1165
   .word 0x3380 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x7f40 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1166
   .word 0x3388 @ x
   .hword 0x100 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1167
   .word 0x3388 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1168
   .word 0x3390 @ x
   .hword 0xe0 @ y
   .hword 0x3 @ type
   .hword 0x5a4 @ changes BG for 180 frames
   .hword 0x3c5b @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0000 @ Empty, needed for word alignment
@ Object 1169
   .word 0x3390 @ x
   .hword 0x178 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1170
   .word 0x3390 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1171
   .word 0x3394 @ x
   .hword 0x14c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1172
   .word 0x3398 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1173
   .word 0x33a8 @ x
   .hword 0x100 @ y
   .hword 0x6 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1174
   .word 0x33a8 @ x
   .hword 0x130 @ y
   .hword 0x6 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1175
   .word 0x33b0 @ x
   .hword 0x190 @ y
   .hword 0x19 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1176
   .word 0x33c0 @ x
   .hword 0x100 @ y
   .hword 0x18 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1177
   .word 0x33c0 @ x
   .hword 0x118 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1178
   .word 0x33c0 @ x
   .hword 0x14c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1179
   .word 0x33d0 @ x
   .hword 0x190 @ y
   .hword 0x18 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1180
   .word 0x33e0 @ x
   .hword 0x100 @ y
   .hword 0x19 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1181
   .word 0x33e0 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1182
   .word 0x33e0 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 49152 @ rotation
@ Object 1183
   .word 0x33f0 @ x
   .hword 0x130 @ y
   .hword 0x7 @ type
   .hword 0x1 @ bg layer 0 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 1184
   .word 0x33f0 @ x
   .hword 0x14c @ y
   .hword 0x17 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1185
   .word 0x33f0 @ x
   .hword 0x160 @ y
   .hword 0x7 @ type
   .hword 0x0 @ bg layer 0 non rotated   
   .hword 0 @ rotation
@ Object 1186
   .word 0x3400 @ x
   .hword 0x110 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
@ Object 1187
   .word 0x3400 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x4 @ bg layer 0 rotated   
   .hword 16384 @ rotation
   .byte 0xff
