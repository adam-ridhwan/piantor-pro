#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define H(kc)   HYPR(kc)

// THUMB KEYS
#define EDT     MO(EDITING)
#define ESC_NAV LT(NAVIGATION, KC_ESC)
#define JSC_TAB LT(JAVASCRIPT, KC_TAB)
#define NUM_SPC LT(NUMBER, KC_SPC)
#define SYM_BPC LT(SYMBOL, KC_BSPC)
#define FUN_ENT LT(FUNCTION, KC_ENT)
#define MED_SLH LT(MEDIA, KC_SLSH)
#define SCR_Z   LT(SCREENSHOT, KC_Z)

// HOME ROW LEFT KEYS
#define SHFT_A  SFT_T(KC_A)
#define CTRL_R  CTL_T(KC_R)
#define OPTN_S  OPT_T(KC_S)
#define CMND_T  CMD_T(KC_T)

// HOME ROW RIGHT KEYS
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

// NUMBER LAYER
#define ONE     SFT_T(KC_1)
#define TWO     CTL_T(KC_2)
#define THREE   OPT_T(KC_3)
#define FOUR    CMD_T(KC_4)
#define FIVE    KC_5
#define SIX     KC_6
#define SEVEN   CMD_T(KC_7)
#define EIGHT   OPT_T(KC_8)
#define NINE    CTL_T(KC_9)
#define ZERO    SFT_T(KC_0)

// SYMBOL LAYER
#define EXCLM   KC_EXLM
#define AT      KC_AT
#define HASH    KC_HASH
#define DOLLAR  KC_DLR
#define PERCENT KC_PERC
#define CARET   KC_CIRC
#define AMPR    KC_AMPR
#define STAR    KC_ASTR
#define MINUS   KC_MINS
#define EQUAL   KC_EQUAL

#define TILDE   KC_TILD
#define PIPE    KC_PIPE
#define PLUS    KC_PLUS
#define GRAVE   KC_GRV
#define BSLS    KC_BSLS
#define UNDER   KC_UNDS
#define QUOT    KC_QUOT
#define DQUOT   KC_DQT

// FUNCTION LAYER
#define F1      SFT_T(KC_F1)
#define F2      CTL_T(KC_F2)
#define F3      OPT_T(KC_F3)
#define F4      CMD_T(KC_F4)
#define F5      KC_F5
#define F6      KC_F6
#define F7      CMD_T(KC_F7)
#define F8      OPT_T(KC_F8)
#define F9      CTL_T(KC_F9)
#define F10     SFT_T(KC_F10)


// EDITING LAYER
#define COPY    G(KC_C)
#define PASTE   G(KC_V)
#define CUT     G(KC_X)
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))

// SCREENSHOT LAYER
#define PRT_3   G(S(KC_3))
#define PRT_4   G(S(KC_4))
#define PRT_5   G(S(KC_5))
#define CPRT_3  G(S(C(KC_3)))
#define CPRT_4  G(S(C(KC_4)))

#endif
