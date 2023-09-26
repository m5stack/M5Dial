/**
 * @file wakeup.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Dial Timer Wakeup Test
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
    M5Dial.Display.setTextFont(&fonts::FreeSerifItalic18pt7b);
    M5Dial.Display.setTextSize(1);

    M5Dial.Display.drawString("Press Btn", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2 - 60);
    M5Dial.Display.drawString("to sleep", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2 - 20);
    M5Dial.Display.drawString("After 5s", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2 + 20);
    M5Dial.Display.drawString("Wakeup", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2 + 60);
}

void loop(void) {
    M5Dial.update();

    if (M5Dial.BtnA.wasPressed()) {
        M5Dial.Power.timerSleep(5);
        // M5Dial.Power.timerSleep(const rtc_time_t& time);
        // M5Dial.Power.timerSleep(const rtc_date_t& date, const rtc_time_t&
        // time);
        // M5Dial.Power.powerOff(); shutdown
    }
}
