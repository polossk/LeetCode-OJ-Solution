# Minimum Path Sum

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode064-cpp-f34b7d.svg)   | 8 ms    | 8.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode064-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode064-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a *m* x *n* grid filled with non-negative numbers, find a path from top left to bottom right which *minimizes* the sum of all numbers along its path.

## EXAMPLE

```plain
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

## NOTE

You can only move either down or right at any point in time.

## SOLUTION

* 从左上角开始往右下行进，每一个点的来源路线只有两条，上方或左方

## CODE

### C++

```cpp
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            else
                dp[i][j] = grid[i][j] + std::min(dp[i][j-1], dp[i-1][j]);
        }
        return dp[n-1][m-1];
        // return dp.back().back();
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java

```java
```
