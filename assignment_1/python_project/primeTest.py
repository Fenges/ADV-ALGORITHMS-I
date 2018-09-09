#!/usr/bin/env python3
import unittest
import random

"""Miller-Rabin Primality Test

Usage:
    Algorithm Implementation

    In terminal, execute by $ python primeTest.py
    To update testing, edit in test_check()
"""

##############################################################################################
# Performance: ?%

class MillerRabinTest(object):
    def isPrime(self, n, k):
        """
        :type input
        n: int (prime candidate)
        k: int (accuracy level)
        :rtype:
        """
        if n <= 1 or n == 4:
            return False
        if n <= 3:
            return True

        d = n - 1

        while d % 2 == 0:
            d /= 2

        for i in range(0, k):
            if self.millerRabinTest(int(d), n) == False:
                return False

        return True

    def millerRabinTest(self, d, n):
        """
        :type input:
        d: int (exponential)
        n: int (prime candidate)
        :rtype:
        """
        a = random.randint(2, n-2)
        x = self.power(a, d, n)

        if x == 1 or x == n-1:
            return True

        while d != n-1:
            x = (x * x) % n
            d *= 2

            if x == 1:
                return False
            if x == n-1:
                return True

        return False

    def power(self, x, y, p):
        """
        :type input:
        x: int (base)
        y: int (exponential)
        p: int (mod p)
        :rtype:
        """
        res = 1
        x = x % p

        while y > 0:
            if y % 2 != 0:
                res = (res * x) % p
            y = y >> 1
            x = (x * x) % p

        return res

    def isCoPrime(self, p, q, e):
        """
        :type input
        p: int (prime number)
        q: int (prime number)
        :rtype: boolean
        """
        return e%p != 0 and e%q != 0

##############################################################################################
# Test Case
class UnitTest(unittest.TestCase):
    def test_check(self):
        test = MillerRabinTest()

        # TC - check prime
        # Arrange
        args = 100
        # Act
        k = 4
        for n in range(1, args):
            if test.isPrime(n, k):
                print(n)
        # Assert
        print("Test is completed!")

        # TC - check co-prime (pass)
        # Arrange
        args = 2, 3, 35
        expected = True
        # Act
        actual = test.isCoPrime(*args)
        # Assert
        print("Test Case: co prime pass check... ")
        self.assertEqual(actual, expected)

        # TC - check co-prime (fail)
        # Arrange
        args = 2, 3, 8
        expected = False
        # Act
        actual = test.isCoPrime(*args)
        # Assert
        print("Test Case: co prime fail check... ")
        self.assertEqual(actual, expected)

##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
