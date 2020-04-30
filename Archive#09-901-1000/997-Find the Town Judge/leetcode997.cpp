// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 997                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> in(N + 1, 0), out(N + 1, 0);
        int ret = 1;
        for (int i = 0, sz = trust.size(); i < sz; i++)
        {
                int a = trust[i][0], b = trust[i][1];
                in[b]++;
                out[a]++;
                ret = in[ret] < in[b] ? b : ret;
        }
        return (in[ret] == N - 1 && out[ret] == 0) ? ret : -1;
    }
};

void test() {}

int main() { test(); return 0; }
