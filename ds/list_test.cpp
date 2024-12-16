#include <cassert>
#include <iostream>

#include "list.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    Node<int> node = Node(15);
    Node<int> next = Node(20);
    Node<int> prev = Node(10);

    node.setNext(&next);
    node.setPrev(&prev);

    assert(*node.getNext() == next);
    assert(*node.getPrev() == prev);
    assert(node.getVal() == 15);
}
