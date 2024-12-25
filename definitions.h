#ifndef HOMEROW_H
#define HOMEROW_H

// thumb keys
#define JSC_ESC LT(JAVASCRIPT, KC_ESC)
#define NAV_TAB LT(NAVIGATION, KC_TAB)
#define FUN_BPC LT(FUNCTION, KC_BSPC)
#define NUM_SPC LT(NUMBER, KC_SPC)
#define SYM_SFT LT(SYMBOL, KC_RSFT)
#define TIL_ENT LT(TILING, KC_ENT)

// homerow left keys
#define SHFT_A  SFT_T(KC_A)
#define CTRL_R  CTL_T(KC_R)
#define OPTN_S  OPT_T(KC_S)
#define CMND_T  CMD_T(KC_T)

// homerow right keys
#define CMND_N  CMD_T(KC_N)
#define OPTN_E  OPT_T(KC_E)
#define CTRL_I  CTL_T(KC_I)
#define SHFT_O  SFT_T(KC_O)

#define UNDO    LCMD(KC_Z)
#define REDO    LCMD(KC_X)
#define COPY    LCMD(KC_C)
#define PASTE   LCMD(KC_V)

#define KC_HYPER  (MOD_LGUI | MOD_LALT | MOD_LCTL | MOD_LSFT)
#define LG_LA     (MOD_LGUI | MOD_LALT)

#define CYCLE   RGUI(KC_GRAVE)

#endif
