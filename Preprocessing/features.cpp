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

Features::Features(long number, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC,int unicC,int diffC,int subC){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    this->id = number;
    this->charFrequency = charF;
    this->wordCount = wordC;
    this->sentenceCount = sentenceC;
    this->wordFrequency=wordF;
    this->unicWordsCount=unicC;
    this->differentWordsCount=diffC;
    this->subordinationsCount=subC;
}
void Features::createcsv(){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    string name=text::intToString(id);
    std::ofstream myfile("../results.txt", std::ios::in);
     std::ofstream myfile2("../id.txt", std::ios::in);
    myfile.seekp(0, ios::end); // On se déplace à la fin du fichier
    myfile2.seekp(0, ios::end); // On se déplace à la fin du fichier
    myfile2 << name+"\n";
    myfile << text::floatToString(this->wordCount)+",";
    for (int i=0; i<charFrequency.size();i++){
        myfile << text::floatToString(this->charFrequency.at(i))+",";
    }
    for (int i=0; i<wordFrequency.size();i++){
        myfile << text::floatToString(this->wordFrequency.at(i))+",";
    }
    myfile << text::floatToString(this->sentenceCount)+",";
    myfile << text::floatToString(this->unicWordsCount)+",";
    myfile << text::floatToString(this->subordinationsCount)+",";
    myfile << text::floatToString(this->differentWordsCount);
    myfile << "\n";
    myfile.close();
    myfile2.close();
};
