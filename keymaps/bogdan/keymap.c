#include QMK_KEYBOARD_H

enum custom_keycodes {
    M_CTRL_SHIFT_V = SAFE_RANGE,
    M_HIGLIGHT_ALL,
    M_COPY_WORD,
    M_W_SHIFT_S, // Print screen
    M_SEND_COMMA,
    M_DOPLICATE_PAGE,
    M_COPY_PAGE_URL,
    M_GO_TO_LINE, // Перейти к строке
    М_FIND_ALL, // Найти все
};

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_FUN,
    LAYER_SYM,
    LAYER_MEDIA,
    LAYER_POINTER,
};

// Layers
#define LOWER MO(LAYER_LOWER)
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define FUN MO(LAYER_FUN)
#define MEDIA MO(LAYER_MEDIA)

// Ctrl-Tab
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)

// Short
#define SC_NWIN LCTL(KC_N)
#define SC_NTAB LCTL(KC_T)
#define DPI_UP POINTER_DEFAULT_DPI_FORWARD
#define DPI_DOWN POINTER_DEFAULT_DPI_REVERSE
#define SCROLL DRAGSCROLL_MODE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────╮
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,          KC_Y,  KC_U,    KC_I,  KC_O,   KC_P,     KC_LBRC,
  // ├───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,  KC_J,    KC_K,  KC_L,  KC_SCLN,   KC_QUOT,
  // ├───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       SC_LCPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,  KC_M, KC_COMM,  KC_DOT, ALT_T(KC_SLSH), KC_RBRC,
  // ╰───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────╯
              LWIN_T(KC_BSPC),  LT(LAYER_SYM, KC_SPC), MO(LOWER),     LT(RAISE, KC_TAB),  LT(FUN, KC_ENT)
  //         ╰───────────────────────────────────────────────────╯ ╰─────────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭───────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       DPI_DOWN,  DPI_UP, XXXXXXX, XXXXXXX,  QK_BOOT, EE_CLR,      XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS, KC_LALT,  KC_LCTL, KC_LSFT, KC_TAB, XXXXXXX,        KC_EQL, KC_4, KC_5, KC_6, KC_MINS, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRG_TOG, KC_BTN1, KC_BTN2, KC_BTN3, SNIPING, XXXXXXX,       KC_0, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX,
  // ╰───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_ENT
  //                             ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, A(S(KC_T)), A(KC_TAB), XXXXXXX, XXXXXXX,    C(S(KC_T)), XXXXXXX, S(KC_B), M_COPY_PAGE_URL, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
       KC_TAB, KC_LEFT,   KC_DOWN, KC_UP, KC_RGHT, XXXXXXX,     M_DOPLICATE_PAGE, KC_TAB, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
       KC_LCTL, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, KC_LWIN,  RCS_TAB, CTL_TAB, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                                  _______, MEDIA, FUN,          _______, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUN] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────╮
       XXXXXXX, KC_DEL, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F12, XXXXXXX,
  // ├─────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       XXXXXXX, C(KC_C), C(KC_V), C(KC_X), C(KC_A), М_FIND_ALL,    XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, XXXXXXX,
  // ├─────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       KC_LALT, A(KC_F4), C(KC_Z), C(S(KC_Z)),  C(S(KC_Z)),        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F10, XXXXXXX,
  // ╰─────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────╯
                                     XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BSPC
  //                               ╰───────────────────────────╯ ╰──────────────────╯
  ),
  
  [LAYER_SYM] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────╮
       XXXXXXX, KC_HASH, KC_AMPERSAND, KC_DOLLAR, KC_LBRC, KC_ASTERISK,    KC_QUOT, KC_RBRC, KC_AT, KC_CIRC, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       XXXXXXX, KC_TILD, KC_QUESTION, KC_EXCLAIM, KC_LPRN, KC_MINS,        KC_GRV, KC_RPRN, KC_COLN, KC_SCLN, KC_GT, KC_EQL,
  // ├─────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────┤
       KC_UNDS, KC_SLSH, KC_PIPE, KC_BSLS, KC_LCBR, KC_PLUS,               KC_DQUO, KC_RCBR, KC_DOT, KC_COMM, KC_LT, KC_PERCENT,
  // ╰─────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────╯
                                             XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, LT(LAYER_LOWER, KC_SPC)
  //                                        ╰──────────────────────────╯ ╰─────────────────────────╯
  ),

  [LAYER_MEDIA] = LAYOUT(
  // ╭───────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,     XXXXXXX, KC_WSCH, KC_WHOM, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_WBAK, XXXXXXX, KC_WFWD, XXXXXXX,
  // ╰───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
  //                             ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_S, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,       S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                        TG(0), TG(1), TG(2),    TG(3), TG(0)
  //                                  ╰─────────────────────╯ ╰─────────────╯
  ),
};

//////////////// CUSTOM ///////////////

// COMBOS

enum combo_events {
  SWITCH_LANG,
};

const uint16_t PROGMEM CB_PASTE_WITHOUT_FROMATTING[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM CB_CAPS_WORD[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM CB_DASH[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM CB_SWITCH_LANG[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(CB_PASTE_WITHOUT_FROMATTING, M_CTRL_SHIFT_V),
    COMBO(CB_CAPS_WORD, CW_TOGG),
    COMBO(CB_DASH, KC_MINS),
    [SWITCH_LANG] = COMBO_ACTION(CB_SWITCH_LANG),
};

bool is_en_layout = true;

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case SWITCH_LANG:
            if (pressed && is_en_layout) {
                tap_code16(KC_F13);
                is_en_layout = false;
            } else if (pressed) {
                tap_code16(KC_F14);
                is_en_layout = true;
            }
            break;
    }
}

// MACROS

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_CTRL_SHIFT_V:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_V);
            } else {
                unregister_code(KC_V);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;
        case M_GO_TO_LINE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_G);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_G);
            }
            break;
        case M_W_SHIFT_S:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_LSFT);
                register_code(KC_S);   
            } else {
                unregister_code(KC_LWIN);
                unregister_code(KC_LSFT);
                unregister_code(KC_S);
            }
            break;
        case M_COPY_WORD: 
            if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code(KC_BTN1);
                tap_code16(C(KC_C));
            }
            break;
        case M_DOPLICATE_PAGE:
            if (record->event.pressed) {
                tap_code16(A(KC_D));
                tap_code16(A(KC_ENT));
            }
            break;  
        case M_COPY_PAGE_URL:
            if (record->event.pressed) {
                tap_code16(A(KC_D));
                tap_code16(C(KC_C));
                tap_code(KC_ESC);
            }
            break;
        case М_FIND_ALL:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_F);   
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
    }
    return true;
}

///////////////////////// CHARYBDIS SETTINGS ///////////////////////////

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));

    // Переключение раскладке на EN при переходе на слой SYM и возврат на RU, когда слой SYM отключается
    if (get_highest_layer(state) == LAYER_SYM) {
        if (!is_en_layout) {
            tap_code(KC_F14);
        }
    } else {
        if (!is_en_layout) {
            tap_code(KC_F13);
        }
    }
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
