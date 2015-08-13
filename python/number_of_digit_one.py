import sys
list = [1]
class Solution:

    def genList(self):
        i = 1
        maxLen = len(str(sys.maxint))
        while i < maxLen:
            baseval = pow(10, i)
            list.append(baseval + list[i-1] * 10)
            i += 1
    # @param {integer} n
    # @return {integer}
    def countDigitOne(self, n):
        if n < 0:
            return 0
        if len(list) == 1:
            self.genList()
        if n == 0:
            return 0

        if 10 > n >= 0:
            return 1

        topd = int(str(n)[0])
        restd = int(str(n)[1:])
        dlen = len(str(n))
        if topd == 1:
            val = restd + 1 + list[dlen-2]
        else:
            val = topd * list[dlen-2] + pow(10, dlen - 1)
        val += self.countDigitOne(restd)
        return val

# def test():
#     s = Solution()
#     assertEqual(s.countDigitOne(-1), 0)
#     assertEqual(s.countDigitOne(11), 4)
#     assertEqual(s.countDigitOne(10), 2)
#     assertEqual(s.countDigitOne(23), 13)
#     assertEqual(s.countDigitOne(100), 21)
#     assertEqual(s.countDigitOne(123), 57)
#     assertEqual(s.countDigitOne(5555), 2716)
#     assertEqual(s.countDigitOne(22343), 19775)
#     assertEqual(s.countDigitOne(111111), 66672)
#
#     total = 0
#     for i in range(0, 111112):
#         count = str(i).count('1')
#         total += count
#
#     print(str(i) + " " + str(total))