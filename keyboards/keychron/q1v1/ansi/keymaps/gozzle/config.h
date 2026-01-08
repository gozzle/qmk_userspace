#pragma once

// optimisations for boot time
//#ifndef NO_DEBUG
//#define NO_DEBUG
//#endif
//#ifndef NO_PRINT
//#define NO_PRINT
//#endif



#ifdef RGB_MATRIX_ENABLE

// hard-coded colors for caps lock and fn layer
#  define CAPS_LOCK_INDICATOR_COLOR_RGB RGB_RED
#  define FN_LAYER_COLOR_RGB RGB_GREEN

#  define RGB_MATRIX_KEYREACTIVE_ENABLED

// Leave as default
// #  define RGB_MATRIX_SOLID_REACTIVE_BACKLIGHT_COLOR_HSV 0, 0, 96  // dim white

#endif //RGB_MATRIX_ENABLE