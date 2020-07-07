/*
 * Given a list that is assumed to have a available partition, find the partition.
 * Partition is a subset of a list that splits the original array in two halves in terms of sum of elements
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "SubsetSum.h"
using namespace std;

vector<vector<int>> partition(vector<int> arr);

int main(int argc, char const *argv[])
{   
    vector<int> arr = {2, 6, 3, 4, 8, 5};
    
    auto part = partition(arr);

    cout << "[";
    for (int i = 0; i < part.size(); i++) {
        cout << "[";
        for (int j = 0; j < part[i].size(); j++) {
            cout << part[i][j];
            if (j != part[i].size()-1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != part.size()-1) {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}

vector<vector<int>> partition(vector<int> arr) {
    vector<vector<int>> result;
    int target = 0;
    for (auto it = arr.cbegin(); it != arr.cend(); it++) {
        target += *it;
    }
    // [optional because of assumptions] if the sum of arr is not even
    if (target % 2 == 1) {
        return result;
    }
    target /= 2;

    // find one partition
    vector<int> partitionOne = subsetSum(arr, target);

    // find another partition by removing partitionOne elements from input array
    // use combination of vector.erase + <algorithm> remove to remove by value
    for (auto it = partitionOne.cbegin(); it != partitionOne.cend(); it++) {
        // this erases all occurrences of same value
        // arr.erase(remove(arr.begin(), arr.end(), *it), arr.end());

        // this finds the first one and erase one element only:
        auto arr_it = find(arr.begin(), arr.end(), *it);
        if (arr_it != arr.end()) {
            arr.erase(arr_it);
        }
    }

    // [optional because of assumptions] check if SUM_partitionOne == SUM_partitionTwo (AKA if array is partitionable)
    int sumOfPartitionTwo = 0;
    for (auto it = arr.cbegin(); it != arr.cend(); it++) {
        sumOfPartitionTwo += *it;
    }
    if (sumOfPartitionTwo != target) {
        return result;
    }

    result.push_back(partitionOne);
    result.push_back(arr);

    return result;
}
