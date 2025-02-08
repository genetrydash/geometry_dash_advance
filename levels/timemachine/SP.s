@ Sprite Data Export

.section .rodata
.align 2
.global timemachine_spr_data
.hidden timemachine_spr_data
timemachine_spr_data:
@ Object 1
   .word 0x10 @ x
   .hword 0x170 @ y
   .hword 0x3 @ type
   .hword 0x2d4 @ changes BG for 90 frames
   .hword 0x5bc0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 2
   .word 0x10 @ x
   .hword 0x180 @ y
   .hword 0x3 @ type
   .hword 0x2d5 @ changes GROUND for 90 frames
   .hword 0x3620 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 3
   .word 0x150 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 4
   .word 0x190 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 5
   .word 0x1b6 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 6
   .word 0x1c3 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 7
   .word 0x1e0 @ x
   .hword 0x1a0 @ y
   .hword 0xd @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 8
   .word 0x246 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 9
   .word 0x256 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 10
   .word 0x288 @ x
   .hword 0x18c @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 11
   .word 0x288 @ x
   .hword 0x19c @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 12
   .word 0x2b3 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 13
   .word 0x2c0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 14
   .word 0x2c0 @ x
   .hword 0x190 @ y
   .hword 0xf @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 15
   .word 0x300 @ x
   .hword 0x1a0 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 16
   .word 0x345 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 17
   .word 0x355 @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 18
   .word 0x363 @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 19
   .word 0x388 @ x
   .hword 0x1a0 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 20
   .word 0x398 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 21
   .word 0x3a8 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 22
   .word 0x3b8 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 23
   .word 0x3d0 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 24
   .word 0x3ed @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 25
   .word 0x3fb @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 26
   .word 0x410 @ x
   .hword 0x1a0 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 27
   .word 0x480 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 28
   .word 0x4a0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 29
   .word 0x4b0 @ x
   .hword 0x168 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 30
   .word 0x4c0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 31
   .word 0x4e0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 32
   .word 0x4f8 @ x
   .hword 0x190 @ y
   .hword 0xe @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 33
   .word 0x546 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 34
   .word 0x553 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 35
   .word 0x570 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 36
   .word 0x580 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 37
   .word 0x5a0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 38
   .word 0x5b0 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 39
   .word 0x5b0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 40
   .word 0x5d0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 41
   .word 0x5f0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 42
   .word 0x610 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 43
   .word 0x640 @ x
   .hword 0x1a0 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 44
   .word 0x650 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 45
   .word 0x680 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 46
   .word 0x688 @ x
   .hword 0x190 @ y
   .hword 0xf @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 47
   .word 0x690 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 48
   .word 0x6b0 @ x
   .hword 0x160 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 49
   .word 0x6d8 @ x
   .hword 0x160 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 50
   .word 0x700 @ x
   .hword 0x160 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 51
   .word 0x718 @ x
   .hword 0x160 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 52
   .word 0x720 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 53
   .word 0x720 @ x
   .hword 0x190 @ y
   .hword 0xe @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 54
   .word 0x730 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 55
   .word 0x770 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 56
   .word 0x7c0 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 57
   .word 0x7d0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 58
   .word 0x7e0 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 59
   .word 0x800 @ x
   .hword 0x170 @ y
   .hword 0x59 @ type
   .hword 0x20 @ coin 0 bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 60
   .word 0x820 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 61
   .word 0x830 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 62
   .word 0x840 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 63
   .word 0x890 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 64
   .word 0x8c0 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 65
   .word 0x8e0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 66
   .word 0x900 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 67
   .word 0x920 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 68
   .word 0x940 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 69
   .word 0x958 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 70
   .word 0x970 @ x
   .hword 0x130 @ y
   .hword 0x3 @ type
   .hword 0x125 @ changes GROUND for 36 frames
   .hword 0x5020 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 71
   .word 0x970 @ x
   .hword 0x140 @ y
   .hword 0x3 @ type
   .hword 0x124 @ changes BG for 36 frames
   .hword 0x7d80 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 72
   .word 0x9ed @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 73
   .word 0x9fa @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 74
   .word 0xa10 @ x
   .hword 0x170 @ y
   .hword 0xd @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 75
   .word 0xa50 @ x
   .hword 0x170 @ y
   .hword 0xd @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 76
   .word 0xa67 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 77
   .word 0xa74 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 78
   .word 0xa81 @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 79
   .word 0xad0 @ x
   .hword 0x150 @ y
   .hword 0xd @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 80
   .word 0xb10 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 81
   .word 0xb20 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 82
   .word 0xbb0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 83
   .word 0xbd0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 84
   .word 0xbe0 @ x
   .hword 0x1a0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 85
   .word 0xbf0 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 86
   .word 0xbf1 @ x
   .hword 0x188 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 87
   .word 0xc10 @ x
   .hword 0x1a0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 88
   .word 0xc39 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 89
   .word 0xc40 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 90
   .word 0xc60 @ x
   .hword 0x1a0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 91
   .word 0xc7b @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 92
   .word 0xc90 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 93
   .word 0xca0 @ x
   .hword 0x1a0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 94
   .word 0xcc4 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 95
   .word 0xcd0 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 96
   .word 0xcd0 @ x
   .hword 0x1a0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 97
   .word 0xcf0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 98
   .word 0xd10 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 99
   .word 0xd50 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 100
   .word 0xd70 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 101
   .word 0xd90 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 102
   .word 0xdd0 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 103
   .word 0xdd0 @ x
   .hword 0x1b0 @ y
   .hword 0x7 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 104
   .word 0xdf0 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 105
   .word 0xe08 @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 106
   .word 0xe18 @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 107
   .word 0xe40 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 108
   .word 0xe70 @ x
   .hword 0x170 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 109
   .word 0xe80 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 110
   .word 0xea0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 111
   .word 0xed0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 112
   .word 0xee8 @ x
   .hword 0x180 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 113
   .word 0xf00 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 114
   .word 0xf40 @ x
   .hword 0x180 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 115
   .word 0xfaa @ x
   .hword 0x14d @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 116
   .word 0xfaa @ x
   .hword 0x15d @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 117
   .word 0xfaa @ x
   .hword 0x16d @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 118
   .word 0xff0 @ x
   .hword 0x1a0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 119
   .word 0xff8 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 120
   .word 0x1010 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 121
   .word 0x1030 @ x
   .hword 0x1a0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 122
   .word 0x1090 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 123
   .word 0x10c0 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 124
   .word 0x10d0 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 125
   .word 0x10f0 @ x
   .hword 0x180 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 126
   .word 0x1110 @ x
   .hword 0x180 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 127
   .word 0x1140 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 128
   .word 0x1158 @ x
   .hword 0x190 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 129
   .word 0x1170 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 130
   .word 0x11a0 @ x
   .hword 0x190 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 131
   .word 0x11b0 @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 132
   .word 0x11e0 @ x
   .hword 0x190 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 133
   .word 0x11f0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 134
   .word 0x1208 @ x
   .hword 0x190 @ y
   .hword 0x4 @ type
   .hword 0x22 @ bg layer 4 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 135
   .word 0x1230 @ x
   .hword 0x130 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x5c1f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 136
   .word 0x1230 @ x
   .hword 0x140 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x3c13 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 137
   .word 0x1240 @ x
   .hword 0x160 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 138
   .word 0x1260 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 139
   .word 0x1290 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 140
   .word 0x1290 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 141
   .word 0x12c0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 142
   .word 0x12c0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 143
   .word 0x12f0 @ x
   .hword 0x130 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 144
   .word 0x12f0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 145
   .word 0x1320 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 146
   .word 0x1320 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 147
   .word 0x1350 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 148
   .word 0x1380 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 149
   .word 0x1390 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 150
   .word 0x1390 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 151
   .word 0x13a8 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 152
   .word 0x13c0 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 153
   .word 0x13c0 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 154
   .word 0x13d0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 155
   .word 0x13f0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 156
   .word 0x13f0 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 157
   .word 0x1400 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 158
   .word 0x1430 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 159
   .word 0x1430 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 160
   .word 0x1430 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 161
   .word 0x1458 @ x
   .hword 0x160 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 162
   .word 0x1458 @ x
   .hword 0x170 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 163
   .word 0x1458 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 164
   .word 0x1458 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 165
   .word 0x1480 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 166
   .word 0x1480 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 167
   .word 0x1480 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 168
   .word 0x1490 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 169
   .word 0x14b0 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 170
   .word 0x14b0 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 171
   .word 0x14c0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 172
   .word 0x14d6 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 173
   .word 0x14d6 @ x
   .hword 0x138 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 174
   .word 0x14d6 @ x
   .hword 0x148 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 175
   .word 0x14d6 @ x
   .hword 0x180 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 176
   .word 0x14d6 @ x
   .hword 0x190 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 177
   .word 0x14d6 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 178
   .word 0x14e0 @ x
   .hword 0x1b0 @ y
   .hword 0x7 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 179
   .word 0x14f8 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 180
   .word 0x14f8 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 181
   .word 0x1510 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 182
   .word 0x151b @ x
   .hword 0x121 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 183
   .word 0x151b @ x
   .hword 0x131 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 184
   .word 0x151b @ x
   .hword 0x141 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 185
   .word 0x151b @ x
   .hword 0x17d @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 186
   .word 0x151b @ x
   .hword 0x18d @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 187
   .word 0x151b @ x
   .hword 0x19d @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 188
   .word 0x1520 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 189
   .word 0x1538 @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 190
   .word 0x155a @ x
   .hword 0x114 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 191
   .word 0x155a @ x
   .hword 0x124 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 192
   .word 0x155a @ x
   .hword 0x134 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 193
   .word 0x155a @ x
   .hword 0x170 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 194
   .word 0x155a @ x
   .hword 0x180 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 195
   .word 0x155a @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 196
   .word 0x1560 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 197
   .word 0x1578 @ x
   .hword 0x170 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 198
   .word 0x1580 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 199
   .word 0x15a0 @ x
   .hword 0x10a @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 200
   .word 0x15a0 @ x
   .hword 0x11a @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 201
   .word 0x15a0 @ x
   .hword 0x12a @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 202
   .word 0x15a0 @ x
   .hword 0x166 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 203
   .word 0x15a0 @ x
   .hword 0x176 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 204
   .word 0x15a0 @ x
   .hword 0x186 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 205
   .word 0x15a0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 206
   .word 0x15cc @ x
   .hword 0x180 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 207
   .word 0x15cc @ x
   .hword 0x180 @ y
   .hword 0xd @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 208
   .word 0x15cc @ x
   .hword 0x190 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 16 @ metatile ID appareance
