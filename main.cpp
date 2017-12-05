#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>
#include <Preprocessing/buildtxt.cpp>

int main(int argc, char *argv[])
{
    int nbriteration = 10;
    std::map<int, std::string> idToAuthor;
    //idToAuthor = createTextFeatures(nbriteration);
    createtxtFile(nbriteration);
    return 0;
}
