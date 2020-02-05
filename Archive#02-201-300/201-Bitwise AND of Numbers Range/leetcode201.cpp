// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 201                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int hoge = m ^ n, ret = 0;
        for (int i = 1; ; i <<= 1)
        {
            if (i > n || i < 0) break;
            if (i > hoge) ret += i;
        }
        return ret & m;
    }
};

void test() {}

int main() { test(); return 0; }