@ Object 209
   .word 0x15cc @ x
   .hword 0x1a0 @ y
   .hword 0x2c @ type
   .hword 0x20 @ bg layer 4   
   .hword 43 @ metatile ID appareance
@ Object 210
   .word 0x15cc @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 211
   .word 0x15d0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 212
   .word 0x1620 @ x
   .hword 0x160 @ y
   .hword 0x1 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 213
   .word 0x1648 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 214
   .word 0x1650 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 215
   .word 0x1670 @ x
   .hword 0x120 @ y
   .hword 0x6 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 216
   .word 0x1670 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 217
   .word 0x16a0 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 218
   .word 0x16a0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 219
   .word 0x16d0 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 220
   .word 0x16d0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 221
   .word 0x16e0 @ x
   .hword 0x158 @ y
   .hword 0x1f @ type
   .hword 0x12 @ bg layer 2 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 222
   .word 0x16e0 @ x
   .hword 0x178 @ y
   .hword 0x1f @ type
   .hword 0x12 @ bg layer 2 non rotated flipped horizontally  
   .hword 0 @ rotation
@ Object 223
   .word 0x16f0 @ x
   .hword 0x148 @ y
   .hword 0x20 @ type
   .hword 0x10 @ bg layer 2 non rotated   
   .hword 0 @ rotation
