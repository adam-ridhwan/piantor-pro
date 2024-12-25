#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include QMK_KEYBOARD_H
#include "enums.h"

static inline void hyper(uint16_t code) {
    register_mods(KC_HYPER);
    tap_code(code);
    unregister_mods(KC_HYPER);
}

static inline void meh(uint16_t code) {
    register_mods(MOD_LCTL | MOD_LALT | MOD_LSFT);
    tap_code(code);
    unregister_mods(MOD_LCTL | MOD_LALT | MOD_LSFT);
}

static inline void center(void) {
    wait_ms(200);
    hyper(KC_D);
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
            center();
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

        case BITBUCK:
            hyper(KC_T);
            break;

        case JIRA:
            hyper(KC_J);
            break;

        case CONFLUE:
            hyper(KC_L);
            break;

        default:
            break;
    }
}

static inline void tile_app(uint16_t keycode) {
    switch (keycode) {
        case MAX:
            meh(KC_J);
            break;

        case MAX_H:
            meh(KC_K);
            break;

        case MAX_W:
            meh(KC_M);
            break;

        case FOUR_1:
            meh(KC_L);
            break;

        case FOUR_2:
            meh(KC_U);
            break;

        case FOUR_3:
            meh(KC_Y);
            break;

        case FOUR_4:
            meh(KC_SEMICOLON);
            break;

        case THIRD_L:
            meh(KC_H);
            break;

        case THIRD_C:
            meh(KC_COMMA);
            break;

        case THIRD_R:
            meh(KC_DOT);
            break;

        case HALF_L:
            meh(KC_N);
            break;

        case HALF_C:
            meh(KC_E);
            break;

        case HALF_R:
            meh(KC_I);
            break;

        case BIGGER:
            meh(KC_O);
            break;

        case SMALLER:
            meh(KC_SLASH);
            break;

        case CENTER:
            meh(KC_SPACE);
            break;

        default:
            break;
    }
}

#endif
