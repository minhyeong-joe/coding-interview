#include "MinHeap.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MinHeap<int> minHeap;
    minHeap.insert(4);
    minHeap.insert(8);
    minHeap.insert(2);
    minHeap.insert(11);
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.print();
    while (!minHeap.isEmpty()) {
        cout << "Min: " << minHeap.remove() << endl;
        cout << "New Heap: ";
        minHeap.print();
        cout << endl;
        cout << "Size: " << minHeap.size() << endl;
    }
    try
    {
        minHeap.remove();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}
