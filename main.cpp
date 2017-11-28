#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

int main(int argc, char *argv[])
{

    text test0 ;
    test0.id = 27;
    std::cout<< test0.id << std::endl;
    test0.createBlockList();

    test0.blockList[0].updateDifferentWordsCount();
    test0.blockList[0].updateUnicWordsCount();

    std::cout<< std::to_string(test0.blockList[0].differentWordsCount) << std::endl;
    std::cout<< std::to_string(test0.blockList[0].unicWordsCount) << std::endl;

}
