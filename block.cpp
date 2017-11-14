#include "block.h"

Block::Block()
{
}

Block::Block(long number, std::vector<char> text){
    this->id = number;
    this->textUnit = text;
}
