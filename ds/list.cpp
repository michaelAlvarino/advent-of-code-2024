#include <iostream>

#include "list.hpp"

using namespace std;

template <typename T>
Node<T>::Node(T v) {
    val = v;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
    return prev;
}

template <typename T>
T Node<T>::getVal() {
    return val;
}

template <typename T>
bool Node<T>::operator==(const Node<T>& other) {
    return val == other.val;
}

template <typename T>
void Node<T>::setNext(Node<T> *nextNode) {
    next = nextNode;
}

template <typename T>
void Node<T>::setPrev(Node<T> *prevNode) {
    prev = prevNode;
}
