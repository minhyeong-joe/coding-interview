'''
Given a list, reverse the order without using extra arrays.
'''

def reverse(arr):
    left = 0
    right = len(arr)-1
    print(left, right)

    while left < right:
        arr[left] = arr[left] + arr[right]
        arr[right] = arr[left] - arr[right]
        arr[left] = arr[left] - arr[right]
        left += 1
        right -= 1


def main():
    arr = [1, 2, 3, 4, 5]

    print(arr)

    reverse(arr)

    print(arr)


if __name__=="__main__":
    main()