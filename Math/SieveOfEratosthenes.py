def findPrime(upper):
    """
    Given an exclusive upperbound, find all primes from 2 to upperbound using Sieve of Eratosthenes
    """
    soeTable = list(range(2, upper))
    for num in soeTable:
        multiple = num**2
        i = 0
        while multiple < upper:
            try:
                soeTable.remove(multiple)
            except ValueError:
                pass
            i += 1
            multiple = num * (num + i)
    return soeTable


def isPrime(num):
    """
    Simple isPrime checker to see if given num exists in Sieve Of Eratosthenes table
    """
    return num in findPrime(num+1)


# test driver
primes = findPrime(23)
print(primes)
print(findPrime(100))
print(isPrime(1723))
print(isPrime(1214))
