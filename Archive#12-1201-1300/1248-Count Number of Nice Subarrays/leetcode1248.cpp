// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1248                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> odds(1, -1), gap;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
            if (nums[i] & 1) odds.push_back(i);
        int ret = 0;
        if (odds.size() < k) return ret;
        odds.push_back(sz);
        for (int i = 1, osz = odds.size(); i < osz; i++)
            gap.push_back(odds[i] - odds[i - 1]);
        for (int i = 0, gsz = gap.size(); i + k < gsz; i++)
            ret += gap[i] * gap[i + k];
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
