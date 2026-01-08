// rgb_matrix_user.c

#include QMK_KEYBOARD_H
#include "rgb_matrix_user.h"
#include "keymap_user.h"

// map to allow us to easily retrieve key position for a given led index
keypos_t led_index_key_position[RGB_MATRIX_LED_COUNT];

void rgb_matrix_init_user(void) {
    // set up led_index_key_position map
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
  for (uint8_t i = led_min; i < led_max; i++) {
    uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
    if (is_keycode(keycode)) {
      RGB_MATRIX_INDICATOR_SET_COLOR(i, red, green, blue);
    }
  }
}

// Determine if the given keycode should light up as a caps lock indicator
// Depends on user setting of caps_lock_light_tab and caps_lock_light_alphas
// Always considers KC_CAPS and KC_CAPC to be indicator keys
bool is_caps_lock_indicator_key(uint16_t keycode) {
  bool indicator = keycode == KC_CAPS || keycode == KC_CAPC;

  if (user_config.caps_lock_light_tab) {
    indicator = keycode == KC_TAB || indicator;
  }
  if (user_config.caps_lock_light_alphas) {
    indicator = (KC_A <= keycode && keycode <= KC_Z) || indicator;
  }
  return indicator;
}

// Determine if the given keycode is transparent
bool is_transparent(uint16_t kc) {return kc == KC_TRNS;}
bool is_not_transparent(uint16_t kc) {return !is_transparent(kc);}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
  switch (current_layer) {
    case MAC_BASE:
    case WIN_BASE:
      if (host_keyboard_led_state().caps_lock) {
#ifdef CAPS_LOCK_INDICATOR_COLOR_RGB
        rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, &is_caps_lock_indicator_key, CAPS_LOCK_INDICATOR_COLOR_RGB);
#else
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 255, 255);
#endif
      }
      break;
    case MAC_FN:
    case WIN_FN:
#ifdef FN_LAYER_COLOR_RGB
      if (user_config.fn_layer_color_enable) {
        rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, &is_not_transparent, FN_LAYER_COLOR_RGB);
      }
#endif
      if (user_config.fn_layer_transparent_keys_off) {
          rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, &is_transparent, RGB_OFF);
      }
      break;
  }
  return false;
}
