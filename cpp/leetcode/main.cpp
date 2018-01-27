//
//  main.cpp
//  leetcode
//
//  Created by Yi Zheng on 2016/11/2.
//  Copyright © 2016年 yizheng. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <set>
#include <thread>
#include <tuple>
#include <vector>

#include "utility.h"

using namespace std;

#include "442_find_all_duplicates_in_an_array.h"

int main(int argc, const char * argv[]) {
    auto start = chrono::system_clock::now();
    Test();
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::microseconds>(end - start);
    std::cout << diff.count() << " ms" << std::endl;
    return 0;
}


