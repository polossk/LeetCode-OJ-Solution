// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 022                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
    void dfs(vector<string> &ans, string &&cur, int Left, int Right)
    {
        if (Left == 0 && Right == 0) { ans.push_back(cur); return; }
        if (Left > Right) return; // using too much left parenthes
        if (Left > 0) { dfs(ans, cur + "(", Left - 1, Right); }
        if (Right > 0) { dfs(ans, cur + ")", Left, Right - 1); }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        if (n == 0) return ret;
        dfs(ret, "", n, n);
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }