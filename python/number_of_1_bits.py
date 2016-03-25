class Solution(object):
    def hammingWeight(self, n):
        return bin(n).count('1')

#
# class Solution(object):
#     def hammingWeight(self, n):
#         n = (n & 0x55555555) + ((n & 0xaaaaaaaa) >> 1)
#         n = (n & 0x33333333) + ((n & 0xcccccccc) >> 2)
#         n = (n & 0x0f0f0f0f) + ((n & 0xf0f0f0f0) >> 4)
#         n = (n & 0x00ff00ff) + ((n & 0xff00ff00) >> 8)
#         n = (n & 0x0000ffff) + ((n & 0xffff0000) >> 16)
#         return n

#
# class Solution(object):
#     def hammingWeight(self, n):
#         c = 0
#         while n != 0:
#             n &= (n - 1)
#             c += 1
#         return c
