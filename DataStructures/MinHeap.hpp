#ifndef _MIN_HEAP_HPP
#define _MIN_HEAP_HPP

#include <vector>

template<class T>
class MinHeap {
private:
    std::vector<T> _heap;

    // helper functions
    // find the index of parent, left, and right child
    int parentIndex(const int& index) const;
    int leftChildIndex(const int& index) const;
    int rightChildIndex(const int& index) const;
    // heapify after deletion
    void heapifyDown();
    // heapify after insertion
    void heapifyUp();
    // swap two elements in vector
    void swap(const int& indexA, const int& indexB);
public:
    MinHeap();
    ~MinHeap();
    void insert(const T& data);
    // remove and return the root
    T remove();
    T min() const;
    int size() const;
    bool isEmpty() const;
    void print() const;
};

#include "MinHeap.cpp"

#endif