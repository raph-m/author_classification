#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

std::map<int, std::string> createtxtFile(int iterations, std::string outputFileName){
    std::ifstream fichier("../data/final_index.json");
    int compteurMap = 0;
    std::map<int, std::string> idToAuthor;
    std::map<std::string, int> authorToId;

    if(fichier){ // checking if file opening worked
        std::string ligne;
        getline(fichier, ligne);
        fichier.close();

        // Delete the beggining and the end of the string
        ligne.erase(0, 2);
        ligne.erase(ligne.length() - 2, 2);

        // Determine the delimiter
        std::string delimiter = "}, {";
        size_t pos = 0;
        std::string token;
        int compteur;
        compteur = 0;
        while ((pos = ligne.find(delimiter)) != std::string::npos && compteur < iterations) {
            std::cout << "=============================" << std::endl;
            std::cout << "New text read in the database" << std::endl;
            std::cout << "Iteration: " << compteur << std::endl;
            token = ligne.substr(0, pos);

            size_t posInt = 0;
            text textIntern;
            std::string deliInter;

            // Get Title
            token.erase(0, 10);
            deliInter = "\", \"id\": \"";
            posInt = token.find(deliInter);
            textIntern.title = token.substr(0, posInt);
            std::cout << "Title acquired" << std::endl;

            // Get id of the text
            token.erase(0, posInt + 10);
            deliInter = "\", \"number_of_lines\": ";
            posInt = token.find(deliInter);
            char * pEnd;
            textIntern.id = std::strtol((token.substr(0, posInt)).c_str(), &pEnd, 10);
            std::cout << "Id of the text acquired" << std::endl;

            // Get number_of_lines
            token.erase(0, posInt + 21);
            deliInter = ", \"author\": \"";
            posInt = token.find(deliInter);
            textIntern.number_of_lines = std::strtol((token.substr(0, posInt)).c_str(), &pEnd, 10);
            std::cout << "Number of lines acquired" << std::endl;

            // Get author
            token.erase(0, posInt + 13);
            deliInter = "\"";
            posInt = token.find(deliInter);
            textIntern.author = token.substr(0, posInt);
            if (authorToId.count(textIntern.author) == 0){
                idToAuthor.insert(std::pair<int, string>(compteurMap, textIntern.author));
                authorToId.insert(std::pair<string, int>(textIntern.author, compteurMap));
                compteurMap += 1;
            }
            textIntern.idAuthor = authorToId[textIntern.author];
            std::cout << "Id Author: " << authorToId[textIntern.author] << " Author Name: " << textIntern.author << std::endl;
            std::cout << "Author acquired" << std::endl;

            ligne.erase(0, pos + delimiter.length());

            // Create blockList
            textIntern.createBlockList();
            std::cout << "BlockList acquired" << std::endl;

            // Create blocks from blockList (functions)
            for(int i=0; i< textIntern.blockList.size(); i++){
                textIntern.blockList[i].updateCharFrequency();
                textIntern.blockList[i].updateDifferentWordsCount();
                textIntern.blockList[i].updateSentenceCount();
                textIntern.blockList[i].updateUnicWordsCount();
                textIntern.blockList[i].updateWordCount();
                textIntern.blockList[i].updateWordFrequency();
                textIntern.blockList[i].updateSubordinationsCount();
                textIntern.blockList[i].updateWordLengthDeviation();
                textIntern.blockList[i].updateSentenceLengthDeviation();
            }
            std::cout << "Block's functions for BlockList processed" << std::endl;

            // Create features
            vector<Features> featuresIntern;
            featuresIntern = textIntern.agregate();
//            std::cout << text::floatToString(featuresIntern.charFrequency.size())<< std::endl;
//            std::cout << text::floatToString(featuresIntern.sentenceCount) << std::endl;
//            std::cout << text::floatToString(featuresIntern.wordCount) << std::endl;
//            std::cout << text::floatToString(featuresIntern.wordFrequency.size()) << std::endl;
            std::cout << "Features generated" << std::endl;

            // Implement the txt file
            for (int i=0;i<featuresIntern.size();i++){
                    featuresIntern.at(i).createcsvTrain();
            }

            compteur += 1;
        }
    }else{
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    return idToAuthor;
}

int preprocessingTest(std::string path,std::string filetype, std::string outputFileName){ //Update for each new feature
    // Open the file
    std::ifstream fichier(path.c_str(), std::ios::in);

    // Prepare the result
    std::string result = "";
    text finalText;

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
    std::cout << "Text read" << std::endl;

    // Create blockList
    int blockLength = 30000;
    std::vector<Block> textParsed;
    size_t numberOfLetters = result.length();
    for (int i = 0; i < numberOfLetters/blockLength; i++){
        // std::cout << "New block created" << std::endl;
        std::vector<char> block;
        for (int j = 0; j < blockLength; j++){
            block.push_back(char(result[i * blockLength + j]));
        }
        finalText.blockList.push_back(Block(i, block));
    }

    // Create blocks from blockList (functions)
    for(int i=0; i< finalText.blockList.size(); i++){
        finalText.blockList[i].updateCharFrequency();
        finalText.blockList[i].updateDifferentWordsCount();
        finalText.blockList[i].updateSentenceCount();
        finalText.blockList[i].updateUnicWordsCount();
        finalText.blockList[i].updateWordCount();
        finalText.blockList[i].updateWordFrequency();
        finalText.blockList[i].updateSubordinationsCount();
        finalText.blockList[i].updateWordLengthDeviation();
        finalText.blockList[i].updateSentenceLengthDeviation();
    }

    // Create features
    vector<Features> featuresIntern;
    featuresIntern = finalText.agregate();
    std::cout << "Features generated" << std::endl;

    // Implement the txt file
    std::string path2 = "../" + outputFileName + "."+filetype;
    std::ofstream myfile(path2.c_str());
    int lineCount = 0;
    if(myfile.is_open()){
        for (int i=0;i<featuresIntern.size();i++){
            featuresIntern.at(i).createcsv(outputFileName,filetype);
            lineCount=lineCount+1;
        }
    }
    return lineCount;
}
