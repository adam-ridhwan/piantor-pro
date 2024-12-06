#include QMK_KEYBOARD_H
#include "definitions.h"

// qmk compile -kb beekeeb/piantor_pro -km adamridhwan

enum layers {
    BASE,
    NAVIGATION,
    NUMBER,
    SYMBOL,
    JAVASCRIPT,
    FUNCTION,
    TILING
};

enum apps {
    BRAVE = SAFE_RANGE,
    IDE,
    CHROME,
    SLACK,
    NOTION,
    SPOTIFY,
    BITBUCK,
    JIRA,
    CONFLUE,
    FINDER
};

void hide_other_apps(void) {
    wait_ms(100);
    register_mods(LG_LA);
    tap_code(KC_H);
    unregister_mods(LG_LA);
}

void key(uint16_t code) {
    register_mods(HYPER);
    tap_code(code);
    unregister_mods(HYPER);
    hide_other_apps();
}

void center_window(void) {
    register_mods(HYPER);
    tap_code(KC_D);
    unregister_mods(HYPER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case IDE:
                key(KC_I);
                break;

            case BRAVE:
                key(KC_B);
                break;

            case CHROME:
                key(KC_R);
                break;

            case FINDER:
                key(KC_F);
                center_window();
                break;

            case SLACK:
                key(KC_K);
                break;

            case NOTION:
                key(KC_N);
                break;

            case SPOTIFY:
                key(KC_S);
                break;

            case BITBUCK:
                key(KC_T);
                break;

            case JIRA:
                key(KC_J);
                break;

            case CONFLUE:
                key(KC_L);
                break;

            default:
                break;
        }
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------,  ,-----------------------------------------------------------,
      XXXXXXX ,   KC_Q  ,   KC_W  ,   KC_F  ,   KC_P  ,   KC_B  ,      KC_J  ,   KC_L  ,   KC_U  ,   KC_Y  , KC_SCLN , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,  SHFT_A ,  CTRL_R ,  OPTN_S ,  CMND_T ,   KC_G  ,      KC_K  ,  CMND_N ,  OPTN_E ,  CTRL_I ,  SHFT_O , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,   KC_Z  ,   KC_X  ,   KC_D  ,   KC_C  ,   KC_V  ,      KC_M  ,   KC_H  , KC_COMM ,  KC_DOT , KC_SLSH , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
                                    JSC_ESC , NAV_TAB , TIL_ENT ,    FUN_BPC , NUM_SPC , SYM_SFT
  //                              `---------+---------+---------'  '---------+---------+---------`
    ),

    [NAVIGATION] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,  ,-----------------------------------------------------------,
      XXXXXXX ,  FINDER ,  CHROME ,   IDE   ,  BRAVE  ,  SLACK  ,     NOTION , BITBUCK ,   JIRA  , CONFLUE ,  CYCLE  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,    KC_LEFT , KC_DOWN ,  KC_UP  , KC_RGHT , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
      XXXXXXX , QK_BOOT , XXXXXXX , XXXXXXX , SPOTIFY , XXXXXXX ,    KC_HOME , KC_PGDN , KC_PGUP ,  KC_END , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'  '---------+---------+---------`
    ),

    [NUMBER] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX ,   KC_7  ,   KC_8  ,   KC_9  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_CAPS ,   KC_4  ,   KC_5  ,   KC_6  , XXXXXXX ,     XXXXXXX , KC_RGUI , KC_ROPT , KC_RCTL , KC_RSFT , XXXXXXX ,
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
                                    KC_QUOT ,  KC_DQT , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [JAVASCRIPT] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LOPT , KC_LCMD , XXXXXXX ,     XXXXXXX , KC_LPRN , KC_RPRN , KC_EQUAL,  KC_GT  , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX ,   UNDO  ,   REDO  ,   COPY  ,  PASTE  ,     XXXXXXX , KC_LCBR , KC_RCBR , KC_LBRC , KC_RBRC , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

    [FUNCTION] = LAYOUT_split_3x6_3(
  //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
      XXXXXXX ,  KC_F12 ,  KC_F7  ,  KC_F8  ,  KC_F9  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,  KC_F11 ,  KC_F4  ,  KC_F5  ,  KC_F6  , XXXXXXX ,     XXXXXXX , KC_RGUI , KC_ROPT , KC_RCTL , KC_RSFT , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
      XXXXXXX ,  KC_F10 ,  KC_F1  ,  KC_F2  ,  KC_F3  , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
  //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
                                    XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
  //                              `---------+---------+---------'   '---------+---------+---------`
    ),

//     [TILING] = LAYOUT_split_3x6_3(
//   //,---------+-------------------------------------------------,   ,-----------------------------------------------------------,
//       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//   //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
//       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//   //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
//       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
//   //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
//                                     XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
//   //                              `---------+---------+---------'   '---------+---------+---------`
//     )
};
