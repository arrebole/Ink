#! /usr/env python3

import unittest
from countPrimes import Solution

class TestSolution(unittest.TestCase):

    def test_countPrimes(self):
        self.assertEqual(Solution().countPrimes(10), 4)
        self.assertEqual(Solution().countPrimes(3), 1)


if __name__ == '__main__':
    unittest.main()