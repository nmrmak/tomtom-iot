#include <ArduinoJson.h>

String parseChannelFromJson(String json)
{
  DynamicJsonBuffer jsonBuffer(200);
  JsonObject& root = jsonBuffer.parseObject(json);
  if (!root.success()) {
    return "ERROR";
  }
  return String((const char*) root["channelId"]);
}
