#pragma once
#include <vector>

typedef struct {
  String username;
  String eta;
} UserEta;

String parseChannelFromJson(String json);
std::vector<UserEta>& parseUserEtaPairsFromJson(String json);
