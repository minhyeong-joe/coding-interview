def digitSum(num):
    sum = 0
    while num > 0:
        sum += num % 10
        num //= 10
    return sum


def singleDigitSum(num):
    while True:
        num = digitSum(num)
        if num // 10 == 0:
            break
    return num


# test driver
print(digitSum(12345))
print(singleDigitSum(12345))