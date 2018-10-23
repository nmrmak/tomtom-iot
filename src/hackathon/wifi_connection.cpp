#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#define CONNECTION_TIMEOUT 20

boolean wifiConnection(String ssid, String password) {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid.c_str(), password.c_str());
    int count = 0;
    Serial.print("Waiting for Wi-Fi connection");
    while (count < CONNECTION_TIMEOUT) {
      if (WiFi.status() == WL_CONNECTED) {
        Serial.println();
        Serial.println("Connected!");
        return (true);
      }
      delay(500);
      Serial.print(".");
      count++;
    }
  } else {
    return (true);
  }

  Serial.println("Timed out.");
  return false;
}
