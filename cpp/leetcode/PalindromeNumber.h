//
//  PalindromeNumber.h
//  leetcode
//
//  Created by Yi Zheng on 11/5/16.
//  Copyright © 2016 yizheng. All rights reserved.
//

#ifndef PalindromeNumber_h
#define PalindromeNumber_h

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int r = reverse(x);
        return r == x;
    };
    
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
            result = result * 10 + remain;
        }
        return result;
    };
    
    static void Test(){
        // int max  2147483647
        // int min -2147483648
        std::vector<std::tuple<int, bool>> tcs = {
            std::make_tuple(10, false),
            std::make_tuple(2147483647, false),
            std::make_tuple(1234321, true),
            std::make_tuple(22222, true),
            std::make_tuple(554455, true),
            std::make_tuple(-2147447412, false),
        };
        
        int input = 0;
        bool expected = 0, result = 0;
        Solution s;
        for (auto tc : tcs)
        {
            std::tie(input, expected) = tc;
            result = s.isPalindrome(input);
            std::cout << "expected: "<< expected << "\tactual: " << result << std::endl;
        }
    }

};

#endif /* PalindromeNumber_h */
