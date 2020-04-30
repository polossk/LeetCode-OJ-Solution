// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 983                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    vector<int> *days, *costs, dp;
    int durations[3] = {1, 7, 30};

    int dfs(int i)
    {
        if (i >= days->size()) { return 0; }
        if (dp[i] != -1) { return dp[i]; }
        dp[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++)
        {
            while (j < days->size() && days->at(j) < days->at(i) + durations[k]) { j++; }
            dp[i] = std::min(dp[i], dfs(j) + costs->at(k));
        }
        return dp[i];
    }
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        this->days = &days;
        this->costs = &costs;
        dp.assign(days.size(), -1);
        return dfs(0);
    }
};

void test() {}

int main() { test(); return 0; }
