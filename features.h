#ifndef FEATURES_H
#define FEATURES_H


class Features
{
public:

    long id;
    int* charCount;
    int* wordCount;
    int sentenceCount;

    Features();
    Features(long number, int* f1, int* f2);
    Features(long number, int* f1, int* f2,int f3);

};

#endif // FEATURES_H
