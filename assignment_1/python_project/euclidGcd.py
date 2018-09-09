#!/usr/bin/env python3
import unittest

"""Euclid Greatest Common Divisor

Usage:
    Algorithm Implementation

    In terminal, execute by $ python euclidGcd.py
    To update testing, edit in test_check()
"""

##############################################################################################
# Performance: ?%

class EuclidGcd(object):
    def gcd(self, a, b):
        """
        :type input
        a: int (integer a)
        b: int (integer b)
        :rtype: int
        """
        while b != 0:
            r = a%b
            a = b
            b = r

        return a

##############################################################################################
# Test Case
class UnitTest(unittest.TestCase):
    def test_check(self):
        test = EuclidGcd()

        # TC
        # Arrange
        args = 24, 36
        expected = 12
        # Act
        actual = test.gcd(*args)
        # Assert
        print("Test Case #1... ")
        self.assertEqual(actual, expected)

         # TC
        # Arrange
        args = 39, 36
        expected = 3
        # Act
        actual = test.gcd(*args)
        # Assert
        print("Test Case #2... ")
        self.assertEqual(actual, expected)

         # TC
        # Arrange
        args = 24, 1
        expected = 1
        # Act
        actual = test.gcd(*args)
        # Assert
        print("Test Case #3... ")
        self.assertEqual(actual, expected)
##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
