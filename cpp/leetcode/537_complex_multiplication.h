#ifndef complex_muliplication_h
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a_real = 0, b_real = 0;
        int a_imag = 0, b_imag = 0;
        int r_real = 0, r_imag = 0;
        parseComplex(a, a_real, a_imag);
        parseComplex(b, b_real, b_imag);

        r_real = a_real * b_real - a_imag * b_imag;
        r_imag = a_real * b_imag + b_real * a_imag;
        stringstream ss;
        ss << r_real << "+" << r_imag << "i";
        return ss.str();
    }

    void parseComplex(string num, int &real, int &imaginary)
    {
        num.substr(0, num.size()-1);
        auto plusPos = num.find('+');
        string realStr = num.substr(0, plusPos);
        string imaStr = num.substr(plusPos+1, num.size() - plusPos - 1);
        real = std::atoi(realStr.c_str());
        imaginary = std::atoi(imaStr.c_str());
    }
};

void Test()
{
    Solution s;
    std::vector<std::tuple<string, string, string>> testCases =
    {
        std::make_tuple("1+1i", "1+1i", "0+2i"),
        std::make_tuple("1+-1i", "1+-1i", "0+-2i"),
        std::make_tuple("1+-1i", "1+1i", "2+0i"),
    };
    
    for(auto tc : testCases)
    {
        string input1, input2;
        string expected, actual;
        std::tie(input1, input2, expected) = tc;
        actual = s.complexNumberMultiply(input1, input2);
        if (actual == expected) cout << "Pass\n";
        else cout << "Failed\n";
    }
    
}

#define complex_muliplication_h
#endif
