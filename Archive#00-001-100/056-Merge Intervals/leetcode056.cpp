// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 056                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        ios::sync_with_stdio(false);
        int sz = intervals.size();
        if (sz <= 1) return intervals;
        vector<int> values;
        unordered_set<int> singluar;
        unordered_map<int, int> index;
        vector<vector<int>> ret;
        for (int i = 0; i < sz; i++)
        {
            values.push_back(intervals[i][0]);
            values.push_back(intervals[i][1]);
            if (intervals[i][0] == intervals[i][1])
                singluar.insert(intervals[i][0]);
        }
        std::sort(values.begin(), values.end());
        auto last = std::unique(values.begin(), values.end());
        values.erase(last, values.end());
        int vsz = values.size();
        vector<int> pool(vsz, 0);
        for (int i = 0; i < vsz; i++)
            index[values[i]] = i;
        for (int i = 0; i < sz; i++)
        {
            pool[ index[ intervals[i][0] ] ]++;
            pool[ index[ intervals[i][1] ] ]--;
        }
        bool notemptyflag = !singluar.empty();
        for (int i = 0, left = 0, height = 0; i < vsz; i++)
        {
            if (pool[i] > 0)
            {
                if (height == 0) { left = i; }
                height += pool[i];
            }
            else if (pool[i] < 0)
            {
                if (height + pool[i] == 0)
                {
                    ret.emplace_back(std::initializer_list<int>{values[left], values[i]});
                    left = 0;
                }
                height += pool[i];
            }
            else // pool[i] == 0
            {
                if (height != 0) continue;
                if (notemptyflag && singluar.find(values[i]) != singluar.end())
                {
                    ret.emplace_back(2, values[i]);
                }
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
