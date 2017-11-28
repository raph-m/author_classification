#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

int main(int argc, char *argv[])
{
    text test0 ;
    test0.id = 27;
    std::cout<< test0.id << std::endl;
    test0.createBlockList();

    for(int i=0; i< test0.blockList.size();i++){
        test0.blockList[i].updateCharFrequency();
        test0.blockList[i].updateDifferentWords();
        test0.blockList[i].updateDifferentWordsCount();
        test0.blockList[i].updateSentenceCount();
        test0.blockList[i].updateUnicWords();
        test0.blockList[i].updateUnicWordsCount();
        test0.blockList[i].updateWordCount();
        test0.blockList[i].updateWordFrequency();
    }


    Features test1;
    test1= test0.agregate();
}
