#include QMK_KEYBOARD_H

enum {
      _LAYER0 = 0,
      _LAYER1,
      _LAYER2
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    // U_T_AGCR,              //USB Toggle Automatic GCR control
    // DBG_TOG,               //DEBUG Toggle On / Off
    // DBG_MTRX,              //DEBUG Toggle Matrix Prints
    // DBG_KBD,               //DEBUG Toggle Keyboard Prints
    // DBG_MOU,               //DEBUG Toggle Mouse Prints
    // MD_BOOT,               //Restart into bootloader after hold timeout
    STT_G0_HUI,                 //Custom gradient color 1 hue increase
    STT_G0_HUD,                 //Custom gradient color 1 hue decrease
    STT_G0_SAI,                 //Custom gradient color 1 saturation increase
    STT_G0_SAD,                 //Custom gradient color 1 saturation decrease
    STT_G0_VAI,                 //Custom gradient color 1 value increase
    STT_G0_VAD,                 //Custom gradient color 1 value decrease
    STT_G100_HUI,               //Custom gradient color 2 hue increase
    STT_G100_HUD,               //Custom gradient color 2 hue decrease
    STT_G100_SAI,               //Custom gradient color 2 saturation increase
    STT_G100_SAD,               //Custom gradient color 2 saturation decrease
    STT_G100_VAI,               //Custom gradient color 2 value increase
    STT_G100_VAD,               //Custom gradient color 2 value decrease
    STT_GRADIENT_PRESETS,       //Gradient presets
    STT_REFLECTED_GRADIENT,     //Toggle between linear and reflected gradient
    STT_GRADIENT_FLIP,          //Flip the gradient colors
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
		    KC_LSFT,       STT_GRADIENT_PRESETS,  STT_REFLECTED_GRADIENT, STT_GRADIENT_FLIP,KC_TRNS, KC_TRNS, AG_NORM, AG_SWAP, RGB_SAD, RGB_SAI, KC_TRNS,  KC_MPLY,          KC_VOLU,  KC_MUTE,\
		    KC_TRNS,       KC_TRNS,    KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,           KC_BRID, KC_VOLD,  KC_BRIU),
        [_LAYER2] = LAYOUT_65_ansi_blocker( /* MOUSE */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_DEL,   KC_CALC,\
            KC_CAPS,       KC_BTN1,  KC_MS_U, KC_BTN2, KC_WH_U, STT_G0_HUD,  STT_G0_HUI, STT_G0_SAD, STT_G0_SAI, STT_G0_VAD, STT_G0_VAI,  KC_SLCK,  KC_PAUS, RESET,    KC_MYCM,\
            KC_TRNS,       KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D, STT_G100_HUD,  STT_G100_HUI, STT_G100_SAD, STT_G100_SAI, STT_G100_VAD, STT_G100_VAI,  KC_TRNS,           EEP_RST,  KC_HOME,\
            KC_LSFT,       RGB_TOG,  RGB_MOD, RGB_VAI, RGB_VAD, STT_GRADIENT_PRESETS,  STT_REFLECTED_GRADIENT, STT_GRADIENT_FLIP, RGB_HUD, KC_TRNS, KC_TRNS,  KC_MPLY,           KC_VOLU,  KC_MUTE,\
            KC_TRNS,       KC_TRNS,  KC_TRNS,                   KC_TRNS,                   KC_TRNS,          KC_TRNS,            KC_MPRV, KC_VOLD,  KC_MNXT),

};

// For STT_CUSTOM_GRADIENT
HSV stt_gradient_0 = {205, 250, 255};
HSV stt_gradient_100 = {140, 215, 125};
bool stt_reflected_gradient = false;
uint8_t stt_gp_i = 0;

typedef struct {
    HSV gradient_0;
    HSV gradient_1;
    bool reflected;
} STT_CUSTOM_PRESETS;

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

