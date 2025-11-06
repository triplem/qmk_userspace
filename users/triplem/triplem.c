#include "triplem.h"

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11]  = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
  [TD_UML_AE]  = ACTION_TAP_DANCE_DOUBLE(KC_A, UML_AE),
  [TD_UML_OE]  = ACTION_TAP_DANCE_DOUBLE(KC_O, UML_OE),
  [TD_UML_UE]  = ACTION_TAP_DANCE_DOUBLE(KC_U, UML_UE),
  [TD_SS]      = ACTION_TAP_DANCE_DOUBLE(KC_S, GER_SZ),
  [TD_EU_EUR]  = ACTION_TAP_DANCE_DOUBLE(KC_E, EU_EUR)
};

// Shift + esc = ~
// GUI + esc = `


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
        }
        break;

    case MC_GRV:
        if (record->event.pressed && ((get_mods() & MOD_MASK_SHIFT) != 0)) {
            register_code(KC_LSFT);
            tap_code(KC_GRV);
            unregister_code(KC_LSFT);
        } else if (record->event.pressed && ((get_mods() & MOD_MASK_GUI) != 0)) {
            SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
        }
        break;
    }
    return true;
};