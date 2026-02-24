#include QMK_KEYBOARD_H
#include "../../macro.h"

enum layer_names {
    _COLEMAK_DH,
    _NUMBER,
    _SYMBOL,
    _FUNCTION,
    _NAVIGATION,
    _MOUSE,
    _RGB
};

enum custom_keycodes {
    MACRO_V = SAFE_RANGE,
    MACRO_A,
    MACRO_C,
    MACRO_1,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MS_WHLD_SLOW,
    MS_WHLD_FASTER,
    MS_WHLD_FASTEST,
    MS_WHLU_SLOW,
    MS_WHLU_FASTER,
    MS_WHLU_FASTEST    
};

enum mouse_wheel_acceleration {
    DEFAULT = 10,
    SLOW = 0,
    FASTER = 1,
    FASTEST = 2
};

uint8_t mouse_wheel_acceleration_mode = DEFAULT;
uint32_t mouse_wheel_acceleration_timer = 0; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3_ex2(                                                        // Colemak DH Layer
    // |-------------+-------------+-------------+-------------+-------------+-------------+-------------|   |-------------+-------------+-------------+-------------+-------------+-------------+-------------|
        MACRO_1,      KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         MACRO_1,          MACRO_3,      KC_J,         KC_L,         KC_U,         KC_Y,         XXXXXXX,      MACRO_2,
    // |-------------+-------------+-------------+-------------+-------------+-------------+-------------|   |-------------+-------------+-------------+-------------+-------------+-------------+-------------|
        KC_CAPS,      LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,         MACRO_2,          MACRO_4,      KC_M,         LCTL_T(KC_N), LSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT,
    // |-------------+-------------+-------------+-------------+-------------+-------------+-------------|   |-------------+-------------+-------------+-------------+-------------+-------------+-------------|
        KC_ESC,       KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                                         KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      QK_LEAD,
    // |-------------+-------------+-------------+-------------+-------------+-------------|                               |-------------+-------------+-------------+-------------+-------------+-------------|
                                                  LT(3,KC_TAB), LT(1,KC_BSPC),LT(2,KC_DEL),                                 LT(5,KC_ENT), LT(4,KC_SPC), LT(6,KC_PSCR) 
    //                                           |-------------+-------------+-------------|                               |-------------+-------------+-------------|
    ),

    [_NUMBER] = LAYOUT_split_3x6_3(                                      // Number Layer
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,    KC_1,       KC_2,       KC_3,       XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_COLN,    KC_GRV,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_UNDS,    KC_7,       KC_8,       KC_9,       KC_SLSH,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
                                            XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_LPRN,    KC_0,       KC_RPRN
    //                                     |-----------+-----------+-----------|   |-----------+-----------+-----------|
    ),

    [_SYMBOL] = LAYOUT_split_3x6_3(                                      // Symbols Layer
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,    KC_EXLM,    KC_AT,      KC_HASH,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,        KC_PLUS,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_SCLN,    KC_TILD,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_EQL,     KC_AMPR,    KC_ASTR,    KC_DOT,     KC_BSLS,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
                                            XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_LBRC,    XXXXXXX,    KC_RBRC
    //                                     |-----------+-----------+-----------|   |-----------+-----------+-----------|
  ),

    [_FUNCTION] = LAYOUT_split_3x6_3(                                   // Function Layer
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,        XXXXXXX,    KC_F4,      KC_F5,      KC_F6,      KC_APP,     KC_PIPE,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,    KC_F7,      KC_F8,      KC_F9,      KC_PAUS,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
                                            XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_F11,     KC_F10,     KC_F12
    //                                     |-----------+-----------+-----------|   |-----------+-----------+-----------|
  ),

    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(                                  // Navigation Layer (with macros)
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC1,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    XXXXXXX,    DM_PLY1,        XXXXXXX,    XXXXXXX,    KC_RCTL,    KC_RSFT,    KC_RALT,    KC_RGUI,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     XXXXXXX,                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
                                            XXXXXXX,    XXXXXXX,    XXXXXXX,                                XXXXXXX,    XXXXXXX,    XXXXXXX
    //                                     |-----------+-----------+-----------|                           |-----------+-----------+-----------|
  ),

    [_MOUSE] = LAYOUT_split_3x6_3_ex2(                                                // Mouse Layer
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
        MACRO_V,    MS_WHLL,    MS_WHLU,    MS_WHLD,    MS_WHLR,    XXXXXXX,    DM_REC2,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
        MACRO_A,    MS_LEFT,    MS_UP,      MS_DOWN,    MS_RGHT,    LSFT(KC_F3),DM_PLY2,        XXXXXXX,    XXXXXXX,    KC_RCTL,    KC_RSFT,    KC_RALT,    KC_RGUI,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
        MACRO_C,    XXXXXXX,    XXXXXXX,    MS_BTN1,    MS_BTN2,    MS_BTN3,                                MS_BTN3,    MS_BTN1,    MS_BTN2,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
                                            MS_ACL0,    MS_ACL1,    MS_ACL2,                                XXXXXXX,    XXXXXXX,    XXXXXXX
    //                                     |-----------+-----------+-----------|                           |-----------+-----------+-----------|
  ),

    [_RGB] = LAYOUT_split_3x6_3(                                           // RGB Layer
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        XXXXXXX,    DT_PRNT,    DT_UP,      DT_DOWN,    XXXXXXX,    XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        RM_TOGG,    RM_NEXT,    RM_HUEU,    RM_SATU,    RM_VALU,    RM_SPDU,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
        RGB_M_G,    RM_PREV,    RM_HUED,    RM_SATD,    RM_VALD,    RM_SPDD,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    // |-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------|
                                            XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX
    //                                     |-----------+-----------+-----------|   |-----------+-----------+-----------|
  )
};

