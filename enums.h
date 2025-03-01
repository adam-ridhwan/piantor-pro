#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER = 2,
    SYMBOL = 3,
    JAVASCRIPT = 4,
    FUNCTION = 5,
    EDITING = 6,
    MEDIA = 7,
    SCREENSHOT = 8,
};

enum custom_keycodes {
    SEARCH = SAFE_RANGE,
};

#endif
