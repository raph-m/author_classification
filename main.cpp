#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>
#include <Preprocessing/buildtxt.cpp>

int main(int argc, char *argv[]){
    int nbriteration = 6;
    std::map<int, std::string> idToAuthor;
    //idToAuthor = createTextFeatures(nbriteration);
    //createtxtFile(nbriteration, "results"); //pour entrainer sur le dataset gutemberg. Ne marche que si le dataset+ fichier vide "results.txt" vide à la racine du projet
    int lineCount = 0; //nbre de ligne du fichier csv qui résultera du texte test
    lineCount=preprocessingTest("../27.txt","txt", "testResult"); //pour tester un fichier .txt (à la racine du projet) dont l'auteur est à déterminer
    return 0;
}
