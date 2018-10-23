#include <ArduinoJson.h>
#include "json_parsing.h"
#include <vector>

String parseChannelFromJson(String json)
{
  DynamicJsonBuffer jsonBuffer(512);
  JsonObject& root = jsonBuffer.parseObject(json);
  if (!root.success()) {
    return "ERROR";
  }
  return String((const char*) root["channelId"]);
}

std::vector<UserEta>& parseUserEtaPairsFromJson(String json)
{
  DynamicJsonBuffer jsonBuffer(512);
  JsonObject& root = jsonBuffer.parseObject(json);
  std::vector<UserEta> userEtaArray;

  const int userCount = root.size();
  for (int user = 0; user < userCount; user++)
  {
    UserEta userEta;
    //userEta.username = (const char*) root.asArray()[0];
    //userEta.eta =      (const char*) root.asArray()[0];
    userEtaArray.push_back(userEta);
  }
  return userEtaArray;
}
