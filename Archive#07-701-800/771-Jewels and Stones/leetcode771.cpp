// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 771                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> jewels, stones;
        for (auto ch : J) jewels[ch]++;
        for (auto ch : S) stones[ch]++;
        int ret = 0;
        for (auto record : jewels)
        {
            if (stones.find(record.first) == stones.end())
                continue;
            ret += stones[record.first];
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
