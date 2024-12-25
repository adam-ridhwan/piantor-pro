#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAVIGATION = 1,
    NUMBER = 2,
    SYMBOL = 3,
    JAVASCRIPT = 4,
    FUNCTION = 5,
    TILING = 6
};

enum apps {
    BRAVE = 1000,
    IDE = 1001,
    CHROME = 1002,
    SLACK = 1003,
    NOTION = 1004,
    SPOTIFY = 1005,
    BITBUCK = 1006,
    JIRA = 1007,
    CONFLUE = 1008,
    FINDER = 1009
};

enum tile {
    MAX = 2000,
    MAX_H = 2001,
    MAX_W = 2002,
    FOUR_1 = 2003,
    FOUR_2 = 2004,
    FOUR_3 = 2005,
    FOUR_4 = 2006,
    THIRD_L = 2007,
    THIRD_C = 2008,
    THIRD_R = 2009,
    HALF_L = 2010,
    HALF_C = 2011,
    HALF_R = 2012,
    BIGGER = 2013,
    SMALLER = 2014,
    CENTER = 2015
};

#endif
