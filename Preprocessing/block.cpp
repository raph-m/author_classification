#include "block.h"
#include <iostream>
#include <algorithm>
#include <vector>

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

// renvoie la liste des mots rencontrés (les mots étant définis grâce à l'ensemble des séparateurs)
// prend en compte les mots tronqués possibles : ne compte pas le 1er mot s'il n'y a pas un séparateur avant et le dernier s'il n'y a pas un séparateur après
void Block::updateDifferentWords() {

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
    this->differentWords = res;
}

// suppose d'avoir calculer differentWords avant
void Block::updateDifferentWordsCount(){
    this->differentWordsCount = this->differentWords.size();
}

// renvoie les mots rencontrés une seule fois (définis par la liste des séparateurs)
void Block::updateUnicWords() {

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
    this->unicWords = unic;
}

// suppose qu'on a déjà déterminé unicWords
void Block::updateUnicWordsCount(){
    this->unicWordsCount = this->unicWords.size();
}
