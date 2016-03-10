class Solution(object):
    def removeDuplicates(self, nums):
        if len(nums) == 0:
            return 0

        curr = 0
        last = 0
        while curr < len(nums):
            if nums[last] == nums[curr]:
                curr += 1
            else:
                last += 1
                nums[last] = nums[curr]
                curr += 1

        return last + 1