// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   CCI 0106                                                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    string compressString(string S)
    {
        if (S.size() == 0) return S;
        stringstream tmp;
        int cnt = 1, sz = S.size();
        char ch = S[0];
        for (int i = 1; i < sz; i++)
        {
            if (S[i] == ch) cnt++;
            else
            {
                tmp << ch << cnt;
                ch = S[i];
                cnt = 1;
            }
        }
        tmp << ch << cnt;
        string ret; tmp >> ret;
        return sz <= ret.size() ? S : ret;
    }
};

void test() {}

int main() { test(); return 0; }
