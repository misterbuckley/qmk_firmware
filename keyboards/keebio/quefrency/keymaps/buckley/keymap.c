// Note from Buckley: to flash from linux, you need to run the following:
//     `systemctl stop ModemManager.service`
//     `sudo make keebio/quefrency/rev1:buckley:avrdude`


// keycodes https://beta.docs.qmk.fm/features/keycodes_basic

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN0 1
#define _FN1 2
#define _FN2 3
#define _FN3 4

#define LOCKCMP LGUI(KC_L)
#define WSCRSHT LALT(KC_PSCR)
#define SSCRSHT LSFT(KC_PSCR)
#define GO_BACK LALT(KC_LEFT)
#define GO_FWRD LALT(KC_RGHT)
#define TABLEFT LSFT(LCTL(KC_TAB))
#define TABRGHT LCTL(KC_TAB)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum {
  TD_LOCK = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_VOLD,     KC_VOLU, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL, KC_HOME, \
    KC_MPLY,     KC_MUTE, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_MPRV,     KC_MNXT, KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,   KC_G, KC_H,             KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
    WSCRSHT,     SSCRSHT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, KC_N,             KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    TD(TD_LOCK), _______, KC_LGUI, KC_LALT, KC_LCTL, MO(_FN0),KC_SPC,       LT(_FN1, KC_SPC), XXXXXXX, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN0] = LAYOUT_65_with_macro(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, \
    _______, _______, _______, GO_BACK, KC_UP,   GO_FWRD, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_ENT,           KC_0,    XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, TABLEFT, GO_BACK, GO_FWRD, TABRGHT, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______
  ),

  [_FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [_FN3] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_NLCK, LOCKCMP),
};
