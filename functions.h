#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include QMK_KEYBOARD_H
#include "enums.h"

static inline void hyper(uint16_t code) {
    register_mods(KC_LSFT | KC_LCTL | KC_LALT | KC_LGUI);
    tap_code(code);
    unregister_mods(KC_LSFT | KC_LCTL | KC_LALT | KC_LGUI);
}

static inline void open_app(uint16_t keycode) {
    switch (keycode) {
        case IDE:
            hyper(KC_I);
            break;

        case BRAVE:
            hyper(KC_B);
            break;

        case CHROME:
            hyper(KC_R);
            break;

        case FINDER:
            hyper(KC_F);
            break;

        case SLACK:
            hyper(KC_K);
            break;

        case NOTION:
            hyper(KC_N);
            break;

        case SPOTIFY:
            hyper(KC_S);
            break;

        default:
            break;
    }
}

#endif
