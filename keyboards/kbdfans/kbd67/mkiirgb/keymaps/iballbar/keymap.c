#include QMK_KEYBOARD_H

enum {
      _LAYER0 = 0,
      _LAYER1,
      _LAYER2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRV,\
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_HOME,\
	  LT(_LAYER2, KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_END,\
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     OSM(MOD_LSFT|MOD_LALT|MOD_LGUI),\
		    KC_LCTL,       KC_LALT,  KC_LGUI,                  KC_SPC,                       KC_RGUI,   MO(1),              KC_LEFT, KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi_blocker( /* FN */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,\
		    KC_TRNS,       RGB_TOG,  RGB_SPI, KC_TRNS,KC_TRNS, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,  KC_SLCK, KC_PAUS, RESET,    KC_PGUP,\
	        CTL_T(KC_CAPS),RGB_RMOD, RGB_SPD, RGB_MOD,RGB_HUD, RGB_VAD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGDN,\
		    KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, AG_NORM, AG_SWAP, RGB_SAD, RGB_SAI, KC_TRNS,  KC_MPLY,          KC_VOLU,  KC_MUTE,\
		    KC_TRNS,       KC_TRNS,    KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,           KC_BRID, KC_VOLD,  KC_BRIU),
        [_LAYER2] = LAYOUT_65_ansi_blocker( /* MOUSE */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_DEL,   KC_CALC,\
            KC_TAB,        KC_BTN1,  KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_SLCK,  KC_PAUS, RESET,    KC_MYCM,\
            CTL_T(KC_CAPS),KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           EEP_RST,  KC_HOME,\
            KC_LSFT,       RGB_TOG,  RGB_MOD, RGB_VAI, RGB_VAD, KC_TRNS,  KC_TRNS, KC_TRNS, RGB_HUD, KC_TRNS, KC_TRNS,  KC_MPLY,           KC_VOLU,  KC_MUTE,\
            KC_TRNS,       KC_TRNS,  KC_TRNS,                   KC_TRNS,                   KC_TRNS,          KC_TRNS,            KC_MPRV, KC_VOLD,  KC_MNXT),

};
