#pragma once
#include "features.h"
#include "text.h"

Features::Features(){
}

//Features::Features(long number, std::vector<int> f1, std::vector<int> f2){
//    this->id = number;
//    this->charCount = f1;
//    this->wordCount = f2;
//}

Features::Features(long number, std::vector<float> wordF,int wordC,std::vector<float> charF,int sentenceC){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    this->id = number;
    this->charFrequency = charF;
    this->wordCount = wordC;
    this->sentenceCount = sentenceC;
    this->wordFrequency=wordF;
}
void Features::createcsv(){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    string name=text::intToString(id);
    std::ofstream myfile("../results.txt", std::ios::in);
    myfile.seekp(0, ios::end); // On se déplace à la fin du fichier
    myfile << name+",";
    myfile << text::floatToString(this->wordCount)+",";
    for (int i=0; i<charFrequency.size();i++){
        myfile << text::floatToString(this->charFrequency.at(i))+",";
    }
    for (int i=0; i<wordFrequency.size();i++){
        myfile << text::floatToString(this->wordFrequency.at(i))+",";
    }
    myfile << text::floatToString(this->sentenceCount);
    myfile << "\n";
    myfile.close();
}
;
