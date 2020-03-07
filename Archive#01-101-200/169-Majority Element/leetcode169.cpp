// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 169                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    // Boyer-Moore Majority Voting Algorithm
    int majorityElement(vector<int>& nums)
    {
        int cur = 0, cnt = 0;
        for (auto elem : nums)
        {
            if (cnt == 0) cur = elem;
            cnt += cur == elem ? 1 : -1;
        }
        return cur;
    }
    // Bit Checking
    int majorityElement(vector<int>& nums)
    {
        int ret = 0, threshold = nums.size() >> 1;
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (auto elem : nums) cnt += (elem >> i) & 1;
            ret += (cnt > threshold) << i;
        }
        return ret;
    }
    // Sorting
    int majorityElement(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};

void test() {}

int main() { test(); return 0; }
