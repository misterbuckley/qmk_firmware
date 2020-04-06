// Note from Buckley: to flash from linux, you need to run the following:
//     `systemctl stop ModemManager.service`
//     `sudo make keebio/quefrency/rev1:buckley:avrdude`

// ===== KEYCODES =====
// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define LOCKCMP LGUI(KC_L)
#define WINSHOT LALT(KC_PSCR)
#define SELSHOT LSFT(KC_PSCR)
#define GO_BACK LALT(KC_LEFT)
#define GO_FWRD LALT(KC_RGHT)

enum layers {
  BASE,
  MOD_WIN,
  MOD_MUSIC,
  FN,
  NUMPAD,
  MOUSE,
  MACRO,
};

enum tap_dances {
  TD_LOCK,
  TD_SHOT,
  TD_MAC1,
  TD_MAC2,
  TD_SPACEBAR,
  TD_CAPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_65_with_macro(
    KC_VOLU,     _______,     KC_GESC,     KC_1,    KC_2,    KC_3,   KC_4,   KC_5, KC_6,              KC_7,    KC_8,        KC_9,        KC_0,    KC_MINS, KC_EQL,         KC_BSPC,  KC_DEL, KC_HOME, \
    KC_VOLD,     _______,     KC_TAB,      KC_Q,    KC_W,    KC_E,   KC_R,   KC_T, KC_Y,              KC_U,    KC_I,        KC_O,        KC_P,    KC_LBRC, KC_RBRC,        KC_BSLS, KC_PGUP, \
    KC_MUTE,     _______,     TD(TD_CAPS), KC_A,    KC_S,    KC_D,   KC_F,   KC_G, KC_H,              KC_J,    KC_K,        KC_L,        KC_SCLN, KC_QUOT, LT(FN, KC_ENT), KC_PGDN, \
    KC_MPLY,     _______,     KC_LSFT,     KC_Z,    KC_X,    KC_C,   KC_V,   KC_B, KC_N,              KC_M,    KC_COMM,     KC_DOT,      KC_SLSH, KC_RSFT, KC_UP,          KC_END, \
    TD(TD_LOCK), TD(TD_SHOT), KC_LCTL,     KC_LALT, KC_LGUI, MO(FN), KC_SPC,       LT(MOUSE, KC_SPC), XXXXXXX, TD(TD_MAC1), TD(TD_MAC2), DM_RSTP, KC_LEFT, KC_DOWN,        KC_RGHT
  ),

  [MOD_WIN] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, _______, _______, _______
  ),

  [MOD_MUSIC] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______
  ),

  [FN] = LAYOUT_65_with_macro(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,    KC_F9,       KC_F10,        KC_F11,  KC_F12,  _______, _______, _______, \
    _______, _______, _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______, KC_7,  KC_8,    KC_9,     _______,     _______,       _______, _______, _______, _______, \
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_4,  KC_5,    KC_6,     _______,     _______,       _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,  KC_2,    KC_3,     _______,     _______,       _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          KC_0,  XXXXXXX, TO(BASE), TO(MOD_WIN), TO(MOD_MUSIC), _______, _______, _______
  ),

  [NUMPAD] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          KC_0,    XXXXXXX, _______, _______, _______, _______, _______, _______
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

// ==================================================

void td_macro_1(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 2) return;

  keyrecord_t kr;
  kr.event.pressed = false;
  uint16_t action = DYN_MACRO_PLAY1;

  if (state->count == 2) {
    action = DYN_REC_START1;
  }

  process_dynamic_macro(action, &kr);
}

void td_macro_2(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 2) return;

  keyrecord_t kr;
  kr.event.pressed = false;
  uint16_t action = DYN_MACRO_PLAY2;

  if (state->count == 2) {
    action = DYN_REC_START2;
  }

  process_dynamic_macro(action, &kr);
}

// ==================================================

// PRESSED MEANS ITS BEING HELD
void td_lock_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (!state->pressed) {
      register_code(KC_NLCK);

      if (layer_state_is(NUMPAD)) {
        layer_off(NUMPAD);

      } else {
        layer_on(NUMPAD);
      }
    }
  }

  if (state->count == 2) {
    if (!state->pressed) {
      layer_off(NUMPAD);

      register_code(KC_LGUI);
      register_code(KC_L);
    }
  }
}

void td_lock_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_NLCK);
  unregister_code(KC_L);
  unregister_code(KC_LGUI);
}

// ==================================================

void td_spacebar_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->pressed) {
      layer_on(MOUSE);

    } else {
      register_code(KC_SPC);
    }
  }

  if (state->count == 2) {
    if (state->pressed) {
      layer_on(FN);
    }
  }
}

void td_spacebar_reset (qk_tap_dance_state_t *state, void *user_data) {
  layer_off(MOUSE);
  unregister_code(KC_SPC);
  layer_off(FN);
}

// ==================================================

void td_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->pressed) {
      register_code(KC_LCTL);

    } else {
      register_code(KC_CAPS);
    }
  }
}

void td_caps_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  unregister_code(KC_CAPS);
}

// ==================================================

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lock_finished, td_lock_reset),
  [TD_SHOT] = ACTION_TAP_DANCE_DOUBLE(SELSHOT, WINSHOT),
  [TD_MAC1] = ACTION_TAP_DANCE_FN(td_macro_1),
  [TD_MAC2] = ACTION_TAP_DANCE_FN(td_macro_2),
  [TD_SPACEBAR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spacebar_finished, td_spacebar_reset),
  [TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_finished, td_caps_reset),
};
