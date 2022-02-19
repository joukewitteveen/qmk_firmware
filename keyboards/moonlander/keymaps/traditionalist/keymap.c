#include QMK_KEYBOARD_H
#include "version.h"
#include "okcolors.h"

enum layers {
    BASE,   // default layer
    NUMPAD, // numpad layer
};

// tap dance codes
enum {
    TH_1_F1,
    TH_2_F2,
    TH_3_F3,
    TH_4_F4,
    TH_5_F5,
    TH_6_F6,
    TH_7_F7,
    TH_8_F8,
    TH_9_F9,
    TH_0_F10,
    TH_MINS_F11,
    TH_EQL_F12,
    TH_APP_PSCR,
};

// clang-format off
#define TAP_DANCE_TAP_HOLD     TD(TH_1_F1)
#define TAP_DANCE_TAP_HOLD_MAX TD(TH_APP_PSCR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_GRAVE,     TD(TH_1_F1),  TD(TH_2_F2),  TD(TH_3_F3),  TD(TH_4_F4),  TD(TH_5_F5),  TD(TH_MINS_F11),                TD(TH_EQL_F12),TD(TH_6_F6), TD(TH_7_F7),  TD(TH_8_F8),  TD(TH_9_F9),  TD(TH_0_F10), KC_DELETE,
    KC_RBRC,      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         TD(TH_APP_PSCR),                TG(1),        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_LBRC,
    KC_BACKSLASH, KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_LGUI,                        KC_RGUI,      KC_H,         KC_J,         KC_K,         KC_L,         KC_SEMICOLON, KC_QUOTE,
    KC_LEFT_SHIFT,KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                                       KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RIGHT_SHIFT,
    KC_LEFT_CTRL, KC_HOME,      KC_PAGE_UP,   KC_PAGE_DOWN, KC_END,                     KC_ESCAPE,                      KC_TAB,                     KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,     KC_RIGHT_CTRL,
                                                            KC_SPACE,     KC_BACKSPACE, KC_LEFT_ALT,                    KC_RIGHT_ALT, KC_ENTER,     KC_SPACE
  ),
  [NUMPAD] = LAYOUT_moonlander(
    KC_ESCAPE,    KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F11,                         KC_F12,       KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       _______,
    _______,      KC_MS_BTN1,   KC_MS_UP,     KC_MS_BTN2,   KC_MS_BTN3,   MAGIC_TOGGLE_NKRO,QK_BOOT,                    _______,      KC_KP_SLASH,  KC_KP_7,      KC_KP_8,      KC_KP_9,      KC_KP_MINUS,  _______,
    _______,      KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,  RGB_MOD,      TOGGLE_LAYER_COLOR,AU_TOG,                    KC_NUM_LOCK,  KC_KP_ASTERISK,KC_KP_4,     KC_KP_5,      KC_KP_6,      KC_KP_PLUS,   _______,
    _______,      RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_SPI,      RGB_TOG,                                                    KC_KP_EQUAL,  KC_KP_1,      KC_KP_2,      KC_KP_3,      KC_UP,        KC_CAPS_LOCK,
    _______,      RGB_HUD,      RGB_SAD,      RGB_VAD,      RGB_SPD,                    MU_TOG,                         _______,                    KC_KP_0,      KC_KP_DOT,    KC_LEFT,      KC_DOWN,      KC_RIGHT,
                                                            MU_MOD,       _______,      _______,                        KC_LGUI,      KC_KP_ENTER,  _______
  ),
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [BASE] = LED_LAYOUT_moonlander(
    {HSV_OFF},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {HSV_OFF},                      {HSV_OFF},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_DARK},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {OK_YELLOW},                    {OK_LIGHT},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {OK_BASE1},   {HSV_OFF},    {OK_RED},                       {OK_RED},     {HSV_OFF},    {OK_BASE1},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {OK_RED},     {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},                                                  {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {OK_RED},
    {OK_RED},     {OK_DARK},    {OK_DARK},    {OK_DARK},    {OK_DARK},                  {OK_DARK},                      {HSV_OFF},                  {OK_DARK},    {OK_DARK},    {OK_DARK},    {OK_DARK},    {OK_RED},
                                                            {HSV_OFF},    {OK_DARK},    {OK_RED},                       {OK_RED},     {HSV_OFF},    {HSV_OFF}
  ),
  [NUMPAD] = LED_LAYOUT_moonlander(
    {OK_LIGHT},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},                      {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {OK_LIGHT},
    {HSV_OFF},    {OK_CYAN},    {OK_CYAN},    {OK_CYAN},    {OK_CYAN},    {HSV_OFF},    {OK_MAGENTA},                   {OK_LIGHT},   {OK_BASE0},   {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BASE0},   {HSV_OFF},
    {HSV_OFF},    {OK_CYAN},    {OK_CYAN},    {OK_CYAN},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},                      {OK_YELLOW},  {OK_BASE0},   {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_BASE0},   {HSV_OFF},
    {OK_RED},     {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},                                                  {OK_BASE0},   {OK_BLUE},    {OK_BLUE},    {OK_BLUE},    {OK_GREEN},   {OK_YELLOW},
    {OK_RED},     {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},                  {HSV_OFF},                      {HSV_OFF},                  {OK_BLUE},    {OK_BASE0},   {OK_GREEN},   {OK_GREEN},   {OK_GREEN},
                                                            {HSV_OFF},    {OK_DARK},    {OK_RED},                       {OK_RED},     {HSV_OFF},    {HSV_OFF}
  ),
};

