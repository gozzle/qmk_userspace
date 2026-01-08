
#pragma once

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};


#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_CAPC KC_CAPS_CUSTOM
#define KC_LTTOG KC_LIGHT_TAB_TOGGLE
#define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
#define KC_TKTOG KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
#define KC_FCTOG KC_FN_LAYER_COLOR_TOGGLE
#define KC_BOOT KC_BOOT_WITH_DELAY

enum custom_keycodes {
    KC_NULL = SAFE_RANGE,
    KC_CAPS_CUSTOM,  // use macro to fire KC_CAP to avoid MacOS's inbuilt stupid delay
    KC_LIGHT_TAB_TOGGLE,
    KC_LIGHT_ALPHAS_TOGGLE,
    KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE,
    KC_FN_LAYER_COLOR_TOGGLE,
    KC_BOOT_WITH_DELAY,  //restart into bootloader after 500ms hold timeout
}
