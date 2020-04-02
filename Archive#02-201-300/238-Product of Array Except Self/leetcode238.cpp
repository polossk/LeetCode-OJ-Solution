// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 238                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int sz = nums.size();
        if (sz <= 1) return nums;
        vector<int> ans(sz, 1);
        for (int i = 0; i + 1 < sz; i++)
            ans[i + 1] = ans[i] * nums[i];
        int tmp = 1;
        for (int i = sz - 1; i >= 0; i--)
        {
            ans[i] *= tmp;
            tmp *= nums[i];
        }
        return ans;
    }
};

void test() {}

int main() { test(); return 0; }
