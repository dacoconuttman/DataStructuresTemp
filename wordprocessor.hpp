#ifndef WORDPROCESSOR_HPP
#define WORDPROCESSOR_HPP

#include "article.hpp"
#include "porter2_stemmer.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class WordProcessor {
private:
  vector<Article>* articles;
  IndexInterface* index;
  hash<string> hash_function;
  unordered_map<size_t, string> stopwords;
  bool isStopWord(string& s);
  void removeNonAlphaChars(string& s);

public:
  WordProcessor();
 WordProcessor(vector<Article>* vec, IndexInterface* ix);

  void setArticles(vector<Article>* vec);
 void setIndex(IndexInterface ix);

  void processWords();
};

#endif
