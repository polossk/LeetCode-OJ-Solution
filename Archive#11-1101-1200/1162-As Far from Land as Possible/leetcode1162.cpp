// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1162                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    static const int MAXN = 100 + 5;
    static const int MAXD = 4;
    static const int INF = 0x7f7f7f7f;
    const int dx[MAXD] = {-1, 0, 1, 0};
    const int dy[MAXD] = {0, 1, 0, -1};

    int n, d[MAXN][MAXN];

    struct GreaterPairIntInt
    {
        using T = std::pair<int, int>;
        constexpr bool operator()(const T& lhs, const T& rhs) const
        {
            return lhs.first > rhs.first;
        }
    };

    inline bool valid(int x)
    {
        return 0 <= x && x < n;
    }

    // bfs
    int maxDistance(vector<vector<int>>& grid)
    {
        this->n = grid.size();
        std::queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
        {
            if (!grid[i][j]) continue;
            q.push(make_pair(i, j));
        }
        if (q.size() == n * n || q.size() == 0) { return -1; }

        int layer = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto current = q.front(); q.pop();
                int old_x = current.first;
                int old_y = current.second;
                for (int i = 0; i < MAXD; i++)
                {
                    int nx = old_x + dx[i], ny = old_y + dy[i];
                    if (!(valid(nx) && valid(ny))) continue;
                    if (grid[nx][ny]) continue;
                    grid[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
            layer++;
        }
        return layer - 1;
    }

    // dijkstra
    int maxDistance(vector<vector<int>>& grid)
    {
        this->n = grid.size();
        memset(d, 0x7f, sizeof(d));
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, GreaterPairIntInt> pq;
        // std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<>> pq;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
        {
            if (!grid[i][j]) continue;
            d[i][j] = 0;
            pq.push(make_pair(0, i * n + j));
        }
        if (pq.size() == n * n || pq.size() == 0) { return -1; }

        while (!pq.empty())
        {
            auto current = pq.top(); pq.pop();
            int old_v = current.first;
            int old_x = current.second / n;
            int old_y = current.second % n;
            for (int i = 0; i < MAXD; i++)
            {
                int nx = old_x + dx[i], ny = old_y + dy[i];
                if (!(valid(nx) && valid(ny))) continue;
                int &dis = d[nx][ny];
                if (old_v + 1 >= dis) continue;
                dis = old_v + 1;
                pq.push(make_pair(dis, nx * n + ny));
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!grid[i][j]) ans = max(ans, d[i][j]);
        return (ans == INF) ? -1 : ans;
    }
};

void test() {}

int main() { test(); return 0; }
