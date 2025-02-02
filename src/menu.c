#include <tonc.h>
#include "main.h"
#include "menu.h"
#include "tonc_tte.h"
#include "pusab.h"
#include "posprintf.h"
#include <maxmod.h>
#include "soundbank.bin.h"
#include "soundbank.h"
#include <string.h>
#include <ctype.h>
#include "color.h"

u16 game_state;

#define LEVEL_NAME_POS_X 120
#define LEVEL_NAME_POS_Y 5*8

void print_level_info(u16 level_id);

void menu_loop() {
    // Enable all BGs, also enable sprites
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

    REG_BG0CNT  = BG_CBB(0) | BG_SBB(24) | BG_REG_32x32 | BG_PRIO(0);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BG1CNT  = BG_CBB(0) | BG_SBB(25) | BG_REG_32x32 | BG_PRIO(1);
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT  = BG_CBB(0) | BG_SBB(26) | BG_REG_32x32 | BG_PRIO(3);
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    
    REG_BG3CNT  = BG_CBB(0) | BG_SBB(27) | BG_REG_32x32 | BG_PRIO(2);
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;

    memset32(palette_buffer, 0, 256);
    memcpy16(palette_buffer, menu_palette, sizeof(menu_palette) / sizeof(COLOR));
    memcpy16(&palette_buffer[256], menu_spr_palette, sizeof(menu_spr_palette) / sizeof(COLOR));

    // Init PUSAB font
    tte_init_se(
        3,                      // Background number (BG 3)
        BG_CBB(0) | BG_SBB(31), // BG control (for REG_BGxCNT)
        0,                      // Tile offset (special cattr)
        0,                      // Ink color
        0,                      // BitUnpack offset (on-pixel = 15)
        &pusabFont,             // Default font (sys8)
        NULL);                  // Default renderer (se_drawg_s)

    tte_set_special(0x2000);

    memcpy32(&tile_mem[0][0], menu_chr, sizeof(menu_chr) / 8);
    memcpy32(&tile_mem_obj[0][0], &menu_chr[256], sizeof(menu_chr) / 8);
    memcpy32(&tile_mem_obj[0][992], level_text_chr, sizeof(level_text_chr) / 4);

    memcpy32(&se_mem[24][0], menu_l0_tilemap, sizeof(menu_l0_tilemap) / 4);
    memcpy32(&se_mem[25][0], menu_l1_tilemap, sizeof(menu_l1_tilemap) / 4);
    memcpy32(&se_mem[26][0], menu_l2_tilemap, sizeof(menu_l2_tilemap) / 4);
    
    // Erase screen
    tte_erase_rect(0, 0, 240, 128);
    print_level_info(loaded_level_id);

    s32 level_id = loaded_level_id;
    
    // Init OAM
    memset32(shadow_oam, ATTR0_HIDE, 256);
    obj_copy(oam_mem, shadow_oam, 128);
    
    mmStart(MOD_MENU, MM_PLAY_LOOP);

    fade_in_menu();
    while (1) {
        key_poll();
        
        // Copy to OAM
        obj_copy(oam_mem, shadow_oam, 128);

        // Clear OAM
        memset32(shadow_oam, ATTR0_HIDE, 256);
        
        nextSpr = 0;

        put_star_number(level_id);
        put_coin_sprites(level_id);
#ifdef DEBUG
        if (key_hit(KEY_SELECT)) {
            debug_mode ^= 1;
        }
#endif

        if (key_hit(KEY_RIGHT)) {
            // Increment level ID
            level_id++;
            level_id = wrap(level_id, 0, LEVEL_COUNT);

            // Erase written text
            tte_erase_rect(0, 0, 240, 128);

            // Write level name
            print_level_info(level_id);
            
            // Copy palette from buffer
            memcpy32(pal_bg_mem, palette_buffer, 256);
        }
        if (key_hit(KEY_LEFT)) {
            // Decrement level ID
            level_id--;
            level_id = wrap(level_id, 0, LEVEL_COUNT);
            
            // Erase written text
            tte_erase_rect(0, 0, 240, 128);

            // Write level name
            print_level_info(level_id);
            
            // Copy palette from buffer
            memcpy32(pal_bg_mem, palette_buffer, 256);
        }

        if (key_hit(KEY_A | KEY_START)) {
            // Start the game
            loaded_level_id = level_id;
            game_state = STATE_PLAYING;
            mmStop();
            mmEffect(SFX_LEVEL_ENTER);
            for (s32 i = 0; i < 30; i++) {
                VBlankIntrWait();
            }
            break;
        }

        // Wait for VSYNC
        VBlankIntrWait();
    }
}


