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
        if (*it == ' ') {
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

    int l = textUnit.size(); //always 1000, but we never know what may happen :)
    int mem = 0; //turns to 1 if a separator is met


    for (int i = 0; i<l; i++){
        if (textUnit[i]==separators[0] || textUnit[i]==separators[1] || textUnit[i]==separators[2]){//we check whether the char is a separator
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

// renvoie la liste des mots rencontrés (les mots étant définis grâce à l'ensemble des séparateurs)
// prend en compte les mots tronqués possibles : ne compte pas le 1er mot s'il n'y a pas un séparateur avant et le dernier s'il n'y a pas un séparateur après
void Block::updateDifferentWordsCount() {


    // caractères séparateurs de mots
    vector<char> separators = vector<char>();
    separators.push_back(' ');
    separators.push_back('.');
    separators.push_back(',');
    separators.push_back('!');
    separators.push_back('?');
    separators.push_back('\'');
    separators.push_back('(');
    separators.push_back(')');

    vector<string> res = vector<string>();
    string temp = string();
    vector<char>::iterator it = this->textUnit.begin();

    // on ne compte pas le premier mot s'il n'y a pas un séparateur avant (évacue les mots tronqués en début de bloc)
    while (find(separators.begin(), separators.end(), *it) == separators.end()) {
        it++;
    }

    for (it; it != this->textUnit.end(); ++it) {
        if (find(separators.begin(), separators.end(), *it) == separators.end()) {
            temp += *it;
        }
        else if (temp != string()) { // évite d'ajouter une string vide si 2 séparateurs consécutifs
            if (find(res.begin(), res.end(), temp) == res.end()) {
                res.push_back(temp);
            }
            temp = string();
        }
    }
    this->differentWordsCount = res.size();
}

// renvoie les mots rencontrés une seule fois (définis par la liste des séparateurs)
void Block::updateUnicWordsCount() {

    // caractères séparateurs de mots
    vector<char> separators = vector<char>();
    separators.push_back(' ');
    separators.push_back('.');
    separators.push_back(',');
    separators.push_back('!');
    separators.push_back('?');
    separators.push_back('\'');
    separators.push_back('(');
    separators.push_back(')');

    vector<string> unic = vector<string>(); // mots rencontrés une seule fois
    vector<string> used = vector<string>(); // mots rencontrés plusieurs fois
    string temp = string();
    vector<char>::iterator it = this->textUnit.begin();

    // on ne compte pas le premier mot s'il n'y a pas un séparateur avant (évacue les mots tronqués en début de bloc)
    while (find(separators.begin(), separators.end(), *it) == separators.end()) {
        it++;
    }

    for (it; it != this->textUnit.end(); ++it) {
        if (find(separators.begin(), separators.end(), *it) == separators.end()) {
            temp += *it;
        }
        else if (temp != string()) { // évite d'ajouter une string vide si 2 séparateurs consécutifs
            if (find(unic.begin(), unic.end(), temp) == unic.end() && find(used.begin(), used.end(), temp) == used.end()) { // temp ne se trouve pas dans unic ni used: il est nouveau
                unic.push_back(temp);
            }
            else if (find(unic.begin(), unic.end(), temp) != unic.end()) { // temp a déjà été rencontré une seule fois
                unic.erase(find(unic.begin(), unic.end(), temp));
                used.push_back(temp);
            }
            temp = string();
        }
    }
    this->unicWordsCount = unic.size();
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
    std::string filePath = "../author_classification/Preprocessing/100mostCommonWord.txt";
    std::ifstream fichier(filePath.c_str(),ios::in);

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
        }

    wordFrequency = res;
}

void Block::updateSubordinationsCount() {

    // conjonctions de subordination
    vector<string> sub = vector<string>();
    sub.push_back("after");
    sub.push_back("although");
    sub.push_back("as");
    sub.push_back("because");
    sub.push_back("before");
    sub.push_back("even");
    sub.push_back("how");
    sub.push_back("if");
    sub.push_back("inasmuch");
    sub.push_back("lest");
    sub.push_back("now");
    sub.push_back("once");
    sub.push_back("provided");
    sub.push_back("rather");
    sub.push_back("since");
    sub.push_back("so");
    sub.push_back("supposing");
    sub.push_back("than");
    sub.push_back("that");
    sub.push_back("though");
    sub.push_back("till");
    sub.push_back("unless");
    sub.push_back("until");
    sub.push_back("when");
    sub.push_back("whenever");
    sub.push_back("where");
    sub.push_back("whereas");
    sub.push_back("wherever");
    sub.push_back("whether");
    sub.push_back("which");
    sub.push_back("while");
    sub.push_back("who");
    sub.push_back("whoever");
    sub.push_back("why");

    // caractères séparateurs de mots
    vector<char> sep = vector<char>();
    sep.push_back(' ');
    sep.push_back('.');
    sep.push_back(',');
    sep.push_back('!');
    sep.push_back('?');
    sep.push_back('\'');
    sep.push_back('(');
    sep.push_back(')');

    int res = 0;
    string temp = string();
    vector<char>::iterator it = this->textUnit.begin();

    // on ne compte pas le premier mot s'il n'y a pas un séparateur avant (évacue les mots tronqués en début de bloc)
    while (find(sep.begin(), sep.end(), *it) == sep.end()) {
        it++;
    }

    for (it; it != this->textUnit.end(); ++it) {
        if (find(sep.begin(), sep.end(), *it) == sep.end()) {
            temp += *it;
        }
        else if (temp != string()) { // évite d'ajouter une string vide si 2 séparateurs consécutifs
            if (find(sub.begin(), sub.end(), temp) != sub.end()) {
                res++;
            }
            temp = string();
        }
    }
    subordinationsCount = res;
}

void Block::updateWordLengthDeviation() {
    // caractères séparateurs de mots
    vector<char> sep = vector<char>();
    sep.push_back(' ');
    sep.push_back('.');
    sep.push_back(',');
    sep.push_back('!');
    sep.push_back('?');
    sep.push_back('\'');
    sep.push_back('(');
    sep.push_back(')');

    float mean = 0;
    float variance = 0;
    vector<float> lengths = vector<float>();
    string temp = string();
    vector<char>::iterator it1 = this->textUnit.begin();

    // on ne compte pas le premier mot s'il n'y a pas un séparateur avant (évacue les mots tronqués en début de bloc)
    while (find(sep.begin(), sep.end(), *it1) == sep.end()) {
        it1++;
    }

    for (it1; it1 != this->textUnit.end(); ++it1) {
        if (find(sep.begin(), sep.end(), *it1) == sep.end()) {
            temp += *it1;
        }
        else if (temp != string()) { // évite d'ajouter une string vide si 2 séparateurs consécutifs
            lengths.push_back(temp.size());
            mean += temp.size();
            temp = string();
        }
    }

    mean = mean / lengths.size();
    vector<float>::iterator it2 = lengths.begin();
    for (it2; it2 != lengths.end(); ++it2) {
        variance += (*it2-mean)*(*it2-mean);
    }
    wordLengthDeviation = sqrt(variance/lengths.size());
}

void Block::updateSentenceLengthDeviation(){
    // caractères séparateurs de phrases
    vector<char> sep = vector<char>();
    sep.push_back('.');
    sep.push_back('!');
    sep.push_back('?');

    float mean = 0;
    float variance = 0;
    vector<float> lengths = vector<float>();
    string temp = string();
    vector<char>::iterator it1 = this->textUnit.begin();

    // on ne compte pas la premiere phrase s'il n'y a pas un séparateur avant (évacue les mots tronqués en début de bloc)
    while (find(sep.begin(), sep.end(), *it1) == sep.end()) {
        it1++;
    }

    for (it1; it1 != this->textUnit.end(); ++it1) {
        if (find(sep.begin(), sep.end(), *it1) == sep.end()) {
            temp += *it1;
        }
        else if (temp != string()) { // évite d'ajouter une string vide si 2 séparateurs consécutifs
            lengths.push_back(temp.size());
            mean += temp.size();
            temp = string();
        }
    }

    mean = mean / lengths.size();
    vector<float>::iterator it2 = lengths.begin();
    for (it2; it2 != lengths.end(); ++it2) {
        variance += (*it2 - mean)*(*it2 - mean);
    }
    sentenceLengthDeviation = sqrt(variance/lengths.size());
}
