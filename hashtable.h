#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "indexinterface.h"


class hashtable : public IndexInterface
{
public:
    hashtable();
    std::vector<int> get(std::string);
    void put(std::string, int);
    int getTotalPuts();


private:
    IndexInterface* hashIndex[26];
    int wordCounter;


};

#endif // HASHTABLE_H
