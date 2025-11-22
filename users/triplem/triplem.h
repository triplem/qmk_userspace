#pragma once

#include "quantum.h"

// Home-Row Modifier
#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define LT_G LT(_SYMB, KC_G)

#define LT_H LT(_SYMB, KC_H)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_SCLN RGUI_T(KC_SEMICOLON)

// Keycodes for umlauts and eszett
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)

// Shortcuts
#define SC_CAD LALT(LCTL(KC_DEL)) // alt-ctrl-del - reset

// Layers
enum layers { _QWERTY, _FUNCTION, _CODING, _SYMB };

// Tap Dance Declarations
enum {
  TD_F1_F11 = 0,
  TD_F2_F12,
  TD_ESC_GRV
};

// Custom Keycodes to avoid dead-keys
// MC_AGD = Macro for Emacs org-agenda (Space o A T)
// MC_QUT = Macro to quit doom emacs
enum custom_keycodes {
  MC_QUOT = SAFE_RANGE,
  MC_AGD,
  MC_QUT,
  MC_TLD_ESC,
  MC_GRV_ESC
};
