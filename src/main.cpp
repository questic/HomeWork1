#include "FileIO.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>

#define FILE_NAME "statistics.txt"


int main() {
    bool isWriting = true;
    std::stringstream inputData;

    std::cout.precision(3);

    if (!IsFileExist(FILE_NAME)) {
        std::cout << "File does not exist. The file will be created automatically." << std::endl;

        CreateFile(FILE_NAME);

        std::cout << "File created." << std::endl;
    }

    if (!IsFileEmpty(FILE_NAME)) {
        std::cout << "File contents:" << std::endl; 

        PrintFileData(FILE_NAME);
    }

    inputData << std::endl;

    while (isWriting) {
        int round = 1;
        float time;
        char commentChoice;
        std::string comment;

        while (round <= 5) {
            std::cout << "Enter your " << round << " check-in time" << std::endl;

            while (true) {
                if (std::cin >> time) {
                    break;
                }
                else {
                    std::cout << "Please enter a valid time" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            
            inputData << time << " ";
            round++;
        }

        std::cout << "Do you need a comment for this ride? y/n" << std::endl;

        while (true) {
            if (std::cin >> commentChoice && (commentChoice == 'y' || commentChoice == 'n')) {
                break;
            }
            else {
                std::cout << "Please enter a valid answer" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        
        if (commentChoice == 'y') {
            while (true) {
                if (std::cin >> comment) {
                    break;
                }
                else {
                    std::cout << "Please enter a valid comment" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if (commentChoice == 'n') {
            isWriting = false;
        }

        inputData << comment;
        isWriting = false; 
    }

    std::ofstream file;

    file.open(FILE_NAME, std::ios::app);
    file << inputData.rdbuf();
    file.close();

    std::cout << "Statistics written successfully." << std::endl;
}
