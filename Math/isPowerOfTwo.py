# is Power of Two
# Given a positive integer, determine if the input is a power of two, (ie. 1, 2, 4, 8, 16...)
# and find the exponent x of 2^x.

# similar to algorithm that converts decimal to binary (keep dividing by two)
# but as converting one digit from the right-end, check if it is 0 or 1
# if 0, add 1 power, else if 1, immediately return false flag
# when decimal is 1, return the accumulated power
def isPowerofTwo(num):
    power = 0
    while num > 0:
        if num == 1:
            return power
        if num % 2 == 0:
            power += 1
        else:
            return -1
        num = num//2


# test driver
print(isPowerofTwo(16))
print(isPowerofTwo(4096))
print(isPowerofTwo(24))
print(isPowerofTwo(1))
print(isPowerofTwo(128))
print(isPowerofTwo(10))

# output
# 4
# 12
# -1
# 0
# 7
# -1
