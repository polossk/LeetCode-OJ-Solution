// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 844                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        int lenS = 0, lenT = 0;
        for (int i = 0, sz = S.size(); i < sz; i++)
        {
            if (S[i] == '#') lenS -= lenS != 0;
            else S[lenS++] = S[i];
        }
        for (int i = 0, sz = T.size(); i < sz; i++)
        {
            if (T[i] == '#') lenT -= lenT != 0;
            else T[lenT++] = T[i];
        }
        if (lenS != lenT) return false;
        for (int i = 0; i < lenS; i++)
            if (S[i] != T[i]) return false;
        return true;
    }
};

void test() {}

int main() { test(); return 0; }