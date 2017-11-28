#include "features.h"

Features::Features(){
}

//Features::Features(long number, std::vector<int> f1, std::vector<int> f2){
//    this->id = number;
//    this->charCount = f1;
//    this->wordCount = f2;
//}

Features::Features(long number, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC){
    this->id = number;
    this->charFrequency = charF;
    this->wordCount = wordC;
    this->sentenceCount = sentenceC;
    this->wordFrequency=wordF;
};
