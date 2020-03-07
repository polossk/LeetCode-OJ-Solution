// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 300                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    // dp
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (!len) return 0;
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    // greedy
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (!len) return 0;
        vector<int> greedy; greedy.push_back(nums[0]);
        for (int i = 1; i < len; i++)
        {
            if (greedy.back() < nums[i]) greedy.push_back(nums[i]);
            else
            {
                // self implementation
                // int l = 0, r = greedy.size() - 1;
                // while (l < r)
                // {
                //     int mid = l + (r - l) >> 1;
                //     if (greedy[mid] < nums[i])
                //         l = mid + 1;
                //     else r = mid;
                // }
                // greedy[l] = nums[i];
                // std::lower_bound
                int pos = 0;
                do {
                    if (greedy.size() == 1) break;
                    auto it = std::lower_bound(greedy.begin(), greedy.end(), nums[i]);
                    pos = it == greedy.end() ? 0 : std::distance(greedy.begin(), it);
                } while (0);
                greedy[pos] = nums[i];
            }
        }
        return greedy.size();
    }
};

void test() {}

int main() { test(); return 0; }
