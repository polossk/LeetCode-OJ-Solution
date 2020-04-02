// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 064                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            else
                dp[i][j] = grid[i][j] + std::min(dp[i][j-1], dp[i-1][j]);
        }
        return dp.back().back();
    }
};

void test() {}

int main() { test(); return 0; }
