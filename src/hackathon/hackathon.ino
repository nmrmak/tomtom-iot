#include "oled_display.h"
#include "connection.h"
#include "json_parsing.h"
#include "wifi_connection.h"
#include <WiFiClientSecure.h>

const char* host = "sharing.test.navcloud.tomtom.com";
String ssid = "WTH V.4 Guests";
String pass = "20H@ck@thon18";
String channel_create_url = "/api/v2/share";
String eta_get_url = "/api/v2/update";
String eta_channel_id = "2dacf261-c2c6-4673-a1d8-ec7e4bc02ff5";
String eta_full_url = eta_get_url + "/" + eta_channel_id;
String data = "{\"email\": \"sencerburak.okumus@tomtom.com\", \"storeName\": \"device-location\", \"valid\": 1000}";

WiFiClientSecure client;
SSD1306Wire display(I2C_DISPLAY_ADDRESS, SDA_PIN, SCL_PIN);

void Initialize() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Initializing display... ");
  initialize_display(display);
  Serial.println("done.");  
}

void setup() {
  Initialize();
  Serial.begin(115200);
    if (wifiConnection(ssid, pass)) {
    Serial.println("GET to https://" + String(host) + eta_full_url);
    Serial.print("Result(response): ");
    String restResponse = httpsGet(host, eta_full_url);
    Serial.println(restResponse);
    parseChannelFromJson(restResponse);
    display.clear();
    display.display();
    display.drawString(64, 7, parseChannelFromJson(restResponse));
    display.display();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
