#pragma once
#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>
#include "block.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>


class text
{
public:

    std::string title;
    std::string author;
    long id;
    std::vector<Block> blockList;


    text();
    text(std::string x, std::string y, long number,std::vector<Block> blockList);
    string getText(int id);
    std::vector<Block> parseTextToBlock(int id);
    std::vector<std::map<std::string, std::string> > readJson();
    void printMap(std::map<std::string, std::string> mapIn);
    void createBlockList();
    static string intToString(long a);
};

#endif // TEXT_H
