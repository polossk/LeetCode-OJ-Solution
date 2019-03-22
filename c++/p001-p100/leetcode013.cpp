// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 013                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
    unordered_map<char, int> _;
public:
    Solution() {
        _ = {
            { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 },
            { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
        };
    }
    int romanToInt(string s)
    {
        int ret = _[s.back()];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            ret -= (_[s[i]] < _[s[i + 1]]) ? _[s[i]] : -_[s[i]];
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
