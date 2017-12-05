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



    Features();
    Features(long number, long idAuthor, std::vector<int> wordF,int wordC,std::vector<int> charF,int sentenceC,int unicC,int diffC,int subC);
    void createcsv(std::string outputFileName);

};

#endif // FEATURES_H
