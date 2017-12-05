#pragma once
#include "text.h"



text::text()
{
}

text::text(std::string x, std::string y,long number,std::vector<Block> blockList)
{
    this->author = x;
    this->title = y;
    this->id = number;
    this->blockList=blockList;
}

std::string text::getText(int id){
    // Find the file
    string str = text::intToString(id);
    std::string filePath = std::string("../data/books/") + str + ".txt";

    // Open the file
    std::ifstream fichier(filePath.c_str(), std::ios::in);

    // Prepare the result
    std::string result = "";

    if(fichier){  // si l'ouverture a fonctionné
        std::string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            size_t lastLetter = ligne.length() - 1;
            if (ligne[lastLetter] == '-'){
                ligne.erase(lastLetter);
            }
            result = result + " " + ligne;
        }
        fichier.close();
    }else{
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    return result;
}

std::vector<Block> text::parseTextToBlock(int id){
    int blockLength = 30000;
    std::string textToParse = text::getText(id);
    std::vector<Block> textParsed;
    size_t numberOfLetters = textToParse.length();
    for (int i = 0; i < numberOfLetters/blockLength; i++){
        std::vector<char> block;
         //std::cout << "New block" << std::endl;
        for (int j = 0; j < blockLength; j++){
            block.push_back(char(textToParse[i * blockLength + j]));
        }
        // Create Block id
                int times = 1;
                int idBlock;
                while(times <= i){
                    times *= 10;
                }
                idBlock = id*times + i;
        textParsed.push_back(Block(idBlock,block));
    }
    return(textParsed);
}

void text::printMap(std::map<std::string, std::string> mapIn){
    for (std::map<std::string, std::string>::iterator it = mapIn.begin(); it != mapIn.end(); it++){
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void text::createBlockList(){
    this->blockList = parseTextToBlock(this->id);
}

string text::intToString(long a){
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

string text::floatToString(float a){
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

vector<Features> text::agregate(){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    int l=blockList.size();
    vector<Features> res;
    std::vector<float> wordF(100,0);
    int wordC=0;
    std::vector<float> charF(95,0);
    int sentenceC=0;
    for (int i=0;i<l;i++){
        res.push_back(Features(blockList.at(i).id, idAuthor,blockList.at(i).wordFrequency,blockList.at(i).wordCount,blockList.at(i).charFrequency,blockList.at(i).sentenceCount,blockList.at(i).unicWordsCount,blockList.at(i).differentWordsCount,blockList.at(i).subordinationsCount));
    }
    return res;
}
