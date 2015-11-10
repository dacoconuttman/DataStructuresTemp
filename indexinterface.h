#ifndef INDEXINTERFACE
#define INDEXINTERFACE
#include <iostream>


class IndexInterface
{
   public:
      // pure virtual function
    virtual vector<int> get(string) =0;
    virtual void put(string, int) =0;
    virtual void dumptoFile() =0;
    virtual void pullfromFile() =0;
    virtual void deleteAll() =0;
    virtual int getTotalPuts() =0;

   private:

};

      #endif // INDEXINTERFACE
