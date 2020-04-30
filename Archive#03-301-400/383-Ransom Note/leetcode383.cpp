// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 383                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> cnt;
        for (auto ch : magazine) cnt[ch]++;
        for (auto ch : ransomNote)
        {
            if (cnt[ch] <= 0) return false;
            cnt[ch]--;
        }
        return true;
    }
};

void test() {}

int main() { test(); return 0; }

