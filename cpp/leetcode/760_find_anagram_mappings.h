//
//  760_find_anagram_mappings.h
//  leetcode
//
//  Created by Yi Zheng on 09/01/2018.
//  Copyright © 2018 yizheng. All rights reserved.
//

#ifndef _60_find_anagram_mappings_h
#define _60_find_anagram_mappings_h

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B)
    {
        std::unordered_map<int, int> bmap;
        
        for (int i = 0 ; i < B.size(); ++i)
        {
            bmap[B[i]] = i;
        }
        std::vector<int> result;
        for (const auto& v : A)
        {
            result.push_back(bmap[v]);
        }
        return result;
    }
    
    static void print(vector<int>& vec)
    {
        std::cout << "size : " << vec.size() << ' ';
        for (auto & i : vec)
        {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
    
    static void Test()
    {
        Solution s;
        std::vector<std::tuple<vector<int>, vector<int>, vector<int>>> testCases =
        {
            std::make_tuple<vector<int>, vector<int>, vector<int>>({1}, {1}, {0}),
            std::make_tuple<vector<int>, vector<int>, vector<int>>({3,2,1,1}, {1,2,3,3}, {3,1,0,0}),
            std::make_tuple<vector<int>, vector<int>, vector<int>>({}, {}, {})
        };
        
        for(auto tc : testCases)
        {
            vector<int> inputA, inputB, expected, actual;
            std::tie(inputA, inputB, expected) = tc;
            actual = s.anagramMappings(inputA, inputB);
            print(actual);
            print(expected);
        }
    }
};

#endif /* _60_find_anagram_mappings_h */

