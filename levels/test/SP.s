@ Sprite Data Export

.section .rodata
.align 2
.global test_spr_data
.hidden test_spr_data
test_spr_data:
@ Object 1
   .hword 0x10 @ delta x
   .hword 0x190 @ y
   .hword 0x33 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 2
   .hword 0x10 @ delta x
   .hword 0x170 @ y
   .hword 0x29 @ type
   .hword 0x8 @ bg layer 1 non rotated   
   .hword 0 @ rotation
@ Object 3
   .hword 0x20 @ delta x
   .hword 0x180 @ y
   .hword 0x2a @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 4
   .hword 0x10 @ delta x
   .hword 0x150 @ y
   .hword 0x29 @ type
   .hword 0x18 @ bg layer 3 non rotated   
   .hword 0 @ rotation
@ Object 5
   .hword 0x0 @ delta x
   .hword 0x1a0 @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 2 @ metatile ID appareance
@ Object 6
   .hword 0x10 @ delta x
   .hword 0x19c @ y
   .hword 0x2b @ type
   .hword 0x20 @ bg layer 4   
   .hword 20 @ metatile ID appareance
@ Object 7
   .hword 0x20 @ delta x
   .hword 0x160 @ y
   .hword 0x2f @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 8
   .hword 0x10 @ delta x
   .hword 0x1b0 @ y
   .hword 0x11 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 9
   .hword 0x18 @ delta x
   .hword 0x160 @ y
   .hword 0x30 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 10
   .hword 0x18 @ delta x
   .hword 0x130 @ y
   .hword 0x11 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 11
   .hword 0x10 @ delta x
   .hword 0x160 @ y
   .hword 0x31 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 12
   .hword 0x20 @ delta x
   .hword 0x160 @ y
   .hword 0x32 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 13
   .hword 0x0 @ delta x
   .hword 0x1a0 @ y
   .hword 0x1c @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 14
   .hword 0x30 @ delta x
   .hword 0x180 @ y
   .hword 0x3d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 15
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x13 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 16
   .hword 0x20 @ delta x
   .hword 0x1b0 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 17
   .hword 0x10 @ delta x
   .hword 0x180 @ y
   .hword 0x3e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 18
   .hword 0x30 @ delta x
   .hword 0x180 @ y
   .hword 0x3f @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 19
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x11 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 20
   .hword 0x10 @ delta x
   .hword 0x190 @ y
   .hword 0x11 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 21
   .hword 0x40 @ delta x
   .hword 0x1a0 @ y
   .hword 0x1a @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 22
   .hword 0x30 @ delta x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 23
   .hword 0x30 @ delta x
   .hword 0x1a0 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 24
   .hword 0x60 @ delta x
   .hword 0x1b0 @ y
   .hword 0x11 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 25
   .hword 0x18 @ delta x
   .hword 0x17c @ y
   .hword 0x2c @ type
   .hword 0x20 @ bg layer 4   
   .hword 43 @ metatile ID appareance
@ Object 26
   .hword 0x48 @ delta x
   .hword 0x1b0 @ y
   .hword 0x3 @ type
   .hword 0x4 @ changes BG for 0 frames
   .hword 0x1f @ color
   .hword 0x0 @ doesn't copy any channel
   .hword 0x1 @ touch trigger
@ Object 27
   .hword 0x10 @ delta x
   .hword 0x140 @ y
   .hword 0x13 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 28
   .hword 0x10 @ delta x
   .hword 0x180 @ y
   .hword 0x29 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 29
   .hword 0x0 @ delta x
   .hword 0x180 @ y
   .hword 0x30 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 30
   .hword 0x10 @ delta x
   .hword 0x140 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 31
   .hword 0x0 @ delta x
   .hword 0x1a0 @ y
   .hword 0x59 @ type
   .hword 0x20 @ coin 0 bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 32
   .hword 0x20 @ delta x
   .hword 0x1a0 @ y
   .hword 0x59 @ type
   .hword 0xa0 @ coin 1 bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 33
   .hword 0x10 @ delta x
   .hword 0x180 @ y
   .hword 0x28 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 34
   .hword 0x0 @ delta x
   .hword 0x180 @ y
   .hword 0x2f @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 35
   .hword 0x10 @ delta x
   .hword 0x1a0 @ y
   .hword 0x59 @ type
   .hword 0x120 @ coin 2 bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 36
   .hword 0x10 @ delta x
   .hword 0x140 @ y
   .hword 0x13 @ type
   .hword 0x21 @ bg layer 4 non rotated  flipped vertically 
   .hword 0 @ rotation
