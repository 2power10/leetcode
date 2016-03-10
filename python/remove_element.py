class Solution(object):
    def removeElement(self, nums, val):
        if len(nums) == 0:
            return 0

        curr = 0
        last = 0
        while curr < len(nums):
            if nums[curr] == val:
                curr += 1
            else:
                nums[last] = nums[curr]
                last += 1
                curr += 1

        return last