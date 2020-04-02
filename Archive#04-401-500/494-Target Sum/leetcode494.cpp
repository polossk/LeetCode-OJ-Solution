// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 494                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int64 sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (((sum + S) & 1) || S > sum) return 0;
        int T = (sum + S) >> 1;
        vector<int> dp(T + 1, 0); dp[0] = 1;
        for (auto e : nums)
            for (int j = T; j >= e; j--)
                dp[j] += dp[j - e];
        return dp[T];
    }
};

void test() {}

int main() { test(); return 0; }
