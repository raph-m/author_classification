#include "block.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <QDir>
using namespace std;

Block::Block()
{
}

Block::Block(long number, vector<char> text){
    this->id = number;
    this->textUnit = text;
}


void Block::updateWordCount(){
    int cmpt = 1;
    for (vector<char>::iterator it = this->textUnit.begin(); it != this->textUnit.end(); ++it) {
        if (*it == ' ' || *it == '/') {
            cmpt++;
        }
    }
    this->wordCount = cmpt;
}

void Block::updateSentenceCount(){//sentenceCount is set to the number of sentences, separators are '.', '!', '?', or '-'
    sentenceCount = 0;
    vector<char> separators ; //vector with all separators
    separators.push_back('.');
    separators.push_back('!');
    separators.push_back('?');
    separators.push_back('-');

    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int mem = 0; //turns to 1 if a separator is met


    for (int i = 0; i<l; i++){
        if (find(separators.begin(), separators.end(), textUnit[i]) != separators.end()){//we check whether the char is a separator
            if (!mem){ //if the previous character was not a separator, it means that we reached the end of a sentence
                sentenceCount+=1;
                mem=1;
            }
        }
        else{
            mem=0;
        }
    }
}

void Block::updateCharFrequency(){// takes into account characters from 32 (space) to 126 (~),charFrequency is set to an int vector of size 95
    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int ascii;
    vector<int> res(95,0);
    for (int i = 0; i<l; i++){
        ascii = (int) textUnit[i];
        if ((ascii>=32)&(ascii<=126)){
            res[ascii-32]+=1; //we add 1 to the corresponding indicator in the vector
        }
    }
    charFrequency = res;
}

void Block::updateWordFrequency(){ // returns an int vector of size 100 (apparitions des 100 mots les plus utilisés)
    vector<char> text = textUnit;
    vector<char> separators ; //vector with all separators
    separators.push_back(' ');
    separators.push_back('.');
    separators.push_back(',');
    separators.push_back(';');
    separators.push_back(':');
    separators.push_back('\''); //the apostrophe
    separators.push_back('!');
    separators.push_back('?');
    // - is not considered as a separator : up-to-date will be one word
    // we only work with minuscules, using the tolower function (at char level)

    // Prepare the vector bibli of the 100 common words (load the file)
    std::string filePath = "../data/100mostCommonWord.txt"; //fichier dans le dossier data, même emplacement
    std::ifstream fichier(filePath,ios::in);

    vector<std::string> bibli;

    if(fichier.is_open()){  // si l'ouverture a fonctionné
        std::string ligne;
        while(getline(fichier, ligne))
        {
            bibli.push_back(ligne);
        }
        fichier.close();
    }else{
        std::cout << "Impossible d'ouvrir la liste des 100 mots ! (Ask Luca)" << std::endl;
    }

    //Browse the text
    int l = text.size(); //always 1000, but we never know
    vector<int> res(100,0); // result vector of 100 int initialized to 0

    std::string word = ""; //we will extract the words one by one and check whether they belong to bibli

    for (int i = 0; i<l; i++){
            text[i]=tolower(text[i]); //minuscules !
            //we check whether the char is a separator
            if (find(separators.begin(), separators.end(), text[i]) != separators.end()){
                //if we are here then it's the end of a word ; we check if it's in bibli
                int indice = 0;
                while(indice<100){
                    if (bibli[indice]==word){

                        res[indice]+=1;
                        break;
                    }
                    indice++;
                }
                word = ""; // then we reinitialize word
            }
            else{ //if we have not met any separator, then we just fill word
                word=word+text[i];
            }
            cout << word << endl;
        }

    wordFrequency = res;
}




