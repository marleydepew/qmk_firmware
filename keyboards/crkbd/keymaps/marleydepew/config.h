
#pragma once

#define MASTER_LEFT

// Dynamic Tapping Term Settings
#define TAPPING_TERM 220
#define DYNAMIC_TAPPING_TERM_INCREMENT 5

// Leader Key Settings
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 400
#define LEADER_NO_TIMEOUT

// Dynamic Macro Settings
#define DYNAMIC_MACRO_SIZE 64

// Mouse Key Combined Mode (Accelerated + Constant) Settings
#define MK_COMBINED

    // Accelerated Mouse Key Settings
    #define MOUSEKEY_DELAY 10
    #define MOUSEKEY_INTERVAL 16
    #define MOUSEKEY_MOVE_DELTA 2
    #define MOUSEKEY_MAX_SPEED 8
    #define MOUSEKEY_TIME_TO_MAX 30

    #define MOUSEKEY_WHEEL_DELAY 10
    #define MOUSEKEY_WHEEL_INTERVAL 80
    #define MOUSEKEY_WHEEL_DELTA 1
    #define MOUSEKEY_WHEEL_MAX_SPEED 1
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 0

    // Constant Settings
    #define MK_3_SPEED
    #define MK_MOMENTARY_ACCEL

    #define MK_C_OFFSET_UNMOD 8
    #define MK_C_INTERVAL_UNMOD 16
    #define MK_C_OFFSET_0 1
    #define MK_C_INTERVAL_0 32
    #define MK_C_OFFSET_1 4
    #define MK_C_INTERVAL_1 16
    #define MK_C_OFFSET_2 16
    #define MK_C_INTERVAL_2 16

    #define MK_W_OFFSET_UNMOD 1
    #define MK_W_INTERVAL_UNMOD 80
    #define MK_W_OFFSET_0 1
    #define MK_W_INTERVAL_0 320
    #define MK_W_OFFSET_1 1
    #define MK_W_INTERVAL_1 160
    #define MK_W_OFFSET_2 1
    #define MK_W_INTERVAL_2 40

// RGB Light Settings
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 127
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGB_MATRIX_TIMEOUT 30000
#endif

// RGB Matrix Settings
#ifdef RGB_MATRIX_ENABLE

    #define ENABLE_RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
    #define ENABLE_RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness, maintaining user set color
    #define ENABLE_RGB_MATRIX_STARLIGHT_SMOOTH    // LEDs slowly increase and decrease in brightness randomly
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
    #define ENABLE_RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing

    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define RGB_MATRIX_TIMEOUT 30000

#endif
