// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 695                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
private:
    int XMAX, YMAX;
    static const int ND = 4; // number of directions
    std::function<bool(int, int)> judges[ND] = {
        [](int x, int y)->bool { return x >= 0; },
        [](int x, int y)->bool { return y >= 0; },
        [this](int x, int y)->bool { return x < this->XMAX; },
        [this](int x, int y)->bool { return y < this->YMAX; }
    };
    static constexpr int dx[ND] = {-1, 0, 1, 0};
    static constexpr int dy[ND] = {0, -1, 0, 1};
    vector<vector<bool>> vis;

    inline int bfs(pair<int, int> start, vector<vector<int>>& grid)
    {
        int aera = 1;
        queue<pair<int, int>> q;
        q.push(start);
        while (!q.empty())
        {
            pair<int, int> now = q.front();
            q.pop();
            int nx = now.first, ny = now.second;
            for (int d = 0; d < ND; d++)
            {
                int rx = nx + dx[d], ry = ny + dy[d];
                if (!judges[d](rx, ry)) continue;
                if (vis[rx][ry]) continue;
                if (grid[rx][ry] == 0) continue;
                q.push(make_pair(rx, ry));
                vis[rx][ry] = true;
                aera += 1;
            }
        }
        return aera;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.empty()) return 0;
        XMAX = grid.size();
        YMAX = grid[0].size();
        vis.assign(XMAX, vector<bool>(YMAX, false));
        vector<int> island;
        int ret = 0;
        for (int i = 0; i < XMAX; i++)
        {
            for (int j = 0; j < YMAX; j++)
            {
                if (vis[i][j]) continue;
                vis[i][j] = true;
                if (grid[i][j] == 0) continue;
                island.push_back(bfs(make_pair(i, j), grid));
            }
        }
        if (island.size() == 0)
            return 0;
        return *std::max_element(island.begin(), island.end());
    }
};

void test() {}

int main() { test(); return 0; }
