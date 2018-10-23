#include "oled_display.h"

void Initialize() {
  SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SCL_PIN);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Initializing display... ");
  initialize_display(display);
  Serial.println("done.");  
}

void setup() {
  Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
}
