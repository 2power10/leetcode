import sys
class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        if n < 1:
            return False
        if n == 1:
            return True
        if n % 2 != 0:
            return False
        maxint = sys.maxint
        i = 2
        while i < maxint:
            if i == n:
                return True
            i <<= 1
        return False