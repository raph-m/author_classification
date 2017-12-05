#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>
#include <Preprocessing/buildtxt.cpp>

int main(int argc, char *argv[])
{
    int nbriteration = 100;
    std::map<int, std::string> idToAuthor;
    //idToAuthor = createTextFeatures(nbriteration);
    //createtxtFile(nbriteration, "results");
    preprocessingTest("../27.txt", "testResult");
    return 0;
}
