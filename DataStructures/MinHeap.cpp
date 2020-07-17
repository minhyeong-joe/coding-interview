#include "MinHeap.hpp"
#include <exception>
#include <iostream>

class HeapEmptyException : public std::exception {
    virtual const char* what() const throw()
    {
        return "Heap is Empty.";
    }
} heapEmptyException;

template<class T>
MinHeap<T>::MinHeap() {}

template<class T>
MinHeap<T>::~MinHeap() {}

template<class T>
void MinHeap<T>::insert(const T& data) {
    _heap.push_back(data);
    heapifyUp();
}

template<class T>
T MinHeap<T>::remove() {
    if (isEmpty())
        throw heapEmptyException;
    T root = _heap[0];
    swap(0, _heap.size() - 1 );
    _heap.erase(_heap.begin() + _heap.size() - 1);
    heapifyDown();
    return root;
}

template<class T>
T MinHeap<T>::min() const {
    if (isEmpty())
        throw heapEmptyException;
    return _heap[0];
}

template<class T>
int MinHeap<T>::size() const {
    return _heap.size();
}

template<class T>
bool MinHeap<T>::isEmpty() const {
    return !_heap.size();
}

template<class T>
void MinHeap<T>::print() const {
    for (T data: _heap) {
        std::cout << data << " ";
    }
}

template<class T>
int MinHeap<T>::parentIndex(const int& index) const {
    return (index - 1) / 2;
}

template<class T>
int MinHeap<T>::leftChildIndex(const int& index) const {
    return index * 2 + 1;
}

template<class T>
int MinHeap<T>::rightChildIndex(const int& index) const {
    return index * 2 + 2;
}

template<class T>
void MinHeap<T>::heapifyDown() {
    int currentIndex = 0;
    int leftIndex = leftChildIndex(currentIndex);
    int rightIndex = rightChildIndex(currentIndex);
    // while not heapified, keep taking the parent down.
    // if there's no left child (that means no right child too), it's the bottom of heap
    while ((_heap[currentIndex] > _heap[leftIndex] || _heap[currentIndex] > _heap[rightIndex]) 
            && leftIndex < _heap.size()) {
        int smallerChildIndex = leftIndex;
        if (_heap[leftIndex] > _heap[rightIndex]) {
            smallerChildIndex = rightIndex;
        }
        swap(currentIndex, smallerChildIndex);
        currentIndex = smallerChildIndex;
        leftIndex = leftChildIndex(currentIndex);
        rightIndex = rightChildIndex(currentIndex);
    }
}

template<class T>
void MinHeap<T>::heapifyUp() {
    int currentIndex = _heap.size() - 1;
    int pIndex = parentIndex(currentIndex);
    while (_heap[currentIndex] < _heap[pIndex] && pIndex >= 0) {
        swap(currentIndex, pIndex);
        currentIndex = pIndex;
        pIndex = parentIndex(currentIndex);
    }
}

template<class T>
void MinHeap<T>::swap(const int& indexA, const int& indexB) {
    T temp = _heap[indexA];
    _heap[indexA] = _heap[indexB];
    _heap[indexB] = temp;
}
