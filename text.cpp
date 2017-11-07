#include "text.h"
#include <string>

text::text()
{
}

text::text(string x, string y,long number)
{
    this->author = x;
    this->title = y;
    this->id = number;
}
