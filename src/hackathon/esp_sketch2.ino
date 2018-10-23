#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
const char* host = "sharing.test.navcloud.tomtom.com";
String ssid = "WTH V.4 Guests";
String pass = "20H@ck@thon18";
WiFiClientSecure client;
void setup()
{

Serial.begin(115200);
    if (wifiConnection()) {
    String url = "/api/v2/share";
    String data = "\"email\": \"sencerburak.okumus@tomtom.com\", \"storeName\": \"device-location\", \"valid\": 1000" + ESP.getVcc();
    Serial.println("POST to https://" + String(host) + url);
    Serial.print("Result(response): ");
    Serial.println(httpsPost(url, data));
  }
}

void loop() {

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
    Serial.print(".");    client.println("POST " + url + " HTTP/1.1");
    client.println("Host: " + (String)host);
    client.println("User-Agent: ESP8266/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded;");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.println(data);
    count++;
  }
  Serial.println("Timed out.");
  return false;
}

String httpsPost(String url, String data) {
  if (client.connect(host, 443)) {
    client.println("POST " + url + " HTTP/1.1");
    client.println("Host: " + (String)host);
    client.println("User-Agent: ESP8266/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded;");
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
