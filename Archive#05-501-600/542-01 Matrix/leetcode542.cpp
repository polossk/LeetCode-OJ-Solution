// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 542                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    static const int MAXD = 4;
    static const int INF = 0x7f7f7f7f;
    const int dx[MAXD] = {-1, 0, 1, 0};
    const int dy[MAXD] = {0, 1, 0, -1};

    int n, m;

    inline bool valid(int x, int limit)
    {
        return 0 <= x && x < limit;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        std::ios::sync_with_stdio(false);
        this->n = matrix.size();
        if (n == 0) return vector<vector<int>>();
        this->m = matrix[0].size();
        std::queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> ret(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
        {
            if (matrix[i][j]) continue;
            q.push(make_pair(i, j));
            vis[i][j] = true;
        }

        int layer = 1;
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
                    if (!(valid(nx, n) && valid(ny, m))) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    ret[nx][ny] = layer;
                    q.push(make_pair(nx, ny));
                }
            }
            layer++;
        }
        return ret;
    }
};

void test() {}

int main() { return 0; }
