
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0 ; i < s.size() * 2 ; ++i)
        {
            int pos = i / 2;
            int div = i % 2;
            count += countFromMid(s, pos, div);
        }
        return count;
    }
    
    int countFromMid(string &s, int pos, int div) {
        int count = 0;
        int distance = 1;
        if (div == 0) count ++;
        int left = pos - distance + div;
        int right = pos + distance;
        while (right < s.size() &&
               left >= 0)
        {
            if (s[left] != s[right]) break;
            count ++;
            left --;
            right ++;
        }
        return count;
    }
};

void Test()
{
    vector<std::tuple<string, int> > testCases =
    {
        {"", 0},
        {"a", 1},
        {"aa", 3},
        {"aaa", 6},
        {"fdsklf", 6}
    };
    Solution s;
    for (auto tc : testCases)
    {
        string input;
        int expected = 0, actual = 0;
        tie(input, expected) = tc;
        actual = s.countSubstrings(input);
        if (expected == actual) cout << "Passed\n";
        else cout << "Failed\n";
    }
    
}
