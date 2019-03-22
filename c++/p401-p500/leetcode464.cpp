// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 464                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool canIWin(int hoge, int desiredTotal)
    {
        if (desiredTotal == 0) return true;
        if ((hoge + 1) * hoge / 2 < desiredTotal) return false;
        unordered_map<int, bool> dp;
        int rcd = 0;
        for (int i = 0; i <= hoge; i++)
        {
            rcd = (rcd << 1) + 1;
        }
        return f(desiredTotal, rcd, dp);
    }

    bool f(int dt, int rcd, unordered_map<int, bool> &dp)
    {
        if (dp.count(rcd)) return dp[rcd];
        for (int i = 20; i > 0; i--)
        {
            int bit = 1 << i;
            if (rcd & bit)
            {
                if (i >= dt) { return dp[i] = true; }
                bool flag = f(dt - i, rcd ^ bit, dp);
                dp[rcd ^ bit] = flag;
                if (!flag) return true;
            }
        }
        return false;
    }
};

void test() {}

int main() { test(); return 0; }