// --- Constants (in tiles) ---
#define AREA_WIDTH            18
#define AREA_HEIGHT           6
#define MARGIN                1
#define FACE_WIDTH            2
#define FACE_HEIGHT           2
#define FACE_TILE_ID_OFFSET   0xA0
#define GAP                   1

#define OFFSET_X              6
#define OFFSET_Y              3 

// The usable width inside margins:
#define USABLE_WIDTH          (AREA_WIDTH - 2 * MARGIN)
// Maximum allowed text width per line (text is on the left, then gap, then face):
#define MAX_TEXT_WIDTH_ALLOWED (USABLE_WIDTH - (FACE_WIDTH + GAP))

// Maximum number of lines we can wrap into.
#define MAX_LINES             4

// --- Word Wrapping Function ---
// This function splits the input text into lines so that each line is no longer
// than 'maxWidth' characters (tiles). It respects word boundaries when possible.
// If a word is longer than maxWidth, it will be split.
s32 wordWrap(const char *text, s32 maxWidth, char lines[][maxWidth + 1], s32 maxLines) {
    s32 lineCount = 0;
    s32 i = 0;
    s32 len = strlen(text);
    char currentLine[maxWidth + 1];
    s32 currentLength = 0;

    while (i < len) {
        // Skip any leading spaces.
        while (i < len && isspace((unsigned char)text[i])) {
            i++;
        }
        if (i >= len) break;

        // Identify the next word.
        s32 wordStart = i;
        while (i < len && !isspace((unsigned char)text[i])) {
            i++;
        }
        s32 wordLen = i - wordStart;

        // If the word is longer than maxWidth, break it into pieces.
        if (wordLen > maxWidth) {
            s32 wordPos = 0;
            while (wordPos < wordLen) {
                s32 chunk = (wordLen - wordPos < maxWidth) ? (wordLen - wordPos) : maxWidth;
                // If there is already text in currentLine, end that line first.
                if (currentLength > 0) {
                    currentLine[currentLength] = '\0';
                    if (lineCount < maxLines) {
                        strcpy(lines[lineCount], currentLine);
                        lineCount++;
                    }
                    currentLength = 0;
                }
                // Copy a chunk of the word into currentLine.
                strncpy(currentLine, text + wordStart + wordPos, chunk);
                currentLine[chunk] = '\0';
                if (lineCount < maxLines) {
                    strcpy(lines[lineCount], currentLine);
                    lineCount++;
                }
                wordPos += chunk;
            }
            continue; // Word has been processed.
        }

        // If adding this word would exceed the current line's limit, finish the line.
        if (currentLength > 0 && currentLength + 1 + wordLen > maxWidth) {
            currentLine[currentLength] = '\0';
            if (lineCount < maxLines) {
                strcpy(lines[lineCount], currentLine);
                lineCount++;
            }
            currentLength = 0;
        }

        // If this isn’t the first word on the line, add a space.
        if (currentLength > 0) {
            currentLine[currentLength] = ' ';
            currentLength++;
        }
        // Append the word.
        strncpy(currentLine + currentLength, text + wordStart, wordLen);
        currentLength += wordLen;
    }

    // Add any remaining text as the last line.
    if (currentLength > 0) {
        currentLine[currentLength] = '\0';
        if (lineCount < maxLines) {
            strcpy(lines[lineCount], currentLine);
            lineCount++;
        }
    }

    return lineCount;
}


