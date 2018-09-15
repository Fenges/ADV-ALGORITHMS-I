#include "../include/headers.hpp"
#include <math.h>
#include <random>

// C++ program Miller-Rabin primality test
/*

 Miller-Rabin Test Algorithm Introduction:

 // It returns false if n is composite and returns true if n
 // is probably prime.  k is an input parameter that determines
 // accuracy level. Higher value of k indicates more accuracy.
 bool isPrime(int n, int k)
 1) Handle base cases for n < 3
 2) If n is even, return false.
 3) Find an odd number d such that n-1 can be written as d*2r.
 Note that since n is odd, (n-1) must be even and r must be
 greater than 0.
 4) Do following k times
 if (millerTest(n, d) == false)
 return false
 5) Return true.

 // This function is called for all k trials. It returns
 // false if n is composite and returns false if n is probably
 // prime.
 // d is an odd number such that  d*2r = n-1 for some r >= 1
 bool millerTest(int n, int d)
 1) Pick a random number 'a' in range [2, n-2]
 2) Compute: x = pow(a, d) % n
 3) If x == 1 or x == n-1, return true.

 // Below loop mainly runs 'r-1' times.
 4) Do following while d doesn't become n-1.
 a) x = (x*x) % n.
 b) If (x == 1) return false.
 c) If (x == n-1) return true.
 */

// Utility function to do modular exponentiation.
// It returns (x^y) % p

long power(long x, unsigned long y, long p)
{
    long res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool millerRabinTest(long d, long n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    long a = 2 + rand() % (n - 4);

    // Compute a^d % n
    long x = power(a, d, n);

    if (x == 1  || x == n-1)
        return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(long n, long k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
        if (millerRabinTest(d, n) == false)
            return false;

    return true;
}

bool isCoPrime(long p, long q, long e)
{
    if (e%p != 0 && e%q != 0){
        return true;
    }
    else{
        return false;
    }
}

int generatePrimeCandidate(int k) {
    if (k % 2 == 0) k = k + 1;

    bool candidateNotFound = true;

    while (candidateNotFound) {
        k = k + 2;
        cout << k << endl;
        bool prime = millerRabinWrapper(k, 40);
        cout << prime << endl;
        if (prime == true) candidateNotFound = false;
    }
    return k;
}

/*
 * step 1: find n - 1 = (2^k) m
 * step 2: choose a from 1 < a < n - 1
 * step 3: compute b0 = a^m (mod n), bi = (bi-1)^2
 */
bool millerRabin(int n) {
    int nMinus1 = n - 1;
    // step 1
    int m = n - 1;
    int k = 0;
    while (m % 2 == 0) {
        m = m / 2;
        k = k + 1;
    }

//    cout << "k: " << k << endl;
//    cout << "m: " << m << endl;

    // step 2
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(1, n-1); // define the range

    int a = distr(eng);

    //cout << "a: " << a << endl;

    // step 3
    int b;
    b = power(a, m, n);
    if (b == 1 || b == nMinus1) return true;
    cout << b << endl;
    // iterate b after b0 up to k - 1 times
    for (int i = 0; i < k - 1; i ++) {
        b = power(b, 2, n);
        if (b == 1) return false;
        if (b == nMinus1) return true;
    }

    return false;
}

bool millerRabinWrapper(int n, int k) {
    for (int i = 0; i < k; i++) {
      if (millerRabin(n) == false) {
        return false;
      }
    }
    return true;
}
