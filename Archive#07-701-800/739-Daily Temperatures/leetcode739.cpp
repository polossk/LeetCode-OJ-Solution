// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 739                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> s;
        int sz = T.size();
        vector<int> ret(sz, 0);
        for (int i = sz - 1; i >= 0; i--)
        {
            while (!s.empty() && T[i] >= T[s.top()]) s.pop();
            ret[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
