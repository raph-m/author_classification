#include <QCoreApplication>
#include <iostream>
#include <Preprocessing/text.h>

int main(int argc, char *argv[])
{

    text test0 ;
    test0.id = 27;
    std::cout<< test0.id << std::endl;
    std::cout<< test0.author << std::endl;
    std::cout<< test0.title << std::endl;
    test0.createBlockList();



}

