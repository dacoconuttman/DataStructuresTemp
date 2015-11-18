#include <iostream>
#include "hashtable.h"

using namespace std;

hashtable::hashtable()
{


}

//Pull some shit outta this
vector<int> hashtable::get(string toSearch)
{
    int pos = toSearch[0];
    pos = pos % 25;


    if(hashIndex[pos] == NULL)
    {
        std::vector<int> emptyVec;
        return emptyVec;
    }

    LinkedListNode* temp = hashIndex[pos];
    while(temp->next != NULL && temp->data->word !=toSearch)
    {
        temp = temp->next;
    }
    if(temp->data->word == toSearch)
    {
        return temp->data->articles;
    }
    else
    {
        std::vector<int> emptyVec;
        return emptyVec;
    }

}

//Throw this shit in here
void hashtable::put(Word* toInsert)
{
    wordCounter++;

    int pos = toInsert->word[0];
    pos = pos % 25; //Account for ascii and find the right bucket for the goods

    //First node detection
    if(hashIndex[pos] == NULL)
    {
        hashIndex[pos] = new LinkedListNode;
        hashIndex[pos]->data = toInsert;
        return;
    }

    LinkedListNode* temp = hashIndex[pos];
    while(temp->next != NULL && temp->data->word != toInsert->word)
    {
        temp = temp->next;
    }
    if(temp->data->word == toInsert->word)
    {
        //Words are same, need to add page num to vector
        temp->data->articles.push_back(toInsert->articles[0]);
        delete toInsert;
        return;
    }
    temp->next = new LinkedListNode;
    temp->next->data = toInsert;



}

// De-allocates all memory used for the Hash Table.
hashtable::~hashtable()
{

}

//a counter to see how many words are in the total ammount
int hashtable::getTotalPuts()
{
    return wordCounter;
}
