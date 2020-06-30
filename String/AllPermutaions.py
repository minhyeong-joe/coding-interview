'''
All Permutations

Given a string, find all possible permutations of string's characters. Return array of strings in any order.
'''

permutations = list()
def allPermutations(strArr, left=0, right=None):
    global permutations

    if right is None:
        right = len(strArr)-1

    # print(list(dict.fromkeys(permutations)))


    if left == right:
        # base case: no more characters
        permutations.append(''.join(strArr))
        permutations = list(dict.fromkeys(permutations))
    else:
        for i in range(left, right+1):
            # swap 
            strArr[left], strArr[i] = strArr[i], strArr[left]
            # recursive on sub-string
            allPermutations(strArr, left+1, right)
            # backtrack
            strArr[left], strArr[i] = strArr[i], strArr[left]



def main():
    str = "abcc"

    allPermutations(list(str))

    print(permutations)



if __name__ == "__main__":
    main()