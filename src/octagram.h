#ifndef RIME_OCTAGRAM_H_
#define RIME_OCTAGRAM_H_

#include <rime/common.h>
#include <rime/component.h>
#include <rime/resource.h>
#include <rime/gear/grammar.h>

namespace rime {

extern const ResourceType kGramDbType;
extern const string kGrammarDefaultLanguage;

class Config;
class GramDb;
struct GrammarConfig;

class Octagram : public Grammar {
 public:
  explicit Octagram(Config* config);
  virtual ~Octagram();
  double Query(const string& context,
               const string& word,
               bool is_rear) override;

 private:
  the<GramDb> db_;
  the<GrammarConfig> config_;
};

}  // namespace rime

#endif  // RIME_OCTAGRAM_H_
