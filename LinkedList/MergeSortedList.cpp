#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arrA[] = {2, 4, 5};
    int arrB[] = {0, 1, 2, 3, 6};
    int sizeA = sizeof(arrA)/sizeof(*arrA);
    int sizeB = sizeof(arrB)/sizeof(*arrB);
    LinkedList<int> listA(arrA, sizeA);
    LinkedList<int> listB(arrB, sizeB);

    cout << listA << endl;
    cout << listB << endl;

    // operator+ overloading in LinkedList.cpp
    LinkedList<int> list = listA + listB;

    cout << list << endl;

    return 0;
}
