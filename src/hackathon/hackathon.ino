#include "oled_display.h"
#include "connection.h"
#include "json_parsing.h"
#include "wifi_connection.h"
#include "frames.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <vector>
std::vector<UserEta> userEtas;

String host = "sharing.test.navcloud.tomtom.com";
String ssid = "WTH V.4 Guests";
String pass = "20H@ck@thon18";
String channel_create_url = "/api/v2/share";
String eta_channel_id = "/2dacf261-c2c6-4673-a1d8-ec7e4bc02ff5";
String data = "{\"email\": \"sencerburak.okumus@tomtom.com\", \"storeName\": \"device-location\", \"valid\": 1000}";

WiFiClientSecure client;
SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SCL_PIN);
OLEDDisplayUi ui(&display);
FrameCallback frames[] = { drawFrame1, drawFrame2, drawFrame3, drawFrame4, drawFrame5 };
int frameCount = 5;

void Initialize() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Initializing display... ");
  initialize_display(display);
  Serial.println("done.");  
}

std::vector<String> getVectorOfChannels(String host)
{
  String channel_list_get_url = "/api/v2/devices/eta-monitor";
  String restResponse = httpsGet(host, channel_list_get_url);
  return parseChannelListFromJson(restResponse);
}

std::vector<UserEta> getUserEtaPairs(String host, std::vector<String> vectorOfChannels)
{
  String eta_get_url = "/api/v2/update";
  userEtas.clear();
  for (auto channel : vectorOfChannels)
  {
    String restResponse = httpsGet(host, eta_get_url + "/" + channel);
    std::vector<UserEta> userEtasForThisChannel = parseUserEtaPairsFromJson(restResponse);
    userEtas.insert(std::end(userEtas), std::begin(userEtasForThisChannel), std::end(userEtasForThisChannel));
    Serial.println(String("frameCount: ") + String(frameCount) + String(" userEtas.size(): ") + String((int)userEtas.size()));
//    ui.setFrames(frames, min(frameCount, (int)userEtas.size()));
    Serial.println("Before update");
//    ui.init();
//    ui.update();
    Serial.println("After update");
    for (const auto eta : userEtasForThisChannel)
    {
      Serial.println("User: " + eta.username + ", ETA: " + eta.eta);
      display.clear();
      display.drawString(64, 7, eta.username + String("\nETA: ") + eta.eta);
      display.display();
    }
  
  }
  return userEtas;
}

void setup() {
  Initialize();
  Serial.begin(115200);
  display.clear();
  display.display();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255); // default is 255
  display.drawString(64, 7, "ETA Monitor\nTeam 26\nConnecting...");
  display.display();
//  ui.setTargetFPS(30);
//  ui.setIndicatorPosition(BOTTOM);
//  ui.setIndicatorDirection(LEFT_RIGHT);
//  ui.setFrameAnimation(SLIDE_LEFT);
//  ui.setFrames(frames, frameCount);
//  ui.init();
}


void loop() {
//  ui.update();
  if (wifiConnection(ssid, pass)) {
    Serial.print("Result(response): ");
    std::vector<String> channelList = getVectorOfChannels(host);
    userEtas = getUserEtaPairs(host, channelList);
  }
}


void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + userEtas[0].username + "\nETA: " + userEtas[0].eta);
}
void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + userEtas[1].username + "\nETA: " + userEtas[1].eta);
}
void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + userEtas[2].username + "\nETA: " + userEtas[2].eta);
}
void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + userEtas[3].username + "\nETA: " + userEtas[3].eta);
}
void drawFrame5(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  // Demonstrates the 3 included default sizes. The fonts come from DFRobot_OLED12864Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "User: " + userEtas[4].username + "\nETA: " + userEtas[4].eta);
}
