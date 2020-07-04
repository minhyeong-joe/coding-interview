'''
Given an unsorted list of integers and a target value,

find a pair that sums up to be the target value.

Sorting and then two-pointer approach
'''
# uses python's built-in list sort()
# https://wiki.python.org/moin/TimeComplexity
# python's sort uses Timsort and takes O(n log n)


def pairSum(arr, target):
    pair = []
    arr.sort()
    i, j = 0, len(arr)-1
    while i < j:
        if arr[i]+arr[j] < target:
            i += 1
        elif arr[i]+arr[j] > target:
            j -= 1
        else:
            pair.append(arr[i])
            pair.append(arr[j])
            return pair

    return pair


def main():
    arr = [3, 7, 2, 5, 6]
    target = 9

    pair = pairSum(arr, target)

    print(pair)


if __name__ == "__main__":
    main()
