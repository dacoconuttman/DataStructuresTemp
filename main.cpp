#include "wordprocessor.hpp"
#include "article.hpp"
#include "parser.hpp"
#include "porter2_stemmer.h"
#include "hashtable.h"
#include "linkedlistnode.h"
#include "indexinterface.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){

  IndexInterface* ix = new hashtable;

  Parser p("enwikibooks-latest-pages-meta-current.xml");
  vector<Article>* articles;
  articles = p.getArticles();

  WordProcessor wp(articles, ix);

  wp.processWords();

  cout << "Total puts: " << ix->getTotalPuts();

}
