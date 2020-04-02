// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 053                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int sz = nums.size(), ret = 0, tmp = 0;
        if (sz == 0) return ret;
        tmp = ret = nums[0];
        for (int i = 1; i < sz; i++)
        {
            tmp = max(0, tmp) + nums[i];
            ret = max(ret, tmp);
        }
        return ret;
    }
};


void test() {}

int main()
{
    test();
    return 0;
}
