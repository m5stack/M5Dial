#ifndef M5DIAL_H
#define M5DIAL_H

#include "M5Unified.h"

#include "utility/Encoder.h"
#include "utility/MFRC522.h"

#define DIAL_ENCODER_PIN_A 41
#define DIAL_ENCODER_PIN_B 40

namespace m5 {
class M5_DIAL {
   private:
    /* data */

   public:
    void begin(bool enableEncoder = false, bool enableRFID = false);
    void begin(m5::M5Unified::config_t cfg, bool enableEncoder = false,
               bool enableRFID = false);

    M5GFX &Display         = M5.Display;
    M5GFX &Lcd             = Display;
    Touch_Class &Touch     = M5.Touch;
    Power_Class &Power     = M5.Power;
    RTC8563_Class &Rtc     = M5.Rtc;
    Speaker_Class &Speaker = M5.Speaker;
    Button_Class &BtnA     = M5.BtnA;

    /// for internal I2C device
    I2C_Class &In_I2C = m5::In_I2C;

    /// for external I2C device (Port.A)
    I2C_Class &Ex_I2C = m5::Ex_I2C;

    ENCODER Encoder = ENCODER(DIAL_ENCODER_PIN_A, DIAL_ENCODER_PIN_B);
    MFRC522 Rfid    = MFRC522(RC522_I2C_ADDRESS);
    void update(void);
};

}  // namespace m5

extern m5::M5_DIAL M5Dial;

#endif