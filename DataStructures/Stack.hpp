#ifndef _STACK_HPP
#define _STACK_HPP

#include<vector>

template<class T>
class Stack {
private:
    std::vector<T> _stack;
    int _size;
public:
    Stack();
    ~Stack();
    // add the data to the top of stack
    void push(const T& data);
    // remove and return the data at the top of stack
    T pop();
    // return the data at the top without removing
    T peek() const;
    // return the size of stack
    int size() const;
    // return true if stack is empty
    bool isEmpty() const;
};

#include "Stack.cpp"

#endif