@ Object 224
   .word 0x16f0 @ x
   .hword 0x158 @ y
   .hword 0x2b @ type
   .hword 0x10 @ bg layer 2   
   .hword 8 @ metatile ID appareance
@ Object 225
   .word 0x16f0 @ x
   .hword 0x168 @ y
   .hword 0x2b @ type
   .hword 0x10 @ bg layer 2   
   .hword 22 @ metatile ID appareance
@ Object 226
   .word 0x16f0 @ x
   .hword 0x178 @ y
   .hword 0x2b @ type
   .hword 0x11 @ bg layer 2  flipped vertically 
   .hword 8 @ metatile ID appareance
@ Object 227
   .word 0x16f0 @ x
   .hword 0x188 @ y
   .hword 0x20 @ type
   .hword 0x11 @ bg layer 2 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 228
   .word 0x1700 @ x
   .hword 0x120 @ y
   .hword 0x6 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 229
   .word 0x1700 @ x
   .hword 0x148 @ y
   .hword 0x20 @ type
   .hword 0x10 @ bg layer 2 non rotated   
   .hword 0 @ rotation
@ Object 230
   .word 0x1700 @ x
   .hword 0x158 @ y
   .hword 0x2b @ type
   .hword 0x10 @ bg layer 2   
   .hword 4 @ metatile ID appareance
@ Object 231
   .word 0x1700 @ x
   .hword 0x168 @ y
   .hword 0x2b @ type
   .hword 0x10 @ bg layer 2   
   .hword 22 @ metatile ID appareance
@ Object 232
   .word 0x1700 @ x
   .hword 0x168 @ y
   .hword 0x59 @ type
   .hword 0x88 @ coin 1 bg layer 1 non rotated   
   .hword 0 @ rotation
@ Object 233
   .word 0x1700 @ x
   .hword 0x178 @ y
   .hword 0x2b @ type
   .hword 0x11 @ bg layer 2  flipped vertically 
   .hword 4 @ metatile ID appareance
