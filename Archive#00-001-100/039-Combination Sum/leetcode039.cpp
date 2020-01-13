// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 039                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
private:
    vector<vector<int>> ret;

    void dfs(const vector<int>& candidates, vector<int>& tmp, int start, int residual)
    {
        if (residual == 0) { ret.push_back(tmp); return; }
        for (int i = start, sz = candidates.size();
            i < sz && candidates[i] <= residual; i++)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, tmp, i, residual - candidates[i]);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        // std::sort(candidates.begin(), candidates.end(), std::less<int>());
        std::sort(candidates.begin(), candidates.end());
        vector<int> ans;
        dfs(candidates, ans, 0, target);
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
