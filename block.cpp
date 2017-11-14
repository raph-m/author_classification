#include "block.h"

Block::Block()
{
}

Block::Block(long number, std::vector<char> text){
    this->id = number;
    this->textUnit = text;
}

Block::Block(long number, std::vector<char> text, int* f1, int* f2, int f3){
    this->id = number;
    this->textUnit = text;
    this->charCount = f1;
    this->wordCount = f2;
    this->sentenceCount = f3;
}
