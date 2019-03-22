// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 309                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int curr = INT_MIN, prev = 0, ret = 0, tmp = 0;
        for (int item : prices)
        {
            prev = curr;
            curr = max(tmp - item, prev);
            tmp = ret;
            ret = max(prev + item, tmp);
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
