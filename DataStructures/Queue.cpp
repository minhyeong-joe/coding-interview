#include "Queue.hpp"
#include <exception>

class QueueEmptyException: public std::exception {
    virtual const char* what() const throw()
    {
        return "Queue is Empty.";
    }
} queueEmptyException;

template<class T>
Queue<T>::Queue() {
    _size = 0;
}

template<class T>
Queue<T>::~Queue() {}

template<class T>
void Queue<T>::enqueue(const T& data) {
    _queue.push_back(data);
    _size += 1;
}

template<class T>
T Queue<T>::dequeue() {
    if (isEmpty())
        throw queueEmptyException;
    T temp = _queue[0];
    _queue.erase(_queue.begin());
    _size -= 1;
    return temp;
}

template<class T>
T Queue<T>::peek() const {
    if (isEmpty())
        throw queueEmptyException;
    return _queue[0];
}

template<class T>
int Queue<T>::size() const {
    return _size;
}

template<class T>
bool Queue<T>::isEmpty() const {
    return !_size;
}