// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 279                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int numSquares(int n)
    {
        if (n == 1) return 1;
        vector<int> mem;
        mem.assign(n, 0);
        queue<int> q; q.push(n);
        int ret = 0;
        while (!q.empty())
        {
            ret++;
            for (int i = 0, sz = q.size(); i < sz; i++)
            {
                int now = q.front(); q.pop();
                for (int j = 1; now - j * j >= 0; j++)
                {
                    int r = now - j * j;
                    if (r == 0) return ret;
                    if (mem[r]) continue;
                    q.push(r); mem[r] = ret;
                }
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
