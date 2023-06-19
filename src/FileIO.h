#pragma once
#include <string>
#include <sstream>


bool IsFileExist(std::string fileName);
void CreateFile(std::string fileName);
bool IsFileEmpty(std::string fileName);
void PrintFileData(std::string fileName);
void ClearInputBuffer();
float GetTimeFromUserInput();
char GetChoiceFromUserInput();
std::string GetCommentFromUserInput();
void WriteStatisticsToFile(std::string fileName, std::string data);
void GetStatisticsFromUserInput(std::string fileName);