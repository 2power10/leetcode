class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        count_dict = {}
        i = 0
        l = len(nums)
        while i < l:
            num = nums[i]
            if count_dict.has_key(num):
                if i - count_dict[num] <= k:
                    return True
                else:
                    count_dict[num] = i
            else:
                count_dict[num] = i
            i += 1
        return False
