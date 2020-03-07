# As Far from Land as Possible

 ![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Breadth--first_Search](https://img.shields.io/badge/广度优先搜索-Breadth--first_Search-007ec6.svg) ![Graph](https://img.shields.io/badge/图-Graph-007ec6.svg)

## RESULT

| Submission                                                                 | Runtime | Memory Usage |
| -------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1162--bfs-cpp-f34b7d.svg)      | 52 ms   | 12.7 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode1162--dijkstra-cpp-f34b7d.svg) | 256 ms  | 13.1 Mb      |
| ![python](https://img.shields.io/badge/leetcode1162-py-3572A5.svg)         | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1162-rb-701516.svg)           | -       | -            |

## DESCRIPTION

Given an N x N `grid` containing only values `0` and `1`, where `0` represents water and `1` represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

If no land or water exists in the grid, return `-1`.

## EXAMPLE 1

```plain
Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.
```

## EXAMPLE 2

```plain
Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.
```

## NOTE

1. `1 <= grid.length == grid[0].length <= 100`
2. `grid[i][j]` is `0` or `1`

## SOLUTION

* 很容易想到通过逐层 bfs，层数恰好为距离
* 也可以通过额外开一个 `d[n][n]` 数组，`d[i][j]` 记录超源点到 `(i, j)` 的距离，相当于把问题转换为了单元点最短路问题，其中超源点到陆地的距离为 0.

## CODE

### C++

```cpp
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
```

### Python3


### Ruby