@ Object 234
   .word 0x1700 @ x
   .hword 0x188 @ y
   .hword 0x20 @ type
   .hword 0x11 @ bg layer 2 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 235
   .word 0x1700 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 236
   .word 0x1710 @ x
   .hword 0x148 @ y
   .hword 0x20 @ type
   .hword 0x10 @ bg layer 2 non rotated   
   .hword 0 @ rotation
@ Object 237
   .word 0x1710 @ x
   .hword 0x158 @ y
   .hword 0x2b @ type
   .hword 0x12 @ bg layer 2 flipped horizontally  
   .hword 8 @ metatile ID appareance
@ Object 238
   .word 0x1710 @ x
   .hword 0x168 @ y
   .hword 0x2b @ type
   .hword 0x10 @ bg layer 2   
   .hword 22 @ metatile ID appareance
@ Object 239
   .word 0x1710 @ x
   .hword 0x178 @ y
   .hword 0x2b @ type
   .hword 0x13 @ bg layer 2 flipped horizontally flipped vertically 
   .hword 8 @ metatile ID appareance
@ Object 240
   .word 0x1710 @ x
   .hword 0x188 @ y
   .hword 0x20 @ type
   .hword 0x11 @ bg layer 2 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 241
   .word 0x1720 @ x
   .hword 0x158 @ y
   .hword 0x1f @ type
   .hword 0x10 @ bg layer 2 non rotated   
   .hword 0 @ rotation
@ Object 242
   .word 0x1720 @ x
   .hword 0x178 @ y
   .hword 0x1f @ type
   .hword 0x10 @ bg layer 2 non rotated   
   .hword 0 @ rotation
@ Object 243
   .word 0x1720 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 244
   .word 0x1730 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 245
   .word 0x1750 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 246
   .word 0x1760 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 247
   .word 0x1780 @ x
   .hword 0x120 @ y
   .hword 0x6 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 248
   .word 0x1780 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 249
   .word 0x17f0 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 250
   .word 0x17f0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 251
   .word 0x1820 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 252
   .word 0x1938 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 253
   .word 0x1940 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 254
   .word 0x1960 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 255
   .word 0x1970 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 256
   .word 0x1990 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 257
   .word 0x19b0 @ x
   .hword 0x140 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 258
   .word 0x19c0 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 259
   .word 0x1ab8 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 260
   .word 0x1ac0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 261
   .word 0x1ad0 @ x
   .hword 0x140 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 262
   .word 0x1ad0 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 263
   .word 0x1ae0 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 264
   .word 0x1af0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 265
   .word 0x1b00 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 266
   .word 0x1b00 @ x
   .hword 0x168 @ y
   .hword 0x2 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 267
   .word 0x1b50 @ x
   .hword 0x1a0 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 268
   .word 0x1b50 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 269
   .word 0x1b70 @ x
   .hword 0x1b0 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 270
   .word 0x1b90 @ x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 271
   .word 0x1b90 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 272
   .word 0x1bb0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 273
   .word 0x1bc0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 274
   .word 0x1bd0 @ x
   .hword 0x180 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 275
   .word 0x1bf0 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 276
   .word 0x1c00 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 277
   .word 0x1c10 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 278
   .word 0x1c10 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 279
   .word 0x1c20 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 280
   .word 0x1c30 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 281
   .word 0x1c40 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 282
   .word 0x1c40 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 283
   .word 0x1c40 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 284
   .word 0x1c70 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 285
   .word 0x1c70 @ x
   .hword 0x178 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 286
   .word 0x1c70 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 287
   .word 0x1c90 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 288
   .word 0x1ca0 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 289
   .word 0x1ca0 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 290
   .word 0x1cc0 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 291
   .word 0x1cd0 @ x
   .hword 0x140 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 292
   .word 0x1cd0 @ x
   .hword 0x168 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 293
   .word 0x1ce0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 294
   .word 0x1d10 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 295
   .word 0x1d30 @ x
   .hword 0x110 @ y
   .hword 0x3 @ type
   .hword 0x12c5 @ changes GROUND for 600 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 296
   .word 0x1d30 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x12c4 @ changes BG for 600 frames
   .hword 0x0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 297
   .word 0x1d30 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 298
   .word 0x1d50 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 299
   .word 0x1d50 @ x
   .hword 0x138 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 300
   .word 0x1d50 @ x
   .hword 0x148 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 301
   .word 0x1d74 @ x
   .hword 0x160 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 302
   .word 0x1d80 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 303
   .word 0x1d81 @ x
   .hword 0x160 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 304
   .word 0x1d8e @ x
   .hword 0x160 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 305
   .word 0x1dc0 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 306
   .word 0x1de0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 307
   .word 0x1df0 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 308
   .word 0x1e00 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 309
   .word 0x1e60 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 310
   .word 0x1e90 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 311
   .word 0x1e90 @ x
   .hword 0x168 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 312
   .word 0x1e90 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 313
   .word 0x1eb0 @ x
   .hword 0x150 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 314
   .word 0x1eb0 @ x
   .hword 0x178 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 315
   .word 0x1eb0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 316
   .word 0x1ed0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 317
   .word 0x1ee0 @ x
   .hword 0x108 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 318
   .word 0x1ee0 @ x
   .hword 0x158 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 319
   .word 0x1f00 @ x
   .hword 0x140 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 320
   .word 0x1f00 @ x
   .hword 0x168 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 321
   .word 0x1f00 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 322
   .word 0x1f30 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 323
   .word 0x1f60 @ x
   .hword 0x120 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 324
   .word 0x1f60 @ x
   .hword 0x148 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 325
   .word 0x1f60 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 326
   .word 0x1f70 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 327
   .word 0x1fa0 @ x
   .hword 0x118 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 328
   .word 0x1fa0 @ x
   .hword 0x148 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 329
   .word 0x1fa0 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 330
   .word 0x1fb8 @ x
   .hword 0x148 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 331
   .word 0x1fc0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 332
   .word 0x1fe8 @ x
   .hword 0x118 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 333
   .word 0x1fe8 @ x
   .hword 0x148 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 334
   .word 0x1ff0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 335
   .word 0x2018 @ x
   .hword 0x148 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 336
   .word 0x2020 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 337
   .word 0x2030 @ x
   .hword 0x118 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 338
   .word 0x2030 @ x
   .hword 0x148 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 339
   .word 0x2050 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 340
   .word 0x2060 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 341
   .word 0x2090 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 342
   .word 0x2090 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 343
   .word 0x20a0 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 344
   .word 0x20a0 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 345
   .word 0x20a0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 346
   .word 0x20d0 @ x
   .hword 0xe0 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 347
   .word 0x20d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 348
   .word 0x20d0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 349
   .word 0x20d0 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 350
   .word 0x2100 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 351
   .word 0x2100 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 352
   .word 0x2100 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 353
   .word 0x2130 @ x
   .hword 0xf0 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 354
   .word 0x2130 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 355
   .word 0x2130 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 356
   .word 0x2140 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 357
   .word 0x2160 @ x
   .hword 0x168 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 358
   .word 0x2170 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 359
   .word 0x2190 @ x
   .hword 0x190 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 360
   .word 0x2190 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 361
   .word 0x21b0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 362
   .word 0x2210 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 363
   .word 0x2220 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 364
   .word 0x2240 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 365
   .word 0x2240 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 366
   .word 0x2250 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 16384 @ rotation
