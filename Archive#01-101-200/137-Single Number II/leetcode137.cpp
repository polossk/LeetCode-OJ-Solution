// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 137                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0, b = 0;
        for (auto e : nums)
        {
            a = (a ^ e) & (~b);
            b = (b ^ e) & (~a);
        }
        return a;
    }
};

void test() {}

int main() { test(); return 0; }