#if defined(AUDIO_ENABLE) && defined(MUSIC_MAP)
const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_moonlander(
    48, 49, 50, 51, 52, 53, 53,    54, 54, 55, 56, 57, 58, 59,
    36, 37, 38, 39, 40, 41, 41,    42, 42, 43, 44, 45, 46, 47,
    24, 25, 26, 27, 28, 29, 29,    30, 30, 31, 32, 33, 34, 35,
    12, 13, 14, 15, 16, 17,            18, 19, 20, 21, 22, 23,
     0,  1,  2,  3,  4,      5,     6,      7,  8,  9, 10, 11,
                     5,  5,  5,     6,  6,  6
);
#endif
// clang-format on

// board sides with indicator LEDs
enum {
    INDICATORS_LEFT,
    INDICATORS_RIGHT,
};

static uint8_t led_override[] = {
    [INDICATORS_LEFT]  = 0,
    [INDICATORS_RIGHT] = 0,
};

void led_update_ports(led_t led_state) {
    bool override;
    bool led_1 = led_state.num_lock;
    bool led_2 = led_state.caps_lock;
    bool led_3 = led_state.scroll_lock;
    led_3 |= layer_state != default_layer_state;

    override = (bool)led_override[INDICATORS_LEFT];
    ML_LED_1(override || led_1);
    ML_LED_2(override || led_2);
    ML_LED_3(override || led_3);
    override = (bool)led_override[INDICATORS_RIGHT];
    ML_LED_4(override || led_1);
    ML_LED_5(override || led_2);
    ML_LED_6(override || led_3);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    led_update_ports(host_keyboard_led_state());
    return state;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            hsv.s   = rgb_matrix_get_sat() * hsv.s / UINT8_MAX;
            hsv.v   = rgb_matrix_get_val() * hsv.v / UINT8_MAX;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (!keyboard_config.disable_layer_led) {
        set_layer_color(get_highest_layer(layer_state));
        return false;
    }
    return true;
}

typedef struct {
    uint8_t tap;
    uint8_t hold;
    bool    side;
    uint8_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    qk_tap_dance_action_t *action;

    switch (keycode) {
        case TAP_DANCE_TAP_HOLD ... TAP_DANCE_TAP_HOLD_MAX:
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code(tap_hold->hold);
            tap_hold->held = tap_hold->hold;

            ++led_override[tap_hold->side];
            led_update_kb(host_keyboard_led_state());
        } else {
            register_code(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        if (tap_hold->held == tap_hold->hold) {
            --led_override[tap_hold->side];
            led_update_kb(host_keyboard_led_state());
        }
        unregister_code(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold, side) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, side, 0}), }

// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TH_1_F1]     = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_F1, INDICATORS_LEFT),
    [TH_2_F2]     = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_F2, INDICATORS_LEFT),
    [TH_3_F3]     = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_F3, INDICATORS_LEFT),
    [TH_4_F4]     = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_F4, INDICATORS_LEFT),
    [TH_5_F5]     = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5, INDICATORS_LEFT),
    [TH_6_F6]     = ACTION_TAP_DANCE_TAP_HOLD(KC_6, KC_F6, INDICATORS_RIGHT),
    [TH_7_F7]     = ACTION_TAP_DANCE_TAP_HOLD(KC_7, KC_F7, INDICATORS_RIGHT),
    [TH_8_F8]     = ACTION_TAP_DANCE_TAP_HOLD(KC_8, KC_F8, INDICATORS_RIGHT),
    [TH_9_F9]     = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_F9, INDICATORS_RIGHT),
    [TH_0_F10]    = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_F10, INDICATORS_RIGHT),
    [TH_MINS_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINUS, KC_F11, INDICATORS_LEFT),
    [TH_EQL_F12]  = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, KC_F12, INDICATORS_RIGHT),
    [TH_APP_PSCR] = ACTION_TAP_DANCE_TAP_HOLD(KC_APPLICATION, KC_PRINT_SCREEN, INDICATORS_RIGHT),
};
// clang-format on
