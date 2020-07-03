'''
Given an unsorted array of size N-1 with no duplicate values from 0 to N, with one missing value.

Find the missing value between 0 and N.
'''

# return -1 if no missing value from range 0~N
def findMissing(arr):
    N = len(arr)+1
    isIncluded = [False]*N
    # check each element of arr
    for i in arr:
        isIncluded[i] = True
    # return the first not included index
    for i in range(0, N):
        if not isIncluded[i]:
            return i
    return -1


def main():
    arr = [1, 5, 7, 3, 8, 6, 9, 2, 0]

    missing = findMissing(arr)

    print("Missing value from %s: %d" %(arr, missing))


if __name__=="__main__":
    main()