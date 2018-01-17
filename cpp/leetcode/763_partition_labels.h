#ifndef partition_labels
#define partition_labels

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};

        vector<int> result;
        int start = 0;
        int furthest = start;
        while (start < S.size())
        {
            int cursor = S.size() - 1;
            while (cursor >= furthest)
            {
                if (S[cursor] == S[start]) break;
                cursor--;
            }
            if (cursor > furthest)  furthest = cursor;
            if (start == furthest) result.push_back(start);
            start++;
        }
        for (size_t i = result.size() - 1 ; i >= 1; --i)
        {
            result[i] = result[i] - result[i-1];
        }
        result[0] += 1;
        return result;
    }
};

void Test()
{
    Solution s;
    std::vector<std::tuple<string, std::vector<int>>> testCases =
    {
        std::make_tuple("ababcbacadefegdehijhklij", std::vector<int> {9,7,8}),
        std::make_tuple("", std::vector<int>{}),
        std::make_tuple("abcdefg", std::vector<int> {1,1,1,1,1,1,1}),
        std::make_tuple("acqwertyuioa", std::vector<int> {12}),
        std::make_tuple("abebced", std::vector<int> {1,5,1}),
    };
    
    for(auto tc : testCases)
    {
        string x;
        std::vector<int> expected, actual;
        std::tie(x, expected) = tc;
        actual = s.partitionLabels(x);
        if (actual.size() == expected.size())
        {
            bool isSuccess = true;
            for (int i = 0 ; i < actual.size() ; ++i)
            {
                if (actual[i] != expected[i])
                {
                    isSuccess = false;
                }
            }
            if (isSuccess)  cout << "Successed" << endl;
            else cout << "Failed" << endl;
        }
        else
        {
            cout << "Failed" << endl;
        }
    }
    
}



#endif
