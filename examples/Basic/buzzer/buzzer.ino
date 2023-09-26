/**
 * @file buzzer.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Dial Buzzer Test
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
#include "M5Dial.h"

void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, true, false);
    M5Dial.Display.setTextColor(GREEN);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);
    M5Dial.Display.drawString("Buzzer Test", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2);
}

void loop() {
    M5Dial.Speaker.tone(10000, 100);
    delay(1000);
    M5Dial.Speaker.tone(4000, 20);
    delay(1000);
}