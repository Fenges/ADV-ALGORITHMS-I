#include "../include/headers.hpp"
#include <math.h>
#include <random>

// modular exponentiation.
// returns (a^b) % n
long modExp(long a, unsigned long b, long n)
{
    long accumPowers = 1;
    a = a % n;

    while (b > 0)
    {
        if (b & 1) accumPowers = (accumPowers * a) % n;

        b = b >> 1;
        a = (a * a) % n;
    }
    return accumPowers;
}

int generatePrimeCandidate(int k) {
    if (k % 2 == 0) k = k + 1;

    while (true) {
        k = k + 2;
        bool prime = millerRabinWrapper(k, 40);
        if (prime == true) return k;
    }
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

    // step 2
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(1, n-1); // define the range

    int a = distr(eng);

    // step 3
    int b;
    b = modExp(a, m, n);
    if (b == 1 || b == nMinus1) return true;

    // iterate b after b0 up to k - 1 times
    for (int i = 0; i < k - 1; i ++) {
        b = modExp(b, 2, n);
        if (b == 1) return false;
        if (b == nMinus1) return true;
    }

    return false;
}

bool millerRabinWrapper(int n, int k) {
    for (int i = 0; i < k; i++) {
      if (!millerRabin(n)) return false;
    }
    return true;
}
