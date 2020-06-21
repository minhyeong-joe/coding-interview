# Radix sort uses counting sort as subroutine
# Counting sort keeps track of list's key values using counting array
# ie) arr = [2, 5, 4, 8, 7, 3, 9]
#     temp = [0, 0, 1, 1, 1, 1, 0, 1, 1, 1]
# then modify temp array such that temp[i] = temp[i] + temp[i-1]
# ie) temp = [0, 0, 1, 2, 3, 4, 4, 5, 6, 7]
# then starting from end of arr, sorted[temp[arr[i]]-1] = arr[i], and decrement the value of temp[arr[i]] by 1
# ie) sorted = [1, 3, 4, 5, 7, 8, 9]
#     temp = [0, 0, 0, 1, 2, 3, 4, 4, 5, 6]
# list of N elements, k being the largest element
# takes O(N+k) time: 1. going through and counting N elements in list; 2. modifying k items in counting array; 3. going through N elements from end of list
# efficient for k not significantly greater than N. ie) single digits (as k is 10 at most)

# generally can be used for different base system,
# but this one is for base-10 and single digit only (specifically as radix sort's subroutine)
def countingSort(arr, digit):
    print(arr)

    counting = [0] * 10
    sorted = [0] * len(arr)

    # count N elements in list
    for i in range(0, len(arr)):
        countingIndex = arr[i]//10**digit - (arr[i]//10**(digit+1))*10
        counting[countingIndex] += 1

    print("Counting Array:")
    print(counting)

    # modify counting array (similar to dynamic programming)
    for i in range(1, len(counting)):
        counting[i] += counting[i-1]

    print("Modified counting array:")
    print(counting)
    print()

    # insert into sorted
    for i in range(len(arr)-1, -1, -1):
        print("=== %d ===" %arr[i])
        countingIndex = arr[i]//10**digit - (arr[i]//10**(digit+1))*10
        counting[countingIndex] -= 1
        sorted[counting[countingIndex]] = arr[i]
        print("Counting array: ", counting)
        print("Sorted array: ", sorted)

    return sorted


# driver
def main():
    testArr = [2, 5, 4, 8, 7, 3, 9]
    print("Original list:")
    print(testArr)
    print()

    sortedArr = countingSort(testArr, 0)

    print()
    print("Sorted list:")
    print(sortedArr)


# run main only when run as standalone
if __name__ == "__main__":
    main()
