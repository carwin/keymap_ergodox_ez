#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    RNDM,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  | Tab  |           | BSPC |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  Esc |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Hyper | Esc  | LGui |  Alt |  L1  |                                       |  L2  | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Ply/Ps| Mute |       | Calc | PScrn  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VOL+ |       | PgUp |        |      |
 *                                 | Space| BSPC |------|       |------| Enter  |Space |
 *                                 |      |      | VOL- |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
/*
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,       KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_TAB,                 KC_BSPC,        KC_6,      KC_7,     KC_8,     KC_9,    KC_0,      KC_MINS,
  KC_TAB,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(SYMB),               TG(RNDM),       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,      KC_BSLS,
  KC_LCTRL      KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,      KC_J,     KC_K,     KC_L,    KC_SCLN,   KC_QUOT,
  KC_LSFT,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, ALL_T(KC_NO),           MEH_T(KC_NO),   KC_N,      KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,   KC_RSFT,
  ALL_T(KC_NO), KC_ESC, KC_LGUI, KC_LALT, MO(SYMB),                                              MO(RNDM),  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,
                                                     KC_MPLY, KC_MUTE,               KC_CALCULATOR,  KC_PSCR,
                                                                          KC_VOLU,              KC_PGUP,
                                                         KC_SPC, KC_BSPC, KC_VOLD,            KC_PGDN, KC_ENT, KC_SPC
),
*/
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_TAB,              KC_BSPC,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),             TG(RNDM),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_LCTRL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,         KC_Z, KC_X,          KC_C,    KC_V,    KC_B,    KC_ESC,                  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH, KC_RSFT,
  ALL_T(KC_NO), KC_ESC,     KC_LGUI, KC_LALT, MO(SYMB),                                              MO(RNDM),   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
                                                           KC_MPLY, KC_MUTE,                KC_CALCULATOR, KC_PSCR,
                                                                          KC_VOLU,                 KC_PGUP,
                                                         KC_SPC, KC_BSPC, KC_VOLD,                  KC_PGDN, KC_ENT, KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |           |      |  ^   |   &  |   *  |   (  |   )  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |WWW BK|      |      |      |WWW FD|------|           |------|  ~   |   -  |   +  |   {  |   }  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |  |   |   _  |   =  |   [  |   ]  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |Animat| Hue- |Brtns-|Brtns+| Hue+ |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,          _______,              _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM,     KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        _______,              _______, KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
  _______, KC_WWW_BACK, _______, _______, _______, KC_WWW_FORWARD,                                KC_TILDE,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, _______,     _______, _______, _______, _______,        _______,              _______, KC_PIPE,   KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  EEP_RST, _______,     _______, _______, _______,                                                           _______, RGB_HUD, RGB_VAD, RGB_VAI,  RGB_HUI,
                                                               RGB_MOD, KC_TRNS,     RGB_TOG, RGB_SLD,
                                                                        KC_TRNS,     KC_TRNS,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Random Stuff
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |  ^   |  &   |  *   |  (   |  )   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WWW BK|      |      |      |WWW FD|------|           |------|  ~   |  -   |  +   |  {   |  }   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  |   |  _   |  =   |  [   |  ]   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RNDM] = LAYOUT_ergodox_pretty(
  // left hand
  _______, KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,          _______,              _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM,     KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        _______,              _______, KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
  _______, KC_WWW_BACK, _______, _______, _______, KC_WWW_FORWARD,                                KC_TILDE,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, _______,     _______, _______, _______, _______,        _______,              _______, KC_PIPE,   KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, _______,     _______, _______, _______,                                                           _______, _______, _______, _______, _______,
                                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                                        KC_TRNS,     KC_TRNS,
                                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
