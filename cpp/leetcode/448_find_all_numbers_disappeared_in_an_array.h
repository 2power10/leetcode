// This question is same with 442 with simple modification
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0 ; i < nums.size() ; )
        {
            int num = nums[i];
            if (num == 0 || num == -1)
            {
                ++i;
            }
            else if (nums[num-1] == 0)
            {
                nums[i] = -1;
                ++i;
            }
            else
            {
                nums[i] = nums[num-1];
                nums[num-1] = 0;
            }
        }
        vector<int> result;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] == -1)  result.push_back(i+1);
        }
        
        // sort(result.begin(), result.end());
        return result;
    }
};