/** 
 *  An anagram is a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.
 *  Write a program to detect if a string is an anagram of another input string.
 * 
 * This solution is implementation of improved approach using dictionary (AKA map in C++)
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram(string str1, string str2);

int main(int argc, char const *argv[])
{
    string str1 = "abcdefg";
    string str2 = "fcegabd";

    if (isAnagram(str1, str2)) {
        cout << str1 << " is an anagram of " << str2 << endl;
    } else {
        cout << str1 << " is NOT an anagram of " << str2 << endl;
    }

    return 0;
}

bool isAnagram(string str1, string str2) {
    unordered_map<char, int> freq;
    for (char c: str1) {
        if (freq.find(c) == freq.end()) {
            freq.insert(make_pair(c, 1));
        } else {
            freq[c] += 1;
        }
    }
    for (char c: str2) {
        // if c in str2 does not exist in frequency map OR if count is already 0
        if (freq.find(c) == freq.end() || freq[c] <= 0) {
            return false;
        } else {
            freq[c] -= 1;
        }
    }
    // check to make sure all count has been decremented to 0
    for (auto it: freq) {
        if (it.second > 0)
            return false;
    }
    return true;
}
