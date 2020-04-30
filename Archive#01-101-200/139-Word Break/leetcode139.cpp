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
    unordered_set<string> fail_, dict_;
    bool dfs(string s)
    {
        if (s.length() == 0) return true;
        for (int i = 1, sz = s.size(); i <= sz; i++)
        {
            string hoge = s.substr(0, i);
            if (dict_.find(hoge) != dict_.end())
            {
                string piyo = s.substr(i);
                if (fail_.find(piyo) == fail_.end())
                {
                    if (dfs(piyo)) return true;
                    else fail_.insert(piyo);
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        dict_ = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};

void test() {}

int main() { test(); return 0; }
