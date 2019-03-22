// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 415 Add Strings                                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0) { sum += (num1[i] - '0'); i--; }
            if (j >= 0) { sum += (num2[j] - '0'); j--; }
            sum += carry;
            carry = sum / 10;
            res = to_string(sum % 10) + res;
        }
        return res;
    }
};

void test() {}

int main() { return 0; }
