/**
 * @file touch.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Dial Touch Test
 * @version 0.1
 * @date 2023-09-26
 *
 *
 * @Hardwares: M5Dial
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include <M5Dial.h>

void setup(void) {
    auto cfg = M5.config();
    M5Dial.begin(cfg, false, false);

    M5Dial.Display.setTextColor(GREEN);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_24);
    M5Dial.Display.setTextSize(1);

    M5Dial.Display.drawString("Touch Test", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2);
}

int prev_x = -1;
int prev_y = -1;

static m5::touch_state_t prev_state;

void loop(void) {
    M5Dial.update();

    auto t = M5Dial.Touch.getDetail();
    if (prev_state != t.state) {
        prev_state                                  = t.state;
        static constexpr const char* state_name[16] = {
            "none", "touch", "touch_end", "touch_begin",
            "___",  "hold",  "hold_end",  "hold_begin",
            "___",  "flick", "flick_end", "flick_begin",
            "___",  "drag",  "drag_end",  "drag_begin"};
        M5_LOGI("%s", state_name[t.state]);
        M5Dial.Display.fillRect(0, 0, M5Dial.Display.width(),
                                M5Dial.Display.height() / 2, BLACK);

        M5Dial.Display.drawString(state_name[t.state],
                                  M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2 - 30);
    }
    if (prev_x != t.x || prev_y != t.y) {
        M5Dial.Display.fillRect(0, M5Dial.Display.height() / 2,
                                M5Dial.Display.width(),
                                M5Dial.Display.height() / 2, BLACK);
        M5Dial.Display.drawString(
            "X:" + String(t.x) + " / " + "Y:" + String(t.y),
            M5Dial.Display.width() / 2, M5Dial.Display.height() / 2 + 30);
        prev_x = t.x;
        prev_y = t.y;
        M5Dial.Display.drawPixel(prev_x, prev_y);
    }
}
