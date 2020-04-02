// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 887                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    static const int MAXN = 10000 + 5;
    int dp[2][MAXN + 1];
public:
    int superEggDrop(int K, int N)
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j <= N; j++) dp[1][j] = j; // dp[1][j]
        for (int i = 2; i <= K; i++)
        {
            int f = i & 1, k = 1; // f is flag
            for (int j = 1; j <= N; j++)
            {
                while (k < j && (max(dp[1-f][k-1], dp[f][j-k])
                        >= max(dp[1-f][k], dp[f][j-k-1]))) k++;
                dp[f][j] = 1 + max(dp[1-f][k-1], dp[f][j-k]);
            }
        }
        return dp[K&1][N];
    }
};

void test() {}

int main() { test(); return 0; }
