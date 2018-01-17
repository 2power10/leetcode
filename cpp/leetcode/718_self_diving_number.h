#ifndef self_diving_number_h
#define self_diving_number_h

#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ret;
        for (int i = left; i <= right ; ++i)
        {
            if (isSelfDiving(i))  ret.push_back(i);
        }
        return ret;
    }

    bool isSelfDiving(int val)
    {
        int org = val;
        while (val)
        {
            int div = val % 10;
            if (div == 0)       return false;
            if (org % div != 0) return false;
            val = val/10;
        }
        return true;
    }
};


void Test()
{
    Solution s;
    auto r = s.selfDividingNumbers(1, 10000);
    bool a[10000];
    memset(&a, 0, sizeof(bool)*10000);
    cout << "{";
    for (auto v : r)
    {
        a[v-1] = true;
    }
    for (auto b : a)
    {
        cout << boolalpha << b << ",";
    }
    cout << "};";
}
#endif
