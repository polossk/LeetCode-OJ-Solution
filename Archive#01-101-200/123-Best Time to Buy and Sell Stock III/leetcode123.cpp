// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 123                                                 *
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
        int dp_i10 = 0, dp_i11 = INT_MIN, dp_i20 = 0, dp_i21 = INT_MIN;
        for (int item : prices)
        {
            dp_i20 = std::max(dp_i20, dp_i21 + item);
            dp_i21 = std::max(dp_i21, dp_i10 - item);
            dp_i10 = std::max(dp_i10, dp_i11 + item);
            dp_i11 = std::max(dp_i11, -item);
        }
        return dp_i20;
    }
};

void test() {}

int main() { test(); return 0; }
