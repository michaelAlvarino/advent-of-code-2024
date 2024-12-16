#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string rowToString(std::vector<int> row) {
    std::string strrep;
    for (auto &val : row) {
        strrep.append(std::to_string(val));
        strrep.append(",");
    }
    return strrep;
}

std::vector<std::vector<int>> extract(std::string filePath) {
    std::ifstream inputData;
    inputData.open(filePath);
    std::vector<std::vector<int>> data;
    if (inputData.is_open()) {
        std::string line;
        int numLines = 0;
        while (std::getline(inputData, line)) {
            std::vector<int> row;
            std::stringstream stream(line);
            std::string chunk;
            while(stream >> chunk) {
                row.push_back(std::stoi(chunk));
            }
            data.push_back(row);
            numLines++;
        }
        std::cout << "Read " << numLines << " rows." << std::endl;
    }
    inputData.close();
    return data;
}

std::vector<int> copyAndRemove(std::vector<int> original, int idxToRemove) {
    std::vector<int> v(original.size() - 1);
    for (int i=0; i < original.size(); i++) {
        if (i == idxToRemove) {
            continue;
        }
        v[i] = original[i];
    }
    return v;
}

bool isSafe(std::vector<int> row) {
    if (row.size() < 2) {
        return true;
    }
    bool isIncreasing = true;
    for (int i=1; i < row.size(); i++) {
        int d = row[i-1] - row[i];
        if (d == 0) {
            // std::cout << "Row is unsafe because of two equal numbers in row "
            //     << rowToString(row)
            //     << std::endl;
            return false;
        }
        if (i == 1 && d > 0) {
            isIncreasing = false;
        } else {
            if (d > 0 && isIncreasing) {
                // std::cout << "Supposed to be increasing but went from " 
                //     << row[i-1]
                //     << " to " 
                //     << row[i]
                //     << " for row "
                //     << rowToString(row)
                //     << std::endl;
                return false;
            }
            if (d < 0 && !isIncreasing) {
                return false;
            }
        }
        int diff = std::abs(d);
        if (diff < 1 || diff > 3) {
            // std::cout << "Row difference outside bounds. Got absolute value of "
            //     << diff
            //     << " between " << row[i-1] << " and " << row[i]
            //     << " for row " << rowToString(row) << std::endl;
            return false;
        }
    }
    return true;
}

bool isAnySubsetSafe(std::vector<int> row) {

    for (int i=0; i < row.size(); i++) {
        std::vector<int> v(row);
        v.erase(v.begin() + i);
        if (isSafe(v)) {
            return true;
        }
    }
    return false;
}

int isSafeInt(std::vector<int> row) {
    return int(isAnySubsetSafe(row));
}

int transform(std::vector<std::vector<int>> data) {
    std::vector<int> results(data.size());
    std::transform(data.begin(), data.end(), results.begin(), isSafeInt);
    return std::accumulate(results.begin(), results.end(), 0);
}

int main(int argc, char* argv[]){
    std::cout << "Starting..." << std::endl;
    if (argc < 2) {
        std::cout << "Please specify a filename"
            << std::endl
            << "e.x. advent-of-code data.txt"
            << std::endl;
        return 0;
    }
    for(int i=0; i < argc; i++) {
        std::cout << "\t" << argv[i] << std::endl;
    }
    std::cout << "Reading data from disc" << std::endl;
    std::vector<std::vector<int>> data = extract(argv[1]);
    std::cout << "Done reading data" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Data size: " << data.size() << std::endl;
    int sum = transform(data);
    std::cout << "Found " << sum << " safe data points." << std::endl;
    return 0;
}
