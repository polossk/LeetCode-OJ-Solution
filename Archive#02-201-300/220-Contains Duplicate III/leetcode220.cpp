// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 220                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using int64 = long long;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<int64> table;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            if (i > k) table.erase(nums[i - k - 1]);
            auto pos = table.lower_bound(nums[i] - int64(t));
            if (pos != table.end() && *pos - nums[i] <= t) return true;
            table.insert(nums[i]);
        }
        return false;
    }
};

void test() {}

int main() { test(); return 0; }
