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
        case NUM_SPC:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
static bool left_mod_active = false;
static bool right_mod_active = false;

    switch (keycode) {
        case SEARCH:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                wait_ms(1);
                tap_code16(G(KC_E));
            }
            return false;

        case SHFT_A:
        case CTRL_R:
        case OPTN_S:
        case CMND_T:
            if (record->event.pressed) {
                left_mod_active = true;
            } else {
                left_mod_active = false;
            }
            return true;

        case CMND_N:
        case OPTN_E:
        case CTRL_I:
        case SHFT_O:
            if (record->event.pressed) {
                right_mod_active = true;
            } else {
                right_mod_active = false;
            }
            return true;

        default:
            if (left_mod_active && (
                keycode == KC_Q || keycode == KC_W || keycode == KC_F || keycode == KC_P || keycode == KC_B ||
                keycode == KC_A || keycode == KC_R || keycode == KC_S || keycode == KC_T || keycode == KC_G ||
                keycode == KC_Z || keycode == KC_X || keycode == KC_D || keycode == KC_C || keycode == KC_V
            )) {
                return false;
            }

            if (right_mod_active && (
                keycode == KC_J || keycode == KC_L || keycode == KC_U || keycode == KC_Y || keycode == KC_M ||
                keycode == KC_N || keycode == KC_E || keycode == KC_I || keycode == KC_O || keycode == KC_SCLN ||
                keycode == KC_K || keycode == KC_H || keycode == KC_COMM || keycode == KC_DOT || keycode == MED_SLH
            )) {
                return false;
            }

            return true;
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
                                      EDT   , ESC_NAV , JSC_TAB ,    KC_BSPC , NUM_SPC , KC_CAPS
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
      XXXXXXX ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,      KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,   ONE   ,   TWO   ,   THR   ,   FOU   ,   FIV   ,       SIX   ,   SEV   ,   EIG   ,   NIN   ,   ZER   , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_EXLM ,  KC_AT  , KC_HASH ,  KC_DLR , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_UNDS , KC_BSLS , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    CW_TOGG ,  KC_F11 ,  KC_F12 ,     _______ , _______ , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [JAVASCRIPT] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_PLUS , KC_LBRC , KC_RBRC , KC_QUOT ,  KC_DQT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,     KC_MINS , KC_LPRN , KC_RPRN ,  KC_EQL ,  KC_GT  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_UNDS , KC_LCBR , KC_RCBR , KC_PIPE ,  KC_GRV , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     _______ , _______ , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [EDITING] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , G(KC_Q) , G(KC_W) ,  SEARCH , G(KC_F) , G(KC_B) ,     XXXXXXX ,  CPRT_3 ,  CPRT_4 , XXXXXXX , QK_BOOT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , G(KC_A) , G(KC_R) , G(KC_S) , G(KC_T) , G(KC_G) ,     XXXXXXX ,   PRT_3 ,   PRT_4 ,   PRT_5 ,  KC_ENT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,   REDO  ,   UNDO  ,   CUT   ,   COPY  ,  PASTE  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     _______ , _______ , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [MEDIA] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     _______ , _______ , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),
};
