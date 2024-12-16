#include <iostream>

#include "heap.hpp"

using namespace std;

template <typename T>
Heap<T>::Heap(size_t capacity, int (*c)(T a, T b)) {
    comparator = c;
    data = new T[capacity+1];
    size = 0;
}

template <typename T>
Heap<T>::~Heap() {
    delete[] data;
}

template <typename T>
T Heap<T>::peek() {
    return data[1];
}

template <typename T>
T Heap<T>::pop() {
    T x = data[1];
    T l = data[size];
    data[1] = l;
    size--;
    bubbleDown();
    return x;
}

template <typename T>
void Heap<T>::insert(T v) {
    size++;
    data[size] = v;
    bubbleUp();
}

template <typename T>
int Heap<T>::getSize() {
    return size;
}

template <typename T>
void swap(T data[], int idx1, int idx2) {
    T tmp = data[idx1];
    data[idx1] = data[idx2];
    data[idx2] = tmp;
}

template <typename T>
void Heap<T>::bubbleUp() {
    int idx = size;
    int parentIdx = idx / 2;
    T child = data[idx];
    T parent = data[idx / 2];
    while (comparator(child, parent) < 0 && idx > 1) {
        swap(data, idx, parentIdx);
        idx = parentIdx;
        parentIdx = idx / 2;
        child = data[idx];
        parent = data[parentIdx];
    }
}

template <typename T>
void Heap<T>::bubbleDown() {
    int idx = 1;
    while (idx * 2 <= size) {
        T v = data[idx];
        T lchild = data[idx * 2];
        T rchild = data[idx * 2 + 1];
        if (idx * 2 <= size && comparator(v, lchild) > 0) {
            swap(data, idx, idx * 2);
            idx = idx * 2;
        } else if (idx * 2 + 1 <= size && comparator(v, rchild) > 0) {
            swap(data, idx, idx * 2 + 1);
            idx = idx * 2 + 1;
        } else {
            break;
        }
    }
}

template <typename T>
void Heap<T>::print() {
    for (int i = 1; i <= size; i++) {
        cout << data[i];
        if (i + 1 <= size) {
            cout << ", ";
        }
    }
    cout << endl;
}