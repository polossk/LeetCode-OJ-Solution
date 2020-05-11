// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 367                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
    constexpr static double EPS = 1e-7;
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        double a = x, x0 = x;
        while (true)
        {
            double x1 = 0.5 * (x0 + a / x0);
            if (fabs(x0 - x1) < EPS) break;
            x0 = x1;
        }
        return int(x0);
    }
public:
    bool isPerfectSquare(int num)
    {
        int64 x = mySqrt(num);
        return x * x == num;
    } 
};


class Solution {
public:
};

void test() {}

int main() { test(); return 0; }

