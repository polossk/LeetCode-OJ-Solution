// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 122                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int tmp = INT_MIN, ret = 0;
        for (int item : prices)
        {
            int prev = ret;
            ret = std::max(ret, tmp + item);
            tmp = std::max(tmp, prev - item);
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
