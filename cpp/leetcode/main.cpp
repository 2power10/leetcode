//
//  main.cpp
//  leetcode
//
//  Created by Yi Zheng on 2016/11/2.
//  Copyright © 2016年 yizheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <locale>
#include <map>
#include <set>
#include <cmath>
#include <future>

#include "537_complex_multiplication.h"

using namespace std;


int main(int argc, const char * argv[]) {
    auto start = chrono::system_clock::now();
    Test();
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::microseconds>(end - start);
    std::cout << diff.count() << std::endl;
    return 0;
}


