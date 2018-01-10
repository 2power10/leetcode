//
//  encode_and_decode_tinyurl.h
//  leetcode
//
//  Created by Yi Zheng on 10/01/2018.
//  Copyright © 2018 yizheng. All rights reserved.
//

#ifndef encode_and_decode_tinyurl_h
#define encode_and_decode_tinyurl_h

#include <string>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        auto result = url_map.find(longUrl);
        long long shortId;
        if (result == url_map.end())
        {
            shortId = static_cast<long long>(url_list.size());
            url_map[longUrl] = shortId;
            url_list.push_back(longUrl);
        }
        else
        {
            shortId = result->second;
        }
        
        stringstream ss;
        ss << shortId;
        return ss.str();
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        long long index = atoll(shortUrl.c_str());
        if (index < 0 || index >= url_list.size()) return "";
        return url_list[index];
    }
private:
    map<string, long long> url_map;
    std::vector<string> url_list;
};

std::string GetRandomNumAsStr(int max = INT_MAX)
{
    static std::once_flag flag;
    std::call_once(flag, []() {
        std::srand(static_cast<unsigned>(std::time(0)));
    });
    
    int random = std::rand() % max;
    std::stringstream ss;
    ss << random;
    return ss.str();
}

void Test()
{
    Solution solution;
    for (int i = 0 ; i < 10000 ; i ++)
    {
        auto url = GetRandomNumAsStr();
        auto decoded = solution.decode(solution.encode(url));
        if (url != decoded)
        {
            std::cout << "Failed\n";
        }
        else
        {
            std::cout << "Passed\n";
        }
    }
}

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

#endif /* encode_and_decode_tinyurl_h */
