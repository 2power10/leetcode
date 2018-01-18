#ifndef counting_bits_h
#define counting_bits_h

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bitVec(num+1, 0);
        int range = 1;
        for (int i = 1; i <= num; ++i)
        {
            if (i == 2*range) range *= 2;
            bitVec[i] = bitVec[i - range] + 1;
        }
        return bitVec;
    }
};

void print(vector<int> vec)
{
    for (auto & i : vec)
    {
        cout << i << " ";
    }
    cout << '\n';
}

void Test()
{
    Solution s;
    vector<tuple<int, vector<int>>> testCases =
    {
        make_tuple<int, vector<int>>(0, {0}),
        make_tuple<int, vector<int>>(1, {0, 1}),
        make_tuple<int, vector<int>>(2, {0, 1, 1}),
        make_tuple<int, vector<int>>(3, {0, 1, 1, 2}),
        make_tuple<int, vector<int>>(4, {0, 1, 1, 2, 1}),
        make_tuple<int, vector<int>>(5, {0, 1, 1, 2, 1, 2}),
        make_tuple<int, vector<int>>(6, {0, 1, 1, 2, 1, 2, 2}),
        make_tuple<int, vector<int>>(7, {0, 1, 1, 2, 1, 2, 2, 3}),
        make_tuple<int, vector<int>>(8, {0, 1, 1, 2, 1, 2, 2, 3, 1}),
        make_tuple<int, vector<int>>(9, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2}),
    };
    
    for(auto tc : testCases)
    {
        int input;
        vector<int> expected, actual;
        tie(input, expected) = tc;
        actual = s.countBits(input);
        print(actual);
        print(expected);
        print({});
    }
}

#endif
