// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 072                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        if (n * m == 0) return n + m;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
        {
            // dp[i-1][j-1] --> dp[i-1][j]
            //  |                |
            //  V                V
            // dp[ i ][j-1] --> dp[ i ][j]
            int ii = dp[i - 1][j] + 1;
            int jj = dp[i][j - 1] + 1;
            int ij = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
            dp[i][j] = min(ii, min(jj, ij));
        }
        return dp[n][m];
    }
};

void test() {}

int main() { test(); return 0; }
