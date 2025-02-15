#include QMK_KEYBOARD_H
#include "definitions.h"
#include "enums.h"

// qmk flash -kb beekeeb/piantor_pro -km adamridhwan

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHFT_A:
        case CTRL_R:
        case OPTN_S:
        case CMND_T:
        case CMND_N:
        case OPTN_E:
        case CTRL_I:
        case SHFT_O:
        case ESC_NAV:
        case JSC_TAB:
        case SYM_BPC:
        case NUM_SPC:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------,  ,-----------------------------------------------------------,
      XXXXXXX ,   KC_Q  ,   KC_W  ,   KC_F  ,   KC_P  ,   KC_B  ,      KC_J  ,   KC_L  ,   KC_U  ,   KC_Y  , KC_SCLN , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,  SHFT_A ,  CTRL_R ,  OPTN_S ,  CMND_T ,   KC_G  ,      KC_M  ,  CMND_N ,  OPTN_E ,  CTRL_I ,  SHFT_O , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,   KC_Z  ,   KC_X  ,   KC_D  ,   KC_C  ,   KC_V  ,      KC_K  ,   KC_H  , KC_COMM ,  KC_DOT , MED_SLH , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
                                      EDT   , ESC_NAV , JSC_TAB ,    SYM_BPC , NUM_SPC ,   FUN
  //                              `---------+---------+---------'  '---------+---------+---------`
    ),

    [NAVIGATION] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,  ,-----------------------------------------------------------,
      XXXXXXX , H(KC_Q) , H(KC_W) , H(KC_F) , H(KC_P) , H(KC_B) ,     CYCLE  , KC_HOME ,  KC_UP  ,  KC_END , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , H(KC_G) ,    KC_PGUP , KC_LEFT , KC_DOWN , KC_RGHT ,  KC_ENT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX , H(KC_Z) , H(KC_X) , H(KC_D) , H(KC_C) , H(KC_V) ,    KC_PGDN ,   BACK  ,   FWRD  ,   PREV  ,   NEXT  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,    _______ , _______ , XXXXXXX
  //                              `---------+---------+---------'  '---------+---------+---------`
    ),

    [NUMBER] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , KC_CAPS ,   KC_7  ,   KC_8  ,   KC_9  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , CW_TOGG ,   KC_4  ,   KC_5  ,   KC_6  , XXXXXXX ,     XXXXXXX , KC_RGUI , KC_ROPT , KC_RCTL , KC_RSFT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX ,   KC_1  ,   KC_2  ,   KC_3  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX ,   KC_0  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [SYMBOL] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,------------------------------------------------------------,
      XXXXXXX , KC_TILD , KC_AMPR , KC_ASTR , KC_PIPE , KC_PLUS ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+----------+---------|
      XXXXXXX ,  KC_GRV ,  KC_DLR , KC_PERC , KC_CIRC , KC_MINS ,     XXXXXXX , KC_RGUI , KC_ROPT , KC_RCTL , KC_RSFT  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+----------+---------|
      XXXXXXX , KC_BSLS , KC_EXLM ,  KC_AT  , KC_HASH , KC_UNDS ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+----------+---------|
                                    XXXXXXX , KC_QUOT ,  KC_DQT ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [JAVASCRIPT] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------, z  ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_SCLN , KC_COLN , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,     XXXXXXX , KC_LPRN , KC_RPRN , KC_EQUAL,  KC_GT  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_LCBR , KC_RCBR , KC_LBRC , KC_RBRC , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [FUNCTION] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , KC_CAPS ,  KC_F7  ,  KC_F8  ,  KC_F9  , KC_F12  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------,   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , CW_TOGG ,  KC_F4  ,  KC_F5  ,  KC_F6  , KC_F11  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------,   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX ,  KC_F1  ,  KC_F2  ,  KC_F3  , KC_F10  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [EDITING] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,   REDO  ,   UNDO  ,   CUT   ,   COPY  ,  PASTE  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [MEDIA] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),
};
