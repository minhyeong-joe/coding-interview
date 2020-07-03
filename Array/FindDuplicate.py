'''
Given a list, find a duplicate element.

Extension: Find all duplicate elements if there are multiple.
'''

# return -1 if no duplicate found
def findDup(arr):
    freq = dict()
    for i in arr:
        if freq.get(i, 0) > 0:
            return i
        freq[i] = freq.get(i, 0) + 1
    return -1


def findDupAll(arr):
    dups = []
    freq = dict()
    for i in arr:
        if freq.get(i, 0) > 0:
            dups.append(i)
        else:
            freq[i] = freq.get(i, 0) + 1
    return dups


def main():
    arr = [2, 4, 3, 2, 8, 7, 0, 1, 3]

    dup = findDup(arr)

    print("Single Duplicate:", dup)

    dups = findDupAll(arr)

    print("All duplicates:", dups)


if __name__ == "__main__":
    main()