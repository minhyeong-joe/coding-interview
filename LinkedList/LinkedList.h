#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

// Linked List Implementation with C++
// Singly linked with basic functionalities only

#include <iostream>

template<class T>
class Node {
private:
    T value;
    Node* next;
public:
    // constructor & destructor
    Node(T val, Node* next=nullptr);
    ~Node();

    // setters and getters
    void setValue(T val);
    void setNext(Node* next);
    T getValue();
    Node* getNext();
};

template<class T>
class LinkedList
{
private:
    Node<T>* head;
public:
    // constructor & destructor
    LinkedList();
    LinkedList(T const* arr, size_t size);
    ~LinkedList();

    // accessor
    Node<T>* getHead();
    T getValue(int pos);

    // modifiers
    void insert(T value, int pos=0);
    void append(T value);
    void remove(int pos);
    void clear();

};
// utilities
template<typename T>
std::ostream& operator<<(std::ostream &os, LinkedList<T> &linkedList) {
    os << "[";
    Node<T>* ptr = linkedList.getHead();
    while(ptr != nullptr) {
        os << ptr->getValue();
        if (ptr->getNext() != nullptr) {
            os << " => ";
        }
        ptr = ptr->getNext();
    }
    os << "]";
    return os;
};

#include "LinkedList.cpp"

#endif
