#include "quantum.h"
#include "triplem.h"

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11]  = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
        }
        break;
    case MC_GRV:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
        }
        break;
    }
    return true;
};