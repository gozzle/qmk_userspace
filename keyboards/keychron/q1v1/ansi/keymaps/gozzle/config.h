#pragma once

// optimisations for boot time
#ifndef NO_DEBUG
#define NO_DEBUG
#endif
#ifndef NO_PRINT
#define NO_PRINT
#endif



#ifdef RGB_MATRIX_ENABLE

  // turn off lights if suspended or after timeout
#  define RGB_MATRIX_SLEEP
#  define RGB_MATRIX_TIMEOUT 300000  // 5 min

  // hard-coded colors for caps lock and fn layer
#  define CAPS_LOCK_INDICATOR_COLOR_RGB RGB_RED
#  define FN_LAYER_COLOR_RGB RGB_GREEN

#  define RGB_MATRIX_KEYREACTIVE_ENABLED

  // Only enable a few effects
#  define ENABLE_RGB_MATRIX_SOLID_COLOR
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_BACKLIGHT

// Leave as defaults
// #  define RGB_MATRIX_SOLID_REACTIVE_BACKLIGHT_COLOR_HSV 0, 0, 96  // dim white
// #  define RGB_MATRIX_KEYREACTIVE_DELAY 70

#endif //RGB_MATRIX_ENABLE