#include "block.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Block::Block()
{
}

Block::Block(long number, vector<char> text){
    this->id = number;
    this->textUnit = text;
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

void Block::updateSentenceCount(){//sentenceCount is set to the number of sentences, separators are '.', '!', '?', or '-'
    sentenceCount = 0;
    vector<char> separators ; //vector with all separators
    separators.push_back('.');
    separators.push_back('!');
    separators.push_back('?');
    separators.push_back('-');

    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int mem = 0; //turns to 1 if a separator is met


    for (int i = 0; i<l; i++){
        if (find(separators.begin(), separators.end(), textUnit[i]) != separators.end()){//we check whether the char is a separator
            if (!mem){ //if the previous character was not a separator, it means that we reached the end of a sentence
                sentenceCount+=1;
                mem=1;
            }
        }
        else{
            mem=0;
        }
    }
}

void Block::updateCharFrequency(){// takes into account characters from 32 (space) to 126 (~),charFrequency is set to an int vector of size 95
    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int ascii;
    vector<int> res(95,0);
    for (int i = 0; i<l; i++){
        ascii = (int) textUnit[i];
        if ((ascii>=32)&(ascii<=126)){
            res[ascii-32]+=1; //we add 1 to the corresponding indicator in the vector
        }
    }
    charFrequency = res;
}



