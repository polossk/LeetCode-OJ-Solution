// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 306 Additive Number                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    typedef long long int64;
    
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3) return false;
        return dfs(num, 0);
    }

    bool dfs(string s, int start)
    {
        for (int i = start, i_end = s.size() - 2; i < i_end; i++)
        {
            int64 a = 0, b = 0;
            for (int j = i + 1, j_end = s.size(); j < j_end; j++)
            {
                
                a = std::stoll(s.substr(start, i + 1 - start));
                b = std::stoll(s.substr(i + 1, j - i));
                string ans = std::to_string(a + b);
                string sc = s.substr(j + 1, ans.size());
                if (ans == sc)
                {
                    if (j + 1 + ans.size() == s.size()) return true;
                    if (dfs(s, i + 1)) return true;
                    break;
                }
                if (b == 0) break;
            }
            if (a == 0) return false;
        }
        return false;
    }
};

void test()
{
    Solution sol;
    vector<string> tests = { "112358", "199100199", "111111", "010102" };
    vector<bool> answer = { true, true, false, false };
    for (int i = 0 ; i < 4; i++)
    {
        printf("tests= %s, result= %s, answer= %s\n", tests[i].c_str(), sol.isAdditiveNumber(tests[i])?"true":"false", answer[i]?"true":"false");
    }
}

int main() { test(); return 0; }
