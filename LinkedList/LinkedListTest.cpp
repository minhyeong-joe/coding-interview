#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{   
    LinkedList<string> test;
    cout << test << endl;

    // array constructor test
    int arr[] = {0, 1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(*arr);
    LinkedList<int> list(arr, size);
    cout << list << endl;

    // iterating and getting value test
    auto it = list.getHead();
    for (int i = 0; i < 2; i++) {
        it = it->getNext();
    }
    cout << it->getValue() << endl;

    // get value test
    try
    {
        cout << list.getValue(1) << endl;
        cout << list.getValue(5) << endl;   // should print "Index Out of Bound"
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    

    // remove test
    try
    {
        list.remove(3);
        list.remove(6);   // should print "Index Out of Bound"
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    cout << list << endl;

    // insertion test
    list.insert(3, 3);
    cout << list << endl;

    // append test
    list.append(5);
    cout << list << endl;

    // clear test
    list.clear();
    cout << list << endl;

    return 0;
}
