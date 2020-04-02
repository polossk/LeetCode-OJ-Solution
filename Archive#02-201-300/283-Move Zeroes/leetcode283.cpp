// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 283                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (int i = 0, nz = 0, sz = nums.size(); i < sz; i++)
            if (nums[i])
                std::swap(nums[i], nums[nz++]);
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
