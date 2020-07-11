// Linked List Implementation with C++
// Singly linked with basic functionalities only

#include "LinkedList.h"
#include <stdexcept>

// Node
template<class T>
Node<T>::Node(T val, Node* next) {
    this->value = val;
    this->next = next;
}

template<class T>
Node<T>::~Node() {
}

template<class T>
void Node<T>::setValue(T val) {
    this->value = val;
}

template<class T>
void Node<T>::setNext(Node* next) {
    this->next = next;
}

template<class T>
T Node<T>::getValue() {
    return this->value;
}

template<class T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

// Linked List
template<class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(T const* arr, size_t size) {
    Node<T>* newNode = new Node<T>(arr[0]);
    this->head = newNode;
    Node<T>* ptr = this->head; 
    for (int i = 1; i < size; i++) {
        newNode = new Node<T>(arr[i]);
        ptr->setNext(newNode);
        ptr = newNode;
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    LinkedList<T>::clear();
}

template<class T>
Node<T>* LinkedList<T>::getHead() {
    return this->head;
}

template<class T>
void LinkedList<T>::setHead(Node<T>* node) {
    this->head = node;
}

template<class T>
T LinkedList<T>::getValue(int pos) {
    Node<T>* ptr = this->head;
    for (int i = 0; i < pos; i++) {
        ptr = ptr->getNext();
        if (ptr == nullptr) {
            throw std::out_of_range("Index Out of Bound");
        }
    }
    return ptr->getValue();
}

template<class T>
void LinkedList<T>::insert(T value, int pos) {
    if (pos == 0) {
        Node<T>* newNode = new Node<T>(value, this->head);
        this->head = newNode;
    } else {
        Node<T>* prevPtr = this->head;
        for (int i = 0; i < pos-1; i++) {
            prevPtr = prevPtr->getNext();
            if (prevPtr->getNext() == nullptr) {
                break;
            }
        }
        Node<T>* newNode = new Node<T>(value, prevPtr->getNext());
        prevPtr->setNext(newNode);
    }
}

template<class T>
void LinkedList<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* ptr = this->head;
    if (ptr == nullptr) {
        this->head = newNode;
        return;
    }
    while (ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
    }
    ptr->setNext(newNode);
}

template<class T>
void LinkedList<T>::remove(int pos) {
    Node<T>* nodeToDelete;
    if (pos == 0) {
        nodeToDelete = this->head;
        this->head = this->head->getNext();
    } else {
        Node<T>* prevNode = this->head;
        for (int i = 0; i < pos-1; i++) {
            prevNode = prevNode->getNext();
            if (prevNode->getNext() == nullptr) {
                throw std::out_of_range("Index Out of Bound");
            }
        }
        nodeToDelete = prevNode->getNext();
        if (nodeToDelete->getNext() == nullptr) {
            prevNode->setNext(nullptr);
        } else {
            prevNode->setNext(nodeToDelete->getNext());
        }
    }
    delete nodeToDelete;
    nodeToDelete = nullptr;
}

template<class T>
void LinkedList<T>::clear() {
    Node<T>* ptr = this->head;
    if (ptr == nullptr) {
        return;
    }
    if (ptr->getNext() == nullptr) {
        delete ptr;
        this->head = nullptr;
        return;
    }
    Node<T>* prevPtr;
    while (ptr != nullptr) {
        prevPtr = ptr;
        ptr = ptr->getNext();
        delete prevPtr;
    }
    this->head = nullptr;
}

template<typename Type>
std::ostream& operator<<(std::ostream &os, LinkedList<Type> &linkedList) {
    os << "[";
    Node<Type>* ptr = linkedList.getHead();
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

template<typename Type>
LinkedList<Type> operator+(LinkedList<Type> &left, LinkedList<Type> &right) {
    LinkedList<Type> merged;
    Node<Type>* leftPtr = left.getHead();
    Node<Type>* rightPtr = right.getHead();
    while (leftPtr != nullptr && rightPtr != nullptr) {
        if (leftPtr->getValue() < rightPtr->getValue()) {
            merged.append(leftPtr->getValue());
            leftPtr = leftPtr->getNext();
        } else {
            merged.append(rightPtr->getValue());
            rightPtr = rightPtr->getNext();
        }
    }
    while (leftPtr != nullptr) {
        merged.append(leftPtr->getValue());
        leftPtr = leftPtr->getNext();
    }
    while (rightPtr != nullptr) {
        merged.append(rightPtr->getValue());
        rightPtr = rightPtr->getNext();
    }
    return merged;
}