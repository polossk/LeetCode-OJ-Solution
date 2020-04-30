# Super Egg Drop

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode887-cpp-f34b7d.svg)   | 56 ms   | 6.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode887-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode887-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode887-java-b07219.svg) | -       | -            |

## DESCRIPTION

You are given `K` eggs, and you have access to a building with `N` floors from `1` to `N`. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor `F` with `0 <= F <= N` such that any egg dropped at a floor higher than `F` will break, and any egg dropped at or below floor `F` will not break.

Each *move*, you may take an egg (if you have an unbroken one) and drop it from any floor `X` (with `1 <= X <= N`). 

Your goal is to know **with certainty** what the value of `F` is.

What is the minimum number of moves that you need to know with certainty what `F` is, regardless of the initial value of `F`?

## EXAMPLE 1

```plain
Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
```

## EXAMPLE 2

```plain
Input: K = 2, N = 6
Output: 3
```

## EXAMPLE 3

```plain
Input: K = 3, N = 14
Output: 4
```

## NOTE

1. `1 <= K <= 100`
2. `1 <= N <= 10000`


## SOLUTION

* `dp[i][j]` 描述 `i` 个鸡蛋，从 `j` 楼扔下这一事件发生的最少需要的步数。
* 对于状态 `(i, j)` 对应可能的事件来源有如下两类：从某一楼层 `k` 扔鸡蛋并且碎了；从某一楼层 `k` 扔鸡蛋并且没碎。
* 前者对应的状态转移为 `(i-1, k-1) -> (i, j)`，因为鸡蛋少了一个，答案只有出现在 `k` 楼下方才能有可能下一个不碎，即对应的子问题为 `(i-1, k-1)`。
* 后者对应的状态转移为 `(i, j-k) -> (i, j)`，因为鸡蛋没碎，说明答案应当出现在 `k` 楼上方，此时对应的子问题为 `(i, j-k)`
* 所以状态转移方程为 `dp[i][j] := 1 + min $ [max $ [dp[i-1][k-1], dp[i][j-k]] for k := 1 to j do]`
* 对于 `dp[i][j]` 其关于 `j` 单调递增，所以对于式子 `dp[i-1][k-1]` 而言，其对于 `k` 单调递增，对于式子 `dp[i][j-k]` 而言，当固定 `j` 时，其对于 `k` 单调递减。
* 考虑两相邻值 `dp[i][j]` 与 `dp[i][j+1]`。不妨假设对于 `dp[i][j]` 而言，其最优值在 `k0` 取得，对于 `dp[i][j+1]` 而言，其最优值在 `k1` 取得，所以有 `dp[i][j] := 1 + max(dp[i-1][k0-1], dp[i][j-k0])`，`dp[i][j+1] := 1 + max(dp[i-1][k1-1], dp[i][j+1-k1])`。用平行四边形法则来证明 `k1 >= k0`。取正整数 `d0`，`d1` 使得 `0 <= d0, d1 < k0`，可知

```plain
A                A := dp[i][j+1-(k0-d0)]    = dp[i][j-k0 +d0+1]
|\               B := dp[i][j-(k0-d0)]      = dp[i][j-k0 +d0]       => A >= B
| \              C := dp[i][j-(k0)]         = dp[i][j-k0]           => B >= C
|  \             D := dp[i][j+1-(k0)]       = dp[i][j-k0 +1]        => D >= C
|   \            C := dp[i-1][k0-1]         = dp[i-1][k0-1]
|    D           E := dp[i-1][(k0+d1)-1]    = dp[i-1][k0-1 +d1]     => E >= C
|    |\          E := dp[i][j+1-(k0+d1)]    = dp[i][j-k0 -d1+1]     => D >= E
B    | \
\    |  \        k0 = argmin {dp[i][j]} <= k1 = argmin {dp[i][j+1]}
|\   |   E
| \  |  /|
|  \ | / |
|   \|/  |
|    C   |
+----+---+
|    |   |
|    |   k0+d1
|    k0
k0-d0
```

* 注意到只有 `dp[i-1][j]` 层影响了 `dp[i][j]`，所以可以使用滚动数组法

## CODE

### C++

```cpp
class Solution
{
    static const int MAXN = 10000 + 5;
    int dp[2][MAXN + 1];
public:
    int superEggDrop(int K, int N)
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j <= N; j++) dp[1][j] = j; // dp[1][j]
        for (int i = 2; i <= K; i++)
        {
            int f = i & 1, k = 1; // f is flag
            for (int j = 1; j <= N; j++)
            {
                while (k < j && (max(dp[1-f][k-1], dp[f][j-k])
                        >= max(dp[1-f][k], dp[f][j-k-1]))) k++;
                dp[f][j] = 1 + max(dp[1-f][k-1], dp[f][j-k]);
            }
        }
        return dp[K&1][N];
    }
};
```

### Python3


### Ruby


### Java

