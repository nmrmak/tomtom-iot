#include "oled_display.h"
#include "connection.h"
#include "json_parsing.h"
#include "wifi_connection.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <vector>

String host = "sharing.test.navcloud.tomtom.com";
String ssid = "WTH V.4 Guests";
String pass = "20H@ck@thon18";
String channel_create_url = "/api/v2/share";
String eta_channel_id = "/2dacf261-c2c6-4673-a1d8-ec7e4bc02ff5";
String data = "{\"email\": \"sencerburak.okumus@tomtom.com\", \"storeName\": \"device-location\", \"valid\": 1000}";

SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SCL_PIN);

void Initialize() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Initializing display... ");
  initialize_display(display);
  Serial.println("done.");  
}

std::vector<String> getVectorOfChannels(String host)
{
  String channel_list_get_url = "/api/v2/devices/hackathon26";
  String restResponse = httpsGet(host, channel_list_get_url);
  return parseChannelListFromJson(restResponse);
}

std::vector<UserEta> getUserEtaPairs(String host, std::vector<String> vectorOfChannels)
{
  String eta_get_url = "/api/v2/update";
  std::vector<UserEta> userEtas;  
  for (auto channel : vectorOfChannels)
  {
    String restResponse = httpsGet(host, eta_get_url + "/" + channel);
    std::vector<UserEta> userEtasForThisChannel = parseUserEtaPairsFromJson(restResponse);
    userEtas.insert(std::end(userEtas), std::begin(userEtasForThisChannel), std::end(userEtasForThisChannel));

    for (const auto eta: userEtasForThisChannel) {
       Serial.println("Channel Id: " + channel + " User: " + eta.username + ", ETA: " + eta.eta);
    }
  }
  return userEtas;
}

void setup() {
  Initialize();
  Serial.begin(115200);
 }

void loop() {
 if (wifiConnection(ssid, pass)) {
    Serial.print("Result(response): ");
    std::vector<String> channelList = getVectorOfChannels(host);
    std::vector<UserEta> userEtas = getUserEtaPairs(host, channelList);
 }
  /* ETA resolution: 1s */
  delay(1000);
}
