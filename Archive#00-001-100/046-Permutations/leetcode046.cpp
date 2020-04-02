// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 046                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    void backtrack(vector<vector<int>> &host, vector<int> &pool,
        int cnt, int len)
    {
        if (cnt == len)
        {
            host.emplace_back(pool);
            return;
        }
        for (int i = cnt; i < len; i++)
        {
            std::swap(pool[i], pool[cnt]);
            backtrack(host, pool, cnt + 1, len);
            std::swap(pool[i], pool[cnt]);
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        backtrack(ret, nums, 0, nums.size());
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
