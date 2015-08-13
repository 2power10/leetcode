class Solution:
    def overlap(self, A, B, C, D, E, F, G, H):
        if A > G:
            return 0
        if E > C:
            return 0
        if F > D:
            return 0
        if B > H:
            return 0

        RY = min(D, H)
        LX = max(A, E)
        RX = min(C, G)
        LY = max(B, F)

        return abs(RY - LY) * abs(RX - LX)
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        return abs((D - B) * (C - A)) + abs((H - F) * (G - E)) - self.overlap(A, B, C, D, E, F, G, H)


# def test():
#     s = Solution()
#     assertEqual(s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2), 45)
#     assertEqual(s.computeArea(-3, 0, 3, 4, 3, 0, 9, 2), 36)
#     assertEqual(s.computeArea(-3, -2, 0, 0, -1, -1, 9, 2), 35)
#     assertEqual(s.computeArea(-3, -2, 0, 0, 0, -1, 9, 2), 33)
#     assertEqual(s.computeArea(0, 0, 0, 0, 0, -0, 0, 0), 0)
#     assertEqual(s.computeArea(0, 0, 0, 0, -1, -1, 1, 1), 4)