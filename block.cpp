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

int Block::updateWordCount(){
    int cmpt = 1;
    for (std::vector<char>::iterator it = this->textUnit.begin(); it != this->textUnit.end(); ++it) {
        if (*it == ' ' || *it == '/') {
            cmpt++;
        }
    }
    return cmpt;
}

int Block::updateSentenceCount(){
    int cmpt = 1;
    for (std::vector<char>::iterator it = this->textUnit.begin(); it != this->textUnit.end(); ++it) {
        if (*it == '.' || *it == '!' || *it == '?') {
            cmpt++;
        }
    }
    return cmpt;
}
