// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 045                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int ret = 0, right_most = 0, end_point = 0;
        for (int i = 0, sz = nums.size(); i < sz - 1; i++)
        {
            right_most = std::max(right_most, nums[i] + i);
            if (i == end_point) { end_point = right_most; ret++; }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
