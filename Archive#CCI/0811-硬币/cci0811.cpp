// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   CCI 0811                                                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
    static const int64 MOD = 1000000007;
public:
    int waysToChange(int n)
    {
        int64 ret = 0;
        for (int i = 0; i * 25 <= n; i++)
        {
            int rest = n - i * 25;
            int64 a = rest / 10;
            int64 b = rest % 10 / 5;
            ret = (ret + (a + 1) * (a + b + 1) % MOD) % MOD;
        }
        return int(ret);
    }
};

void test() {}

int main() { test(); return 0; }
