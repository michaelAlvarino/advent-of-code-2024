#ifndef LIST_HEADER
#define LIST_HEADER

template <typename T>

class Node {
public:
    Node(T v);
    Node<T>* getNext();
    void setNext(Node<T> *nextNode);
    Node<T>* getPrev();
    void setPrev(Node<T> *prevNode);
    T getVal();
    bool operator==(const Node<T>& other);
private:
    T val;
    Node<T> *next;
    Node<T> *prev;
};

#endif