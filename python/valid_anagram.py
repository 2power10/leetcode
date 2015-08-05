__author__ = 'yzheng'

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        arrs = []
        arrt = []
        for num in range(26):
            arrs.append(0)
            arrt.append(0)

        aord = ord('a')
        for c in s:
            idx = ord(c) - aord
            arrs[idx] += 1

        for c in t:
            idx = ord(c) - aord
            arrt[idx] += 1

        i = 0
        while i < len(arrs):
            if arrs[i] != arrt[i]:
                return False
            i += 1

        return True
