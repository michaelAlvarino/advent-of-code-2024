#include <iostream>
#include <string>

#include "../lib/extract.cpp"

using namespace std;

int transform(vector<vector<char>> grid) {
    /*
    Should probably do something like:
    1. Scan for all the X's
    2. If I find one, dfs to find all the XMAS
    */
    return 0;
}

int main(int argc, char* argv[]) {
    vector<string> data = extract(argv[1]);
    int rows = data.size();
    vector<vector<char>> grid;
    for (int row = 0; row < rows; row++) {
        string thisRow = data[row];
        vector<char> line;
        for (char c : thisRow) {
            line.push_back(c);
        }
        grid.push_back(line);
    }
    int result = transform(grid);
    return 0;
}
