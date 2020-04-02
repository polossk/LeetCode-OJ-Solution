// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 008                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int myAtoi(string str)
    {
        int sign = 1, ret = 0, idx = 0;
        while (str[idx] == ' ') idx++;
        if (str[idx] == '-' || str[idx] == '+')
        {
            sign = 1 - 2 * (str[idx++] == '-');
        }
        while (isdigit(str[idx]))
        {
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[idx] > '7'))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ret = ret * 10 + (str[idx++] - '0');
        }
        return sign * ret;
    }
};

void test() {}

int main() { test(); return 0; }
