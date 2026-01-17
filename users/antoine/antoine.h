// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// Modified 2025 for modern QMK

#pragma once

#include QMK_KEYBOARD_H

// Keymap placeholder macros
#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

// Layer definitions - shared across all keyboards
enum layers { 
    COLEMAK, 
    QWERTY, 
    GAMING_QWERTY, 
    GAMING_COLEMAK, 
    BUTTON, 
    MEDIA, 
    NAV, 
    MOUSE, 
    FUN_G, 
    NUM_G, 
    SYM_G, 
    FUN, 
    NUM, 
    SYM 
};

// Clipboard macros - OS-specific
#if defined MIRYOKU_CLIPBOARD_FUN
#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO
#elif defined MIRYOKU_CLIPBOARD_MAC
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)
#elif defined MIRYOKU_CLIPBOARD_WIN
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)
#else
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#endif

// OLED functions (if OLED_ENABLE)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool oled_task_user(void);
#endif

// Per-key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
