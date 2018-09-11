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
    def euclidGcd(self, a, b):
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

    def extendEuclidGcd(self, a, b, g, x, y):
        """
        :type input
        a: int (integer a)
        b: int (integer b)
        g: int (for g = ax * by)
        x: int (for g = ax * by)
        y: int (for g = ax * by)
        :rtype: int
        """
        if b == 0:
            g, x, y = a, 1, 0
            return g, x, y

        r = a%b
        q = int(a/b)

        #Recursive call
        g, x, y = self.extendEuclidGcd(b, r, g, x, y)

        xTemp = x
        x = y
        y = xTemp - y*q

        return g, x, y

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
        actual = test.euclidGcd(*args)
        # Assert
        print("Test Case #1 for gcd()... ")
        self.assertEqual(actual, expected)

         # TC
        # Arrange
        args = 39, 36
        expected = 3
        # Act
        actual = test.euclidGcd(*args)
        # Assert
        print("Test Case #2 for gcd()... ")
        self.assertEqual(actual, expected)

         # TC
        # Arrange
        args = 24, 1
        expected = 1
        # Act
        actual = test.euclidGcd(*args)
        # Assert
        print("Test Case #3 for gcd()... ")
        self.assertEqual(actual, expected)

        # TC - extendGcd()
        # Arrange
        args = 56700, 119070, 0, 0, 0
        expected = 5670, -2, 1
        # Act
        actual = test.extendEuclidGcd(*args)
        # Assert
        print("Test Case #4 for extendGcd()... ")
        self.assertEqual(actual, expected)

         # TC - extendGcd()
        # Arrange
        args = 39, 36, 0, 0, 0
        expected = 3, 1, -1
        # Act
        actual = test.extendEuclidGcd(*args)
        # Assert
        print("Test Case #5 for extendGcd()... ")
        self.assertEqual(actual, expected)

         # TC - extendGcd()
        # Arrange
        args = 24, 1, 0, 0, 0
        expected = 1, 0, 1
        # Act
        actual = test.extendEuclidGcd(*args)
        # Assert
        print("Test Case #6 for extendGcd()... ")
        self.assertEqual(actual, expected)

##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
