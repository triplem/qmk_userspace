#pragma once

// Home-Row Modifier
#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)

#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_SCLN RGUI_T(KC_SEMICOLON)

// Shortcuts
#define SC_CAD	LALT(LCTL(KC_DEL))


enum layers {
    _QWERTY,
    _FUNCTION,
    _CODING
};
