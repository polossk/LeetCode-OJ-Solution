// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   COF 56A                                                      *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    vector<int> singleNumbers(vector<int>& nums)
    {
        int hoge = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        hoge &= -hoge;
        vector<int> ret(2, 0);
        for (int num : nums)
            ret[!(num & hoge)] ^= num;
        return ret;
    }
};


void test() {}

int main() { test(); return 0; }
