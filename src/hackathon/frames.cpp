#include "frames.h"
/*
void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + eta[0].username + ", ETA: " + eta[0].eta);
}
void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Frame2");
}
void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Frame3");
}
void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Frame4");
}
void drawFrame5(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Frame5");
}
/*SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SCL_PIN);
OLEDDisplayUi   ui( &display );
void frameConstructor(FrameCallback Frames, int FrameCount){
  initialize_display(display);
        ui.setTargetFPS(60);

      // You can change this to
      // TOP, LEFT, BOTTOM, RIGHT
      ui.setIndicatorPosition(BOTTOM);

      // Defines where the first frame is located in the bar.
      ui.setIndicatorDirection(LEFT_RIGHT);

      // You can change the transition that is used
      // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
      ui.setFrameAnimation(SLIDE_LEFT);

      // Add frames
      ui.setFrames(Frames, FrameCount);



      // Initialising the UI will init the display too.
      ui.init();

}*/
