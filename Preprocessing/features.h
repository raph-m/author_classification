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
    vector<int> charFrequency;
    vector<int> wordFrequency;
    int wordCount;
    int sentenceCount;
    int differentWordsCount;
    int unicWordsCount;
    int subordinationsCount;



    Features();
    Features(long number, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC,int unicC,int diffC,int subC);
    void createcsv();

};

#endif // FEATURES_H
