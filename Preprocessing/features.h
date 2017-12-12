#ifndef FEATURES_H
#define FEATURES_H
#include <string>
#include <vector>
#include "block.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>


class Features
{
public:

    long id;
    long idAuthor;
    vector<int> charFrequency;
    vector<int> wordFrequency;
    int wordCount;
    int sentenceCount;
    int differentWordsCount;
    int unicWordsCount;
    int subordinationsCount;
    float wordLengthDeviation;
    float sentenceLengthDeviation;


    Features();
    Features(long number, long idAuthor, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC,int unicC,int diffC,int subC,float devW,float devS);
    void createcsv(std::string outputFileName);
    void createcsvTrain();

};

#endif // FEATURES_H
