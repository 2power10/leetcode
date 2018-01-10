//
//  IntegertoRoman.h
//  leetcode
//
//  Created by Yi Zheng on 11/28/16.
//  Copyright © 2016 yizheng. All rights reserved.
//

#ifndef IntegertoRoman_h
#define IntegertoRoman_h

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> nv;
        while(num != 0)
        {
            nv.push_back(num % 10);
            num = num / 10;
        }
        std::string result = "";
        for (auto i : nv)
        {
//            auto map = GetMap(i);
        }
        return result;
    };
    
//    private std::unordered_map<int, std::string> GetMap(int d)
//    {
//        static std::unordered_map<int, std::unordered_map<int, std::string>> mapList = {
//            {
//                0, {
//                    {1, "I"},
//                    {2, "II"},
//                    {3, "III"},
//                    {4, "IV"},
//                    {5, "V"},
//                    {6, "VI"},
//                    {7, "VII"},
//                    {8, "VIII"},
//                    {9, "IX"}
//                },
//                1, {
//                    {1, "X"},
//                    {2, "XX"},
//                    {3, "XXX"},
//                    {4, "XL"},
//                    {5, "L"},
//                    {6, "LX"},
//                    {7, "LXX"},
//                    {8, "LXXX"},
//                    {9, "XC"}
//                },
//                2, {
//                    {1, "C"},
//                    {2, "CC"},
//                    {3, "CCC"},
//                    {4, "CD"},
//                    {5, "D"},
//                    {6, "DC"},
//                    {7, "DCC"},
//                    {8, "DCCC"},
//                    {9, "CM"}
//                },
//                3, {
//                    {1, "M"},
//                    {2, "MM"},
//                    {3, "MMM"}
//                }
//            }
//        };
//    }
};

#endif /* IntegertoRoman_h */
