#include "Queue.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(2);
    while (!q.isEmpty()) {
        cout << q.dequeue() << endl;
    }
    cout << endl;
    q.enqueue(7);
    q.enqueue(8);
    cout << q.size() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.size() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.size() << endl;
    try
    {
        cout << q.peek() << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    try
    {
        cout << q.dequeue() << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    
    return 0;
}
