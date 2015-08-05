class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        try:
            float(s)
            return True
        except Exception:
            return False