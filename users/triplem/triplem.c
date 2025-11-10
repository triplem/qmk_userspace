#include "triplem.h"

//Tap Dance Definitions
void auml_tap_dance(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code16(UML_AE);
    reset_tap_dance(state);     
  }
};

void ouml_tap_dance(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code16(UML_OE);
    reset_tap_dance(state);     
  }
};

void uuml_tap_dance(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code16(UML_UE);
    reset_tap_dance(state);     
  }
};

void ger_sz_tap_dance(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code16(GER_SZ);
    reset_tap_dance(state);     
  }
};

void eur_tap_dance(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code16(EU_EUR);
    reset_tap_dance(state);     
  }
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11]  = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
  [TD_UML_AE]  = ACTION_TAP_DANCE_FN(auml_tap_dance),
  [TD_UML_OE]  = ACTION_TAP_DANCE_FN(ouml_tap_dance),
  [TD_UML_UE]  = ACTION_TAP_DANCE_FN(uuml_tap_dance),
  [TD_GER_SZ]  = ACTION_TAP_DANCE_FN(ger_sz_tap_dance),
  [TD_EU_EUR]  = ACTION_TAP_DANCE_FN(eur_tap_dance)
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
            if (((get_mods() & MOD_MASK_SHIFT) != 0)) {
                register_code(KC_LSFT);
                tap_code(KC_GRV);
                unregister_code(KC_LSFT);
            } else if (((get_mods() & MOD_MASK_GUI) != 0)) {
                SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
            }
       }
       break;

    case MC_AGD: // show org-agenda Today view in emacs
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SPC) "oAT");
      }
      break;
      
    case MC_QUT: // evil-quit doom emacs
       if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SPC) "w" SS_LCTL("q"));
      }
    }

    return true;
};
