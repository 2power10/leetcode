
class Solution {
public:
    string reverseWords(string s) {
        auto beg = 0;
        for (int i = 0 ; i < s.size() ; i ++)
        {
            if (s[i] == ' ')
            {
                if (beg != -1) std::reverse(s.begin() + beg, s.begin() + i);
                beg = -1;
            }
            else
            {
                if (beg == -1)  beg = i;
            }
        }
        if (!s.empty() && beg != -1) std::reverse(s.begin() + beg, s.end());
        return s;
    }
};

void Test()
{
    Solution s;
    vector<tuple<string, string>> testCases =
    {
        make_tuple<string, string>("", ""),
        make_tuple<string, string>(" ", " "),
        make_tuple<string, string>(" a", " a"),
        make_tuple<string, string>("a ", "a "),
        make_tuple<string, string>(" a ", " a "),
        make_tuple<string, string>("abc", "cba"),
        make_tuple<string, string>("abc abc", "cba cba"),
        make_tuple<string, string>(" abc abc", " cba cba"),
        make_tuple<string, string>("abc abc ", "cba cba ")
    };

    for(auto tc : testCases)
    {
        string input, expected;
        tie(input, expected) = tc;
        auto actual = s.reverseWords(input);
        if (actual == expected) cout << "Pass\n";
        else
        {
            cout << "Failed - |" << expected << "|" << actual << "|\n";
        }
    }
}
