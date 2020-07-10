/*
 * Reverse Singly Linked List In-place
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

template<typename T>
void reverse(LinkedList<T>& list);

int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 2, 1, 0};
    int size = sizeof(arr)/sizeof(*arr);
    LinkedList<int> list(arr, size);
    
    cout << list << endl;

    reverse(list);

    cout << list << endl;

    return 0;
}

template<typename T>
void reverse(LinkedList<T>& list) {
    Node<T>* prevPtr = nullptr;
    Node<T>* currPtr = list.getHead();
    // if size 0 or 1
    if (currPtr == nullptr || currPtr->getNext() == nullptr) {
        return;
    }
    Node<T>* nextPtr;

    while (currPtr != nullptr) {
        nextPtr = currPtr->getNext();
        // reverse the link direction for current ptr
        currPtr->setNext(prevPtr);
        // traverse three pointers in correct order
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    list.setHead(prevPtr);
}