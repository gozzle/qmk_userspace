# Gozzle's Custom Keymap for Keychron Q1v1 ANSI

## Features

* New RGB animation, RGB_MATRIX_SOLID_REACTIVE_BACKLIGHT added.
  * Uses constant background color (set by RGB_MATRIX_BACKLIGHT_HSV) and pulses
    to user-set hue on pressed keys. Slight pause after keypress, with duration set
    by RGB_MATRIX_KEYREACTIVE_DELAY.
* Added KC_CAPS_CUSTOM macro.
  * A wrapper round KC_CAPS which works around the fact that MacOS requires a longer
    hold of capslock for it to engage
* Added KC_BOOT macro to reboot the keyboard after long press without needing to press the reset pin.
* Keys rearranged for personal preference
* RGB lighting turns off when the computer sleeps
* Caps Lock RGB indicator
  * the Caps Lock key will light when Caps Lock is enabled with the following options:
    * #define CAPS_LOCK_INDICATOR_COLOR_RGB [color] in config.h to set the backlight color
      used for the indicator when Caps Lock is enabled (default: red)
      * Fn+Z will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit
        keycaps/legends. (default: off)
      * Fn+X will toggle lighting all the alpha keys when Caps Lock is enabled. (default: off)
* Dynamic Fn layer RGB indicator
  * When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
    * #define FN_LAYER_COLOR_RGB [color] in config.h to set a static color for defined keys
      (default: green)
      * Fn+C will toggle turning off RGB for keys with no definition (default: RGB off)
      * Fn+V will toggle lighting the defined Fn layer keys with the static color set with
        FN_LAYER_COLOR_RGB (default: static color off)

RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

## Acknowledgements

Much of this code was borrowed or adapted from existing published user keymaps by Grayson Carr
(gtg465x) and Mike Killewald (mkillewald), both previously visible in QMK Firmware on GitHub:
[Link](https://github.com/qmk/qmk_firmware/tree/ca0f922e073db9804ab0b55c62a43d81a957dce8/keyboards/keychron/q1/rev_0100/keymaps).

## License

Copyright 2026 @ Callum Chalk

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.