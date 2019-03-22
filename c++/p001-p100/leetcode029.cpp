// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 029                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    typedef long long int64;
public:
    int divide(int dividend, int divisor)
    {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = 1 - (((dividend > 0) ^ (divisor > 0)) << 1);
        int64 a = labs(dividend), b = labs(divisor);
        int ret = 0;
        while (a >= b)
        {
            int64 tmp = b, hoge = 1;
            while (a >= (tmp << 1)) { tmp <<= 1; hoge <<= 1; }
            a -= tmp; ret += hoge;
        }
        return sign * ret;
    }
};

void test() {}

int main() { test(); return 0; }
