class Solution(object):
    def reverseWords(self, s):
        if s is None or len(s) == 0:
            return s
        wordlist = s.strip().split(' ')
        idx = len(wordlist) - 1
        result = ""
        while idx >= 0:
            if len(wordlist[idx]) == 0:
                idx -= 1
                continue

            result += wordlist[idx]
            if idx >0:
                result += ' '
            idx -= 1
        return result


if __name__ == "__main__":
    s = Solution()
    r = s.reverseWords("this   is great ")
    print(r)
    r = s.reverseWords("")
    print(r)
    r = s.reverseWords("this is greata...d.d.af  ")
    print(r)
