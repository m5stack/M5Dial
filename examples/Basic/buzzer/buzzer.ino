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