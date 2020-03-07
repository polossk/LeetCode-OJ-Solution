// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 892                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    static const int MAXD = 4;
    const int dx[MAXD] = {1, 0, -1, 0};
    const int dy[MAXD] = {0, 1, 0, -1};
    inline bool valid(int x, int limit)
    {
        return 0 <= x && x < limit;
    }
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
        {
            int height = grid[i][j];
            if (height <= 0) continue;
            ret += 2; // up and down
            for (int k = 0; k < MAXD; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                int that_pillar = 0;
                if (valid(x, n) && valid(y, n)) that_pillar = grid[x][y];
                ret += max(0, height - that_pillar);
            }

        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
