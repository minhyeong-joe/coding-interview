'''
An anagram is a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.
Write a program to detect if a string is an anagram of another input string.

This solution is implementation of naive approach
O(N^2)
'''

def isAnagram(str1, str2):
    marked = []
    for s1 in str1:
        matchFound = False
        for i, s2 in enumerate(str2):
            # check the unmarked letter
            if i not in marked:
                # if found match, mark it and move onto next str1 letter
                if s1 == s2:
                    marked.append(i)
                    matchFound = True
                    break
        # after str2 loop, no match found
        if not matchFound:
            return False
    # after str1 loop, all str2 has been marked
    return len(marked) == len(str2)
        

def main():
    str1 = "abcdefg"
    str2 = "gedfacb"

    if isAnagram(str1, str2):
        print("%s is an anagram of %s" %(str1.upper(), str2.upper()))
    else:
        print("%s is NOT an anagram of %s" %(str1.upper(), str2.upper()))


if __name__ == "__main__":
    main()