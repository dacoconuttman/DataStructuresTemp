#include <string>
#include <iostream>
#include <vector>
#include "pugixml.hpp"
#include "article.hpp"

using namespace std;
using namespace pugi;

int main(){

  vector<Article> articles;
  xml_document doc;
  string title, author, timestamp, text;
  int ns;

  if (!doc.load_file("data/enwikibooks-latest-pages-meta-current.xml")) return -1;

  xml_node root = doc.child("mediawiki");

  int i = 0;

  for(xml_node page_node = root.child("page"); page_node != nullptr; page_node = page_node.next_sibling()){

    ns = atoi(page_node.child_value("ns"));


    title = page_node.child_value("title");
    xml_node revision_node = page_node.child("revision");
    timestamp = revision_node.child_value("timestamp");
    text = revision_node.child_value("text");
    author = revision_node.child("contributor").first_child().child_value();



    if(ns == 0){
      articles.emplace_back(title, author, timestamp, text);
      articles[i].location = i;
      i++;
    }

  }

  for(int i = 0; i < articles.size(); i++){
    cout << articles[i] << endl;
  }

  return 0;
}
