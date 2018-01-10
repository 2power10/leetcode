//
//  reverseInteger.h
//  leetcode
//
//  Created by Yi Zheng on 11/5/16.
//  Copyright © 2016 yizheng. All rights reserved.
//

#ifndef reverseInteger_h
#define reverseInteger_h

#include <vector>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int remain = 0;
        while (x != 0) {
            if (INT_MAX / 10 < result ||
                INT_MIN / 10 > result) {
                return 0;
            }
            remain = x % 10;
            x = x / 10;
            result = result * 10 * remain;
        }
        return result;
    };
    
    static void Test(){
        // int max  2147483647
        // int min -2147483648
        std::vector<std::tuple<int, int>> tcs = {
            std::make_tuple(10, 01),
            std::make_tuple(0, 0),
            std::make_tuple(1, 1),
            std::make_tuple(-123, -321),
            std::make_tuple(123, 321),
            std::make_tuple(2147483647, 0),
            std::make_tuple(-2147483647, 0)
        };
        
        int input = 0, expected = 0, result = 0;
        Solution s;
        for (auto tc : tcs)
        {
            std::tie(input, expected) = tc;
            result = s.reverse(input);
            std::cout << expected << "\t" << result << std::endl;
        }
    }
};

#endif /* reverseInteger_h */
