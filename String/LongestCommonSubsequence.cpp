/*
 * Implement Longest Common Subsequence
 * Given two strings, find the longest common subsequence of the two.
 */

#include <iostream>
#include <vector>
#include <string>
// for max
#include <algorithm>
using namespace std;

string LCS(string str1, string str2);
void displayDpTable(const vector<vector<int>> &dpTable);

int main(int argc, char const *argv[])
{
    string str1 = "ACBAD";
    string str2 = "ABCD";

    string lcs = LCS(str1, str2);

    cout << lcs << endl;

    return 0;
}

string LCS(string str1, string str2) {
    string result;
    // create dynamic programming table
    // size M+1 x N+1 initialized to 0
    // vector<T>(initial size, default value)
    vector<vector<int>> dpTable(str1.length()+1, vector<int>(str2.length()+1, 0));
    
    int longest = 0;
    int longestI = 0;
    int longestJ = 0;
    // start filling in the table, while doing so keep the highest number and index
    for (int i = 1; i < dpTable.size(); i++) {
        for (int j = 1; j < dpTable[i].size(); j++) {
            if (str1.at(i-1) == str2.at(j-1)) {
                dpTable[i][j] = dpTable[i-1][j-1] + 1;
            } else {
                dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
            }
            if (dpTable[i][j] > longest) {
                longest = dpTable[i][j];
                longestI = i;
                longestJ = j;
            }
        }
    }
    cout << "Filled in DP Table:" << endl;
    displayDpTable(dpTable);
    cout << endl;

    cout << "Longest Common Subsequence length: " << longest << endl;
    cout << "index at: [" << longestI << "][" << longestJ << "]" << endl;

    // backtrack to create a string
    int i = longestI;
    int j = longestJ;
    // this prioritizes moving to left
    while (i > 0 && j > 0) {
        // if left and above are both lower values, then push this char and move [i-1][j-1]
        if (dpTable[i][j-1] < dpTable[i][j] && dpTable[i-1][j] < dpTable[i][j]) {
            result = str1.at(i-1) + result;
            i--;
            j--;
        }
        // if left has equal value, move left
        else if (dpTable[i][j-1] == dpTable[i][j]) {
            j--;
        }
        // if above has equal value, move up
        else if (dpTable[i-1][j] ==  dpTable[i][j]) {
            i--;
        }
    }

    return result;
}

void displayDpTable(const vector<vector<int>> &dpTable) {
    for (int i = 0; i < dpTable.size(); i++) {
        for (int j = 0; j < dpTable[i].size(); j++) {
            cout << dpTable[i][j] << " ";
        }
        cout << endl;
    }
    // by using iterator (commented as cpp reference)
    // vector<vector<int>>::const_iterator row;
    // vector<int>::const_iterator col;
    // for (row = dpTable.cbegin(); row != dpTable.cend(); row++) {
    //     for (col = row->cbegin(); col != row->cend(); col++) {
    //         cout << *col << " ";
    //     }
    //     cout << endl;
    // }
}