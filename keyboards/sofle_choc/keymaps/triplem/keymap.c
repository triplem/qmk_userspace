/* Copyright 2024 Markus M. May
 * Copyright 2023 Brian Low
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

#include "triplem.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                   ,-----------------------------------------.
     * | ESC/'|   1  |   2  |   3  |   4  |   5  |                   |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
     * |LShift|A GUI |   S  |D CTL |F SFT |G MO2 |------.    ,-------|H MO1 |J SFT |K CTL |L ALT |; GUI |  '   |
     * |------+------+------+------+------+------| HOME |    |  MUTE |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/      /     \      \-----------------------------------------'
     *            | LCTL | LGUI | LALT | MO(1)| /Enter /       \Space \  | MO(2)|  DEL | RALT | RCTL |
     *            |      |      |      |      |/      /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                       KC_TAB, KC_Q, KC_W, TD(TD_EU_EUR), KC_R, TD(TD_T_LBRC), TD(TD_Y_RBRC), TD(TD_UML_UE), KC_I, TD(TD_UML_OE), KC_P, KC_MINUS,
                       KC_LSFT, TD(TD_UML_AE), TD(TD_GER_SZ), MOD_D, MOD_F, LT_G, LT_H, MOD_J, MOD_K, MOD_L, MOD_SCLN, MC_QUOT,
                       KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_ENT, KC_SPC, MO(2), KC_DEL, KC_RALT, KC_RCTL),

    /*
     * FUNCTION
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ---  |F1/F11|F2/F12|  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RGB T | ---  | ---  | ---  | ---  |   [  |                    |   ]  | ---  | ---  | F11  | F12  |  |   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RGB ->| ---  | ---  | ---  | ---  | ---  |-------.    ,-------| LFT  | DOWN |  UP  | RGHT |  \   | ---  |
     * |------+------+------+------+------+------| ---   |    | ---   |------+------+------+------+------+------|
     * |RGB <-| ---  | ---  | ---  | ---  | ---  |-------|    |-------| HOME | PgDwn| PgUp | END  | ---  | CAD  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | ---  | ---  | ---  | ---  | / ---   /       \ ---  \  | ---  | INS  | ---  | ---  |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_FUNCTION] = LAYOUT(_______, TD(TD_F1_F11), TD(TD_F2_F12), KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_EQUAL,
                         RM_TOGG, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_F11, KC_F12, KC_PIPE,
                         RM_NEXT, MC_AGD, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSLS, _______,
                         RM_PREV, _______, MC_QUT, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, SC_CAD,
                         _______, _______, _______, _______, _______, _______, _______, KC_INS, _______, _______),

    /*
     * CODING - mainly IntelliJ stuff
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ---  | A-F1 | ---  | ---  | ---  | ---  |                    | C-F6 |  C-/ | ---  | ---  | ---  | ---  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ---  | ---  | ---  | ---  | ---  | ---  |                    |  --- | UML_UE | ---  | UML_OE | --- | ---  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ---  | UML_AE | GER_SZ | ---  | ---  | ---  |-------.    ,-------|  --- |  --- | ---  | ---  | ---  | ---  |
     * |------+------+------+------+------+------| ---   |    | ---   |------+------+------+------+------+------|
     * | ---  | ---  | C-X  | C-C  | C-V  | ---  |-------|    |-------|  --- |  --- | ---  | ---  | ---  | ---  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | ---  | ---  | ---  | ---  | / ---   /       \ ---  \  | ---  | ---  | ---  | ---  |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_CODING] = LAYOUT(_______, A(KC_F1), _______, _______, _______, _______, C(KC_F6), C(KC_PSLS), _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______, _______, UML_UE, _______, UML_OE, _______, _______,
                       _______,  UML_AE, GER_SZ, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]   = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_FUNCTION] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_CODING]   = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};
#endif
