//
//  reverseWords.h
//  leetcode
//
//  Created by Yi Zheng on 12/1/16.
//  Copyright © 2016 yizheng. All rights reserved.
//

#ifndef reverseWords_h
#define reverseWords_h

#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        easyWay(s);
    }
    
    void easyWay(string &s) {
        if (s.empty())
            return;
        int begin = 0;
        int end = s.size() - 1;
        while (s[begin] == ' ' && begin <= end)
        {
            begin++;
        }
        while (s[end] == ' ' && end >= begin)
        {
            end--;
        }
        //empty string
        if (begin > end)
        {
            s = "";
            return;
        }
        
        string newS;
        int wordStart = -1;
        for (int i = begin ; i <= end; i ++)
        {
            if (s[i] == ' ' && wordStart != -1)
            {
                if (!newS.empty() && newS[0] != ' ')
                    newS.insert(0, " ");
                newS.insert(0, s.substr(wordStart, i - wordStart));
                wordStart = -1;
            }
            
            if (s[i] != ' ')
            {
                if (wordStart == -1)
                    wordStart = i;
            }
            
            if (i == end && wordStart != -1)
            {
                if (!newS.empty() && newS[0] != ' ')
                    newS.insert(0, " ");
                newS.insert(0, s.substr(wordStart, i - wordStart + 1));
                wordStart = -1;
            }
        }
        s = std::move(newS);
    }
    
    static void Test() {
        Solution s;
        std::vector<std::tuple<std::string, std::string>> testCases =
        {
            std::make_tuple("hello world", "world hello"),
            std::make_tuple(" hello world ", "world hello"),
            std::make_tuple("hello  world", "world hello"),
            std::make_tuple(" ", ""),
            std::make_tuple(" 1", "1"),
            std::make_tuple("a b", "b a"),
        };
        
        for(auto tc : testCases)
        {
            std::string input, expected;
            std::tie(input, expected) = tc;
            s.reverseWords(input);
            std::cout << input << " " << input.size() << std::endl << expected <<  " " << expected.size() <<std::endl << std::endl;
        }
    }
};

#endif /* reverseWords_h */
