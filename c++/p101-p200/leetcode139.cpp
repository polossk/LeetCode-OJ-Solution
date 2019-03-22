// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 139                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
    unordered_set<string> fail;
    bool dfs(string s, unordered_set<string>& wordDict)
    {
        if (s.length() == 0) return true;
        for (int i = 1, sz = s.size(); i <= sz; i++)
        {
            string hoge = s.substr(0, i);
            if (wordDict.find(hoge) != wordDict.end())
            {
                string piyo = s.substr(i);
                if (fail.find(piyo) == fail.end())
                {
                    if (dfs(piyo, wordDict)) return true;
                    else fail.insert(piyo);
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        return dfs(s, wordDict);
    }
};

void test() {}

int main() { test(); return 0; }
