#include "oled_display.h"
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

String httpsGet(String url) {
  if (client.connect(host, 443)) {
    client.println(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n");
    delay(10);
    String response = client.readString();
    int bodypos =  response.indexOf("\r\n\r\n") + 4;
    return response.substring(bodypos);
  }
  else {
    return "ERROR";
  }
}

String httpsPost(String url, String data) {
  if (client.connect(host, 443)) {
    client.println("POST " + url + " HTTP/1.1");
    client.println("Host: " + (String)host);
    client.println("Authorization: SessionId cdf09787-d775-42ad-afe7-5d4a3fcf12ed");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.println(data);
    delay(10);
    String response = client.readString();
    int bodypos =  response.indexOf("\r\n\r\n") + 4;
    return response.substring(bodypos);
  }
  else {
    return "ERROR";
  }
}

void setup() {
  Initialize();
  Serial.begin(115200);
    if (wifiConnection()) {
    Serial.println("POST to https://" + String(host) + url);
    Serial.print("Result(response): ");
    String restResponse = httpsGet(url2);
    Serial.println(restResponse);
    display.clear();
    display.display();
    display.drawString(64, 7, restResponse.substring(0,60).c_str());
    display.display();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