@ Object 37
   .hword 0x20 @ delta x
   .hword 0x140 @ y
   .hword 0x10 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 38
   .hword 0x0 @ delta x
   .hword 0x180 @ y
   .hword 0x31 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 39
   .hword 0x0 @ delta x
   .hword 0x180 @ y
   .hword 0x2a @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 40
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x3b @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 41
   .hword 0x40 @ delta x
   .hword 0x1b0 @ y
   .hword 0x3c @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 42
   .hword 0x40 @ delta x
   .hword 0x1b0 @ y
   .hword 0x3a @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 43
   .hword 0x40 @ delta x
   .hword 0x1a0 @ y
   .hword 0x2 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 44
   .hword 0x4c @ delta x
   .hword 0x178 @ y
   .hword 0x40 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 45
   .hword 0x0 @ delta x
   .hword 0x197 @ y
   .hword 0x1f @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 46
   .hword 0x14 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 47
   .hword 0x7 @ delta x
   .hword 0x199 @ y
   .hword 0x1e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 48
   .hword 0x1 @ delta x
   .hword 0x178 @ y
   .hword 0x41 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 49
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 50
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 51
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 52
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 53
   .hword 0x2 @ delta x
   .hword 0x19a @ y
   .hword 0x20 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 54
   .hword 0x2 @ delta x
   .hword 0x178 @ y
   .hword 0x42 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 55
   .hword 0x4 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 56
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 57
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 58
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 59
   .hword 0x4 @ delta x
   .hword 0x178 @ y
   .hword 0x43 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 60
   .hword 0x1 @ delta x
   .hword 0x19a @ y
   .hword 0x21 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 61
   .hword 0x3 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 62
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 63
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 64
   .hword 0x8 @ delta x
   .hword 0x178 @ y
   .hword 0x44 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 65
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 66
   .hword 0x1 @ delta x
   .hword 0x198 @ y
   .hword 0x22 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 67
   .hword 0x7 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 68
   .hword 0x8 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 69
   .hword 0x8 @ delta x
   .hword 0x178 @ y
   .hword 0x45 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 70
   .hword 0x0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x2e @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 71
   .hword 0x0 @ delta x
   .hword 0x19a @ y
   .hword 0x23 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 72
   .hword 0x20 @ delta x
   .hword 0x178 @ y
   .hword 0x46 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 73
   .hword 0x0 @ delta x
   .hword 0x198 @ y
   .hword 0x24 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 74
   .hword 0x1c @ delta x
   .hword 0x178 @ y
   .hword 0x47 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 75
   .hword 0x2 @ delta x
   .hword 0x19a @ y
   .hword 0x25 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 76
   .hword 0x21 @ delta x
   .hword 0x199 @ y
   .hword 0x26 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 77
   .hword 0x1c @ delta x
   .hword 0x199 @ y
   .hword 0x27 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 78
   .hword 0x5d @ delta x
   .hword 0x1a0 @ y
   .hword 0x1d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 79
   .hword 0x90 @ delta x
   .hword 0x1a0 @ y
   .hword 0x1 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 80
   .hword 0x30 @ delta x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 81
   .hword 0x40 @ delta x
   .hword 0x190 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 82
   .hword 0x140 @ delta x
   .hword 0x1b0 @ y
   .hword 0x13 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 83
   .hword 0x30 @ delta x
   .hword 0x1b0 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 84
   .hword 0x90 @ delta x
   .hword 0x170 @ y
   .hword 0x2d @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 85
   .hword 0x1a0 @ delta x
   .hword 0x1a0 @ y
   .hword 0x1a @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 8192 @ rotation
@ Object 86
   .hword 0x30 @ delta x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 87
   .hword 0x50 @ delta x
   .hword 0x1a0 @ y
   .hword 0x9 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 88
   .hword 0xf0 @ delta x
   .hword 0x1b0 @ y
   .hword 0x13 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 89
   .hword 0x30 @ delta x
   .hword 0x1b0 @ y
   .hword 0x12 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 90
   .hword 0xa0 @ delta x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 91
   .hword 0x50 @ delta x
   .hword 0x1a0 @ y
   .hword 0x10 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 92
   .hword 0x110 @ delta x
   .hword 0x190 @ y
   .hword 0xe @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 49152 @ rotation
@ Object 93
   .hword 0x50 @ delta x
   .hword 0x190 @ y
   .hword 0xe @ type
   .hword 0x24 @ bg layer 4 rotated   
   .hword 16384 @ rotation
@ Object 94
   .hword 0x40 @ delta x
   .hword 0x1a0 @ y
   .hword 0x2 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 95
   .hword 0x50 @ delta x
   .hword 0x1a0 @ y
   .hword 0x34 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 96
   .hword 0x80 @ delta x
   .hword 0x1a0 @ y
   .hword 0x36 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 97
   .hword 0xc0 @ delta x
   .hword 0x1a0 @ y
   .hword 0x37 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 98
   .hword 0x90 @ delta x
   .hword 0x1a0 @ y
   .hword 0x38 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 99
   .hword 0x90 @ delta x
   .hword 0x1a0 @ y
   .hword 0x35 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 100
   .hword 0x70 @ delta x
   .hword 0x1a0 @ y
   .hword 0x39 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 101
   .hword 0xa0 @ delta x
   .hword 0x1b0 @ y
   .hword 0xa @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
@ Object 102
   .hword 0x40 @ delta x
   .hword 0x1a0 @ y
   .hword 0x10 @ type
   .hword 0x20 @ bg layer 4 non rotated   
   .hword 0 @ rotation
   .byte 0xff
