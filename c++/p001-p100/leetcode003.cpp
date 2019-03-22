// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 003 Longest Substring Without Repeating Characters  *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int fin[400];
        memset(fin, -1, sizeof(fin));
        int sz = s.size();
        if (sz == 0) return 0;
        int hoge = 1;
        int ans = 1;
        fin[s[0]] = 0;
        for (int i = 1; i < sz; i++)
        {
            int idx = fin[s[i]];
            if (idx == -1) hoge++;
            else hoge = min(hoge + 1, i - idx);
            fin[s[i]] = i;
            ans = max(ans, hoge);
        }
        return ans;
    }
};

void test() {}

int main() { test(); return 0; }
