
#pragma once

#define MASTER_LEFT

// Dynamic Tapping Term Settings
// #define PERMISSIVE_HOLD
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
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// RGB Light Settings
    #define RGB_MATRIX_GRADIENT_UP_DOWN
    #define RGB_MATRIX_STARLIGHT
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

// Create some space
#undef NKRO_ENABLE