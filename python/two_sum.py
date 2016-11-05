class Solution(object):
    def twoSum(self, nums, target):
        dict = {}
        i = 0
        while i < len(nums):
            num = nums[i]
            if num not in dict:
                dict[num] = []
            dict[num].append(i)
            i += 1

        nums.sort()
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] + nums[j] == target:
                break
            if nums[i] + nums[j] < target:
                i += 1
            else:
                j -=1
        if nums[i] == nums[j]:
            return dict[nums[i]]
        else:
            return [dict[nums[i]][0], dict[nums[j]][0]]

# class Solution(object):
#     def twoSum(self, nums, target):
#         i = 0
#         while i < len(nums) - 1:
#             j = i + 1
#             while j < len(nums):
#                 if nums[i] + nums[j] == target:
#                     return [i, j]
#                 j += 1
#             i += 1

import time

if __name__ == "__main__":
    s = Solution()
    nums = range(10000)
    target = 6
    beg = time.time()
    result = s.twoSum(nums, target)
    end = time.time()
    print result
    print (end - beg)
