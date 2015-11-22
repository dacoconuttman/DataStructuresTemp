#ifndef WORD_H
#include <vector>
#include <string>
#define WORD_H

using namespace std;


class Word
{
public:

    vector<int> articles;
    string word;

    bool operator <(Word & word2) const
    {
        int result = this->word.compare(word2.word);

        if (result < 0)
        {return true;}
        else
            return false;
    }


    bool operator >(Word & word2) const
    {
        int result = this->word.compare(word2.word);
        if (result > 0)
        {return true;}
        else
            return false;
    }

};

#endif // WORD_H
