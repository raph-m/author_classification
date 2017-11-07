#ifndef TEXT_H
#define TEXT_H
#include <string>

class text
{
public:

    string title;
    string author;
    long id;


    text();
    text(string x, string y, long number);
};

#endif // TEXT_H
