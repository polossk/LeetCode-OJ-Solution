// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1009                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
public:
    int bitwiseComplement(int num)
    {
        if (num == 0) return 1;
        int64 save = num, flag = 1;
        while (num > 0) { flag <<= 1; num >>= 1; }
        return int((flag - 1) ^ save);
    }
};

void test() {}

int main() { test(); return 0; }