uint8_t color_adj_step = 5;
STT_CUSTOM_PRESETS stt_gradient_presets[] = {
    {{205, 250, 255}, {140, 215, 125}, false },
    {{41, 255, 255}, {233, 245, 255}, false },
    {{45, 245, 155}, {160, 255, 80}, false },
    {{173, 245, 40}, {41, 255, 205}, true },
    {{32, 255, 165}, {217, 185, 70}, false },
    {{240, 255, 145}, {115, 255, 245}, true },
    {{118, 255, 255}, {242, 255, 255}, false },
    {{118, 255, 255}, {242, 255, 255}, false },
    {{212, 0, 0}, {223, 235, 165}, true },
};
uint8_t stt_gp_length = sizeof(stt_gradient_presets)/sizeof(stt_gradient_presets[0]);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case STT_G0_HUI:
            if (record->event.pressed) {
                stt_gradient_0.h += color_adj_step;
            }
            return false;
        case STT_G0_HUD:
            if (record->event.pressed) {
                stt_gradient_0.h -= color_adj_step;
            }
            return false;
        case STT_G0_SAI:
            if (record->event.pressed) {
                stt_gradient_0.s = (stt_gradient_0.s + color_adj_step * 2 <= 255) ? stt_gradient_0.s + color_adj_step * 2 : 255;
            }
            return false;
        case STT_G0_SAD:
            if (record->event.pressed) {
                stt_gradient_0.s = (stt_gradient_0.s - color_adj_step * 2 >= 0) ? stt_gradient_0.s - color_adj_step * 2 : 0;
            }
            return false;
        case STT_G0_VAI:
            if (record->event.pressed) {
                stt_gradient_0.v = (stt_gradient_0.v + color_adj_step * 2 <= 255) ? stt_gradient_0.v + color_adj_step * 2 : 255;
            }
            return false;
        case STT_G0_VAD:
            if (record->event.pressed) {
                stt_gradient_0.v = (stt_gradient_0.v - color_adj_step * 2 >= 0) ? stt_gradient_0.v - color_adj_step * 2 : 0;
            }
            return false;
        case STT_G100_HUI:
            if (record->event.pressed) {
                stt_gradient_100.h += color_adj_step;
            }
            return false;
        case STT_G100_HUD:
            if (record->event.pressed) {
                stt_gradient_100.h -= color_adj_step;
            }
            return false;
        case STT_G100_SAI:
            if (record->event.pressed) {
                stt_gradient_100.s = (stt_gradient_100.s + color_adj_step * 2 <= 255) ? stt_gradient_100.s + color_adj_step * 2 : 255;
            }
            return false;
        case STT_G100_SAD:
            if (record->event.pressed) {
                stt_gradient_100.s = (stt_gradient_100.s - color_adj_step * 2 >= 0) ? stt_gradient_100.s - color_adj_step * 2 : 0;
            }
            return false;
        case STT_G100_VAI:
            if (record->event.pressed) {
                stt_gradient_100.v = (stt_gradient_100.v + color_adj_step * 2 <= 255) ? stt_gradient_100.v + color_adj_step * 2 : 255;
            }
            return false;
        case STT_G100_VAD:
            if (record->event.pressed) {
                stt_gradient_100.v = (stt_gradient_100.v - color_adj_step * 2 >= 0) ? stt_gradient_100.v - color_adj_step * 2 : 0;
            }
            return false;
        case STT_GRADIENT_PRESETS:
            if (record->event.pressed) {
                stt_gp_i = (stt_gp_i + stt_gp_length ) % stt_gp_length;
                stt_gradient_0 = stt_gradient_presets[stt_gp_i].gradient_0;
                stt_gradient_100 = stt_gradient_presets[stt_gp_i].gradient_1;
                stt_reflected_gradient = stt_gradient_presets[stt_gp_i].reflected;
                stt_gp_i += 1;
            }
            return false;
        case STT_REFLECTED_GRADIENT:
            if (record->event.pressed) {
                stt_reflected_gradient = !stt_reflected_gradient;
            }
            return false;
        case STT_GRADIENT_FLIP:
            if (record->event.pressed) {
                HSV temp_color = stt_gradient_0;
                stt_gradient_0 = stt_gradient_100;
                stt_gradient_100 = temp_color;
            }
            return false;
    }
    return true;
}

// void rgb_matrix_indicators_user(void) {
//     //
// }
// void set_hsv_at(HSV hsv, uint8_t index);
// void set_hsv_at(HSV hsv, uint8_t index) {
//     RGB rgb = hsv_to_rgb(hsv);
//     rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
// }