@ Object 367
   .word 0x2260 @ x
   .hword 0x170 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 368
   .word 0x2280 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 369
   .word 0x22a8 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 370
   .word 0x22d0 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 371
   .word 0x22d8 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 372
   .word 0x2300 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 373
   .word 0x2310 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 374
   .word 0x2310 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 375
   .word 0x2330 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 376
   .word 0x2350 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 377
   .word 0x2350 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 378
   .word 0x2360 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 379
   .word 0x237c @ x
   .hword 0x150 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 380
   .word 0x23a0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 381
   .word 0x23d0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 382
   .word 0x2400 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 383
   .word 0x2450 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 384
   .word 0x2498 @ x
   .hword 0x150 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 385
   .word 0x24d0 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 386
   .word 0x2538 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 387
   .word 0x2560 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 388
   .word 0x2568 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 389
   .word 0x2570 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 390
   .word 0x2570 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 391
   .word 0x25a0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 392
   .word 0x25b0 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 393
   .word 0x25b0 @ x
   .hword 0x198 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 394
   .word 0x25c8 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 395
   .word 0x25f0 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 396
   .word 0x25f0 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 397
   .word 0x2610 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 398
   .word 0x2630 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 399
   .word 0x2658 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 400
   .word 0x2680 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 401
   .word 0x26a0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 402
   .word 0x26c0 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 403
   .word 0x26c8 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 404
   .word 0x26d0 @ x
   .hword 0x1a8 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 405
   .word 0x26e0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 406
   .word 0x2700 @ x
   .hword 0x190 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 407
   .word 0x2720 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 408
   .word 0x2750 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 409
   .word 0x2750 @ x
   .hword 0x188 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 410
   .word 0x2750 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 411
   .word 0x2780 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 412
   .word 0x2790 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 413
   .word 0x2790 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 414
   .word 0x27a0 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 415
   .word 0x27d0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 416
   .word 0x27e0 @ x
   .hword 0x190 @ y
   .hword 0xf @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 417
   .word 0x2800 @ x
   .hword 0x140 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 418
   .word 0x2800 @ x
   .hword 0x160 @ y
   .hword 0x3 @ type
   .hword 0x12c4 @ changes BG for 600 frames
   .hword 0x4013 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 419
   .word 0x2800 @ x
   .hword 0x170 @ y
   .hword 0x3 @ type
   .hword 0x12c5 @ changes GROUND for 600 frames
   .hword 0x4013 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 420
   .word 0x2800 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 421
   .word 0x2830 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 422
   .word 0x2870 @ x
   .hword 0x140 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 423
   .word 0x2870 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 424
   .word 0x28b0 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 425
   .word 0x28b0 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 426
   .word 0x28b0 @ x
   .hword 0x140 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 427
   .word 0x28d0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 428
   .word 0x28d0 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 429
   .word 0x28f0 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 430
   .word 0x28f0 @ x
   .hword 0x150 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 431
   .word 0x2900 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 432
   .word 0x2919 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 433
   .word 0x2919 @ x
   .hword 0x138 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 434
   .word 0x2919 @ x
   .hword 0x148 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 435
   .word 0x2920 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 436
   .word 0x2920 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 437
   .word 0x2940 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 438
   .word 0x2940 @ x
   .hword 0x140 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 439
   .word 0x2940 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 440
   .word 0x2950 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 441
   .word 0x2960 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 442
   .word 0x2960 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 443
   .word 0x2970 @ x
   .hword 0x108 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 444
   .word 0x2970 @ x
   .hword 0x130 @ y
   .hword 0xa @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 445
   .word 0x2980 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 446
   .word 0x2980 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 447
   .word 0x2998 @ x
   .hword 0x110 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 448
   .word 0x2998 @ x
   .hword 0x120 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 449
   .word 0x2998 @ x
   .hword 0x130 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 450
   .word 0x29a0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 451
   .word 0x29b0 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 452
   .word 0x29c0 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 453
   .word 0x29c0 @ x
   .hword 0x140 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 454
   .word 0x29d0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 455
   .word 0x29e0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 456
   .word 0x29e9 @ x
   .hword 0x120 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 457
   .word 0x29e9 @ x
   .hword 0x130 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 458
   .word 0x29e9 @ x
   .hword 0x140 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 459
   .word 0x2a10 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 460
   .word 0x2a10 @ x
   .hword 0x140 @ y
   .hword 0xa @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 461
   .word 0x2a20 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 462
   .word 0x2a30 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 463
   .word 0x2a60 @ x
   .hword 0x158 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 464
   .word 0x2a60 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 465
   .word 0x2a80 @ x
   .hword 0x90 @ y
   .hword 0x6 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 466
   .word 0x2aa0 @ x
   .hword 0x90 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 467
   .word 0x2ab0 @ x
   .hword 0x180 @ y
   .hword 0xe @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 468
   .word 0x2ad0 @ x
   .hword 0x90 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 469
   .word 0x2ad0 @ x
   .hword 0xc0 @ y
   .hword 0xe @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 470
   .word 0x2ae0 @ x
   .hword 0x90 @ y
   .hword 0x6 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 471
   .word 0x2b00 @ x
   .hword 0xe0 @ y
   .hword 0x59 @ type
   .hword 0x120 @ coin 2 bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 472
   .word 0x2b20 @ x
   .hword 0x110 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 473
   .word 0x2b60 @ x
   .hword 0x130 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 474
   .word 0x2b70 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 475
   .word 0x2bdc @ x
   .hword 0x17d @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 476
   .word 0x2bdc @ x
   .hword 0x18d @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 477
   .word 0x2bdc @ x
   .hword 0x19d @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 478
   .word 0x2be9 @ x
   .hword 0x17d @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 479
   .word 0x2be9 @ x
   .hword 0x18d @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 480
   .word 0x2be9 @ x
   .hword 0x19d @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 481
   .word 0x2c40 @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 482
   .word 0x2c56 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 483
   .word 0x2c64 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 484
   .word 0x2c70 @ x
   .hword 0x150 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x681f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 485
   .word 0x2c70 @ x
   .hword 0x160 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x3c12 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 486
   .word 0x2c70 @ x
   .hword 0x16c @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 487
   .word 0x2c72 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 488
   .word 0x2d10 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 489
   .word 0x2d50 @ x
   .hword 0x170 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 490
   .word 0x2df0 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 491
   .word 0x2e0d @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 492
   .word 0x2e1a @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 493
   .word 0x2e30 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 494
   .word 0x2e40 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 495
   .word 0x2e60 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 496
   .word 0x2e70 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 497
   .word 0x2e84 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 498
   .word 0x2e91 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 499
   .word 0x2e9e @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 500
   .word 0x2f16 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 501
   .word 0x2f23 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 502
   .word 0x2f40 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 503
   .word 0x2f60 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 504
   .word 0x2f80 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 505
   .word 0x2fa0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 506
   .word 0x2fc0 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 507
   .word 0x3000 @ x
   .hword 0x140 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 508
   .word 0x3010 @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 509
   .word 0x308d @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 510
   .word 0x309a @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 511
   .word 0x30b0 @ x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 512
   .word 0x30c6 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 513
   .word 0x30d0 @ x
   .hword 0x150 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x3e1 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 514
   .word 0x30d0 @ x
   .hword 0x160 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x200 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 515
   .word 0x30d0 @ x
   .hword 0x168 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 516
   .word 0x30d4 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 517
   .word 0x30e2 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 518
   .word 0x3100 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 519
   .word 0x3178 @ x
   .hword 0x180 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 520
   .word 0x31a0 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 521
   .word 0x31b0 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 522
   .word 0x31d0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 523
   .word 0x3200 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 524
   .word 0x3230 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 525
   .word 0x3240 @ x
   .hword 0x1a0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 526
   .word 0x3255 @ x
   .hword 0x1a0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 527
   .word 0x3260 @ x
   .hword 0x150 @ y
   .hword 0x3 @ type
   .hword 0x784 @ changes BG for 240 frames
   .hword 0x7fe0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 528
   .word 0x3260 @ x
   .hword 0x160 @ y
   .hword 0x3 @ type
   .hword 0x785 @ changes GROUND for 240 frames
   .hword 0x5aa0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 529
   .word 0x3288 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 530
   .word 0x3288 @ x
   .hword 0x1b0 @ y
   .hword 0x2c @ type
   .hword 0x20 @ bg layer 4   
   .hword 43 @ metatile ID appareance
