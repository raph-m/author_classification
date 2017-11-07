#include "text.h"
#include <string>

text::text()
{
}

text::text(std::string x, std::string y,long number)
{
    this->author = x;
    this->title = y;
    this->id = number;
}
