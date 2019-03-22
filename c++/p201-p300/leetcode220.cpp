// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 091                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<int> table;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            if (i > k) table.erase(nums[i - k - 1]);
            auto pos = table.lower_bound(nums[i] - t);
            if (pos != table.end() && *pos - nums[i] <= t) return true;
            table.insert(nums[i]);
        }
        return false;
    }
};

void test() {}

int main() { test(); return 0; }
