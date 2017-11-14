#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>

using namespace std;

class Block
{
public:

    long id;
    vector<char> textUnit;

    vector<int> charCount;
    int wordCount;
    int sentenceCount;

    Block();
    Block(long number, vector<char> text);
    Block(long number, vector<char> text,vector<int> f1,int f2,int f3);

    void updateWordCount();
    void updateSentenceCount();
    void updateCharCount();

};

#endif // BLOCK_H
