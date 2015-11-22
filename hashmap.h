#ifndef HASHMAP_H
#define HASHMAP_H
#include "indexinterface.h"
#include "linkedhash.h"

class hashmap
{
private:
    linkedHash **htable;


public:
    hashmap();
        {
            linkedHash* htable = new linkedHash[TABLE_SIZE];
            for(int i = 0; i < TABLE_SIZE; i++)
                {
                    htable[i] = NULL;
                }

                ~hashmap()
                {
                    for(int i = 0; i < TABLE_SIZE; i++)
                    {
                        if(htable[i]! = NULL)
                        {
                            linkedHash *prev = NULL;
                            linkedHash *entry = htable[i];

                            while(entry != NULL)
                            {
                                prev = entry;
                                entry = entry->next;
                                delete prev;
                            }
                        }
                        delete[]htable;
                    }

                int hashfunction(int key)
                {
                    return key% TABLE_SIZE
                }

                void Insert(int key, int value)
                {
                    int Hash_val = hashfunction(key);
                    if(htable[Hash_val]==null)
                        htable[Hash_val]=newLinked

                    else
                        {
                        linkedHash *entry = htable[Hash_val]
                        while(entry->next!=NULL)
                                entry = entry -> next;
                                if(entry->key == key)
                                    entry->value = value;
                                else
                                    entry->next = newLinkedHash(key, value)
                        }
                }

                    if find(int key)
                    {
                        int hash_val=hashfunction(key)
                                if(htable[hash_val]==NULL)
                                {
                                    return -1;
                                else
                                    {
                                        LinkedHash *entry = htable[hash_val];
                                        while(entry!=NULL && entry->key !=key)
                                            entry = entry->nest;
                                        if(antry == NULL)
                                            return -1;
                                        else
                                            return entry->value;
                                    }
                                }
                    }

                    Void delete(int key)
                    {
                        int hash_val = hashfunction(key)
                                if (htable[hash_val]!= NULL)
                                    {
                                        prev = entry;
                                        entry = entry->next;
                                    }
                                if (prev == NULL)
                                    {
                                        Linked *next = entry -> next;
                                        delete entry;
                                        htable[hash_val]=next;
                                    }
                                else
                                    {
                                        LinkedHash *next=entry->next;
                                        delete entry;
                                        prev -> next =next;
                                    }
                    }



                }


        }

};

#endif // HASHMAP_H
