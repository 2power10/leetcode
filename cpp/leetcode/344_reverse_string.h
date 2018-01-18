
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size() - 1;
        char tmp = 0;
        while (l < r)
        {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l;
            r--;
        }
        return s;
    }
};