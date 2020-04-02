// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 327                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    multimap<int64_t, int> _hash;
    vector<int64_t> _prefix;
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        _hash.clear(); _prefix.clear();
        _prefix.push_back(0);
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            _prefix.push_back(_prefix.back() + nums[i]);
            _hash.insert({_prefix.back(), i + 1});
        }
        int ret = 0;
        for (int i = 0, sz = _prefix.size(); i < sz; i++)
        {
            int64_t hoge = _prefix[i];
            for (auto it = _hash.lower_bound(hoge + lower);
                it != _hash.end() && it -> first <= hoge + upper; it++ )
                if (it -> second > i)
                    ret++;
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }

