// RGB_MATRIX_EFFECT(solid_resplash)
// RGB_MATRIX_EFFECT(solid_multiresplash)
/*   Custom gradient that can be tweaked by keycodes
...........................................................*/
RGB_MATRIX_EFFECT(STT_CUSTOM_GRADIENT)
RGB_MATRIX_EFFECT(STT_CUSTOM_GRADIENT_SPLASH)
RGB_MATRIX_EFFECT(STT_WIDE_RAINBOW_GRADIENT)
RGB_MATRIX_EFFECT(wide_rainbow_splash)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "effects/stt_custom_gradient.c"
#include "effects/stt_wide_rainbow_gradient.c"

HSV resplash_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.h += effect;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
    // hsv.h += qsub8(130, tick);
    // return hsv;
}

// bool effect_runner_reactive_resplash(uint8_t start, effect_params_t* params, reactive_splash_f effect_func) {
//     RGB_MATRIX_USE_LIMITS(led_min, led_max);

//     uint8_t count = g_last_hit_tracker.count;
//     for (uint8_t i = led_min; i < led_max; i++) {
//         RGB_MATRIX_TEST_LED_FLAGS();
//         HSV hsv = rgb_matrix_config.hsv;
//         //hsv.v   = 0;
//         for (uint8_t j = start; j < count; j++) {
//             int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
//             int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
//             uint8_t  dist = sqrt16(dx * dx + dy * dy);
//             uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
//             hsv           = effect_func(hsv, dx, dy, dist, tick);
//         }
//         hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
//         RGB rgb = hsv_to_rgb(hsv);
//         rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//     }
//     return led_max < DRIVER_LED_TOTAL;
// }

bool effect_runner_rainbow_splash(uint8_t start, effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        //hsv.v   = 0;
        hsv = STT_WIDE_RAINBOW_GRADIENT_math(hsv, i, time);
        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            hsv           = resplash_math(hsv, dx, dy, dist, tick);
        }
        hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool effect_runner_gradient_splash(uint8_t start, effect_params_t* params){
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    uint8_t min_x = 0;  // X coordinate of the left-most LED
    uint8_t max_x = 224; // X coordinate of the right-most LED;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv = STT_CUSTOM_GRADIENT_math(g_led_config.point[i].x, min_x, max_x);
        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            hsv           = resplash_math(hsv, dx, dy, dist, tick);
        }
        hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

// bool solid_resplash(effect_params_t* params) {
//     return effect_runner_reactive_resplash(qsub8(g_last_hit_tracker.count, 1), params, &solid_resplash_math);
// }

// bool solid_multiresplash(effect_params_t* params) {
//     return effect_runner_reactive_resplash(0, params, &solid_resplash_math);
// }

bool wide_rainbow_splash(effect_params_t* params) {
    return effect_runner_rainbow_splash(qsub8(g_last_hit_tracker.count, 1), params);
}

static bool STT_CUSTOM_GRADIENT_SPLASH(effect_params_t* params) {
    return effect_runner_gradient_splash(qsub8(g_last_hit_tracker.count, 1), params);
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
