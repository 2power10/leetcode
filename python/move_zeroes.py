class Solution(object):
    def moveZeroes(self, nums):
        curr = 0
        last = 0
        while curr < len(nums):
            if nums[curr] == 0:
                curr += 1
            else:
                nums[last] = nums[curr]
                if last != curr:
                    nums[curr] = 0
                last += 1
                curr += 1
