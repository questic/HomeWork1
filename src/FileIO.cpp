#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

#define ROUND 5



bool IsFileExist(std::string fileName) {
    std::fstream file(fileName);
    return !file.fail() ? true : false;
}

void CreateFile(std::string fileName) {
    std::ofstream file(fileName);
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

void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float GetTimeFromUserInput() {
    float time;

    while (!(std::cin >> time)) {
        std::cout << "Please enter a valid time: " << std::endl;
        ClearInputBuffer();
    }

    return time;
}

char GetChoiceFromUserInput() {
    char choice;

    while (!(std::cin >> choice) || (choice != 'y' && choice != 'n')) {
        std::cout << "Please enter a valid answer" << std::endl;
        ClearInputBuffer();
    }

    return choice;
}

std::string GetCommentFromUserInput() {
    std::string comment;
    ClearInputBuffer();
    std::getline(std::cin, comment);

    return comment;
}

void WriteStatisticsToFile(std::string fileName, std::string data) {
    std::ofstream file(fileName, std::ios::app);

    if (!file) {
        std::cerr << "Failed to open file for writing: " << fileName << std::endl;
        return;
    }

    file << data;

    if (!file) {
        std::cerr << "Error occured while writing to file: " << fileName << std::endl; 
    }
    else {
        std::cout << "Statistics written successfully." << std::endl;
    }
}

void GetStatisticsFromUserInput(std::string fileName) {
    std::stringstream data;
    bool isWriting = true;

    while (isWriting) {
        for (int i = 1; i <= ROUND; ++i) {
            std::cout << "Enter your " << i << " check-in time:" << std::endl;
            float time = GetTimeFromUserInput();
            data << time << ' ';
        }

        std:: cout << "Do you need a comment for this ride? (y/n)" << std::endl;
        char commentChoice = GetChoiceFromUserInput();

        if (commentChoice == 'y') {
            std::cout << "Enter your comment" << std::endl;
            std::string comment = GetCommentFromUserInput();
            data << comment;
        }

        data << std::endl;

        WriteStatisticsToFile(fileName, data.str());

        std::cout << "Do you want to add more ride? (y/n): " << std::endl;
        char addMoreChoice = GetChoiceFromUserInput();

        if (addMoreChoice == 'n') {
            isWriting = false;
        }
    }
}
