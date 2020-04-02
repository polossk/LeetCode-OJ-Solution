// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 221                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int maxlen = 0, prev = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
        {
            int tmp = dp[j];
            if (matrix[i-1][j-1] == '1')
            {
                dp[j] = std::min(dp[j], std::min(dp[j-1], prev)) + 1;
                maxlen = std::max(maxlen, dp[j]);
            }
            else dp[j] = 0;
            prev = tmp;
        }
        return maxlen * maxlen;
    }
};

void test() {}

int main() { test(); return 0; }
