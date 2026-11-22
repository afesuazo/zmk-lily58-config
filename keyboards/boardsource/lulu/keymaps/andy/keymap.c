#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "oled_images.h"

// Shared layout: the wireless Lily58 uses the same layers in config/blelulu.keymap (ZMK).
// Change both files together.

enum layers {
    _BASE,
    _SYMBOLS,
    _NUMBERS,
    _NAV,
    _SETTING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (Mac default, GUI/CTRL auto-swapped on Windows/Linux)
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |      `      |      1      |      2      |      3      |      4      |      5      |                              |      6      |      7      |      8      |      9      |      0      |      -      |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |     Tab     |      Q      |      W      |      E      |      R      |      T      |                              |      Y      |      U      |      I      |      O      |      P      |      \      |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |     Esc     |      A      |      S      |      D      |      F      |      G      |-------------.  .-------------|      H      |      J      |      K      |      L      |      ;      |      '      |
 * |-------------+-------------+-------------+-------------+-------------+-------------|   Reboot     |  |   SETTING  |-------------+-------------+-------------+-------------+-------------+-------------|
 * |    Shift    |      Z      |      X      |      C      |      V      |      B      |-------------|  |-------------|      N      |      M      |      ,      |      .      |      /      |    Ctrl     |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |    Boot     |     GUI     |   SH/BSP    |   NAV/Del   |  |   SYM/Ent   |  SH/Space   |   NUM/Ent   |    Ctrl     |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 */
[_BASE] = LAYOUT(
    KC_GRV,                  KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                                                                      KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    KC_MINS,
    KC_TAB,                  KC_Q,                    KC_W,                    KC_E,                    KC_R,                    KC_T,                                                                      KC_Y,                    KC_U,                    KC_I,                    KC_O,                    KC_P,                    KC_BSLS,
    KC_ESC,                  KC_A,                    KC_S,                    KC_D,                    KC_F,                    KC_G,                                                                      KC_H,                    KC_J,                    KC_K,                    KC_L,                    KC_SCLN,                 KC_QUOT,
    KC_LSFT,                 KC_Z,                    KC_X,                    KC_C,                    KC_V,                    KC_B,                    QK_REBOOT,               MO(_SETTING),            KC_N,                    KC_M,                    KC_COMM,                 KC_DOT,                  KC_SLSH,                 KC_LCTL,
                                                                               QK_BOOT,                 KC_LGUI,                 MT(MOD_LSFT, KC_BSPC),   LT(_NAV, KC_DEL),        LT(_SYMBOLS, KC_ENT),    MT(MOD_RSFT, KC_SPC),    LT(_NUMBERS, KC_ENT),    KC_LCTL
),

/* SYMBOLS
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |             |             |             |             |             |             |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |      (      |      )      |      +      |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |      {      |      }      |      -      |-------------.  .-------------|      =      |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|             |  |             |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |      [      |      ]      |      *      |-------------|  |-------------|             |             |             |             |             |             |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |             |             |             |             |  |             |             |             |             |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 */
[_SYMBOLS] = LAYOUT(
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_LPRN,                 KC_RPRN,                 KC_PLUS,                                                                   KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_LCBR,                 KC_RCBR,                 KC_MINS,                                                                   KC_EQL,                  KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_LBRC,                 KC_RBRC,                 KC_ASTR,                 KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
                                                                               KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT
),

/* NUMBERS
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |             |             |             |             |             |             |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |     F1      |     F2      |     F3      |     F4      |     F5      |                              |     F6      |     F7      |     F8      |     F9      |     F10     |     F11     |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |      1      |      2      |      3      |      4      |      5      |-------------.  .-------------|      6      |      7      |      8      |      9      |      0      |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|             |  |             |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |-------------|  |-------------|             |             |             |             |             |             |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |             |             |             |             |  |             |             |             |             |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 */
[_NUMBERS] = LAYOUT(
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_F1,                   KC_F2,                   KC_F3,                   KC_F4,                   KC_F5,                                                                     KC_F6,                   KC_F7,                   KC_F8,                   KC_F9,                   KC_F10,                  KC_F11,
    KC_TRANSPARENT,          KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                                                                      KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
                                                                               KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT
),

/* NAV (Navigation + Mouse)
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |             |             |             |             |             |             |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |                              |    LClk     |    Ms Lt    |    Ms Dn    |    Ms Up    |    Ms Rt    |    RClk     |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |-------------.  .-------------|    Left     |    Down     |     Up      |    Right    |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|             |  |             |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |-------------|  |-------------|    Home     |    PgDn     |    PgUp     |     End     |             |             |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |             |             |             |             |  |             |             |             |             |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 */
[_NAV] = LAYOUT(
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            MS_BTN1,                 MS_LEFT,                 MS_DOWN,                 MS_UP,                   MS_RGHT,                 MS_BTN2,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_LEFT,                 KC_DOWN,                 KC_UP,                   KC_RGHT,                 KC_TRANSPARENT,          KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_HOME,                 KC_PGDN,                 KC_PGUP,                 KC_END,                  KC_TRANSPARENT,          KC_TRANSPARENT,
                                                                               KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT
),

/* SETTING
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |             |    (BT1)    |    (BT2)    |             |             |             |                              |             |             |             |     XX      |     XX      |   RGB TG    |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |  (Studio)   |  (BT clr)   |             |             |             |             |                              |             |             |             |    BRI-     |    BRI+     |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |    Reset    |             |             |             |             |             |-------------.  .-------------|             |             |             |    HUE-     |    HUE+     |    Reset    |
 * |-------------+-------------+-------------+-------------+-------------+-------------|   Win/Mac   |  |   (held)    |-------------+-------------+-------------+-------------+-------------+-------------|
 * |    Boot     |             |             |             |             |             |-------------|  |-------------|             |             |             |             |             |    Boot     |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |             |             |             |             |  |             |             |             |             |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 * (BT1) (BT2) (Studio) (BT clr): wireless board only, so KC_NO here.
 * Win/Mac (CG_TOGG): manual Ctrl/GUI swap, on top of the automatic OS detection below.
 */
[_SETTING] = LAYOUT(
    KC_TRANSPARENT,          KC_NO,                   KC_NO,                   KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_NO,                   KC_NO,                   RM_TOGG,
    KC_NO,                   KC_NO,                   KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          RM_VALD,                 RM_VALU,                 KC_TRANSPARENT,
    QK_RBT,                  KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          RM_HUED,                 RM_HUEU,                 QK_RBT,
    QK_BOOT,                 KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          CG_TOGG,                 KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          QK_BOOT,
                                                                               KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT
)
};

/* BLANK TEMPLATE (copy-paste for new layers)
 * ,-------------+-------------+-------------+-------------+-------------+-------------.                              ,-------------+-------------+-------------+-------------+-------------+-------------.
 * |             |             |             |             |             |             |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |                              |             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|                              |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |-------------.  .-------------|             |             |             |             |             |             |
 * |-------------+-------------+-------------+-------------+-------------+-------------|             |  |             |-------------+-------------+-------------+-------------+-------------+-------------|
 * |             |             |             |             |             |             |-------------|  |-------------|             |             |             |             |             |             |
 * `-------------+-------------+-------------+-------------+-------------+-------------'             |  |             `-------------+-------------+-------------+-------------+-------------+-------------'
 *                                           |             |             |             |             |  |             |             |             |             |
 *                                           `-------------+-------------+-------------+-------------'  `-------------+-------------+-------------+-------------'
 *
 * [_LAYER] = LAYOUT(
 *     KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
 *     KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
 *     KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,                                                            KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
 *     KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,
 *                                                                                KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT,          KC_TRANSPARENT
 * ),
 */

// Encoder: volume control on all layers
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOLS]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMBERS]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SETTING]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

