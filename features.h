#ifndef FEATURES_H
#define FEATURES_H


class Features
{
public:

    long id;
    int* charCount;
    int* wordCount;

    Features();
    Features(long number, int* f1, int* f2);
};

#endif // FEATURES_H
