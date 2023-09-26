#include "M5Dial.h"

using namespace m5;

M5_DIAL M5Dial;

void M5_DIAL::begin(bool enableEncoder, bool enableRFID) {
    M5.begin();
    if (enableEncoder) {
        Encoder.begin();
    }
    if (enableRFID) {
        Rfid.begin();
    }
}

void M5_DIAL::begin(m5::M5Unified::config_t cfg, bool enableEncoder,
                    bool enableRFID) {
    M5.begin(cfg);
    if (enableEncoder) {
        Encoder.begin();
    }
    if (enableRFID) {
        Rfid.begin();
    }
}

void M5_DIAL::update(void) {
    M5.update();
}
