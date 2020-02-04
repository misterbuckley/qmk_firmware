// Note from Buckley:
// - to install from linux, you need to run `systemctl stop ModemManager.service`

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN0 1
#define _FN1 2
#define _FN2 3
#define _FN3 4

#define LOCKCMP LGUI(KC_L)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum {
  TD_LOCK = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,   KC_F2,   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL, KC_HOME, \
    KC_F3,   KC_F4,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_F5,   KC_F6,   KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_F7,   KC_F8,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,   KC_PGDN, \
    KC_F9,   KC_F10,  KC_LGUI, KC_LALT, KC_LCTL, MO(_FN0),KC_SPC,           KC_SPC,  _______, MO(_FN1), MO(_FN2), TD(TD_LOCK), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN0] = LAYOUT_65_with_macro(
    KC_F11,  KC_F12,  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR, \
    KC_F13,  KC_F14,  _______, KC_WH_L, KC_UP,   KC_WH_R, KC_WH_U, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, \
    KC_F15,  KC_F16,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, \
    KC_F17,  KC_F18,  _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, \
    KC_F19,  KC_F20,  _______, _______, _______, _______, _______,          KC_0,    _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, KC_VOLU, _______, \
    _______, _______, _______, _______, _______, _______, KC_MPLY,          KC_MPLY, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),

  [_FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN3] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, LOCKCMP)
};
