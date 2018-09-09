#!/usr/bin/env python3
import unittest

"""Number Convert

Usage:
    Used for number converting

"""

##############################################################################################
# Performance: ?%

class NumberConvert(object):
    def toDecimal(self, num, base):
        """
        :type input
        num: list[int] (number in other base to convert)
        base: int (number system)
        :rtype: list[int]
        """
        l = len(num)
        even = 0
        odd = 0

        if l % 2 == 0:
            odd = num[0]
            even = num[1]
        else:
            even = num[0]
            odd = num[1]

        for i in range(2, l):
            if i % 2 != 0:
                even = even * base * base + num[i]
            if i % 2 == 0:
                odd = odd * base * base + num[i]

        odd *= base

        return (even + odd)

    def toNum(self, num, base):
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

        # TC
        # Arrange
        args = 397838, 27
        expected = [20, 5, 19, 20]
        #args = 235, 2
        #expected = [1, 1, 1, 0, 1, 0, 1, 1]
        # Act
        actual = test.toNum(*args)
        # Assert
        print("Test Case #1... ")
        self.assertEqual(actual, expected)

        # TC
        # Arrange
        args = [20, 5, 19, 20], 27
        expected = 397838
        #args = [1, 1, 1, 0, 1, 0, 1, 1], 2
        #expected = 235
        #args = [1, 0, 1, 1], 2
        #expected = 11
        # Act
        actual = test.toDecimal(*args)
        # Assert
        print("Test Case #2... ")
        self.assertEqual(actual, expected)

##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
