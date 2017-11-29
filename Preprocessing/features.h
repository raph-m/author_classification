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
    std::vector<float> wordFrequency;
    int wordCount;
    std::vector<float> charFrequency;
    int sentenceCount;

    Features();
    Features(long number, std::vector<float> wordF,int wordC,std::vector<float> charF,int sentenceC);
    void createcsv();

};

#endif // FEATURES_H
