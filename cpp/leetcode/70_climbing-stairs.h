//
//  climbing-stairs.h
//  leetcode
//
//  Created by Yi Zheng on 2018/6/22.
//  Copyright © 2018 yizheng. All rights reserved.
//

#ifndef climbing_stairs_h
#define climbing_stairs_h

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int p1 = 1;
        int p2 = 2;
        int new_p2 = 0;
        for (int i = 3; i <= n ; ++i)
        {
            new_p2 = p1 + p2;
            p1 = p2;
            p2 = new_p2;
        }
        return p2;
    }
};

void Test()
{
    std::vector<std::tuple<int, int>> tcs = {
        std::make_tuple(1,1),
        std::make_tuple(2,2),
        std::make_tuple(3,3),
        std::make_tuple(4,5),
        std::make_tuple(5,8),
    };
    
    int input;
    int expected = 0, result = 0;
    Solution s;
    for (auto tc : tcs)
    {
        std::tie(input, expected) = tc;
        result = s.climbStairs(input);
        bool isSuccess = (result == expected);
        std::cout << (isSuccess ? "Success " : "Failed  ");
        std::cout << "expected: "<< expected << "\tactual: " << result << std::endl;
    }
}
#endif /* climbing_stairs_h */
