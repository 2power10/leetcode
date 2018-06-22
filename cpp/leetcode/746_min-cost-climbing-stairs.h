#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return std::min(cost[0], cost[1]);
        int p1 = cost[0];
        int p2 = cost[1];
        int new_p2 = 0;
        for (int i = 2; i < cost.size(); ++i)
        {
            new_p2 = std::min(p1, p2) + cost[i];
            p1 = p2;
            p2 = new_p2;
        }
        return std::min(p1,p2);
    }
};

void Test()
{
    std::vector<std::tuple<std::vector<int>, int>> tcs = {
        std::make_tuple(std::vector<int>({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}), 6),
        std::make_tuple(std::vector<int>({1, 1}), 1),
        std::make_tuple(std::vector<int>({1, 2}), 1),
        std::make_tuple(std::vector<int>({2, 1}), 1),
        std::make_tuple(std::vector<int>({0, 1, 2, 3, 2, 1, 0}), 4),
        std::make_tuple(std::vector<int>({999, 999, 999}), 999),
    };
    
    std::vector<int> input;
    int expected = 0, result = 0;
    Solution s;
    for (auto tc : tcs)
    {
        std::tie(input, expected) = tc;
        result = s.minCostClimbingStairs(input);
        bool isSuccess = (result == expected);
        std::cout << (isSuccess ? "Success " : "Failed  ");
        std::cout << "expected: "<< expected << "\tactual: " << result << std::endl;
    }
}
