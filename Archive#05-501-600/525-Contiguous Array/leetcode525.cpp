// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 525                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sz = nums.size();
        vector<int> tmp(1 + (sz << 1), -2);
        tmp[sz] = -1;
        int ret = 0, cnt = 0;
        for (int i = 0; i < sz; i++)
        {
            cnt += nums[i] == 0 ? -1 : 1;
            if (tmp[cnt + sz] >= -1)
                ret = std::max(ret, i - tmp[cnt + sz]);
            else
                tmp[cnt + sz] = i;
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
