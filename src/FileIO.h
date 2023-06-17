#pragma once
#include <string>
#include <sstream>


bool IsFileExist(std::string fileName);
void CreateFile(std::string fileName);
bool IsFileEmpty(std::string fileName);
void PrintFileData(std::string fileName);