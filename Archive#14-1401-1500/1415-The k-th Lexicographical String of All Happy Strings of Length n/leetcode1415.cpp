// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1415                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    inline char next(char prev, int value)
    {
        if (prev == 'a')
            return value == 0 ? 'b' : 'c';
        if (prev == 'b')
            return value == 0 ? 'a' : 'c';
        if (prev == 'c')
            return value == 0 ? 'a' : 'b';
        return '\0';
    }

    string getHappyString(int n, int k)
    {
        int num = 1 << (n - 1);
        k -= 1;
        int r = k % num，first_char = k / num;
        if (first_char > 2) return "";
        string ret = "";
        int size = 1;
        ret += 'a' + first_char;
        while (num >>= 1)
        {
            if (r >= num)
            {
                ret += next(ret[size - 1], 1);
                r -= num;
            }
            else
            {
                ret += next(ret[size - 1], 0);
            }
            size += 1;
        }
        return ret;
    }
};


void test() {}

int main() { test(); return 0; }
