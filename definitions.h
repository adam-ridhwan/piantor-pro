
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define H(kc)   HYPR(kc)

// thumb keys
#define EDT     MO(EDITING)
#define ESC_NAV LT(NAVIGATION, KC_ESC)
#define JSC_TAB LT(JAVASCRIPT, KC_TAB)
#define NUM_SPC LT(NUMBER, KC_SPC)
#define SYM_BPC LT(SYMBOL, KC_BSPC)
#define FUN     MO(FUNCTION)
#define MED_SLH LT(MEDIA, KC_SLSH)

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

// NAVIGATION LAYER
#define CYCLE   G(KC_GRAVE)
#define BACK    G(KC_LCBR)
#define FWRD    G(KC_RCBR)
#define PREV    G(KC_LBRC)
#define NEXT    G(KC_RBRC)
#define IN      G(KC_EQUAL)
#define OUT     G(KC_MINUS)

// EDITING LAYER
#define COPY    G(KC_C)
#define PASTE   G(KC_V)
#define CUT     G(KC_X)
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))

// FUNCTION LAYER
#define PRT_3   G(S(KC_3))
#define PRT_4   G(S(KC_4))
#define PRT_5   G(S(KC_5))
#define CPRT_3  G(S(C(KC_3)))
#define CPRT_4  G(S(C(KC_4)))

#endif
