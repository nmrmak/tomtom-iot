#include "oled_display.h"
#include "connection.h"
#include "json_parsing.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* host = "sharing.test.navcloud.tomtom.com";
String ssid = "WTH V.4 Guests";
String pass = "20H@ck@thon18";
String url = "/api/v2/share";
String url2 = "/api/v2/update/26a9252c-8389-4a98-9741-742eda03fe28";
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

boolean wifiConnection() {
  WiFi.begin(ssid.c_str(), pass.c_str());
  int count = 0;
  Serial.print("Waiting for Wi-Fi connection");
  while ( count < 20 ) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println();
      Serial.println("Connected!");
      return (true);
    }
    delay(500);
    Serial.print(".");
    count++;
  }
  Serial.println("Timed out.");
  return false;
}

void setup() {
  Initialize();
  Serial.begin(115200);
    if (wifiConnection()) {
    Serial.println("GET to https://" + String(host) + url);
    Serial.print("Result(response): ");
    String restResponse = httpsGet(host, url2);
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
