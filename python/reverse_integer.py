class Solution(object):
    def reverse(self, x):
        s = 1
        if x < 0:
            s = -1
            x *= -1

        r = 0
        while x != 0:
            r *= 10
            r += x % 10
            x /= 10
        if r > 2147483647:
            r = 0
        return r * s

if __name__ == "__main__":
    s = Solution()
    tc = [-123, -0, 0, +0, 1, 10, 100, 123, 1234, 123456]
    for i in tc:
        print (s.reverse(i))



