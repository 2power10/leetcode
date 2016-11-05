class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        totalLen = len(nums1) + len(nums2)
        idx1 = totalLen / 2
        idx2 = idx1
        if totalLen % 2 == 0:
            idx2 = idx1 + 1

        m1 = self.fn(nums1, nums2, idx1)
        m2 = self.fn(nums1, nums2, idx2)
        return (m1 + m2) / 2.0

    def fn(self, nums1, nums2, idx):
        l1 = len(nums1)
        l2 = len(nums2)
        if l1 == 0:
            return nums2[idx]
        elif l2 == 0:
            return nums1[idx]
        else:
            mid = l1 / 2
            r = self.binarySearch(nums2, nums1[mid])
            if mid + r >= idx:
                # in python nums1[:mid] is not include mid
                return self.fn(nums1[:mid], nums2[0:r], idx)
            else:
                return self.fn(nums1[mid:], nums2[r + 1:], idx - mid - 1)

    #find position that ele <= arr
    def binarySearch(self, arr, ele):
        b = 0
        e = len(arr) - 1
        while b <= e:
            mid = (b + e) / 2
            if ele == arr[mid]:
                return mid
            elif ele > arr[mid]:
                b = mid + 1
            else:
                e = mid - 1
        return b

def assertEqual(a, b):
    text = str(a) + "==" + str(b)
    if a == b:
        text+= " PASS"
    else:
        text+= " FAILED"
    print text

def testBinarySearch():
    s = Solution()
    idx = s.binarySearch([2,3,4,5,6,7,8,9], 4.5)
    assertEqual(idx, 3)
    idx = s.binarySearch([2],1)
    assertEqual(idx, 0)
    idx = s.binarySearch([1,2],1)
    assertEqual(idx, 0)
    idx = s.binarySearch([1,2],2)
    assertEqual(idx, 1)
    idx = s.binarySearch([1,2,3],100)
    assertEqual(idx, 3)
    idx = s.binarySearch([1],100)
    assertEqual(idx, 1)


def testMedian():
    s = Solution()
    m = s.findMedianSortedArrays([1,3], [2])
    assertEqual(m, 2.0)

if __name__ == "__main__":
    testBinarySearch()
    testMedian()
