#include "block.h"
#include <iostream>
using namespace std;

Block::Block()
{
}

Block::Block(long number, std::vector<char> text){
    this->id = number;
    this->textUnit = text;
}

void Block::updateCharCount(){// takes into account characters from 32 (space) to 126 (~),charCount is set to an int vector of size 95
    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int ascii;
    vector<int> res(95,0);
    for (int i = 0; i<l; i++){
        ascii = (int) textUnit[i];
        if ((ascii>=32)&(ascii<=126)){
            res[ascii-32]+=1; //we add 1 to the corresponding indicator in the vector
        }
    }
    charCount = res;
}
