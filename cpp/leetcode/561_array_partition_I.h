#ifndef array_partition_I
#define array_partition_I

#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};


void Test()
{
    Solution s;
    std::vector<std::tuple<std::vector<int>, int>> testCases =
    {
        std::make_tuple(std::vector<int> {9,7,8,9}, 16),
        std::make_tuple(std::vector<int> {1,4,3,2}, 4),
    };
    
    for(auto tc : testCases)
    {
        int expected, actual;
        std::vector<int> input;
        std::tie(input, expected) = tc;
        actual = s.arrayPairSum(input);
        if (actual == expected) cout << "Successed" << endl;
        else cout << "Failed" << endl;
    }
    
}

#endif
