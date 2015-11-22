#include <iostream>
#include "hashtable.h"
#include "word.h"

using namespace std;

hashtable::hashtable()
{


}

//Pull some shit outta this
vector<int> hashtable::get(string toSearch)
{

  cout << "cash money" << endl;
    int pos = toSearch[0];
    pos = pos % 25;

    //if what is comming in is empty
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
    //yeah!! you found your word and I am going to return you the article it came in.
    if(temp->data->word == toSearch)
    {
        return temp->data->articles;
    }
    //you recached the end of the LLN and didn't find your word, sorry bro
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
