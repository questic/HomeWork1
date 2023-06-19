#include "FileIO.h"
#include <iostream>

#define FILE_NAME "statistics.txt"


int main() {
    if (!IsFileExist(FILE_NAME)) {
        std::cout << "File does not exist. The file will be created automatically." << std::endl;

        CreateFile(FILE_NAME);

        std::cout << "File created." << std::endl;
    }

    if (!IsFileEmpty(FILE_NAME)) {
        std::cout << "File contents:" << std::endl; 

        PrintFileData(FILE_NAME);
    }

    GetStatisticsFromUserInput(FILE_NAME);

    return 0;
}
