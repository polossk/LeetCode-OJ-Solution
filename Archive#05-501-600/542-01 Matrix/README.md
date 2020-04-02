# 01 Matrix

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Depth--first_Search](https://img.shields.io/badge/深度优先搜索-Depth--first_Search-007ec6.svg) ![Breadth--first_Search](https://img.shields.io/badge/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode542-cpp-f34b7d.svg)   | 224 ms  | 23.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode542-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode542-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

## EXAMPLE 1

```plain
Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
```

## EXAMPLE 2

```plain
Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
```

## NOTE

1. The number of elements of the given matrix will not exceed 10,000.
2. There are at least one 0 in the given matrix.
3. The cells are adjacent in only four directions: up, down, left and right.

## SOLUTION

* 以 `0` 为起点，逐层 bfs 搜索即可

## CODE

### C++

```cpp
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
```

### Python3


### Ruby

