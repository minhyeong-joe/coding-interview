'''
Find First Non-repeated Char:
Given a string find the first character that does not repeat (AKA, appears only once in the string). (Case-sensitive)

Find All Non-repeated Char:
Extension of first one - find ALL non-repeating characters in the string
'''

# create frequency dictionary given a string (refactored into separate function as both findFirst and findAll use this logic)
def countChars(str):
    freq = dict()
    # iterate over string
    for c in str:
        if freq.get(c) is None:
            freq.update({c: 1})
        else:
            freq.update({c: freq.get(c)+1})

    return freq


def findFirstNonRepeatedChar(str):
    freq = countChars(str)
    
    # return the first char with frequency 1
    for ch, fr in freq.items():
        if fr == 1:
            return ch


def findNonRepeatedChar(str):
    freq = countChars(str)
    result = []

    # add all non-repeating chars to result array to be returned
    for ch, fr in freq.items():
        if fr == 1:
            result.append(ch)
    
    return result


def main():
    str = "abacdeac"
    print("Input String: %s" %str) 

    ch = findFirstNonRepeatedChar(str)

    chs = findNonRepeatedChar(str)

    print("First Non-repeated character is: %c" %ch)

    print("All Non-repeated characters are: %s" %chs)


if __name__ == "__main__":
    main()