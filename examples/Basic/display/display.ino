/**
 * @file display.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Dial Display Test
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

void draw_function(LovyanGFX* gfx) {
    int x      = rand() % gfx->width();
    int y      = rand() % gfx->height();
    int r      = (gfx->width() >> 4) + 2;
    uint16_t c = rand();
    gfx->fillRect(x - r, y - r, r * 2, r * 2, c);
}

void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, false, true);

    int textsize = M5Dial.Display.height() / 60;
    if (textsize == 0) {
        textsize = 1;
    }
    M5Dial.Display.setTextSize(textsize);
}

void loop() {
    int x      = rand() % M5Dial.Display.width();
    int y      = rand() % M5Dial.Display.height();
    int r      = (M5Dial.Display.width() >> 4) + 2;
    uint16_t c = rand();
    M5Dial.Display.fillCircle(x, y, r, c);
    draw_function(&M5Dial.Display);
}