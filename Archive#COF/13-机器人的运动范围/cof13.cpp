// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   COF 13                                                       *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    int n_, m_;
    static const int MAXM = 100 + 5;
    static const int MAXN = 100 + 5;
    static const int MAXD = 2;
    const int dx[2] = {1, 0};
    const int dy[2] = {0, 1};
    bool vis[MAXM][MAXN];
    
    inline int getsum(int x)
    {
        int ret = 0;
        while (x)
        {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }

    inline bool is_valid(int x, int y, int k)
    {
        return (x < m_) && (y < n_) && (!vis[x][y]) && (getsum(x) + getsum(y) <= k);
    }
    
public:
    int movingCount(int m, int n, int k)
    {
        if (!k) return 1;
        m_ = m; n_ = n;
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int ans = vis[0][0] = 1;
        while (!q.empty())
        {
            pair<int, int> head = q.front(); q.pop();
            for (int d = 0; d < MAXD; d++)
            {
                int nx = head.first + dx[d];
                int ny = head.second + dy[d];
                if (!is_valid(nx, ny, k)) continue;
                q.push(make_pair(nx, ny));
                ans += vis[nx][ny] = 1;
            }
        }
        return ans;
    }
};

void test() {}

int main() { test(); return 0; }
