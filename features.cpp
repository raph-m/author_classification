#include "features.h"

Features::Features()
{
}

Features::Features(long number, int* f1, int* f2){
    this->id = number;
    this->charCount = f1;
    this->wordCount = f2;
}
