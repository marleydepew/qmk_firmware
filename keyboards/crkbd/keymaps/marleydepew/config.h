
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

    #define RGB_MATRIX_NONE
    #define RGB_MATRIX_SOLID_COLOR         // Static single hue, no speed support
    #define RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
    #define RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
/*    RGB_MATRIX_GRADIENT_LEFT_RIGHT // Static gradient left to right, speed controls how much gradient changes
    RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
    RGB_MATRIX_BAND_SAT            // Single hue band fading saturation scrolling left to right
    RGB_MATRIX_BAND_VAL            // Single hue band fading brightness scrolling left to right
    RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
    RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
    RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
    RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
    RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
    RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
    RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
    RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
    RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
    RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
    RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
    RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
    RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halves of keyboard
    RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
    RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
    RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
    RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight amount at the same time, then shifts back
    RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight amount in a wave to the right, then back to the left
    RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight amount and then back down in a wave to the right
    RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
    RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
    RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
    RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
    RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
    RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
    RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
    RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
    RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
    RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
    RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
    RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness, maintaining user set color
    RGB_MATRIX_STARLIGHT_SMOOTH    // LEDs slowly increase and decrease in brightness randomly
    RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
    RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
    RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
    RGB_MATRIX_EFFECT_MAX */
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define RGB_MATRIX_TIMEOUT 30000
#endif
