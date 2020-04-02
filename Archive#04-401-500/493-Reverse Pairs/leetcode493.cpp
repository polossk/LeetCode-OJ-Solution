// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 493                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    int merge_sort(vector<int>::iterator first, vector<int>::iterator last)
    {
        if (last - first <= 1) return 0;
        auto mid = first + (last - first) / 2;
        int ret = merge_sort(first, mid) + merge_sort(mid, last);
        for (auto i = first, j = mid; i != mid; i++)
        {
            while (j != last && ( (*i) > 2LL * (*j) ) ) j++;
            ret += j - mid;
        }
        std::inplace_merge(first, mid, last);
        return ret;
    }
public:
    int reversePairs(vector<int>& nums)
    {
        return merge_sort(nums.begin(), nums.end());
    }
};

void test() {}

int main() { test(); return 0; }
