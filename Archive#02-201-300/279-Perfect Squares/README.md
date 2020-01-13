# Perfect Squares

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Math](https://img.shields.io/badge/-Math-007ec6.svg) ![Dynamic%20Programming](https://img.shields.io/badge/-Dynamic%20Programming-007ec6.svg) ![Breadth--first%20Search](https://img.shields.io/badge/-Breadth--first%20Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode279-cpp-f34b7d.svg)   | 16 ms   | 13.1 Mb      |
| ![python](https://img.shields.io/badge/leetcode279-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode279-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a positive integer *n*, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to *n*.

## EXAMPLE 1:

```plain
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
```

## Example 2:

```plain
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## SOLUTION

* BFS 变种，对状态空间逐层搜索
* 状态转移方程 `dp[i] = min(dp[i], dp[i - j*j] + 1)`, 初值条件 `dp[0] = 0`

## CODE

### C++

```cpp
class Solution {
public:
    int numSquares(int n)
    {
        if (n == 1) return 1;
        vector<int> mem;
        mem.assign(n, 0);
        queue<int> q; q.push(n);
        int ret = 0;
        while (!q.empty())
        {
            ret++;
            for (int i = 0, sz = q.size(); i < sz; i++)
            {
                int now = q.front(); q.pop();
                for (int j = 1; now - j * j >= 0; j++)
                {
                    int r = now - j * j;
                    if (r == 0) return ret;
                    if (mem[r]) continue;
                    q.push(r); mem[r] = ret;
                }
            }
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
