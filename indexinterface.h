#ifndef INDEXINTERFACE
#define INDEXINTERFACE
#include <iostream>
#include <vector>
#include <word.h>


class IndexInterface
{
   public:
      // pure virtual function
    virtual std::vector<int> get(std::string) =0;
    virtual void put(Word*) =0;
    virtual void dumptoFile() =0;
    virtual void pullfromFile() =0;
    virtual void deleteAll() =0;
    virtual int getTotalPuts() =0;

   private:

};

      #endif // INDEXINTERFACE
