
class Solution:
    def calc(self, beg, end):
        if beg is None:
            return ""
        if end is None:
            return str(beg)
        if beg == end:
            return str(beg)
        return str(beg) + "->" + str(end)

    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        beg = None
        end = None
        i = 0
        list = []
        length = len(nums)
        while i < length:
            if beg is None:
                beg = nums[i]
            if end is None:
                end = nums[i]

            if i < length - 1:
                if nums[i + 1] == nums[i] + 1:
                    end = nums[i+1]
                else:
                    list.append(self.calc(beg, end))
                    beg = None
                    end = None
            else:
                list.append(self.calc(beg, end))
            i += 1
        return list
# def test1():
#     s = Solution()
#     l1 = s.summaryRanges([1, 2, 3, 4, 5, 6, 7, 8, 9])
#     assertEqual(len(l1), 1)
#     assertEqual(l1[0], "1->9")
#
#     l2 = s.summaryRanges([1, 3, 5, 7, 8, 9, 10, 12])
#     assertEqual(len(l2), 5)
#     assertEqual(l2[0], "1")
#     assertEqual(l2[1], "3")
#     assertEqual(l2[2], "5")
#     assertEqual(l2[3], "7->10")
#     assertEqual(l2[4], "12")
#
#     l3 = s.summaryRanges([])
#     assertEqual(len(l3), 0)