#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "indexinterface.h"
#include <vector>
#include "word.h"
#include "linkedlistnode.h"




class hashtable : public IndexInterface
{
public:
    hashtable();
    ~hashtable();
    std::vector<int> get(std::string);
    void put(Word*);
    int getTotalPuts();


private:
    LinkedListNode* hashIndex[26];
    int wordCounter;


};

#endif // HASHTABLE_H
