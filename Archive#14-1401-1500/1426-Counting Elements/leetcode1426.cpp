// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1426                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    unordered_map<int, int> cnt_;
public:
    int countElements(vector<int>& arr)
    {
        for (auto e : arr) cnt_[e] += 1;
        int ret = 0;
        for (auto it = cnt_.begin(); it != cnt_.end(); it++)
        {
            auto [key, value] = *it;
            auto got = cnt_.find(key + 1);
            if (got != cnt_.end())
                ret += value;
        } 
        return ret;
    }
};


void test() {}

int main() { test(); return 0; }
