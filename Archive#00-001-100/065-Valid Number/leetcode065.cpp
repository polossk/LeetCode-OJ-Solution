// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 065                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool isNumber(string s)
    {
        int dot = 0, dgt = 0, idx = 0;
        while (s[idx] == ' ') idx++;
        if (s[idx] == '+' || s[idx] == '-') idx++;
        for (; isdigit(s[idx]) || s[idx] == '.'; )
            s[idx++] == '.' ? dot++ : dgt++;
        if (dot > 1 || dgt < 1) return false;
        if (s[idx] == 'e')
        {
            idx++; dgt = 0;
            if (s[idx] == '+' || s[idx] == '-') idx++;
            for (; isdigit(s[idx]); dgt++, idx++);
            if (dgt < 1) return false;
        }
        while (s[idx] == ' ') idx++;
        return idx == s.size();
    }
};

void test() {}

int main() { test(); return 0; }
