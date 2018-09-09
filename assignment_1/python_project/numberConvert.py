#!/usr/bin/env python3
import unittest

"""Number Convert

Usage:
    Used for number converting

"""

##############################################################################################
# Performance: ?%

class NumberConvert(object):
    def toDecimal(self, num, sys):
        """
        :type input
        a: int (number to convert)
        b: int (number system)
        :rtype: list[int]
        """
        res = []

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
        print(actual)
        self.assertEqual(actual, expected)

##############################################################################################
# Script Section - Call Test Cases
if __name__ == '__main__':
    unittest.main()
##############################################################################################
