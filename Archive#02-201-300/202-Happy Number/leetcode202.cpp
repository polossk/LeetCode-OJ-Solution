// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 202                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
    // bit equals to 1 if and only if index equals to 1 or 7
    // diagram for that
    // bit index: 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // bit value:  0  0  1  0  0  1  0  0  1  0  0  0  0  0  1  0
    // hex value:           2           4           8           2
    const std::bitset<16> ans = std::bitset<16>(0x2482);
    
    inline int next(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            ret += d * d;
        }
        return ret;
    }
public:
    bool isHappy(int n)
    {
        while (n >= 16) n = next(n);
        return ans[n];
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
