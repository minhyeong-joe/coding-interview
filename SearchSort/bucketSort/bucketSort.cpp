/**
Bucket sort using linked list as buckets
Bucket sort is efficient for evenly distributed range of list.
It first places input elements into corresponding bin (each "slot" implemented with vector or linked list)
then sort them within the bin,
lastly it concatenate all the bins into a single sorted list.
*/

#include <iostream>
#include "linkedList.cpp"
#include <cmath>
using namespace std;

void bucketSort(int arr[], int len, int min = 0, int max = 99, int bins = 10);
void printArray(int arr[], int len);

// Driver
int main() {
  int testArr[] = {23, 51, 35, 67, 82, 93, 46, 6, 12, 75, 34, 29, 68, 76, 43, 95, 71, 14, 3};
  int length = sizeof(testArr)/sizeof(testArr[0]);
  printArray(testArr, length);
  cout << endl;

  bucketSort(testArr, length);

  cout << "\nSorted Array: " << endl;
  printArray(testArr, length);

  return 0;
}

void bucketSort(int arr[], int len, int min, int max, int bins) {
  LinkedList<int> llist[bins];
  int range = max - min + 1;
  int eachBin = range/bins;
  // sort them in corresponding bins
  for (int i = 0; i < len; i++) {
    int binIndex = (arr[i] - min)/eachBin;
    cout << "Insert " << arr[i] << " into bin # " << binIndex << endl;
    llist[binIndex].insert(arr[i], llist[binIndex].firstLarger(arr[i]));
    cout << llist[binIndex].toString() << endl;
  }
  // concatenate bins
  int j = 0;
  for (int i = 0; i < bins; i++) {
    while (llist[i].size() > 0) {
      try {
        arr[j] = llist[i].pop();
      }
      catch (EmptyListException& e) {
        cout << e.what() << endl;
      }
      j++;
    }
  }
}

void printArray(int arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++) {
		cout << arr[i];
		if (i != len - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}
