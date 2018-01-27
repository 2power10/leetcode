class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0 ; i < nums.size() ; )
        {
            int num = nums[i];
            if (num == 0 || num == -1)
            {
                ++i;
            }
            else if (nums[num-1] == 0)
            {
                result.push_back(num);
                nums[i] = -1;
                ++i;
            }
            else
            {
                nums[i] = nums[num-1];
                nums[num-1] = 0;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

void Test()
{
    Solution s;
    vector<int> input = {4,3,2,7,8,2,3,1};
    auto result = s.findDuplicates(input);
    printVec(result);
}
