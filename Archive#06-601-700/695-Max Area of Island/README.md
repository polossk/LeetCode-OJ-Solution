# Max Area of Island

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode695-cpp-f34b7d.svg)   | 20 ms   | 13.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode695-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode695-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a non-empty 2D array `grid` of 0's and 1's, an **island** is a group of `1`'s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

## EXAMPLE 1

```plain
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
```

## EXAMPLE 2

```plain
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
```

## NOTE

The length of each dimension in the given `grid` does not exceed 50.

## SOLUTION

* BFS

## CODE

### C++

```cpp
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

    inline int bfs(pair<int, int> start, vector<vector<char>>& grid)
    {
        int ret = 0;
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
                if (grid[rx][ry] == '0') continue;
                q.push(make_pair(rx, ry));
                vis[rx][ry] = true;
            }
        }
        return 1;
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty()) return 0;
        XMAX = grid.size();
        YMAX = grid[0].size();
        vis.assign(XMAX, vector<bool>(YMAX, false));
        int ret = 0;
        for (int i = 0; i < XMAX; i++)
        {
            for (int j = 0; j < YMAX; j++)
            {
                if (vis[i][j]) continue;
                vis[i][j] = true;
                if (grid[i][j] == '0') continue;
                ret += bfs(make_pair(i, j), grid);
            }
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
