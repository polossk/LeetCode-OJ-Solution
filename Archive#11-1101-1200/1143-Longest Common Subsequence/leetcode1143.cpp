// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1143                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int sz1 = text1.size(), sz2.text2.size();
        vector<int> dp(sz1 + 1, 0);
        int ret = 0;
        for (int j = 1; j <= sz2; j++)
        {
            int last = 0;
            for (int i = 1; i <= sz1; i++)
            {
                int tmp = dp[i];
                dp[i] = text1[i-1] == text2[j-1] ? (last + 1) : std::max(dp[i-1], dp[i]);
                ret = std::max(ret, dp[i]);
                last = tmp;
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
