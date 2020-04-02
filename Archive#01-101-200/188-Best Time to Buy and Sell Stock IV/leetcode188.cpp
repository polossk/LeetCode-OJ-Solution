// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 188                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    int maxProfit_inf(vector<int> &prices)
    {
        int dp_i0 = 0, dp_i1 = INT_MIN;
        for (int item : prices)
        {
            int tmp = dp_i0;
            dp_i0 = std::max(dp_i0, dp_i1 + item);
            dp_i1 = std::max(dp_i1, tmp - item);
        }
        return dp_i0;
    }
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k >= (prices.size() >> 1))
            return maxProfit_inf(prices);
        vector<int> dp0(k + 1, 0), dp1(k + 1, INT_MIN);
        for (int item : prices)
            for (int kk = k; kk > 0; kk--)
        {
            dp0[kk] = std::max(dp0[kk], dp1[kk] + item);
            dp1[kk] = std::max(dp1[kk], dp0[kk - 1] - item);
        }
        return dp0[k];
    }
};

void test() {}

int main() { test(); return 0; }
