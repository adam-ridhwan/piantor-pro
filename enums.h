#ifndef ENUMS_H
#define ENUMS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER = 2,
    JAVASCRIPT = 3,
    EDITING = 4,
    MEDIA = 5,
};

enum custom_keycodes {
    SEARCH = SAFE_RANGE,
};

#endif
