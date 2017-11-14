#include <QCoreApplication>
#include "testgit.h"
#include "block.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}

