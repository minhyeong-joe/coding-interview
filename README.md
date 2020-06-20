# Coding Interview
Some coding problems to practice & review for interviews

# Navigation
- Search and Sort
    1. [BubbleSort](#bubble-sort)
    2. [InsertionSort](#insertion-sort)
    3. [MergeSort](#merge-sort)
    4. [QuickSort](#quick-sort)
    5. [RadixSort (and counting sort)](#radix-sort)
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