@ Object 531
   .word 0x32d0 @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 532
   .word 0x32e0 @ x
   .hword 0x1b0 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 533
   .word 0x331b @ x
   .hword 0x1a0 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 534
   .word 0x331b @ x
   .hword 0x1b0 @ y
   .hword 0x2c @ type
   .hword 0x20 @ bg layer 4   
   .hword 43 @ metatile ID appareance
@ Object 535
   .word 0x3360 @ x
   .hword 0x190 @ y
   .hword 0xb @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 536
   .word 0x3390 @ x
   .hword 0x150 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 537
   .word 0x33d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 538
   .word 0x3403 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 539
   .word 0x3413 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 540
   .word 0x3423 @ x
   .hword 0x1b0 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 541
   .word 0x3430 @ x
   .hword 0x1a0 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 542
   .word 0x3438 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 543
   .word 0x3470 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 544
   .word 0x3480 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 545
   .word 0x3480 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 546
   .word 0x34b0 @ x
   .hword 0x160 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 547
   .word 0x34c0 @ x
   .hword 0x190 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 548
   .word 0x34c0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 549
   .word 0x3500 @ x
   .hword 0x180 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 550
   .word 0x3500 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 551
   .word 0x3510 @ x
   .hword 0xf0 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x681f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 552
   .word 0x3510 @ x
   .hword 0x100 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x280c @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 553
   .word 0x3520 @ x
   .hword 0x110 @ y
   .hword 0xb @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 554
   .word 0x3530 @ x
   .hword 0x148 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 555
   .word 0x3540 @ x
   .hword 0x148 @ y
   .hword 0xf @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 556
   .word 0x3550 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 557
   .word 0x3580 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 558
   .word 0x35a0 @ x
   .hword 0x120 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 559
   .word 0x35c0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 560
   .word 0x35f0 @ x
   .hword 0x120 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 561
   .word 0x35f0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 562
   .word 0x3620 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 563
   .word 0x3630 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 564
   .word 0x3640 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 565
   .word 0x3650 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 566
   .word 0x3680 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 567
   .word 0x36a0 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 568
   .word 0x36b0 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 569
   .word 0x36c0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 570
   .word 0x36d0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 571
   .word 0x36f0 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 572
   .word 0x36f0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 573
   .word 0x3720 @ x
   .hword 0x120 @ y
   .hword 0xa @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 574
   .word 0x3730 @ x
   .hword 0x110 @ y
   .hword 0xb @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 575
   .word 0x3730 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 576
   .word 0x3750 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 577
   .word 0x3760 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 578
   .word 0x3760 @ x
   .hword 0x160 @ y
   .hword 0xa @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 579
   .word 0x3770 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 580
   .word 0x3780 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 581
   .word 0x3780 @ x
   .hword 0x110 @ y
   .hword 0x3 @ type
   .hword 0xf4 @ changes BG for 30 frames
   .hword 0x3e6 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 582
   .word 0x3780 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0xf5 @ changes GROUND for 30 frames
   .hword 0x224 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 583
   .word 0x3780 @ x
   .hword 0x190 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 584
   .word 0x37a0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 585
   .word 0x37a0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 586
   .word 0x37b0 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 587
   .word 0x37b8 @ x
   .hword 0x160 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 588
   .word 0x37c0 @ x
   .hword 0x138 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 589
   .word 0x37d0 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 590
   .word 0x37e0 @ x
   .hword 0x140 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 591
   .word 0x37e0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 592
   .word 0x37f0 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 593
   .word 0x3800 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 594
   .word 0x3803 @ x
   .hword 0x150 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 595
   .word 0x381d @ x
   .hword 0x150 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 596
   .word 0x3820 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 597
   .word 0x3820 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 598
   .word 0x3830 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 599
   .word 0x3840 @ x
   .hword 0x140 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 600
   .word 0x3850 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 601
   .word 0x3850 @ x
   .hword 0x130 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 602
   .word 0x3850 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 603
   .word 0x3860 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 604
   .word 0x3870 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 605
   .word 0x3873 @ x
   .hword 0x140 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 606
   .word 0x388d @ x
   .hword 0x140 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 607
   .word 0x3890 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 608
   .word 0x38a0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 609
   .word 0x38a0 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 610
   .word 0x38b0 @ x
   .hword 0x130 @ y
   .hword 0xc @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 611
   .word 0x38c0 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 612
   .word 0x38d0 @ x
   .hword 0x108 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 613
   .word 0x38d0 @ x
   .hword 0x130 @ y
   .hword 0xb @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 614
   .word 0x38d0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 615
   .word 0x38f0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 616
   .word 0x38f0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 617
   .word 0x3900 @ x
   .hword 0x128 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 618
   .word 0x3900 @ x
   .hword 0x180 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 619
   .word 0x3910 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 620
   .word 0x3920 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 621
   .word 0x3930 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 622
   .word 0x3930 @ x
   .hword 0x170 @ y
   .hword 0x8 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 623
   .word 0x3940 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 624
   .word 0x3950 @ x
   .hword 0x118 @ y
   .hword 0x8 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 625
   .word 0x3950 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 626
   .word 0x3954 @ x
   .hword 0x140 @ y
   .hword 0x1e @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 627
   .word 0x3960 @ x
   .hword 0x160 @ y
   .hword 0x1 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 628
   .word 0x3970 @ x
   .hword 0x120 @ y
   .hword 0x3 @ type
   .hword 0x964 @ changes BG for 300 frames
   .hword 0x7dc0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 629
   .word 0x3970 @ x
   .hword 0x130 @ y
   .hword 0x3 @ type
   .hword 0x965 @ changes GROUND for 300 frames
   .hword 0x3ce0 @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x0 @ normal trigger
