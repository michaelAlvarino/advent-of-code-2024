#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <regex>
#include <iterator>

#include "../lib/extract.cpp"
#include "../ds/heap.cpp"

using namespace std;

vector<string> getData(string fname) {
    vector<string> data = extract(fname);
    // need to find everything that matches "mul(x,y)"

    return data;
}

int comparator(tuple<int, string, sregex_iterator> a, tuple<int, string, sregex_iterator> b) {
    int one = get<0>(a);
    int two = get<0>(b);
    if (one < two) { return -1; }
    if (one > two) { return 1; }
    return 0;
}

bool isDoCall(tuple<int, string, sregex_iterator> t) {
    return get<1>(t) == "do()";
}

bool isDontCall(tuple<int, string, sregex_iterator> t) {
    return get<1>(t) == "don't()";
}

int multiply(tuple<int, string, sregex_iterator> t) {
    string mulCall = get<1>(t);
    cout << mulCall << endl;
    regex number("\\d+");
    sregex_iterator it(mulCall.begin(), mulCall.end(), number);
    int first = stoi(it->str());
    it++;
    int second = stoi(it->str());
    int x = first * second;
    return x;
}

int transform(vector<string> data) {
    // idea: make a heap of 3 heaps. Each sub-heap will parse the input string for
    // different data: either mul, do, or dont. The first value in the tuple will be
    // the position of the next appearance of that value. So we can continually pop
    // values from the "outer" heap, 
    Heap<tuple<int, string, sregex_iterator>> h = Heap<tuple<int, string, sregex_iterator>>(3, comparator);
    regex mul("mul\\([0-9]*,[0-9]*\\)");
    regex dos("do\\(\\)");
    regex dont("don\'t\\(\\)");
    sregex_iterator end;
    int v = 0;
    bool doMultiply = true;
    for (auto& s : data) {
        auto doCalls = sregex_iterator(s.begin(), s.end(), dos);
        auto dontCalls = sregex_iterator(s.begin(), s.end(), dont);
        auto mulCalls = sregex_iterator(s.begin(), s.end(), mul);
        tuple<int, string, sregex_iterator> t = make_tuple(doCalls->position(), doCalls->str(), doCalls);
        tuple<int, string, sregex_iterator> t2 = make_tuple(dontCalls->position(), dontCalls->str(), dontCalls);
        tuple<int, string, sregex_iterator> t3 = make_tuple(mulCalls->position(), mulCalls->str(), mulCalls);
        h.insert(t);
        h.insert(t2);
        h.insert(t3);
        while (h.getSize() > 0) {
            tuple<int, string, sregex_iterator> heapMin = h.pop();
            if (isDoCall(heapMin)) {
                cout << "do()" << endl;
                doMultiply = true;
            } else if(isDontCall(heapMin)) {
                cout << "don't()" << endl;
                doMultiply = false;
            } else {
                if (doMultiply) {
                    v = v + multiply(heapMin);
                }
            }
            sregex_iterator s = get<2>(heapMin);
            ++s;
            int pos = s->position();
            string next = s->str();
            if (s != end) {
                tuple<int, string, sregex_iterator> tmp = make_tuple(pos, next, s);
                h.insert(tmp);
            }
        }
    }
    return v;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Include the file name when running the program, plz" << endl;
        return 1;
    }
    cout << argv[1] << endl;
    vector<string> data = getData(argv[1]);
    int result = transform(data);
    cout << "All multiplications sum to: " << result << endl;
    /*
    178538786
    112796423 ^
    107519039
    102467299
    */
    return 0;
}