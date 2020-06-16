/*
Implement Bubble Sort
Sort N items by running through the list and compare adjacent elements and swap iff two are out of order.
In worst case, have to run through list N-1 times.
O(N^2) runtime.
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b);
void printArray(int arr[], int len);

int main() {

	// create list to sort
	//int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int testArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int testArray[] = { 3, 7, 5, 9, 4, 2, 6, 1, 8 };
	int len = sizeof(testArray) / sizeof(testArray[0]);
	cout << "Original List: ";
	printArray(testArray, len);
	
	// bubble sort iterations
	bool isSwapped;
	for (int i = 0; i < len - 1; i++) {
		isSwapped = false;
		cout << endl << "Iteration " << i+1 << ":" << endl;
		for (int j = 0; j < len; j++) {
			if (testArray[j] > testArray[j + 1]) {
				cout << "Swap " << testArray[j] << " and " << testArray[j + 1] << endl;
				swap(testArray[j], testArray[j + 1]);
				isSwapped = true;
				printArray(testArray, len);
			}
		}
		// if in this iteration, nothing was swapped, then the list is already sorted.
		if (!isSwapped) {
			cout << "Nothing is swapped in this iteration. Done." << endl;
			break;
		}
	}

	cout << endl << "Sorted List: ";
	printArray(testArray, len);
	
	return 0;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int arr[], int len) {
	cout << "[ ";
	for (int i = 0; i < len; i++) {
		cout << arr[i];
		if (i != len - 1) {
			cout << ", ";
		}
	}
	cout << " ]" << endl;
}