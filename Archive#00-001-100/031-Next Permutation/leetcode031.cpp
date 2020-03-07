// <!-- encoding UTF-8 --!>
/*****************************************************************************
 *                     ----Stay Hungry Stay Foolish----                       *
 *   @author :   Shen                                                         *
 *   @name   :   Leetcode 031                                                 *
 *****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0)
        {
            while (nums[j] <= nums[i]) j--;
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }

    // std impl
    void nextPermutation(vector<int> &nums)
    {
        std::next_permutation(nums.begin(), nums.end());
    }
};

void test() {}

int main() { test(); return 0; }
