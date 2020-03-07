// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   COF 62                                                       *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        int ret = 0;
        // last round will just be 2 people left
        for (int i = 2; i <= n; i++)
            ret = (ret + m) % i;
        return ret;
    }
};


void test() {}

int main() { test(); return 0; }
