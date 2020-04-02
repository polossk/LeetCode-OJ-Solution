// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 020                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution {
private:
    set<char> left{ '(', '[', '{' };
    set<char> right{ ')', ']', '}' };
    map<char, char> query{ {')', '('},  {']', '['},  {'}', '{'} };
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (left.count(s[i])) { stk.push(s[i]); continue; }
            if (!right.count(s[i])) continue;
            if (stk.empty()) return false;
            if (query[s[i]] == stk.top()) { stk.pop(); }
            else return false;
        }
        return stk.empty();
    }
};

void test() {}

int main() { test(); return 0; }