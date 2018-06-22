class Solution {
public:
    int singleNonDuplicate(vector<int> nums) {
        auto beg = 0;
        auto end = nums.size() - 1;
        while (beg != end)
        {
            auto mid = (beg + end) / 2;
            if (nums[mid] == nums[mid - 1]) end = mid;
            else beg = mid;
        }
        return nums[beg];
    }
};


void Test()
{
    Solution s;
    auto actual1 = s.singleNonDuplicate({1,2,2,3,3});
    auto actual2 = s.singleNonDuplicate({1});
    auto actual3 = s.singleNonDuplicate({1,1,4,5,5});
}
