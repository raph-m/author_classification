#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block
{
public:

    long id;
    std::vector<char> textUnit;

    int* charCount;
    int* wordCount;
    int sentenceCount;

    Block();
    Block(long number, std::vector<char> text);
    Block(long number, std::vector<char> text,int* f1,int* f2,int f3);

    int updateWordCount();
    int updateSentenceCount();
};

#endif // BLOCK_H
