#include "M5Dial.h"

void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, false, true);
    M5Dial.Display.setTextColor(GREEN);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);

    M5Dial.Display.drawString("RFID Card", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2);
}

void loop() {
    if (M5Dial.Rfid.PICC_IsNewCardPresent() ||
        M5Dial.Rfid.PICC_ReadCardSerial()) {
        M5Dial.Display.clear();
        String uid = "";
        for (byte i = 0; i < M5Dial.Rfid.uid.size;
             i++) {  // Output the stored UID data.  将存储的UID数据输出
            Serial.printf("%02X ", M5Dial.Rfid.uid.uidByte[i]);
            uid += String(M5Dial.Rfid.uid.uidByte[i], HEX);
        }
        M5Dial.Speaker.tone(8000, 20);
        M5Dial.Display.drawString("card uid:", M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2 - 20);

        M5Dial.Display.drawString(uid, M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2 + 20);
        Serial.println();
    }
}