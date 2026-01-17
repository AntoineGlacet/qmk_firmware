// Copyright 2024 Antoine
// SPDX-License-Identifier: GPL-2.0-or-later

#include "antoine.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              U_NP,
KC_LSFT,           LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   U_NP,
KC_LCTL,           LT(BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,  U_NP, U_NP,  KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH), U_NP,
U_NP,              U_NP,              LT(FUN, KC_ESC), LT(NUM, KC_ENT),   LT(SYM, KC_TAB), LT(MOUSE, KC_BSPC),   LT(NAV, KC_SPC),  LT(MEDIA, KC_DEL),   U_NP,              U_NP
),
[NAV] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_INS,  DF(GAMING_QWERTY),    DF(QWERTY),    DF(GAMING_COLEMAK),    DF(COLEMAK),    QK_BOOT, U_NP,
U_NP, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_PSCR, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NP,
U_NP, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO, U_NP, U_NP,  U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, U_NP,
U_NP,    U_NP,    KC_ESC,  KC_ENT, KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
),
[MOUSE] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,U_NP,
U_NP, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,U_NP,
U_NP, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO, U_NP, U_NP,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,U_NP,
U_NP,    U_NP,    KC_BTN3, KC_BTN2, KC_BTN1, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
),
[MEDIA] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, U_NU,    U_NU,    KC_VOLU, U_NU,    U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,U_NP,
U_NP, U_NU,    KC_MPRV, KC_VOLD, KC_MNXT, U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,U_NP,
U_NP, RGB_MOD, RGB_HUI, RGB_SAI, BL_STEP, BL_TOGG, U_NP, U_NP, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,U_NP,
U_NP,    U_NP,    KC_MUTE, KC_MPLY, KC_MSTP, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
),
[NUM] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,U_NP,
U_NP, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,U_NP,
U_NP, U_NA,    U_NA,    U_NA,    U_NA,    U_NA, U_NP, U_NP,    KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MINS, KC_0,    KC_DOT,  U_NP,    U_NP
),
[SYM] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,U_NP,
U_NP, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,U_NP,
U_NP, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NP, U_NP, KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_UNDS, KC_LPRN, KC_RPRN, U_NP,    U_NP
),
[FUN] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP, QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12, U_NP,
U_NP, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11, U_NP,
U_NP, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA, U_NP, U_NP,    KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NP,    U_NP
),
[BUTTON] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP,C(KC_Q), C(KC_W), C(KC_E),  C(KC_R),  C(KC_T),    KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,U_NP,
U_NP,C(KC_A), C(KC_S), C(KC_D),  C(KC_F),  C(KC_G),    KC_H,  KC_J,  KC_K,  KC_L,  KC_QUOT,U_NP,
U_NP,U_NA,    C(KC_X), C(KC_C),  C(KC_V),  C(KC_B), U_NP,U_NP,   KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,U_NP,
U_NP,    U_NP,    U_NA,     C(KC_Z),  KC_LSFT,    U_NA,  U_NA,  U_NA,  U_NP,  U_NP
),
[NUM_G] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP,KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,U_NP,
U_NP,KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,U_NP,
U_NP,KC_GRV,  KC_1,    KC_2,    KC_3,    U_NP,U_NP,KC_BSLS, KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MINS, KC_0,    KC_DOT,  U_NP,    U_NP
),
[SYM_G] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP,KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,U_NP,
U_NP,KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,U_NP,
U_NP,KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NP, U_NP,   KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_UNDS, KC_LPRN, KC_RPRN, U_NP,    U_NP
),
[FUN_G] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP,KC_F12,  KC_F7,   KC_F8,    KC_F9,    KC_PSCR,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,U_NP,
U_NP,KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,       KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11,U_NP,
U_NP,KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,  U_NP,U_NP,     KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,U_NP,
U_NP,    U_NP,    U_NA,    U_NA,    U_NA,          KC_BSPC, KC_ENT,  KC_DEL,  U_NP,    U_NP
),
[GAMING_QWERTY] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,U_NP,
KC_LSFT,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   LSFT_T(KC_J),   LCTL_T(KC_K),    LALT_T(KC_L),  LGUI_T(KC_QUOT),U_NP,
KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, U_NP,U_NP,KC_N,   KC_M,   KC_COMM,   ALGR_T(KC_DOT),   KC_ENT,U_NP,
U_NP,   U_NP,   KC_TAB,  KC_SPC, KC_LALT,    LT(MOUSE, KC_BSPC),   LT(NAV, KC_SPC),  LT(MEDIA, KC_DEL),   U_NP,   U_NP
),
[GAMING_COLEMAK] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
KC_LSFT,KC_Q,             KC_W,         KC_F,         KC_P,         KC_B, KC_J, KC_L,         KC_U,         KC_Y,           KC_QUOT,U_NP,
KC_TAB,KC_A,     KC_R, KC_S, KC_T, KC_G, KC_M, RSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I),   LGUI_T(KC_O),U_NP,
KC_LCTL,KC_Z,     KC_X, KC_C, KC_D, KC_V, U_NP,U_NP,KC_K, KC_H,         KC_COMM,      ALGR_T(KC_DOT), LT(BUTTON, KC_SLSH),U_NP,
U_NP,             U_NP,         MO(FUN_G), LT(NUM_G, KC_ENT),   LT(SYM_G, KC_TAB), LT(MOUSE, KC_BSPC),   LT(NAV, KC_SPC),  LT(MEDIA, KC_DEL), U_NP, U_NP
),
[COLEMAK] = LAYOUT_antoine(
KC_ESC,            KC_1,              KC_2,              KC_3,              KC_4,               KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,              KC_BSPC,
U_NP,KC_Q,             KC_W,         KC_F,         KC_P,         KC_B, KC_J, KC_L,         KC_U,         KC_Y,           KC_QUOT,U_NP,
U_NP,LGUI_T(KC_A),     LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I),   LGUI_T(KC_O),U_NP,
U_NP,LT(BUTTON, KC_Z), ALGR_T(KC_X), KC_C,         KC_D,         KC_V,U_NP,U_NP, KC_K, KC_H,         KC_COMM,      ALGR_T(KC_DOT), LT(BUTTON, KC_SLSH),U_NP,
U_NP,             U_NP,         LT(FUN, KC_ESC), LT(NUM, KC_ENT),   LT(SYM, KC_TAB), LT(MOUSE, KC_BSPC),   LT(NAV, KC_SPC),  LT(MEDIA, KC_DEL), U_NP, U_NP
)
};
