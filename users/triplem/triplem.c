#include "triplem.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
  [TD_UML_AE] = ACTION_TAP_DANCE_DOUBLE(KC_A, UML_AE),
  [TD_UML_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, UML_OE),
  [TD_UML_UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, UML_UE),
  [TD_GER_SZ] = ACTION_TAP_DANCE_DOUBLE(KC_S, GER_SZ),
  [TD_EU_EUR] = ACTION_TAP_DANCE_DOUBLE(KC_E, EU_EUR),
  [TD_T_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_RBRC),
  [TD_Y_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_LBRC)
};

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));

// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

const key_override_t *key_overrides[] = {
	&tilde_esc_override,
	&grave_esc_override
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT:
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
    }

    return true;
};

// LAyer Indicator on all keys
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            default:
                break;
        }
    }
    return false;
}
