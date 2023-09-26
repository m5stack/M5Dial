#include "M5Dial.h"

void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, true, false);
    M5Dial.Display.setTextColor(GREEN);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);
    M5Dial.Display.drawString("Button Test", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2);
}


void loop() {
    M5Dial.update();
    if (M5Dial.BtnA.wasPressed()) {
        M5Dial.Speaker.tone(8000, 20);
        M5Dial.Display.clear();
        M5Dial.Display.drawString("Pressed", M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2);
    }
    if (M5Dial.BtnA.wasReleased()) {
        M5Dial.Speaker.tone(8000, 20);
        M5Dial.Display.clear();
        M5Dial.Display.drawString("Released", M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2);
    }
}