#!/usr/bin/env python3
import unittest

"""Number Convert

Usage:
    Used for number converting

"""

##############################################################################################
# Performance: ?%

class NumberConvert(object):
    def polyEval(self, coef, base):
        """
        :type input
        coef: list[int] (number in other base to convert)
        base: int (number system)
        :rtype: int (decimal base)
        """
        l = len(coef)
        indexFactor = l - 1
        even = 0
        odd = 0

        #Corner check for l = 1 or 2
        if l == 1:
            return coef[0]
        if l == 2:
            return (coef[0] + coef[1] * base)

        #If l > 2, determine initial value for even & odd
        if l % 2 == 0:
            odd, even = coef[0], coef[1]
        else:
            even, odd = coef[0], coef[1]

        #Polyn Calculation
        for i in range(2, l):
            index = abs(i - indexFactor)
            if index % 2 == 0:
                even = even * base * base + coef[i]
            if index % 2 != 0:
                odd = odd * base * base + coef[i]

        #multiply base for odd after loop
        odd *= base

        return (even + odd)

    def changeBase(self, num, base):
        """
        :type input
        num: int (number to convert)
        base: int (number system)
        :rtype: list[int]
        """
        res = []

        while num > base:
            r = num % base
            num = (num - r) / base
            res.insert(0, int(r))

        res.insert(0, int(num))

        return res

##############################################################################################
# Test Case
class UnitTest(unittest.TestCase):
    def test_check(self):
        test = NumberConvert()

        # TC - decimal to Number test
        # Arrange
        args = 397838, 27
        expected = [20, 5, 19, 20]
        #args = 235, 2
        #expected = [1, 1, 1, 0, 1, 0, 1, 1]
        # Act
        actual = test.changeBase(*args)
        # Assert
        print("Test Case #1 decimal to number test... ")
        self.assertEqual(actual, expected)

        # TC - 27 base test
        # Arrange
        args = [20, 5, 19, 20], 27
        expected = 397838
        # Act
        actual = test.polyEval(*args)
        # Assert
        print("Test Case #2 27 base test... ")
        self.assertEqual(actual, expected)

        # TC - binary base test
        # Arrange
        args = [1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1], 2
        expected = 2549
        # Act
        actual = test.polyEval(*args)
        # Assert
        print("Test Case #3 binary base test... ")
        self.assertEqual(actual, expected)

        # TC - octal base test
        # Arrange
        args = [1, 2, 3, 4, 5], 8
        expected = 5349
        # Act
        actual = test.polyEval(*args)
        # Assert
        print("Test Case #4 octal base test... ")
        self.assertEqual(actual, expected)

##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
