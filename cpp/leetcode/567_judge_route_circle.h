#ifndef judge_route_circle_h
#define judge_route_circle_h

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(const char c : moves)
        {
            switch(c)
            {
                case 'L':   --x; break;
                case 'R':   ++x; break;
                case 'U':   ++y; break;
                case 'D':   --y; break;
            }
        }
        return (x+y == 0);
    }
};


void Test()
{
    Solution s;
    std::vector<std::tuple<string, bool>> testCases =
    {
        std::make_tuple("", true),
        std::make_tuple("R", false),
        std::make_tuple("URLDDULR", true),
    };
    
    for(auto tc : testCases)
    {
        string x;
        bool expected, actual;
        std::tie(x, expected) = tc;
        actual = s.judgeCircle(x);
        if (actual == expected) cout << "Pass\n";
        else cout << "Failed\n";
    }
    
}
#endif
