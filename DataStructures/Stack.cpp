#include "Stack.hpp"
#include <exception>

class EmptyStackException: public std::exception {
    virtual const char* what() const throw()
    {
        return "Stack is Empty.";
    }
} emptyStackException;

template<class T>
Stack<T>::Stack() {
    _size = 0;
}

template<class T>
Stack<T>::~Stack() {}

template<class T>
void Stack<T>::push(const T& data) {
    _stack.push_back(data);
    _size += 1;
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw emptyStackException;
    }
    T temp = _stack[_size - 1];
    _stack.erase(_stack.begin() + _size - 1);
    _size -= 1;
    return temp;
}

template<class T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw emptyStackException;
    }
    return _stack[_size - 1];
}

template<class T>
int Stack<T>::size() const {
    return _size;
}

template<class T>
bool Stack<T>::isEmpty() const {
    return !_size;
}
