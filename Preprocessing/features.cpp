#include "features.h"

Features::Features()
{
}

Features::Features(long number, std::vector<int> f1, std::vector<int> f2){
    this->id = number;
    this->charCount = f1;
    this->wordCount = f2;
}

Features::Features(long number, std::vector<int> f1, std::vector<int> f2,int f3){
    this->id = number;
    this->charCount = f1;
    this->wordCount = f2;
    this->sentenceCount = f3;
}
