#include "block.h"
#include <iostream>
#include <vector>

using namespace std;

Block::Block()
{
}

Block::Block(long number, vector<char> text){
    this->id = number;
    this->textUnit = text;
}

Block::Block(long number, vector<char> text, vector<int> f1, int f2, int f3){
    this->id = number;
    this->textUnit = text;
    this->charCount = f1;
    this->wordCount = f2;
    this->sentenceCount = f3;
}

void Block::updateWordCount(){
    int cmpt = 1;
    for (vector<char>::iterator it = this->textUnit.begin(); it != this->textUnit.end(); ++it) {
        if (*it == ' ' || *it == '/') {
            cmpt++;
        }
    }
    this->wordCount = cmpt;
}

void Block::updateSentenceCount(){
    int cmpt = 1;
    for (vector<char>::iterator it = this->textUnit.begin(); it != this->textUnit.end(); ++it) {
        if (*it == '.' || *it == '!' || *it == '?') {
            cmpt++;
        }
    }
    this->sentenceCount = cmpt;
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

