#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>
#include <Preprocessing/buildtxt.cpp>

int main(int argc, char *argv[]){
    int nbriteration = 6;
    std::map<int, std::string> idToAuthor;
    //idToAuthor = createTextFeatures(nbriteration);
    int lineCount = 0; //nbre de ligne du fichier csv qui résultera du texte test
    lineCount=preprocessingTest("../1013.txt", "txt", "testResult");
    return 0;
}
