# Coding Interview
Some coding problems to practice & review for interviews

# Navigation
- Search and Sort
    1. [BubbleSort](#bubble-sort)
    2. [InsertionSort](#insertion-sort)
    3. MergeSort
    4. QuickSort
    5. RadixSort
    6. BucketSort
    7. BinarySearch
- String
    1. IsPalindrome
    2. IsAnagram
    3. RemoveAllChars
    4. FindFirstNonRepeatedChar
    5. CountChar
    6. RemoveDupChar
    7. MostFrequentChar
    8. AllPermutations
    9. LongestSubPalindrome
    10. LongestCommonSubsequence
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
    7. MaxPointsOnLine

# Problems
  
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

