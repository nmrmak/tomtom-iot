#pragma once
#include <vector>

typedef struct UserEta_t {
  UserEta_t(String u, String e) {
    username = u;
    eta = e;
  }
  String username;
  String eta;
} UserEta;

String parseChannelFromJson(String json);
std::vector<UserEta> parseUserEtaPairsFromJson(String json);
