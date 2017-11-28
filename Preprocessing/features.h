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
    std::vector<int> wordFrequency;
    int wordCount;
    std::vector<int> charFrequency;
    int sentenceCount;

    Features();
    Features(long number, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC);
    void createcsv();

};

#endif // FEATURES_H
