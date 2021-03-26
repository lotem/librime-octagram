//
// Copyright RIME Developers
//
#include <algorithm>
#include <iostream>
#include <rime/common.h>
#include "gram_db.h"
#include "gram_encoding.h"
#include "octagram.h"

using namespace rime;

int main(int argc, char* argv[]) {
  string language = argc > 1 ? string(argv[1]) : kGrammarDefaultLanguage;
  LOG(INFO) << "building grammar for language: " << language;

  vector<pair<string, double>> data;
  while (std::cin) {
    string key;
    double value;
    std::cin >> key;
    if (key.empty())
      break;
    std::cin >> value;
    data.push_back({grammar::encode(key), value});
  }
  std::sort(data.begin(), data.end());

  GramDb db(language + kGramDbType.suffix);
  LOG(INFO) << "creating " << db.file_name();
  if (!db.Build(data) || !db.Save()) {
    LOG(ERROR) << "failed to build " << db.file_name();
    return 1;
  }
  LOG(INFO) << "created: " << db.file_name();
  return 0;
}
