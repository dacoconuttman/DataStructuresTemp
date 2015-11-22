#include <iostream>
#include "avltree.h"
#include "word.h"
using namespace std;

    // Test program
int main( )
{

    AvlTree <Word> indexer;

    Word word1;

    word1.word = "dog";
    word1.articles.push_back(0);

    indexer.insert(word1);


    Word word2;

    word2.word = "apple";
    word2.articles.push_back(0);

    indexer.insert(word2);


    Word word3;

    word3.word = "cartoon";
    word3.articles.push_back(0);

    indexer.insert(word3);


    indexer.printTree();

}
