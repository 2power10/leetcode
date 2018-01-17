//
//  461_hamming_distance.h
//  leetcode
//
//  Created by Yi Zheng on 14/01/2018.
//  Copyright © 2018 yizheng. All rights reserved.
//

#ifndef _61_hamming_distance_h
#define _61_hamming_distance_h

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int xor_xy = x ^ y;
        int result = 0;
        while (xor_xy)
        {
            result = result + (xor_xy & 1);
            xor_xy = xor_xy >> 1;
        }
        return result;
    }
};

void Test()
{
    Solution s;
    std::vector<std::tuple<int, int, int>> testCases =
    {
        std::make_tuple(0, 0 , 0),
        std::make_tuple(INT_MAX, 123 , 25)
    };
    
    for(auto tc : testCases)
    {
        int x, y, expected, actual;
        std::tie(x, y, expected) = tc;
        actual = s.hammingDistance(x, y);
        if (actual == expected) cout << "Pass\n";
        else cout << "Failed\n";
    }
}

#endif /* _61_hamming_distance_h */
