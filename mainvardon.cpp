#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

int mainvardon(int argc, char *argv[])
{

    text test0;
    test0.id = 27;
    std::cout<< test0.id << std::endl;
    test0.createBlockList();
    std::vector<text> vectJson;
    vectJson = text::readJson();
    for (std::vector<text>::iterator textIt = vectJson.begin(); textIt != vectJson.end(); textIt++){
        for (std::vector<Block>::iterator blockIt = textIt->blockList.begin(); blockIt != textIt->blockList.end(); blockIt++){
            for (std::vector<char>::iterator charIt = blockIt->textUnit.begin(); charIt != blockIt->textUnit.end(); charIt++){
                std::cout<< *charIt << std::endl;
            }
        }
    }
    return 0;
}
