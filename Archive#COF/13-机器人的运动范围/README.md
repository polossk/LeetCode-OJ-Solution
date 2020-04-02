# 机器人的运动范围

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Searching_Method](https://img.shields.io/badge/搜索法-Searching_Method-009688.svg)

## RESULT

| Submission                                                  | Runtime | Memory Usage |
| ----------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cof13-cpp-f34b7d.svg)   | 0 ms    | 6.2 Mb       |
| ![python](https://img.shields.io/badge/cof13-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cof13-rb-701516.svg)   | -       | -            |

## DESCRIPTION

地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

## EXAMPLE 1

```plain
输入：m = 2, n = 3, k = 1
输出：3
```

## EXAMPLE 2

```plain
输入：m = 3, n = 1, k = 0
输出：1
```

## RESTRICTION

* `1 <= n,m <= 100`
* `0 <= k <= 20`

## SOLUTION

* 从起点开始搜索即可

## CODE

### C++

```cpp
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
```

### Python3


### Ruby

