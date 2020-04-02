// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1049                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sz = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int length = 1 + (sum >> 1);
		vector<int> dp(length, 0);
        for(int i = 0; i < sz; i++)
		{
            for(int j = length - 1; j >= stones[i]; j--)
			{
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[length - 1];
    }
};


void test() {}

int main() { test(); return 0; }
