//
//  longestPalindrome.h
//  leetcode
//
//  Created by Yi Zheng on 2016/11/2.
//  Copyright © 2016年 yizheng. All rights reserved.
//

#ifndef longestPalindrome_h
#define longestPalindrome_h

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.empty())
            return "";
        int s_size = (int)s.size();
        
        
        double curr = (s_size - 1) / 2.0;
        double minBound = 0;
        double maxBound = s_size - 1;
        
        double leftBound = minBound;
        double rightBound = maxBound;
        
        int direction = 1;
        double distance = 0.5;
        int maxLen = -1;
        double maxPos = 0.0;
        
        while (curr >= leftBound && curr <= rightBound)
        {
            int paliLen = getCurrPalindromeSize(s, curr);
            if (paliLen > maxLen)
            {
                maxLen = paliLen;
                maxPos = curr;
            }
            curr += distance * direction;
            distance += 0.5;
            direction *= -1;
            
            leftBound = max<double>((maxLen - 1) / 2.0, 0);
            rightBound = min<double>((s_size - maxLen + s_size) / 2.0, maxBound);
        }
        if (maxLen == 1)
            return s.substr(0, 1);
        else
            return getString(s, maxPos, maxLen);
    }
    
    std::string getString(const string & s, double pos, int len)
    {
        int start = 0;
        if ( int(pos/0.5) % 2 == 0 )
        {
            start = pos - (len / 2.0 - 0.5);
        }
        else
        {
            start = pos - (len - 1) / 2;
        }
        return s.substr(start, len);
    }
    
    int getCurrPalindromeSize(const string &s, double pos)
    {
        int length = (int)s.size();
        int size = 0;
        double distance = 0.5;
        if ( int(pos/0.5) % 2 == 0 )
        {
            size = 1;
            distance = 1;
        }
        
        int left = (int) (pos - distance);
        int right = (int) (pos + distance);
        while (right < length && left >= 0)
        {
            if (s[left] == s[right])
            {
                size += 2;
                distance += 1;
            }
            else
            {
                break;
            }
            left = (int)(pos - distance);
            right = (int)(pos + distance);
        }
        
        return size;
    }
};

void TestLongestPalindrome()
{
    Solution solution;
    std::vector<std::tuple<std::string, std::string>> testCases = {
        std::make_tuple("abcccbb", "bcccb"),
        std::make_tuple("bbbbbbbbbb", "bbbbbbbbbb"),
        std::make_tuple("abcddefg", "dd"),
        std::make_tuple("a", "a"),
        std::make_tuple("abb", "bb"),
        std::make_tuple("aab", "aa"),
        std::make_tuple("abcda", "a"),
    };
    for(auto testCase : testCases)
    {
        std::string input, expected;
        std::tie(input, expected) = testCase;
        auto result = solution.longestPalindrome(input);
        std::cout << result << "\t" << expected << std::endl;
    }
    
    std::vector<std::tuple<std::string, double, int>> testCases2 = {
        std::make_tuple("abc", 1, 1),
        std::make_tuple("abc", 0, 1),
        std::make_tuple("abbbbc", 2, 3),
        std::make_tuple("abbbbc", 2.5,4),
        std::make_tuple("abbbbc", 3,3),
        std::make_tuple("abbbbc", 4,1),
        std::make_tuple("abbbbc", 5,1),
        std::make_tuple("abcccb", 3.5,2),
        std::make_tuple("abcccb", 3,5),
        
    };
    
    for(auto tc : testCases2)
    {
        std::string s;
        int expected;
        double p;
        std::tie(s, p, expected) = tc;
        int result = solution.getCurrPalindromeSize(s, p);
        std::cout << result << "\t" << expected << std::endl;
    }
    
};
#endif /* longestPalindrome_h */
