#ifndef ARTICLE_HPP
#define ARTICLE_HPP
#include <string>
#include <ios>

using namespace std;

struct Article{
public:
  string title, author, timestamp, text;
  int location;
  streampos position;
  Article();
  Article(string tt, string a, string ts, string tx): title(tt), author(a), timestamp(ts), text(tx) {};

  friend ostream& operator<< (ostream& lhs, const Article& rhs){
    lhs << "Article #: " << rhs.location << endl;
    lhs << "Title: " << rhs.title << endl;
    lhs << "Author: " << rhs.author << endl;
    lhs << "Timestamp: " << rhs.timestamp << endl << endl;
    // lhs << rhs.text << endl << endl;
    return lhs;
  }
};

#endif
