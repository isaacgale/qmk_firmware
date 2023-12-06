/* Copyright 2023 Isaac Gale
 *
 * Based off Jwon's Keymap with tweaks to use key overrides and caps word
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

enum layer_names {
    _BASE_DVORAK,
    _NUMS_DVORAK,
    _KEYPAD,
    _QWERTY,
};

// Mac-specific macros
#define MACCOPY LGUI(KC_C)
#define MACPAST LGUI(KC_V)

#define HYP_ESC LT(_BASE_DVORAK, KC_ESC)
#define MEH_TAB MEH_T(KC_TAB)
#define KEYPAD TG(_KEYPAD)
#define QWERTY TG(_QWERTY)
#define NUMS_GUI LM(_NUMS_DVORAK, MOD_LGUI)
#define DEL_NUM LT(_KEYPAD, KC_DEL)

const key_override_t key1_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_1);
const key_override_t key2_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_2);
const key_override_t key3_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_3);
const key_override_t key4_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_4);
const key_override_t key5_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_5);
const key_override_t key6_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_6);
const key_override_t key7_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_7);
const key_override_t key8_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_8);
const key_override_t key9_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_9);
const key_override_t key0_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_0);

const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_PIPE);
const key_override_t dollar_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_DLR);
const key_override_t backslash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_HASH);
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CIRC);
const key_override_t exlm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_PERC);

// Set the overrides so shift correctly swaps symbols to numbers etc without needing a raise key
const key_override_t **key_overrides = (const key_override_t *[]){
    &key1_override,
    &key2_override,
    &key3_override,
    &key4_override,
    &key5_override,
    &key6_override,
    &key7_override,
    &key8_override,
    &key9_override,
    &key0_override,
    &pipe_key_override,
    &dollar_key_override,
    &backslash_key_override,
    &at_key_override,
    &exlm_key_override,
    NULL // Null terminate the array of overrides!
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE_DVORAK] = LAYOUT (
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, QWERTY,  QK_BOOT,
           KC_PIPE, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,           KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
           MEH_TAB, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,           KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
           HYP_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,           KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
           KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,           KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                    KC_GRV,  KC_DLR,  KC_LEFT, KC_RGHT,                  KC_UP,   KC_DOWN, KC_SLSH, KC_AT,

                    KC_LCTL, NUMS_GUI,          KC_RALT, KC_RCTL,
                             MACPAST,           KC_HOME,
           KC_BSPC, DEL_NUM, MACCOPY,           KC_END,  KC_ENT, KC_SPC
    ),


// Used for Hyper and GUI keys to swap symbols back to numbers when those keys are held down
[_NUMS_DVORAK] = LAYOUT (
           _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
           _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,                    _______, _______, _______, _______,

                    _______, _______,           _______, _______,
                             _______,           _______,
           _______, _______, _______,           _______, _______, _______
    ),

[_KEYPAD] = LAYOUT (
           _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,           _______, KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST, _______,
           _______, _______, _______, _______, _______, _______,           _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
           _______, _______, _______, _______, _______, _______,           _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
           _______, _______, _______, _______, _______, _______,           _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                    _______, _______, _______, _______,                    _______, _______, KC_PDOT, KC_PENT,

                    _______, _______,           _______, _______,
                             _______,           _______,
           _______, _______, _______,           _______, _______, KC_P0
    ),

[_QWERTY] = LAYOUT(
           KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_GRV,  KC_INS,  KC_LEFT, KC_RGHT,                 KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,

                    KC_LCTL, KC_LGUI,           KC_RALT, KC_RCTL,
                             KC_PGUP,           KC_HOME,
           KC_BSPC, KC_DEL,  KC_PGDN,           KC_END, KC_ENT,  KC_SPC
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _KEYPAD:
        writePinLow(LED_COMPOSE_PIN);
        break;
    case _NUMS_DVORAK:
        writePinLow(LED_NUM_LOCK_PIN);
        break;
    case _QWERTY:
        writePinLow(LED_SCROLL_LOCK_PIN);
        break;
    default: //  for any other layers, or the default layer
        writePinHigh(LED_NUM_LOCK_PIN);
        writePinHigh(LED_SCROLL_LOCK_PIN);
        writePinHigh(LED_COMPOSE_PIN);
        break;
    }
  return state;
}

bool led_update_user(led_t led_state) {
    // Disable led_update_kb() so that layer indication code doesn't get overridden.
    return false;
}

// Used for Hyper key with layer switch on hold and Escape on tap
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HYP_ESC:
            if (record->tap.count && record->event.pressed) {
               break;
            } else if (record->event.pressed) {
                register_mods(MOD_HYPR);
                layer_on(_NUMS_DVORAK);
                return false;
            } else {
                layer_off(_NUMS_DVORAK);
                unregister_mods(MOD_HYPR);
                break;
            }
    }
    return true;
}

// Caps Word tweaks so it can also be for entering numbers without holding shift down
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_PLUS: // Number Start Programmer Dvorak
        case KC_LBRC:
        case KC_LCBR:
        case KC_LPRN:
        case KC_AMPR:
        case KC_EQL:
        case KC_RPRN:
        case KC_RCBR:
        case KC_RBRC:
        case KC_ASTR: // Number End
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_DOT: //handy for typing numbers separated with a .
        case KC_COMM: //handy for typing numbers separated with a ,
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        writePinLow(LED_CAPS_LOCK_PIN);
    } else {
        writePinHigh(LED_CAPS_LOCK_PIN);
    }
}
