// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1111                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int ret = 0;
        vector<int> cnt(26, 0);
        for (int i = 0, sz = chars.size(); i < sz; i++)
            cnt[chars[i] - 'a']++;
        for (auto word : words)
        {
            vector<int> tmp = vector<int>(cnt);
            int sz = word.size(), flag = 1;
            for (int i = 0; i < sz; i++)
            {
                if (tmp[word[i] - 'a'] == 0) { flag = 0; break; }
                else tmp[word[i] - 'a']--;
            }
            ret += flag ? sz : 0;
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
