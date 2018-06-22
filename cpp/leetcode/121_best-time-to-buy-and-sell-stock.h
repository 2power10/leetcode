//
//  best-time-to-buy-and-sell-stock.h
//  leetcode
//
//  Created by Yi Zheng on 2018/6/22.
//  Copyright © 2018 yizheng. All rights reserved.
//

#ifndef best_time_to_buy_and_sell_stock_h
#define best_time_to_buy_and_sell_stock_h

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int max_profit = 0;
        int max_buy = 0;
        int min_val = prices[0];
        int min_loc = 0;
        
        for (int i = 1 ; i < prices.size(); ++i)
        {
            int profit_to_min = prices[i] - min_val;
            int profit_to_buy = prices[i] - prices[max_buy];
            if (max_profit <= profit_to_min ||
                max_profit <= profit_to_buy)
            {
                if (max_profit == profit_to_min)
                {
                    if (prices[max_buy] > prices[min_loc])
                        max_buy = min_val;
                }
                if (profit_to_buy > max_profit)
                {
                    max_profit = profit_to_buy;
                }
                if (profit_to_min > max_profit)
                {
                    max_profit = profit_to_min;
                    max_buy = min_val;
                }
            }
            if (prices[i] < min_val)
            {
                min_val = prices[i];
                min_loc = i;
            }
        }
        return max_profit;
    }
};

void Test()
{
    std::vector<std::tuple<vector<int>, int>> tcs = {
        std::make_tuple(vector<int>{1},0),
        std::make_tuple(vector<int>{1, 2},1),
        std::make_tuple(vector<int>{5, 7, 2, 8},6),
        std::make_tuple(vector<int>{5, 7, 2, 4, 3, 2, 6},4),
        std::make_tuple(vector<int>{9, 8, 7, 6, 5, 4, 3},0),
        std::make_tuple(vector<int>{7,1,5,3,6,4},5),
        std::make_tuple(vector<int>{2,1,2,1,0,1,2},2),
        std::make_tuple(vector<int>{2,7,1,4,11},10),
    };
    
    vector<int> input;
    int expected = 0, result = 0;
    Solution s;
    for (auto tc : tcs)
    {
        std::tie(input, expected) = tc;
        result = s.maxProfit(input);
        bool isSuccess = (result == expected);
        std::cout << (isSuccess ? "Success " : "Failed  ");
        std::cout << "expected: "<< expected << "\tactual: " << result << std::endl;
    }
}
#endif /* best_time_to_buy_and_sell_stock_h */
