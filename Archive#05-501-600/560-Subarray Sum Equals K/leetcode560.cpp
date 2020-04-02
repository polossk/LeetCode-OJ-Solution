// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 560                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0, ret = 0;
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int elem : nums)
        {
            sum += elem;
            if (cnt.find(sum - k) != cnt.end())
                ret += cnt[sum - k];
            cnt[sum]++;
        }
        return ret;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i: nums){
            sum += i;
            if(mp.find(sum-k) != mp.end()) ans += mp[sum-k];
            mp[sum] ++;
        }
        return ans;
    }
};

void test() {}

int main() { test(); return 0; }
