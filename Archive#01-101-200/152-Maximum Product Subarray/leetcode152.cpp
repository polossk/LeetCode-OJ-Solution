// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 152                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int sz = nums.size(), ret = 0;
        if (sz == 0) return ret;
        int positive, negative, tmp_p, tmp_n;
        ret = tmp_p = tmp_n = nums[0];
        for (int i = 1; i < sz; i++)
        {
            positive = max(max(nums[i] * tmp_p, nums[i] * tmp_n), nums[i]);
            negative = min(min(nums[i] * tmp_p, nums[i] * tmp_n), nums[i]);
            ret = max(positive, ret);
            tmp_p = positive;
            tmp_n = negative;
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
