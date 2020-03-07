// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   CCI 1716                                                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int massage(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        int dp0 = 0, dp1 = nums[0];
        for (int i = 1; i < n; i++){
            int tmp_dp0 = max(dp0, dp1);
            int tmp_dp1 = dp0 + nums[i];
            dp0 = tmp_dp0;
            dp1 = tmp_dp1;
        }
        return max(dp0, dp1);
    }
};

void test() {}

int main() { test(); return 0; }
