#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

int main(int argc, char *argv[])
{
    text test0 ;
    test0.id = 27;
    std::cout<< test0.id << std::endl;
    test0.createBlockList();

    test0.blockList[0].updateUnicWords();
    test0.blockList[0].updateDifferentWords();
    test0.blockList[0].updateDifferentWordsCount();
    test0.blockList[0].updateUnicWordsCount();
    test0.blockList[0].updateCharFrequency();
    test0.blockList[0].updateWordFrequency();

    std::cout<< text::intToString(test0.blockList[0].differentWordsCount) << std::endl;
    std::cout<< text::intToString(test0.blockList[0].unicWordsCount) << std::endl;
    std::cout<< text::intToString(test0.blockList[0].charFrequency.size()) << std::endl;
    std::cout<< text::intToString(test0.blockList[0].wordFrequency.size()) << std::endl;
}
