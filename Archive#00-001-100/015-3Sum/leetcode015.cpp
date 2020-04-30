// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 015                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using Tuple = std::vector<int>;
public:
    vector<Tuple> threeSum(vector<int> &nums)
    {
        vector<Tuple> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            int target = -nums[i];
            if (target < 0) break;
            int l = i + 1, r = sz - 1;
            while (l < r)
            {
                int cur = nums[l] + nums[r];
                if (cur < target) l++;
                else if (cur > target) r--;
                else
                {
                    ret.push_back(Tuple({nums[i], nums[l], nums[r]}));
                    while (l < r && nums[l] == ret.back().at(1)) l++;
                    while (l < r && nums[r] == ret.back().at(2)) r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return ret;
    }
};

void test() {
    typedef vector<int> TT;
    vector<TT> ret;
    ret.push_back(TT({1, 2, 3}));
    vector<int> _ = {1, 2, 3};
    for (int i = 0, sz = ret[0].size(); i < sz; i++)
        cout << ret[0][i] << " ";
}

int main() { test(); return 0; }
