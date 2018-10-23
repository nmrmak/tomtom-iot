#include "oled_display.h"

void initialize_display(SSD1306Wire &display) {
  display.init();
  display.clear();
  display.display();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255); // default is 255
  display.drawString(64, 7, "Hackathon project\nBy Team 26\nETA monitor");
  display.display();
}