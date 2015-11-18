#include <iostream>
#include "hashtable.h"

using namespace std;

hashtable::hashtable()
{

    //initialize an arry of 26 elements
    //impliment element on to an AVL tree


}

//Pull some shit outta this
vector<int> hashtable::get(string)
{

}

//Throw this shit in here
void hashtable::put(word)
{

}

// De-allocates all memory used for the Hash Table.
hashtable::~hashtable()
{
    //Delete each AVL tree first
    delete [] array;
}

//a counter to see how many words are in the total ammount
hashtable::getTotalPuts()
{
    return wordCounter;
}
