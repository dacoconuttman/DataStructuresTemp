/* Parser.cpp by Andrew Ksendzoff
   Parser object
   Creates a vector of Articles, then populates it
   with the result of parsing an xml document
*/

#include "parser.hpp"
#include "article.hpp"
#include "pugixml.hpp"
#include <vector>
#include <string>

using namespace std;
using namespace pugi;

//Default constructor, creates an Article vector with
//the same length as non-junk articles in WikiBooks
Parser::Parser(){
  articles = new vector<Articles>[79071];
}

//Much of the same, but sets the filename as well
Parser::Parser(string file): filename(file){
  articles = new vector<Article>[79071];
}

//sets the filename in case you needed to use the
//default constructor
void Parser::setFile(string s){
  filename = s;
}

//Parses the XML document into Articles, then returns
//a pointer to the vector of Articles
const vector<Article>* Parser::getArticles(){
  //initializes variables for parsing
  xml_document doc;
  string title, author, timestamp, text;
  int ns;

  //returns nullptr if cannot load the file
  if(!doc.load_file(filename)) return nullptr;

  xml_node root = doc.child("mediawiki");

  int i = 0;

  //traverses the DOM tree page by page
  for(xml_node page_node = root.child("page"); page_node != nullptr; page_node = page_node.next_sibling()){

    //pulls out all the node values I need to create articles
    ns = atoi(page_node.child_value("ns"));
    title = page_node.child_value("title");
    xml_node revision_node = page_node.child("revision");
    timestamp = revision_node.child_value("timestamp");
    text = revision_node.child_value("text");
    author = revision_node.child("contributor").first_child().child_value();

    //only pushes articles with the default namespace into the vector
    //(gets rid of file aricles, talk articles, ...)
    if(ns == 0){
      articles->emplace_back(title, author, timestamp, text);
      articles[i]->location = i;
      i++;
    }
  }

  return articles;
}
