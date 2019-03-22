// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 151                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    void reverseWords(string &s)
    {
        reverse(s.begin(), s.end());
        int hoge = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') continue;
            if (hoge != 0) s[hoge++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ')
                s[hoge++] = s[j++];
            reverse(s.begin() + hoge + i - j, s.begin() + hoge);
            i = j;
        }
        s.erase(s.begin() + hoge, s.end());
    }
};

void test() {}

int main() { test(); return 0; }
