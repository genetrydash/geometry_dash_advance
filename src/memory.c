#include <tonc.h>
#include "main.h"
#include "memory.h"
#include "sprite_routines.h"

// OAM buffer
OAM_SPR shadow_oam[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE*) shadow_oam;

u8 obj_priorities[128];

// Rotation data
EWRAM_DATA u16 rotation_buffer[NUM_ROT_SLOTS];

// Level buffer
EWRAM_DATA u16 level_buffer[LEVEL_LAYERS][MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];
IWRAM_DATA COLOR palette_buffer[512];

EWRAM_DATA u16 col_trigger_buffer[CHANNEL_COUNT][5];

// Current block column [0-LEVEL_BUFFER_WIDTH)
u8 curr_column;

// Current level height, in blocks
u8 curr_level_height;

// Pointer to level data for decompression
u32 *level_pointer[LEVEL_LAYERS];

// Scroll variables
// in subpixels
u64 scroll_x = 0;
u64 scroll_y = 0;

u32 target_scroll_y = 0;

// 0 : up | 1 : down
s8 scroll_y_dir = 0;

// Screen mirror state, changed on the middle of the transition
u8 screen_mirrored = 0;

// Screen mirror flag, changed by mirror portals. This doesn't mirror the screen, but instead, is used for the transition direction
u8 screen_mirrored_transition = 0;

// 0 : no swap queued | 1 : swap queued
u8 swap_queue = FALSE;

// Loaded level and song id
u16 loaded_level_id;
u16 loaded_song_id;

EWRAM_DATA u8 music_data[NUM_CHANNELS * (MM_SIZEOF_MODCH
                               +MM_SIZEOF_ACTCH
                               +MM_SIZEOF_MIXCH)
                               +MM_MIXLEN_31KHZ];

// 0 : off | 1 : on
u8 debug_mode = 0;

// Flags that indicates if VBLANK sensitive stuff should happen
u8 update_flags;

// Timer that increments by 1 every frame
u32 global_timer;

// Pointer to the first empty sprite tile in VRAM
u16 next_free_tile_id = START_OF_OBJECT_CHR;
u16 old_next_free_tile_id;

struct ObjectCHRSlot chr_slots[MAX_OBJECTS];

// Buffers for loading and unloading VRAM tiles for objects
u16 loaded_object_buffer_offset;
s16 loaded_object_buffer[MAX_OBJECTS];

u16 unloaded_object_buffer_offset;
s16 unloaded_object_buffer[MAX_OBJECTS];

// Buffer for sprite block collision
u16 block_object_buffer_offset;
s32 *block_object_buffer[MAX_OBJECTS];
u16 block_object_buffer_flags[MAX_OBJECTS];

// Buffer for copying purposes
u8 vram_copy_buffer[2048];

// Controls the transition state
// 0 : full | 30 : empty | 60 : full
s8 transition_frame;