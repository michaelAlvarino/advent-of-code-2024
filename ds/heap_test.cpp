#include <cassert>

#include "heap.cpp"

int cmp(int a, int b) {
    if (a < b) { return -1; }
    if (a > b) { return 1; }
    return 0;
}

int main(int argc, char* argv[]) {
    Heap h = Heap<int>(5, cmp);
    assert(h.getSize() == 0);
    for(int i = 5; i > 0; i--) {
        h.insert(i);
    }
    assert(h.getSize() == 5);
    assert(h.peek() == 1);
    assert(h.pop() == 1);
    assert(h.pop() == 2);
    assert(h.pop() == 3);
    h.insert(1);
    assert(h.pop() == 1);
    assert(h.pop() == 4);
    assert(h.pop() == 5);
    assert(h.getSize() == 0);

}