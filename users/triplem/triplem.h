#pragma once

// Home-Row Modifier
#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define LT_G LT(_FUNCTION, KC_G)

#define LT_H LT(_CODING, KC_H)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_SCLN RGUI_T(KC_SEMICOLON)

// Shortcuts
#define SC_CAD	LALT(LCTL(KC_DEL)) // alt-ctrl-del - reset

// Layers
enum layers {
  _QWERTY,
  _FUNCTION,
  _CODING
};

//Tap Dance Declarations
enum {
  TD_F1_F11 = 0,
  TD_F2_F12
};

