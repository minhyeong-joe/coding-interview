package Math;

import java.util.*;

public class FindPrime {

    public static void main(String[] args) {
        final int upper = 20;
        List<Integer> primes = findPrime(upper);
        System.out.println(primes.toString());
    }

    private static List<Integer> findPrime(int upper) {
        List<Integer> primes = new ArrayList<Integer>();
        boolean isPrime = true;
        primes.add(2);
        for (int n = 3; n < upper; n++) {
            isPrime = true;
            for (int prime : primes) {
                if (n % prime == 0) {
                    isPrime = false;
                }
            }
            if (isPrime) {
                primes.add(n);
            }
        }
        return primes;
    }

}