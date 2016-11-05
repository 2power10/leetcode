class Solution(object):
    def searchRange(self, nums, target):
        pos = self.binarySearch(nums, target, 0, len(nums)-1)
        if pos == -1:
            return [-1, -1]

        forward = 0
        backward = 0
        reachLeft = False
        reachRight = False

        while not reachLeft or not reachRight:
            if not reachLeft:
                backward -= 1
                if backward + pos < 0 or nums[backward + pos] != target:
                    reachLeft = True
                    backward += 1

            if not reachRight:
                forward += 1
                if forward + pos > len(nums) - 1 or nums[forward + pos] != target:
                    reachRight = True
                    forward -= 1

        return [pos+backward, pos+forward]

    def binarySearch(self, nums, target, f, t):
        if f > t:
            return -1

        mid = (f + t) / 2
        if nums[mid] < target:
            return self.binarySearch(nums, target, mid+1, t)
        elif nums[mid] > target:
            return self.binarySearch(nums, target, f, mid-1)
        elif nums[mid] == target:
            return mid


if __name__ == "__main__":
    s = Solution()
    r = s.searchRange([2,2],1)
    print(r)
    r = s.searchRange([8,8],8)
    print(r)
    r = s.searchRange([8,8,8,8,8,8,8],8)
    print(r)
    r = s.searchRange([],8)
    print(r)
    r = s.searchRange([1],8)
    print(r)
