// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 394                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
    string dfs(string s, int &&idx)
    {
        string ret;
        while (idx < s.size() && s[idx] != ']')
        {
            if (isdigit(s[idx]))
            {
                int n = 0;
                while (idx < s.size() && isdigit(s[idx]))
                    n = n * 10 + s[idx++] - '0';
                idx++; string hoge = dfs(s, std::move(idx)); idx++;
                while (n-- > 0) ret += hoge;
            }
            else ret += s[idx++];
        }
        return ret;
    }
public:
    string decodeString(string s) { return dfs(s, 0); }
};

void test() {}

int main() { test(); return 0; }

