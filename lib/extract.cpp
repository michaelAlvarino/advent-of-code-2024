#ifndef LIB_EXTRACT_DATA_TOOLS
#define LIB_EXTRACT_DATA_TOOLS

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

std::vector<std::string> extract(std::string filePath) {
    std::ifstream inputData;
    inputData.open(filePath);
    std::vector<std::string> data;
    if (!inputData.good()) {
        std::cout << "Unable to open file " << filePath << "." << std::endl;
        return data;
    }
    if (inputData.is_open()) {
        std::string line;
        int numLines = 0;
        while (std::getline(inputData, line)) {
            data.push_back(line);
            numLines++;
        }
        std::cout << "Read " << numLines << " rows." << std::endl;
    }
    inputData.close();
    return data;
}

void printData(std::vector<std::string> d) {
    for (auto &s : d) {
        std::cout << s << std::endl;
    }
}

#endif