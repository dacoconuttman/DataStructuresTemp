/* Parser.hpp by Andrew Ksendzoff
   Interface for the Parser object
   Used to turn the XML file into a vector of
   Article objects with only the necessary data
 */
#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include "article.hpp"

using namespace std;

class Parser{
private:
  string filename;
  vector<Article>* articles;
public:
  //Constructor constructs the Parser object
  Parser();
  Parser(string file);

  //sets filename if you want to specify it later
  void setFile(string s);

  //passes the pointer to the vector of articles
  //returns a nullptr if cannot load the file
  vector<Article>* getArticles();

  // ~Parser();
};




#endif
