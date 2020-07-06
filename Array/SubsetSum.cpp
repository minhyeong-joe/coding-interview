/*
 * Given a list of positive integers and a target sum value,
 * find a subset of elements that sums up to the target sum value.
 * Return any if multiple subsets are possible.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> subsetSum(vector<int> arr, int sum);
void displayDpTable(const vector<vector<bool>> &dpTable);

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 7, 2, 5, 4};
    const int TARGET_SUM = 6;

    vector<int> subset = subsetSum(arr, TARGET_SUM);
    
    cout << "[";
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i];
        if (i < subset.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}


// dpTable[i][j] is true iff there exists a subset that sums up to 'j' from 0~'i' values.
// so, initially, dpTable[i][0] = true, because there is always 0 that sums up to 0.
// and dpTable[0][j] where j > 0, = false, because 0 can't sum to anything greater than 0 itself.
// for each i, j
// if arr[i] > j, then dpTable[i][j] = dpTable[i-1][j]
// because if there exists a subset from 0~'i-1' that sums up to j, then that means there exists a subset from 0~'i' as well.
// if arr[i] <= j, then dpTable[i][j] = dpTable[i-1][j] OR dpTable[i-1][j-arr[i]]
// because either previous range has subset that sums up to j
// OR previous range has subset that sums up to j - arr[i].
// Once dpTable is done, we can backtrack to get the subset elements.
vector<int> subsetSum(vector<int> arr, int sum) {
    // output input array elements (for visual)
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // initialize subset vector
    vector<int> subset;
    // initialize dpTable
    vector<vector<bool>> dpTable(arr.size()+1, vector<bool>(sum+1, false));
    for (int j = 0; j < dpTable[0].size(); j++) {
        dpTable[0][j] = false;
    }
    for (int i = 0; i < dpTable.size(); i++) {
        dpTable[i][0] = true;
    }

    for (int i = 1; i < dpTable.size(); i++) {
        for (int j = 1; j < dpTable[i].size(); j++) {
            if (arr[i-1] > j) {
                dpTable[i][j] = dpTable[i-1][j];
            } else {
                dpTable[i][j] = dpTable[i-1][j] || dpTable[i-1][j-arr[i-1]];
            }
        }
    }
    displayDpTable(dpTable);

    // backtrack from the last row that has target j as True
    int j = sum;
    for (int i = arr.size(); i >= 0; i--) {
        if (dpTable[i][j] && !dpTable[i-1][j]) {
            subset.push_back(arr[i-1]);
            j -= arr[i-1];
        }
        if (j == 0) {
            break;
        }
    }

    return subset;
}

void displayDpTable(const vector<vector<bool>> &dpTable) {
    for (int i = 0; i < dpTable.size(); i++) {
        for (int j = 0; j < dpTable[i].size(); j++) {
            if (dpTable[i][j]) {
                cout << "\033[0;32m" << "T " << "\033[0m";
            }
            else {
                cout << "\033[0;31m" << "F " << "\033[0m";
            }
        }
        cout << endl;
    }
}