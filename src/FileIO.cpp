#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <sstream>


bool IsFileExist(std::string fileName) {
    std::fstream file;

    file.open(fileName);

    return !file.fail() ? true : false;
}

void CreateFile(std::string fileName) {
    std::ofstream file(fileName);
    file.close();
}

bool IsFileEmpty(std::string fileName) {
    std::ifstream file(fileName);

    return file.peek() == EOF ? true : false;
}

void PrintFileData(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;

    while (!file.eof()) {
        std::getline(file, line);
        std::cout << line << std::endl;
    }
}