void print_level_info(u16 level_id) {
    char *level_name = (char *) level_names[level_id];
    
    // Buffer for wrapped lines.
    char lines[MAX_LINES][MAX_TEXT_WIDTH_ALLOWED + 1];
    
    for (s32 line = 0; line < MAX_LINES; line++) {
        lines[line][0] = '\0';
    }
    s32 numLines = wordWrap(level_name, MAX_TEXT_WIDTH_ALLOWED, lines, MAX_LINES);

    // Determine the maximum line length.
    s32 maxLineLength = 0;
    for (s32 i = 0; i < numLines; i++) {
        s32 lineLen = strlen(lines[i]);
        if (lineLen > maxLineLength)
            maxLineLength = lineLen;
    }

    // Compute the width of the combined block (text + gap + face).
    s32 blockWidth = maxLineLength + GAP + FACE_WIDTH;

    // Calculate the starting X coordinate for the block within the usable area.
    s32 startX = OFFSET_X + MARGIN + (USABLE_WIDTH - blockWidth) / 2;
    // Center the text block vertically within the area (ignoring the margins).
    s32 startY = OFFSET_Y + MARGIN + (AREA_HEIGHT - 2 * MARGIN - numLines) / 2;
    
    // Face position:
    // Since the face is to the left, its left edge is at startX.
    s32 faceX = startX;
    // Vertically center the 2-tile-high face relative to the text block.
    s32 faceY = startY + (numLines - FACE_HEIGHT) / 2;

    // Text position:
    // The text should start to the right of the face plus the GAP.
    s32 textStartX = startX + FACE_WIDTH + GAP;

    if (numLines & 1) startY++;

    // Print all lines
    for (s32 line = 0; line < MAX_LINES; line++) {
        tte_set_pos(textStartX << 3, (startY + line) << 3);
        tte_write(lines[line]);
    }
        
    // Now place the face
    u32 *properties_pointer = (u32*) level_defines[level_id][LEVEL_PROPERTIES_INDEX];
    s32 difficulty = properties_pointer[LEVEL_DIFFICULTY];

    u32 difficulty_top_index = FACE_TILE_ID_OFFSET + (difficulty << 1);

    set_face_color(palette_buffer, face_colors[difficulty][0], face_colors[difficulty][1]);
    
    // Plot tiles
    se_plot(&se_mem[31][0], faceX    , faceY     , SE_BUILD(difficulty_top_index, 3, 0, 0));
    se_plot(&se_mem[31][0], faceX + 1, faceY     , SE_BUILD(difficulty_top_index + 1, 3, 0, 0));
    se_plot(&se_mem[31][0], faceX    , faceY + 1 , SE_BUILD(difficulty_top_index + 0x10, 3, 0, 0));
    se_plot(&se_mem[31][0], faceX + 1, faceY + 1 , SE_BUILD(difficulty_top_index + 0x11, 3, 0, 0));
}

void put_star_number(u16 level_id) {
    // Put star sprite
    oam_metaspr(180, 28, menuStarSpr, FALSE, FALSE, 0, 0, TRUE);
    
    u32 *properties_pointer = (u32*) level_defines[level_id][LEVEL_PROPERTIES_INDEX];
    
    u32 stars = properties_pointer[LEVEL_STARS_NUM];

    if (stars >= 10) {
        oam_metaspr(164, 28, menuNumberSpr, FALSE, FALSE, FIRST_NUMBER_ID + (stars / 10), 0, TRUE);
        oam_metaspr(172, 28, menuNumberSpr, FALSE, FALSE, FIRST_NUMBER_ID + (stars % 10), 0, TRUE);
    } else {
        oam_metaspr(172, 28, menuNumberSpr, FALSE, FALSE, FIRST_NUMBER_ID + stars, 0, TRUE);
    }
}

#define MENU_COIN_X 154
#define MENU_COIN_Y 56
void put_coin_sprites(u16 level_id) {
    // Obtain level data
    struct SaveLevelData *level_data = obtain_level_data(level_id);

    // Put coin 1 sprite
    if (level_data->coin1) {
        oam_metaspr(MENU_COIN_X, MENU_COIN_Y, gottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    } else {
        oam_metaspr(MENU_COIN_X, MENU_COIN_Y, ungottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    }

    // Put coin 2 sprite
    if (level_data->coin2) {
        oam_metaspr(MENU_COIN_X + 11, MENU_COIN_Y, gottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    } else {
        oam_metaspr(MENU_COIN_X + 11, MENU_COIN_Y, ungottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    }
    
    // Put coin 3 sprite
    if (level_data->coin3) {
        oam_metaspr(MENU_COIN_X + 22, MENU_COIN_Y, gottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    } else {
        oam_metaspr(MENU_COIN_X + 22, MENU_COIN_Y, ungottenCoinSpr, FALSE, FALSE, 0, 0, TRUE);
    }
}