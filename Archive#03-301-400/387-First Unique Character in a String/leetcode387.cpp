// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 387                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::unordered_map<char, int> cnt;
        for (auto ch : s) cnt[ch]++;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};

void test() {}

int main() { test(); return 0; }

