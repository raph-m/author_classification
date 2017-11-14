#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block
{
public:

    long id;
    std::vector<char> textUnit;

    std::vector<int> charCount;
    std::vector<int> wordCount;
    int sentenceCount;

    Block();
    Block(long number, std::vector<char> text);
    void updateCharCount();
};

#endif // BLOCK_H
