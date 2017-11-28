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
    std::string filePath = std::string("../data/books/") + str + ".txt"; //A VERFIER///////////////////////

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

        // std::cout << result << std::endl;
    }
    return result;
}

std::vector<Block> text::parseTextToBlock(int id){
    std::string textToParse = text::getText(id);
    std::vector<Block> textParsed;
    size_t numberOfLetters = textToParse.length();
    for (int i = 0; i < numberOfLetters/1000; i++){
        std::vector<char> block;
         //std::cout << "New block" << std::endl;
        for (int j = 0; j < 1000; j++){
            // std::cout << textToParse[i*j] << " ";
            block.push_back(char(textToParse[i * 1000 + j]));
        }
        textParsed.push_back(Block(id,block));
        // std::cout << std::endl;
    }
    return(textParsed);
}

std::vector<text> readJson(){
    std::ifstream fichier("../data/final_index.json");   // A VERIFIER   ///////////////////////////////////////////////////
    std::vector<text> vectJson;
    if(fichier){ // si l'ouverture a fonctionné
        std::string ligne;
        getline(fichier, ligne);
        fichier.close();
        // std::cout << ligne << std::endl;

        // Delete the beggining and the end of the string
        ligne.erase(0, 2);
        ligne.erase(ligne.length() - 2, 2);

        // Determine the delimiter
        std::string delimiter = "}, {";
        size_t pos = 0;
        std::string token;
        while ((pos = ligne.find(delimiter)) != std::string::npos) {
            token = ligne.substr(0, pos);
            // std::cout << token << std::endl;

            size_t posInt = 0;
            text textIntern;
            std::string deliInter;
            // Get Title
            token.erase(0, 10);
            deliInter = "\", \"id\": \"";
            posInt = token.find(deliInter);
            textIntern.title = token.substr(0, posInt);
            // Get id
            token.erase(0, posInt + 10);
            deliInter = "\", \"number_of_lines\": ";
            posInt = token.find(deliInter);
            textIntern.id = token.substr(0, posInt);
            // Get number_of_lines
            token.erase(0, posInt + 21);
            deliInter = ", \"author\": \"";
            posInt = token.find(deliInter);
            textIntern.number_of_lines = token.substr(0, posInt);
            // Get author
            token.erase(0, posInt + 13);
            deliInter = "\"";
            posInt = token.find(deliInter);
            textIntern.author = token.substr(0, posInt);

            ligne.erase(0, pos + delimiter.length());

            textIntern.createBlockList();

            vectJson.push_back(textIntern);
        }
        // std::cout << ligne << std::endl;
    }else{
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    return(vectJson);
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

Features text::agregate(){ // A UPDATER A CHAQUE FOIS QU ON AJOUTE UN FEATURE //
    int l=blockList.size();
    std::vector<int> wordF;
    int wordC;
    std::vector<int> charF;
    int sentenceC;
    for (int i=0;i<l;i++){
        wordC=wordC+(blockList.at(i).wordCount)/l;
        for (int j=0;j<blockList.at(i).charFrequency.size();j++){
            charF.at(j)= charF.at(j)+(blockList.at(i).charFrequency.at(j))/l;
        }
        sentenceC+=(blockList.at(i).sentenceCount)/l;

        //wordF.at(j)=0; //en attendant Luca
    }
    return Features(id,wordF,wordC,charF,sentenceC);
}