// These are my custom overrides for the shift keys
#ifdef KEY_OVERRIDE_ENABLE

// Shift + ( = < on the number layer
const key_override_t left_parenth_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_LABK, 1 << _NUMBER);

// Shift + ) = > on the number layer
const key_override_t right_parenth_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_RABK, 1 << _NUMBER);

// Shift + 9 = . on the number layer
const key_override_t nine_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_DOT, 1 << _NUMBER);

// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
const key_override_t *key_overrides[] = {
    &left_parenth_override,
    &right_parenth_override,
    &nine_override,
    NULL // Null terminate the array of overrides
};

#endif // End KEY_OVERRIDE_ENABLE

// This gets called for each key.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // This is for the macros
    switch (keycode) {
        
        case MACRO_V:
            if (record->event.pressed) {
                // when keycode MACRO_V is pressed
                // The string is defined in "../../macro.h"
                SEND_STRING(MV_STRING);
            } else {
                // when keycode MACRO_V is released
            }
            break;

        case MACRO_A:
            if (record->event.pressed) {
                // when keycode MACRO_A is pressed
                // The string is defined in "../../macro.h"
                SEND_STRING(MA_STRING);
            } else {
                // when keycode MACRO_A is released
            }
            break;

        case MACRO_C:
            if (record->event.pressed) {
                // when keycode MACRO_C is pressed
                // The string is defined in "../../macro.h"
                SEND_STRING(MC_STRING);
            } else {
                // when keycode MACRO_C is released
            }
            break;

        case MACRO_1:
            if (record->event.pressed) {
                // when keycode MACRO_1 is pressed
                SEND_STRING(SS_RGUI("r") SS_DELAY(500) "cmd.exe" SS_TAP(X_ENT));
            }
            break;

        case MACRO_2:
            if (record->event.pressed) {
                // when keycode MACRO_2 is pressed
                SEND_STRING(SS_RGUI("r") SS_DELAY(500) "calc.exe" SS_TAP(X_ENT));
            }
            break;

        case MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI("r") SS_DELAY(500) "cmd.exe" SS_TAP(X_ENT) SS_DELAY(1000) "python.exe" SS_TAP(X_ENT));
            }
            break;

        case MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI("r") SS_DELAY(500) "cmd.exe" SS_TAP(X_ENT) SS_DELAY(1000) "jupyter notebook" SS_TAP(X_ENT));
            }
            break;

        case MACRO_5:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_RGUI("x") SS_DELAY(1000) "a" SS_DELAY(1000) 
                    // SS_TAP(X_LEFT) SS_DELAY(2000) SS_TAP(X_ENT) SS_DELAY(2000)
                    "net stop TPHKLOAD" SS_TAP(X_ENT) SS_DELAY(2000)
                    "net stop audiosrv" SS_TAP(X_ENT) SS_DELAY(2000)
                    "net stop AudioEndpointBuilder" SS_TAP(X_ENT) SS_DELAY(2000)
                    "net start AudioEndpointBuilder" SS_TAP(X_ENT) SS_DELAY(2000)
                    "net start audiosrv" SS_TAP(X_ENT) SS_DELAY(2000)
                    "net start TPHKLOAD" SS_TAP(X_ENT) SS_DELAY(2000)
                );
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Down Slow Speed
       case MS_WHLD_SLOW:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        break;
                    case FASTER:
                        mouse_wheel_acceleration_mode = SLOW;
                        unregister_code16(MS_ACL1);
                        register_code16(MS_ACL0);
                        break;
                    case FASTEST:
                        mouse_wheel_acceleration_mode = SLOW;
                        unregister_code16(MS_ACL2);
                        register_code16(MS_ACL0);
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = SLOW;
                        register_code16(MS_ACL0);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLD);
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Down Faster Speed
       case MS_WHLD_FASTER:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        mouse_wheel_acceleration_mode = FASTER;
                        unregister_code16(MS_ACL0);
                        register_code16(MS_ACL1);
                        break;
                    case FASTER:
                        break;
                    case FASTEST:
                        mouse_wheel_acceleration_mode = FASTER;
                        unregister_code16(MS_ACL2);
                        register_code16(MS_ACL1);
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = FASTER;
                        register_code16(MS_ACL1);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLD);
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Down Fastest Speed
        case MS_WHLD_FASTEST:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        mouse_wheel_acceleration_mode = FASTEST;
                        unregister_code16(MS_ACL0);
                        register_code16(MS_ACL2);
                        break;
                    case FASTER:
                        mouse_wheel_acceleration_mode = FASTEST;
                        unregister_code16(MS_ACL1);
                        register_code16(MS_ACL2);
                        break;
                    case FASTEST:
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = FASTEST;
                        register_code16(MS_ACL2);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLD);
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Up Slow Speed
        case MS_WHLU_SLOW:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        break;
                    case FASTER:
                        mouse_wheel_acceleration_mode = SLOW;
                        unregister_code16(MS_ACL1);
                        register_code16(MS_ACL0);
                        break;
                    case FASTEST:
                        mouse_wheel_acceleration_mode = SLOW;
                        unregister_code16(MS_ACL2);
                        register_code16(MS_ACL0);
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = SLOW;
                        register_code16(MS_ACL0);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLU);
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Up Faster Speed
       case MS_WHLU_FASTER:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        mouse_wheel_acceleration_mode = FASTER;
                        unregister_code16(MS_ACL0);
                        register_code16(MS_ACL1);
                        break;
                    case FASTER:
                        break;
                    case FASTEST:
                        mouse_wheel_acceleration_mode = FASTER;
                        unregister_code16(MS_ACL2);
                        register_code16(MS_ACL1);
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = FASTER;
                        register_code16(MS_ACL1);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLU);
            }
            break;

        // For the Rotary Encoder
        // Mouse Wheel Up Fastest Speed
        case MS_WHLU_FASTEST:
            if (record->event.pressed) {
                switch (mouse_wheel_acceleration_mode) {
                    case SLOW:
                        mouse_wheel_acceleration_mode = FASTEST;
                        unregister_code16(MS_ACL0);
                        register_code16(MS_ACL2);
                        break;
                    case FASTER:
                        mouse_wheel_acceleration_mode = FASTEST;
                        unregister_code16(MS_ACL1);
                        register_code16(MS_ACL2);
                        break;
                    case FASTEST:
                        break;
                    case DEFAULT:
                        mouse_wheel_acceleration_mode = FASTEST;
                        register_code16(MS_ACL2);
                        break;
                }
                mouse_wheel_acceleration_timer = timer_read32();
                tap_code16(MS_WHLU);
            }
            break;

    }

    return true;
}

