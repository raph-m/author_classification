#ifndef TEXT_H
#define TEXT_H
#include <string>

class text
{
public:

    std::string title;
    std::string author;
    long id;


    text();
    text(std::string x, std::string y, long number);
};

#endif // TEXT_H
