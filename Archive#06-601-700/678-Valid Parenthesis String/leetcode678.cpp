// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 678                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> left, star;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (s[i] == '(') { left.push(i); }
            else if (s[i] == '*') { star.push(i); }
            else // s[i] == ')'
            {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        if (left.size() > star.size()) return false;
        while (!left.empty())
        {
            int left_idx = left.top(); left.pop();
            int star_idx = star.top(); star.pop();
            if (left_idx > star_idx) return false;
        }
        return true;
    }
};


void test() {}

int main() { test(); return 0; }
