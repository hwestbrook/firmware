
#include "application.h"
#include "unit-test/unit-test.h"

#if PLATFORM_ID == PLATFORM_TRACKER

test(I2C_01_Wire3_Cannot_Be_Enabled_While_Wire_Is_Enabled) {
    Wire.begin();
    assertTrue(Wire.isEnabled());
    // Wire3 cannot be enabled while Wire is enabled.
    Wire3.begin();
    assertFalse(Wire3.isEnabled());

    Wire.end();
    assertFalse(Wire.isEnabled());
    Wire3.begin();
    assertTrue(Wire3.isEnabled());
    Wire3.end();
    assertFalse(Wire3.isEnabled());
}

test(I2C_02_Wire_Cannot_Be_Enabled_While_Wire3_Is_Enabled) {
    Wire3.begin();
    assertTrue(Wire3.isEnabled());
    // Wire cannot be enabled while Wire3 is enabled.
    Wire.begin();
    assertFalse(Wire.isEnabled());

    Wire3.end();
    assertFalse(Wire3.isEnabled());
    Wire.begin();
    assertTrue(Wire.isEnabled());
    Wire.end();
    assertFalse(Wire.isEnabled());
}

test(I2C_03_Wire3_Cannot_Be_Enabled_While_Serial1_Is_Enabled) {
    Serial1.begin(115200);
    assertTrue(Serial1.isEnabled());
    // Wire3 cannot be enabled while Serial1 is enabled.
    Wire3.begin();
    assertFalse(Wire3.isEnabled());

    Serial1.end();
    assertFalse(Serial1.isEnabled());
    Wire3.begin();
    assertTrue(Wire3.isEnabled());
    Wire3.end();
    assertFalse(Wire3.isEnabled());
}

test(I2C_04_Serial1_Cannot_Be_Enabled_While_Wire3_Is_Enabled) {
    Wire3.begin();
    assertTrue(Wire3.isEnabled());
    // Serial1 cannot be enabled while Wire3 is enabled.
    Serial1.begin(115200);
    assertFalse(Serial1.isEnabled());

    Wire3.end();
    assertFalse(Wire3.isEnabled());
    Serial1.begin(115200);
    assertTrue(Serial1.isEnabled());
    Serial1.end();
    assertFalse(Serial1.isEnabled());
}

#endif // PLATFORM_ID == PLATFORM_TRACKER
