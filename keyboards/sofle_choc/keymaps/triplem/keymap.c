/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum tap_dances {
    TD_UML_A,
    TD_UML_O,
    TD_UML_U,
    TD_UML_S
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_UML_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, US_ADIA),
    [TD_UML_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, US_ODIA),
    [TD_UML_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, US_UDIA),
    [TD_UML_S] = ACTION_TAP_DANCE_DOUBLE(KC_S, US_SS),
};

enum layers {
    _QWERTY,
    _FUNCTION,
    _CODING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                   ,-----------------------------------------.
 * | ESC/'|   1  |   2  |   3  |   4  |   5  |                   |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| HOME |    |  MUTE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/      /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT | MO(1)| /Enter /       \Space \  | MO(2)|  DEL | MO(3)| RCTL |
 *            |      |      |      |      |/      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
    QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_MINUS,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_HOME,  KC_MUTE, KC_N,     KC_M,  KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT,
                KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_ENT,             KC_SPC, MO(2),  KC_DEL,  MO(3),    KC_RCTL
),

/*
 * FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ---  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | HOME |   [  |                    |   ]  |  END | ---  | F11  | F12  | ---  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | ---  | ---  |-------.    ,-------| LFT  | DOWN |  UP  | RGHT |  \   | ---  |
 * |------+------+------+------+------+------| ---   |    | ---   |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | ---  | ---  |-------|    |-------| ---  | ---  | ---  | ---  | ---  | ---  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | ---  | ---  | ---  | ---  | / ---   /       \ ---  \  | ---  | INS  | ---  | ---  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
 [_FUNCTION] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQUAL,
    _______, _______, _______, _______, KC_HOME, KC_LBRC,                       KC_RBRC, KC_END,  _______, KC_F11,  KC_F12,  _______,
    _______, _______, _______, _______, _______, _______,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,              _______, _______,  KC_INS, _______, _______
),

/*
 * CODING - mainly IntelliJ stuff
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ---  | A-F1 | ---  | ---  | ---  | ---  |                    | C-F6 |  C-/ | ---  | ---  | ---  | ---  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | ---  | ---  |                    |  --- |  --- | ---  | ---  | ---  | ---  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | ---  | ---  |-------.    ,-------|  --- |  --- | ---  | ---  | ---  | ---  |
 * |------+------+------+------+------+------| ---   |    | ---   |------+------+------+------+------+------|
 * | ---  | ---  | ---  | ---  | ---  | ---  |-------|    |-------|  --- |  --- | ---  | ---  | ---  | ---  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | ---  | ---  | ---  | ---  | / ---   /       \ ---  \  | ---  | ---  | ---  | ---  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_CODING] = LAYOUT(
    _______, A(KC_F1), _______, _______, _______, _______,                       C(KC_F6), C(KC_PSLS), _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______,                       _______,  _______,    _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______,                       _______,  _______,    _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_FUNCTION] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_CODING] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
};
#endif
