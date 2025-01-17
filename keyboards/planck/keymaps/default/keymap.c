#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE 
};

const uint16_t PROGMEM test_combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_F, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_COLN),
    COMBO(test_combo2, KC_SCLN),
    COMBO(test_combo3, KC_QUOT),
    COMBO(test_combo4, KC_DQUO),
};

enum {
    TD_R,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_R] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_EQL,       KC_Q,  KC_W,  KC_E,          KC_R,               KC_T,  KC_Y,           KC_U,              KC_I,          KC_O,    KC_P,          KC_MINS,
    LCTL(KC_SPC), KC_A,  KC_S,  KC_D,          KC_F,               KC_G,  KC_H,           KC_J,              KC_K,          KC_L,    OSM(MOD_LGUI), KC_ENT,
    KC_GRV,       KC_Z,  KC_X,  KC_C,          KC_V,               KC_B,  KC_N,           KC_M,              KC_COMM,       KC_DOT,  KC_SLSH,       KC_BSLS,
    KC_NO,        KC_NO, KC_NO, OSM(MOD_LALT), LT(_LOWER, KC_ESC), KC_NO, LSFT_T(KC_SPC), LT(_RAISE,KC_TAB), OSM(MOD_LCTL), KC_LEFT, KC_NO,         KC_NO
),
[_LOWER] = LAYOUT_planck_grid(
    KC_NO,   KC_NO, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_NO,   KC_7, KC_8,  KC_9,  KC_NO,  KC_NO,
    KC_NO,   KC_NO, KC_DLR,  KC_PERC, KC_CIRC, KC_NO,   KC_NO,   KC_4, KC_5,  KC_6,  KC_NO,  KC_NO,  
    KC_NO,   KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_NO,   KC_NO,   KC_1, KC_2,  KC_3,  KC_NO,  KC_NO,
    QK_BOOT, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_BSPC, KC_0, KC_NO, KC_NO, KC_NO,  KC_NO 
),
[_RAISE] = LAYOUT_planck_grid(
    KC_F1, KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9, KC_F10,    KC_F11,  KC_F12,
    KC_NO, TD(TD_R), KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END,
    KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO,   KC_NO,
    KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO,   KC_NO
)
};

