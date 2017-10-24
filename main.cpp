#include <QCoreApplication>
#include "testgit.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}

