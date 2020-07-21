from math import sqrt

def isPrime(num):
    """
    Given a positive integer, return true if num is a prime number.
    Helper function for primeFactorize()
    """
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True



def primeFactorize(num):
    """
    Given a positive integer, return array of prime factors
    """
    factors = []
    for i in range(2, int(sqrt(num)) + 1):
        if isPrime(i):
            while num % i == 0:
                factors.append(i)
                num //= i
    return [num] if len(factors) == 0 else factors



# print(isPrime(11))
# print(isPrime(21))
# print(isPrime(7))
# print(isPrime(6))
print(primeFactorize(1386))     # 2, 3, 3, 7, 11
print(primeFactorize(10285))    # 5, 11, 11, 17
print(primeFactorize(1485))     # 3, 3, 3, 5, 11