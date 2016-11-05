class Solution(object):
    def maxSubArray(self, nums):
        maxsofar = nums[0]
        maxendinghere = nums[0]
        i = 1
        while i < len(nums):
            maxendinghere = max(maxendinghere + nums[i], 0)
            maxsofar = max(maxendinghere, maxsofar)

        return maxsofar
