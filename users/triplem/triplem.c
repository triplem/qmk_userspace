#include "triplem.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT: // ' on US Intl leyout to avoid deadkeys
       if (record->event.pressed) {
           SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
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
      break;

    case MC_TLD_ESC: // Shift + esc = ~, ESC otherwise
        if (record->event.pressed) {
            uint8_t temp_mods = get_mods();

            // Shift + esc = ~
            if ((temp_mods & MOD_MASK_SHIFT) != 0) {
                clear_mods();
                register_code(KC_LSFT);
                tap_code(KC_GRV);
                tap_code(KC_SPC);
                unregister_code(KC_LSFT);
                set_mods(temp_mods);
                return false;
            // ESC
            } else {
                tap_code(KC_ESC);
            }
        }
        break;

    case MC_GRV_ESC: // ` on US Intl layout to avoid deadkeys
        if (record->event.pressed) {
            tap_code(KC_GRV);
            tap_code(KC_SPC);
        }
        break;
    }

    return true;
};
