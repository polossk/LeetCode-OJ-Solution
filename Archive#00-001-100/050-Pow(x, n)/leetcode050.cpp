// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 050                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
    double qmul(double x, int64 n)
    {
        double ret = 1.0;
        while (n)
        {
            if (n & 1) ret *= x;
            n >>= 1;
            x *= x;
        }
        return ret;
    }
public:
    double myPow(double x, int n)
    {
        return n >= 0 ? qmul(x, n) : 1.0 / qmul(x, -int64(n));
    }
};

void test() {}

int main() { test(); return 0; }