// This gets called constantly
void matrix_scan_user(void) { 
    switch (mouse_wheel_acceleration_mode) {
        case SLOW:
            if (timer_elapsed32(mouse_wheel_acceleration_timer) > 5000) {
                unregister_code16(MS_ACL0);
                mouse_wheel_acceleration_mode = DEFAULT;
            }
            break;
        case FASTER:
            if (timer_elapsed32(mouse_wheel_acceleration_timer) > 5000) {
                unregister_code16(MS_ACL1);
                mouse_wheel_acceleration_mode = DEFAULT;
            }
            break;
        case FASTEST:
            if (timer_elapsed32(mouse_wheel_acceleration_timer) > 5000) {
                unregister_code16(MS_ACL2);
                mouse_wheel_acceleration_mode = DEFAULT;
            }
            break;
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_COLEMAK_DH] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
  [_NUMBER] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
  [_SYMBOL] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
  [_FUNCTION] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), },
  [_NAVIGATION] = { ENCODER_CCW_CW(MS_WHLU_FASTER, MS_WHLD_FASTER), },
  [_MOUSE] = { ENCODER_CCW_CW(MS_WHLU_FASTEST, MS_WHLD_FASTEST), },
  [_RGB] = { ENCODER_CCW_CW(MS_WHLU_SLOW, MS_WHLD_SLOW), },
};
#endif
