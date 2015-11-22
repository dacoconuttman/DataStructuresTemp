#ifndef LINKEDHASH_H
#define LINKEDHASH_H
#include "indexinterface.h"


class linkedHash
{
public:
    linkedHash *next;
    linkedHash(int key, int value)
        {
            this -> key = key;
            this -> value = value;
            next = null;
        }



};

#endif // LINKEDHASH_H
