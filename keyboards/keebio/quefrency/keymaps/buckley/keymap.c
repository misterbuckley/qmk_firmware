// Note from Buckley: to flash from linux, you need to run the following:
//     `systemctl stop ModemManager.service`
//     `sudo make keebio/quefrency/rev1:buckley:avrdude`

// keycodes https://beta.docs.qmk.fm/features/keycodes_basic

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define LOCKCMP LGUI(KC_L)
#define WINSHOT LALT(KC_PSCR)
#define SELSHOT LSFT(KC_PSCR)
#define GO_BACK LALT(KC_LEFT)
#define GO_FWRD LALT(KC_RGHT)

enum layers {
  BASE,
  NUMPAD,
  MOUSE,
  MACRO,
};

enum tap_dances {
  TD_LOCK,
  TD_SHOT,
  TD_MAC1,
  TD_MAC2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_65_with_macro(
    KC_MPLY,     KC_MUTE,     KC_GESC, KC_1,    KC_2,    KC_3,       KC_4,   KC_5, KC_6,              KC_7,    KC_8,        KC_9,        KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL, KC_HOME, \
    KC_VOLD,     KC_VOLU,     KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,   KC_T, KC_Y,              KC_U,    KC_I,        KC_O,        KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_MPRV,     KC_MNXT,     KC_LGUI, KC_A,    KC_S,    KC_D,       KC_F,   KC_G, KC_H,              KC_J,    KC_K,        KC_L,        KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
    _______,     _______,     KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,   KC_B, KC_N,              KC_M,    KC_COMM,     KC_DOT,      KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    TD(TD_LOCK), TD(TD_SHOT), KC_LGUI, KC_LALT, KC_LCTL, MO(NUMPAD), KC_SPC,       LT(MOUSE, KC_SPC), XXXXXXX, TD(TD_MAC1), TD(TD_MAC2), DM_RSTP, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [NUMPAD] = LAYOUT_65_with_macro(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, \
    _______, _______, _______, _______, KC_UP,   _______, _______, _______, KC_7,  KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_4,  KC_5,    KC_6,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,  KC_2,    KC_3,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          KC_0,  XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [MOUSE] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, GO_BACK, KC_BTN1, KC_BTN2, GO_FWRD, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______
  ),

  [MACRO] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, DM_REC1, DM_REC2, _______, _______, _______, _______
  )
};

void dynamicMacro1(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 2) return;

  keyrecord_t kr;
  kr.event.pressed = false;
  uint16_t action = DYN_MACRO_PLAY1;

  if (state->count == 2) {
    action = DYN_REC_START1;
  }

  process_dynamic_macro(action, &kr);
}

void dynamicMacro2(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 2) return;

  keyrecord_t kr;
  kr.event.pressed = false;
  uint16_t action = DYN_MACRO_PLAY2;

  if (state->count == 2) {
    action = DYN_REC_START2;
  }

  process_dynamic_macro(action, &kr);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, LOCKCMP),
  [TD_SHOT] = ACTION_TAP_DANCE_DOUBLE(SELSHOT, WINSHOT),
  [TD_MAC1] = ACTION_TAP_DANCE_FN(dynamicMacro1),
  [TD_MAC2] = ACTION_TAP_DANCE_FN(dynamicMacro2),
};
