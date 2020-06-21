/**
Bucket sort using linked list as buckets
Bucket sort is efficient for evenly distributed range of list.
It first places input elements into corresponding bin (each "slot" implemented with vector or linked list)
then sort them within the bin,
lastly it concatenate all the bins into a single sorted list.
*/

#include <iostream>
#include "linkedList.cpp"
using namespace std;

// Driver
int main() {
  LinkedList<int> list;
  list.insert(3);
  list.insert(5);
  list.insert(2);
  list.insert(7, 0);
  cout << list.toString();
  return 0;
}
