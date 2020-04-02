# 硬币

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg) 

## RESULT

| Submission                                                    | Runtime | Memory Usage |
| ------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cci1603-cpp-f34b7d.svg)   | 0 ms    | 6 Mb         |
| ![python](https://img.shields.io/badge/cci1603-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cci1603-rb-701516.svg)   | -       | -            |

## DESCRIPTION

硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

## EXAMPLE 1

```plain
输入: n = 5
输出：2
解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
```

## EXAMPLE 2

```plain
输入: n = 10
输出：4
解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1
```

## NOTE

* 注意: 你可以假设：0 <= n (总金额) <= 1000000

## SOLUTION

* 令 `dp[i]` 表示使用了 `i` 个 25 分硬币的结果
* 那么剩下的问题转换成使用了多少个 5 分硬币与 1 分硬币，记 `dp[i][j]` 表示在只是用 `i` 个 25 分硬币和 `j` 个 5 分硬币下的结果，显然有 `dp[i][j] = n - 25 * i - 5 * j`，所以等差数列求和即可。

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
    static const int64 MOD = 1000000007;
public:
    int waysToChange(int n)
    {
        int64 ret = 0;
        for (int i = 0; i * 25 <= n; i++)
        {
            int rest = n - i * 25;
            int64 a = rest / 10;
            int64 b = rest % 10 / 5;
            ret = (ret + (a + 1) * (a + b + 1) % MOD) % MOD;
        }
        return int(ret);
    }
};
```

### Python3


### Ruby

