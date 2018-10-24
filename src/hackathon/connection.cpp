#include "connection.h"
#include <WiFiClientSecure.h>

String httpsGet(String host, String url) {
  WiFiClientSecure client;
  if (client.connect(host, 443)) {
    client.println(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n");
    String response = client.readString();
    int bodypos = response.indexOf("\r\n\r\n") + 4;
    return response.substring(bodypos);
  }
  else {
    return "ERROR";
  }
}

String httpsPost(String host, String url, String data) {
  WiFiClientSecure client;
  if (client.connect(host, 443)) {
    client.println("POST " + url + " HTTP/1.1");
    client.println("Host: " + (String)host);
    client.println("Authorization: SessionId cdf09787-d775-42ad-afe7-5d4a3fcf12ed");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.println(data);
    String response = client.readString();
    int bodypos =  response.indexOf("\r\n\r\n") + 4;
    return response.substring(bodypos);
  }
  else {
    return "ERROR";
  }
}
