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
    void setHead(Node<T>* node);
    void insert(T value, int pos=0);
    void append(T value);
    void remove(int pos);
    void clear();

    // operator overloading
    template<typename Type>
    friend std::ostream& operator<<(std::ostream &os, LinkedList<Type> &linkedList);
    
    // add two sorted lists as another sorted list
    // spcifically designed for Merge Two Sorted List
    // assume two lists are already sorted
    template<typename Type>
    friend LinkedList<Type> operator+(LinkedList<Type> &left, LinkedList<Type> &right);
};
// utilities
template<typename Type>
std::ostream& operator<<(std::ostream &os, LinkedList<Type> &linkedList);

template<typename Type>
LinkedList<Type> operator+(LinkedList<Type> &left, LinkedList<Type> &right);

#include "LinkedList.cpp"

#endif
