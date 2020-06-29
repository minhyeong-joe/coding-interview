/*
 * Given a string, return the most frequent character (return any if multiple, case-sensitive)
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char mostFrequentChar(string str);

int main(int argc, char const *argv[])
{
    string str = "Hello World";

    char c = mostFrequentChar(str);

    cout << c;

    return 0;
}

char mostFrequentChar(string str) {
    unordered_map<char, int> freq;
    char mostChar;
    int mostFreq = 0;

    // count chars
    for(char c: str) {
        if(freq.find(c) == freq.end()) {
            freq.insert(make_pair(c, 1));
        } else {
            freq[c] += 1;
        }
    }

    // find most frequent char
    for (auto pair: freq) {
        if (pair.second > mostFreq) {
            mostChar = pair.first;
            mostFreq = pair.second;
        }
    }

    return mostChar;
}
