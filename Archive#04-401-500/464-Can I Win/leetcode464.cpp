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
    unordered_map<int, bool> dp_;
    static const int MAXI = 20;
    bool dfs(int desiredTotal, int mask)
    {
        if (dp_.count(mask)) return dp_[mask];
        for (int i = MAXI; i > 0; i--)
        {
            int bit = 1 << i;
            if (mask & bit)
            {
                if (i >= desiredTotal) { return dp_[i] = true; }
                bool flag = dfs(desiredTotal - i, mask ^ bit);
                dp_[mask ^ bit] = flag;
                if (!flag) return true;
            }
        }
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
#define hoge maxChoosableInteger
        if (hoge >= desiredTotal) return true;
        if ((((hoge + 1) * hoge) >> 1) < desiredTotal) return false;
        int mask = 0;
        for (int i = 0; i <= hoge; i++)
        {
            mask = (mask << 1) + 1;
        }
        return dfs(desiredTotal, mask);
#undef hoge
    }
};

void test() {}

int main() { test(); return 0; }
