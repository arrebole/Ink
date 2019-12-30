import unittest
import singleNumber

class TestSingleNumber(unittest.TestCase):

    def test_singleNumber(self):
        self.assertEqual(singleNumber.Solution().singleNumber([1,2,3,3,2,1,9,5,5]), 9)

if __name__ == '__main__':
    unittest.main()