// OS Detection: auto-swap GUI/CTRL on Windows and Linux
bool process_detected_host_os_user(os_variant_t detected_os) {
    keymap_config.swap_lctl_lgui = (detected_os == OS_WINDOWS || detected_os == OS_LINUX);
    return true;
}

// OLED display
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // physically mounted upside-down
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side: show current layer as pixel art
        switch (get_highest_layer(layer_state)) {
            case _BASE:     oled_write_raw_P(base_img,    sizeof(base_img));    break;
            case _SYMBOLS:  oled_write_raw_P(symbols_img, sizeof(symbols_img)); break;
            case _NUMBERS:  oled_write_raw_P(numbers_img, sizeof(numbers_img)); break;
            case _NAV:      oled_write_raw_P(nav_img,     sizeof(nav_img));     break;
            case _SETTING:  oled_write_raw_P(setting_img, sizeof(setting_img)); break;
        }
    } else {
        // Right side: custom art
        oled_write_raw_P(logo_img, sizeof(logo_img));
    }
    return false;
}
#endif

static void set_key_led(uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t idx = g_led_config.matrix_co[row][col];
    if (idx != NO_LED) {
        rgb_matrix_set_color(idx, r, g, b);
    }
}

// RGB indicator: color innermost thumb keys by detected OS
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    os_variant_t os = detected_host_os();

    // macOS/iOS: do NOT override anything
    if (os == OS_MACOS || os == OS_IOS) {
        return true;
    }

    uint8_t r, g, b;
    switch (os) {
        case OS_MACOS:
        case OS_IOS:
            r = 0; g = 128; b = 255;   // Blue
            break;
        case OS_LINUX:
        case OS_WINDOWS:
            r = 0; g = 200; b = 255;   // Cyan
            break;
        default:
            r = 255; g = 50; b = 50;    // Red
            break;
    }

    set_key_led(4, 5, r, g, b);
    set_key_led(9, 5, r, g, b);
    return false;
}
