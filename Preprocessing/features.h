#ifndef FEATURES_H
#define FEATURES_H
#include <vector>

class Features
{
public:

    long id;
    std::vector<int> charCount;
    std::vector<int> wordCount;
    int sentenceCount;

    Features();
    Features(long number, std::vector<int> f1, std::vector<int> f2);
    Features(long number, std::vector<int> f1, std::vector<int> f2,int f3);

};

#endif // FEATURES_H
