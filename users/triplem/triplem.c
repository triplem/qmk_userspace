#include "quantum.h"
#include "triplem.h"

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_F1_F11]  = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
  [TD_F2_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12)
};

// Types "+p - paste from system clipboard
// Types "+y - yank/ copy to system clipboard
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case SC_VIM_PASTE:  
      if (record->event.pressed) {
        SEND_STRING("\"+p");
      }
      return false;

    case SC_VIM_YANK:  
      if (record->event.pressed) {
        SEND_STRING("\"+y");
      }
      return false;
  }
  return true;
}
