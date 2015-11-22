#ifndef INDEXINTERFACE
#define INDEXINTERFACE
#include <iostream>
#include <vector>
#include <word.h>

class IndexInterface
{
   public:
    // pure virtual functions

    //Get vector of page numbers based on string value
    virtual std::vector<int> get(std::string) =0;

    //Inserts word into data structure (if it doesn't exist already).
    //If already exists, then page numbers from incoming word will be merged
    //into page number vector from Word that is already in data structure.
    virtual void put(Word *) =0;

    //Takes data structure and prints to file on disk
    virtual void dumptoFile() =0;

    //Takes file from disk and inserts to data structure
    virtual void pullfromFile() =0;

    //Clears data structure
    virtual void deleteAll() =0;

    //Return count of total puts (insertions)
    virtual int getTotalPuts() =0;

    //Searches for String with value of word
    //returns pointer to vector of ints which contains article numbers
    vector<int>* get(String wordToFind);

   private:

};

#endif // INDEXINTERFACE
