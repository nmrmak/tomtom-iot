#pragma once

#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"

// Display Settings
const int I2C_DISPLAY_ADDRESS = 0x3c; // I2C Address of your Display (usually 0x3c or 0x3d)
const int SDA_PIN = D2;
const int SCL_PIN = D5;
const boolean INVERT_DISPLAY = false; // true = pins at top | false = pins at the bottom
const int externalLight = LED_BUILTIN; // LED_BUILTIN is is the built in LED on the Wemos

void initialize_display(SSD1306Wire display);
