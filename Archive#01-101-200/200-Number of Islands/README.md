# Number of Islands

![Medium](../../materials/-Medium-f0ad4e.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg) ![Breadth--first_Search](../../materials/广度优先搜索-Breadth--first_Search-007ec6.svg) ![Union_Find](../../materials/并查集-Union_Find-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode200-cpp-f34b7d.svg)   | 20 ms   | 11.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode200-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode200-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

## EXAMPLE 1

```plain
Input:
11110
11010
11000
00000

Output: 1
```

## EXAMPLE 2

```plain
Input:
11000
11000
00100
00011

Output: 3
```

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
