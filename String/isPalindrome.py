'''
A palindrome is a word, phrase, number or sequence of words that reads the same backward as forward.
ie) racecar, level, noon, rotator...
Write a program to detect if input string is a palindrome.

This solution uses stack's LIFO (Last In First Out) to check if the string is palindrome
'''

def isPalindrome(str):
    stack = []
    half = len(str)//2
    isOdd = len(str)%2
    # push first half to stack
    for i in range(0, half):
        stack.append(str[i])
    # if input is odd length, skip the middle one
    if isOdd:
        half += 1
    # pop if match
    for i in range(half, len(str)):
        if str[i] == stack[len(stack)-1]:
            stack.pop() # IndexError exception handling is not required as len(firstHalf) == len(lastHalf)
        else:
            return False
    # return true if stack is completely popped
    return len(stack) == 0


def main():
    str = ["abbaa", "abba", "ababa", "abab", "racecar", "racecars", "rotator", "noon", "abbbbbbbbba"]
    
    for s in str:
        if (isPalindrome(s)):
            print("%s is a palindrome" %(s.upper()))
        else:
            print("%s is not a palindrome" %(s.upper()))


if __name__ == "__main__":
    main()