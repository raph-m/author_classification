#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>
#include "block.h"

class text
{
public:

    std::string title;
    std::string author;
    long id;
    std::vector<Block> blockList;


    text();
    text(std::string x, std::string y, long number);
};

#endif // TEXT_H
