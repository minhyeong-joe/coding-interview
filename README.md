# Coding Interview
Some coding problems to practice & review for interviews

# Navigation
- Search and Sort
    1. [BubbleSort](#bubble-sort)
    2. [InsertionSort](#insertion-sort)
    3. [MergeSort](#merge-sort)
    4. [QuickSort](#quick-sort)
    5. [RadixSort (and counting sort)](#radix-sort)
    6. [BucketSort](#bucket-sort)
    7. [BinarySearch](#binary-search)
- String
    1. [IsPalindrome](#is-palindrome)
    2. [IsAnagram](#is-anagram)
    3. [RemoveAllChars](#remove-all-chars)
    4. [FindFirstNonRepeatedChar](#find-first-non-repeated-char)
    5. [RemoveDupChar](#remove-duplicate-char)
    6. [MostFrequentChar](#most-frequent-char)
    7. [AllPermutations](#all-permutations)
    8. LongestSubPalindrome
    9. LongestCommonSubsequence
- Array
    1. FindMissing
    2. FindDuplicate
    3. FindSecondMax
    4. PairSum
    5. SubsetSum
    6. ReverseInPlace
    7. Partition
- LinkedList
    1. MiddleElementSinglePass
    2. NthFromLast
    3. ReverseSinglyLinkedList
    4. MergeTwoSortedLists
    5. RemoveDuplicate
- Graph and Tree
    1. FindDepth
    2. InOrderTraversal
    3. PreOrderTraversal
    4. PostOrderTraversal
    5. BalanceCheck
    6. ShortestPath
    7. HamiltonPath
- Number and Math
    1. IsPowerOfTwo
    2. FindPrimeGivenUpperBound
    3. BinaryConversion
    4. SumOfDigits
    5. PrimeFactorization
    6. SieveOfEratosthenes

# Problems

## **Search and Sort**
---

- ## Bubble Sort

- ### Problem Statement
    Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
The pass through the list is repeated until the list is sorted.

- ### Solution

  - #### Path to the source codes that solve the problem

    [bubbleSort.cpp](./SearchSort/bubbleSort/bubbleSort.cpp)

  - #### If applicable, What is time complexity of the solution? (Big-O)

    O(N^2).

    Maximum N-1 iterations, and in each iteration, algorithm scans each of N elements.

---

- ## Insertion Sort

- ### Problem Statement
    Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

- ### Solution

  - #### Path to the source codes that solve the problem

    [insertionSort.java](./SearchSort/insertionSort/insertionSort.java)

  - #### If applicable, What is time complexity of the solution? (Big-O)

    O(N^2).

    Always N-1 iterations, and in each iteration, algorithm compares i-th element to all preceding elements
to decide i-th element's new order. (More "shifts" required for worst case)

---

- ## Merge Sort

- ### Problem Statement
    Conceptually, a merge sort works as follows:
1. Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

- ### Solution

  - #### Path to the source codes that solve the problem

    [mergeSort.py](./SearchSort/mergeSort/mergeSort.py)

  - #### If applicable, What is time complexity of the solution? (Big-O)

    O(N log N).

    Similar to binary operations (divide-and-conquer), each split/merge divides the problem
into subproblems of half the size. It takes log N divisions and in each subproblem, N time to sort.

---

- ## Quick Sort

- ### Problem Statement
  Quicksort is a divide-and-conquer algorithm.
  It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.
  The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting.

- ### Solution

- #### Path to the source codes that solve the problem

  [quickSort.java](./SearchSort/quickSort/quickSort.java)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N log N).

  partitions array into sub-arrays and then place them in the right place of the pivot.
  The solution used **Hoarse Partition Scheme** (pivot in the middle and two "pointers" from two ends of array)
  So even for sorted array, the worst case is still O(n log n).
  **Lomuto Partition Scheme** (pivot at the end, and comparison "pointer" from start of index) can be O(n^2) on already sorted list.

---

- ## Radix Sort

- ### Problem Statement
  Radix sort sorts digit by digit.
  Starting with least significant digit, algorithm uses counting sort as subroutine to sort the list.
  For example, for 3-digit integers, counting sort is called three times.

  **Counting Sort**

  Counting sort uses counting array to sort elements. (details in source code)

- ### Solution

- #### Path to the source codes that solve the problem

  [countingSort.py](./SearchSort/radixSort/countingSort.py)

  [radixSort.py](./SearchSort/radixSort/radixSort.py)

- #### If applicable, What is time complexity of the solution? (Big-O)

  Counting Sort takes O(N+k) time.

  Given list of N elements, k is the largest element.

  1. Iterate over N elements to count and store occurrences => O(N)
  2. Iterate over k elements of counting array to modify for sorting => O(k)
  3. Iterate over N elements of original array from the end => O(N)

  Radix Sort takes O(d(N+k)) time.

  d is the largest number of digit.

  With X being the largest number with base-10,

  d = floor((log_10)X) + 1  

---

- ## Bucket Sort

- ### Problem Statement
  Bucket Sort first places input elements into corresponding bins,
  then sort the bins separately, and lastly concatenate all the bins as a single sorted list.

- ### Solution

  Used linked list to store elements within the same bin.

- #### Path to the source codes that solve the problem

  [linkedList.cpp](./SearchSort/bucketSort/linkedList.cpp)

  [bucketSort.cpp](./SearchSort/bucketSort/bucketSort.cpp)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N) to iterate over original list,

  and for each N items, find the correct position to be inserted (take O(k), k is the number of items in the bin)

  This can differ depending on which sorting to use for each bucket.

  In worst case, if all items fall into the same bin, can take O(N^2)

  If all items are evenly distributed, then it can take O(N) time as no sorting within bucket required.

---

- ## Binary Search

- ### Problem Statement
  Binary Search utilizes **Sorted** list to search for a target within the given list.

- ### Solution

  It compares middle value to target value, and do the following:
    1. if target == middle, return middle
    2. if target > middle, do recursive search on right of middle
    3. if target < middle, do recursive search on left of middle
    4. if sub-array is not valid (ie. left-end and right-end crossed path), then element is not found, thus return -1 as flag.

- #### Path to the source codes that solve the problem

  **Any sort is fine, but used quickSort for the solution**

  [binarySearch.java](./SearchSort/binarySearch/binarySearch.java)

  [quickSort.java](./SearchSort/quickSort/quickSort.java)

- #### If applicable, What is time complexity of the solution? (Big-O)

  Excluding quick sort described [above](#quick-sort),

  O(log n)

  Because this is simply divide-and-conquer, each recursion keeps "half-ing" the problem. For N elements, it takes at most log N + 1 recursive calls including the very first call from main.

  In each recursion, it simply compares the values and return index, so this is O(1), thus total time complexity is O(log N) 

---
## **String**
---

- ## Is Palindrome

- ### Problem Statement
  A palindrome is a word, phrase, number or sequence of words that reads the same backward as forward.

  ie) racecar, level, noon, rotator...

  Write a program to detect if input string is a palindrome.

- ### Solution

  Use stack to store first half of the string, then pop from stack as they match the last half of the string. If non-matching found or if stack has remainders, then the string is not palindrome.

  Careful with even and odd length input.

- #### Path to the source codes that solve the problem

  [isPalindrome.py](./String/isPalindrome.py)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N)

  Scans the input string of length N single time.

---

- ## Is Anagram

- ### Problem Statement
  An anagram is a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.

  Write a program to detect if a string is an anagram of another input string.

- ### Solution

  **naive approach**: for each char of string A, scans through string B and mark it. Do until all chars of string A are scanned or entire string B is marked. Return true iff both string A and string B are done.

  **improved approach**: Use a frequency dictionary to first count the occurrences of chars in string A, then match freq dict to string B to see if all chars occur with same frequency.

- #### Path to the source codes that solve the problem

  **naive approach**: [isAnagram.py](./String/isAnagram.py)

  **improved approach**: [isAnagram.cpp](./String/isAnagram.cpp)

- #### If applicable, What is time complexity of the solution? (Big-O)

  **naive approach**: O(N*M), O(N^2)

  N is the length of input string A, and M is the length of input string B.

  For checking anagram, it is highly likely that N and M are equal.

  For each letter in string A, scan through string B, so it is O(N^2)

  **improved approach**: O(N)

  scans through string A of length N, count the occurrences.

  Then scans through string B of length M to match the occurrences.

  Total time complexity is O(max(N,M))
---

- ## Remove All Chars

- ### Problem Statement
  Given a string and an array of characters, remove all occurrences of characters in array from the string. (case-insensitive)

  (Obviously, without using built-in string methods like substring, removeAll, etc)

  Example:
  ```java
  str = removeAllChars("Hello, World", ['h', 'l']);
  print(str);
  // should output:
  // eo, Word
  ```

- ### Solution

  For each char in string, check to see if it is in the array,

  If not then add that char to resulting string.

- #### Path to the source codes that solve the problem

  [RemoveAllChars.java](./String/RemoveAllChars.java)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N * M)

  given string of length N and array of length M.
---

- ## Find First Non-repeated Char

- ### Problem Statement
  Given a string find the first character that does not repeat (AKA, appears only once in the string). (Case-sensitive)

  **Extension**:

  find **ALL** non-repeating characters in the string

  Example:
  ```java
  ch = findFirstNoneRepeatedChar("abacdeac")
  print(ch);
  // should output:
  // b
  // as 'd' and 'e' are not repeating, but not the first.

  // Extension
  arr = findAllNonRepeatedChar("abacdeac")
  print(arr)
  // should output:
  // [b, d, e]  (or any sort of array printing format depend on language)
  ```

- ### Solution

  Iterate over characters in string, and keep track of occurrences using dictionary.

  Once done iterating string, return the first dict key that has occurrence of 1.

- #### Path to the source codes that solve the problem

  [FindNonRepeatedChar.py](./String/FindNonRepeatedChar.py)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N)

  N = length of input string.
---

- ## Remove Duplicate Char

- ### Problem Statement
  Given a string, remove all the duplicate characters (case-sensitive).

  Example:
  ```java
  str = removeDupChar("Hello World")
  print(str);
  // should output:
  // He Wrd
  ```

- ### Solution

  Iterate over characters in string, and keep track of occurrences using dictionary.

  Once done iterating string, concatenate all the dict key with freq of 1 into a string.

- #### Path to the source codes that solve the problem

  [RemoveDupChar.java](./String/RemoveDupChar.java)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N)

  N = length of input string.
---

- ## Most Frequent Char

- ### Problem Statement
  Given a string, find the most frequent character (return any if multiple, case-sensitive)

  Example:
  ```java
  ch = mostFrequentChar("Hello World")
  print(ch);
  // should output:
  // l
  ```

- ### Solution

  Iterate over characters in string, and keep track of occurrences using dictionary.

  Once done iterating string, find max frequency in the dictionary and return the key char associated with that frequency.

- #### Path to the source codes that solve the problem

  [MostFrequentChar.cpp](./String/MostFrequentChar.cpp)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N)

  N = length of input string.
---

- ## All Permutations

- ### Problem Statement
  Given a string, find all possible permutations of string's characters.
  Return array of strings in any order.

  Example:
  ```java
  arr = allPermutations("abcc");
  print(arr);
  // should output: (in any form of array printing format)
  // ["abcc", "acbc", "accb", "bacc", "bcac", "bcca", "cabc", "cbac", "cacb", "cbca", //  "ccab", "ccba"]
  ```

- ### Solution

  Recursively takes portion of string from (0, N-1) -> (N-2, N-1).

  Makes all combinations of swaps with first character and the rest of string,

  and append it into permutation set.

- #### Path to the source codes that solve the problem

  [AllPermutations.py](./String/AllPermutations.py)

- #### If applicable, What is time complexity of the solution? (Big-O)

  O(N!)

  Given string of length N, recursively calls itself N! times.

  Swapping and adding to set each takes O(1).

---