#include "wordprocessor.hpp"
#include "article.hpp"
#include "porter2_stemmer.h"
#include "word.h"
#include "indexinterface.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// WordProcessor::WordProcessor(){
//   stopwords = {
//     {"a",hash_function("a")}, {"an", hash_function("an")},
//     {"and", hash_function("and")}, {"are", hash_function("are")}, {"as", hash_function("as")},
//     {"at", hash_function("at")}, {"be", hash_function("be")}, {"by", hash_function("by")},
//     {"for", hash_function("for")}, {"from", hash_function("from")}, {"has", hash_function("has")},
//     {"he", hash_function("he")}, {"in", hash_function("in")}, {"is", hash_function("is")},
//     {"it", hash_function("it")}, {"its", hash_function("its")}, {"of", hash_function("of")},
//     {"on", hash_function("on")}, {"that", hash_function("that")}, {"the", hash_function("the")},
//     {"to", hash_function("to")}, {"was", hash_function("was")}, {"were", hash_function("were")},
//     {"will", hash_function("will")}, {"with", hash_function("with")}
//   };
// }

WordProcessor::WordProcessor(vector<Article>* vec, IndexInterface* ix)
: articles(vec), index(ix){
  stopwords = {
    {hash_function("a"), "a"}, {hash_function("an"), "an"},
    {hash_function("and"), "and"}, {hash_function("are"), "are"}, {hash_function("as"), "as"},
    {hash_function("at"), "at"}, {hash_function("be"), "be"}, {hash_function("by"), "by"},
    {hash_function("for"), "for"}, {hash_function("from"), "from"}, {hash_function("has"), "has"},
    {hash_function("he"), "he"}, {hash_function("in"), "in"}, {hash_function("is"), "is"},
    {hash_function("it"), "it"}, {hash_function("its"), "its"}, {hash_function("of"), "of"},
    {hash_function("on"), "on"}, {hash_function("that"), "that"}, {hash_function("the"), "the"},
    {hash_function("to"), "to"}, {hash_function("was"), "was"}, {hash_function("were"), "were"},
    {hash_function("will"), "will"}, {hash_function("with"), "with"}
  };
}

void WordProcessor::setArticles(vector<Article>* vec){
  articles = vec;
}

void WordProcessor::setIndex(IndexInterface* ix){
  index = ix;
}

void WordProcessor::processWords(){
  for(int i = 0; i < articles->size(); i++){
    stringstream tempstream(articles->at(i).text);
    string tempword;
    while(!tempstream.eof()){
      tempstream >> tempword;
      transform(tempword.begin(), tempword.end(), tempword.begin(), ::tolower);
      if(!isStopWord(tempword)) continue;
      removeNonAlphaChars(tempword);
      using namespace Porter2Stemmer;
      stem(tempword);
      Word* tempWordObj = new Word;
      tempWordObj->word = tempword;
      tempWordObj->articles.push_back(i);
      cout << "derp" << endl;
      index->put(tempWordObj);
    }
  }
}

void WordProcessor::removeNonAlphaChars(string& s){
  s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
}

bool WordProcessor::isStopWord(string& s){
  size_t key = hash_function(s);
  if(stopwords.find(key) == stopwords.end()){
    return true;
  }else{
    return false;
  }
}
