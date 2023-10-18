/**
 * @file rfid.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Dial RFID Test
 * @version 0.2
 * @date 2023-10-18
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
    M5Dial.begin(cfg, false, true);
    M5Dial.Display.setTextColor(GREEN);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);

    M5Dial.Display.drawString("RFID Card", M5Dial.Display.width() / 2,
                              M5Dial.Display.height() / 2);
}

void loop() {
    if (M5Dial.Rfid.PICC_IsNewCardPresent() &&
        M5Dial.Rfid.PICC_ReadCardSerial()) {
        M5Dial.Display.clear();

        Serial.print(F("PICC type: "));
        uint8_t piccType = M5Dial.Rfid.PICC_GetType(M5Dial.Rfid.uid.sak);
        Serial.println(M5Dial.Rfid.PICC_GetTypeName(piccType));

        // Check is the PICC of Classic MIFARE type
        if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
            piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
            piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
            Serial.println(F("Your tag is not of type MIFARE Classic."));
            M5Dial.Display.drawString("not support", M5Dial.Display.width() / 2,
                                      M5Dial.Display.height() / 2);
            return;
        }
        String uid = "";
        for (byte i = 0; i < M5Dial.Rfid.uid.size;
             i++) {  // Output the stored UID data.  将存储的UID数据输出
            Serial.printf("%02X ", M5Dial.Rfid.uid.uidByte[i]);
            uid += String(M5Dial.Rfid.uid.uidByte[i], HEX);
        }
        M5Dial.Speaker.tone(8000, 20);
        M5Dial.Display.drawString(M5Dial.Rfid.PICC_GetTypeName(piccType),
                                  M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2 - 30);

        M5Dial.Display.drawString("card id:", M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2);

        M5Dial.Display.drawString(uid, M5Dial.Display.width() / 2,
                                  M5Dial.Display.height() / 2 + 30);
        Serial.println();
    }
}