@ Object 630
   .word 0x3970 @ x
   .hword 0x160 @ y
   .hword 0xe @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 631
   .word 0x3980 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 632
   .word 0x3980 @ x
   .hword 0xf0 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 633
   .word 0x3980 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 634
   .word 0x39a0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 635
   .word 0x39c0 @ x
   .hword 0xf0 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 636
   .word 0x39c0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 637
   .word 0x3a60 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 638
   .word 0x3ab0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 639
   .word 0x3ae0 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 640
   .word 0x3b80 @ x
   .hword 0x170 @ y
   .hword 0xf @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 641
   .word 0x3bd0 @ x
   .hword 0x1b0 @ y
   .hword 0x4 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 642
   .word 0x3c20 @ x
   .hword 0x1b0 @ y
   .hword 0x5 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 643
   .word 0x3c70 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 644
   .word 0x3cb0 @ x
   .hword 0x120 @ y
   .hword 0x5 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 645
   .word 0x3ce8 @ x
   .hword 0x120 @ y
   .hword 0x4 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 646
   .word 0x3cf8 @ x
   .hword 0x1b0 @ y
   .hword 0x6 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 647
   .word 0x3d40 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 648
   .word 0x3d40 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 649
   .word 0x3d60 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 650
   .word 0x3d60 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 651
   .word 0x3d80 @ x
   .hword 0x150 @ y
   .hword 0xc @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 652
   .word 0x3d80 @ x
   .hword 0x180 @ y
   .hword 0xc @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
   .byte 0xff
