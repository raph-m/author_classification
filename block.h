#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block
{
public:

    long id;
    std::vector<char> textUnit;

    Block();
    Block(long number, std::vector<char> text);
};

#endif // BLOCK_H
