#ifndef HEAP_HEADER
#define HEAP_HEADER

#include <cstddef> // for size_t

// integer-only for now.
template <typename T>
class Heap {
public:
    Heap(size_t capacity, int (*comparator)(T a, T b));
    ~Heap();
    T pop();
    T peek();
    void insert(T v);

    int getSize();
    void print();
private:
    void bubbleDown();
    void bubbleUp();
    T* data;
    int size;
    int (*comparator)(T a, T b);
};

#endif