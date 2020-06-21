# Radix sort uses counting sort as subroutine for each digit
# Sort the element starting with the least significant digit.
import countingSort as sort
import math

# radix sort
def radixSort(arr):
    # number of digits to check = floor of log base 10 of largest number + 1
    largest = max(arr)
    digits = math.floor((math.log(largest, 10))) + 1

    sorted = [i for i in arr]
    # for each digit, call counting sort
    for d in range(0, digits):
        sorted = sort.countingSort(sorted, d)

    return sorted


# driver
def main():
    testArr = [231, 583, 489, 382, 129, 695, 489, 127, 950, 394, 24, 457, 95]
    print("Original array:")
    print(testArr)
    print()

    sortedArr = radixSort(testArr)

    print()
    print("Sorted array: ")
    print(sortedArr)


if __name__ == "__main__":
    main()
