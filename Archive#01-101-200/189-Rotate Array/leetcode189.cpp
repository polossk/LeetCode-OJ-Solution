// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 189                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int len = nums.size();
        k %= len;
        reverse(nums.begin(), nums.begin() + (len - k));
        reverse(nums.begin() + (len - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

void test() {}

int main() { test(); return 0; }
