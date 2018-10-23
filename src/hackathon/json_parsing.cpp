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

std::vector<String> parseChannelListFromJson(String json)
{
  DynamicJsonBuffer jsonBuffer(512);
  JsonArray& root = jsonBuffer.parseArray(json);
  std::vector<String> returnValue;
  for(auto channel : root)
  {
    returnValue.push_back(String((const char*) channel));
  }
  return returnValue;
}

std::vector<UserEta> parseUserEtaPairsFromJson(String json)
{
  DynamicJsonBuffer jsonBuffer(512);
  JsonObject& root = jsonBuffer.parseObject(json);
  std::vector<UserEta> userEtaArray;

  std::vector<String> usernames;
  for(auto item : root)
  {
    usernames.push_back(item.key);
  }
  
  for(auto username : usernames)
  {
    const UserEta userEta = UserEta(String(username), String((const char*)root[username]["value"]["eta"]));
    userEtaArray.push_back(userEta);
  }
  
  return userEtaArray;
}
