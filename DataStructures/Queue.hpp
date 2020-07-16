#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include <vector>

template<class T>
class Queue {
private:
    std::vector<T> _queue;
    int _size;
public:
    Queue();
    ~Queue();

    // insert data to the beginning of queue
    void enqueue(const T& data);
    // remove and return data from the beginning of queue
    T dequeue();
    // return data from the beginning without removing it
    T peek() const;
    // return the size of queue
    int size() const;
    // return true if queue is empty
    bool isEmpty() const;
};

#include "Queue.cpp"

#endif