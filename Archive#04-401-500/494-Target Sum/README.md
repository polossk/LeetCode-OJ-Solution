# Target Sum

![Medium](../../materials/-Medium-f0ad4e.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode494-cpp-f34b7d.svg)   | 4 ms    | 8.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode494-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode494-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols `+` and `-`. For each integer, you should choose one from `+` and `-` as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

## NOTE

1. The length of the given array is positive and will not exceed 20.
2. The sum of elements in the given array will not exceed 1000.
3. Your output answer is guaranteed to be fitted in a 32-bit integer.

## EXAMPLE

```plain
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
```

## SOLUTION

* 0-1 背包问题。前面为负号的数字集合 `A` 与剩余数字集合 `B` 有如下关系式： `sum(A) - sum(B) = target`，`sum(A) + sum(B) = sum(nums)`。
* 所以可以计算出 `sum(A) = (target + sum(nums)) / 2`
* 相当于对 `nums` 中选出恰好总和 `T = sum(A)` 的数字
* 用 `dp[i][j]` 表示处理了前 `i` 个数字，总和为 `j` 时的方案数，状态转移方程为 `dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]`
* 初值条件为 `dp[i][j] = 0`，`dp[i][0] = 1`
* 注意到 `dp[i]` 层的数据只与 `dp[i - 1]` 层相关，所以实际上不需要使用二维数组，可以用两个数组滚动实现，或者（特殊情况下）可以使用单数组，只需要注意更新顺序即可（防止在更新下一层时过早地刷新掉旧数据）

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int64 sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (((sum + S) & 1) || S > sum) return 0;
        int T = (sum + S) >> 1;
        vector<int> dp(T + 1, 0); dp[0] = 1;
        for (auto e : nums)
            for (int j = T; j >= e; j--)
                dp[j] += dp[j - e];
        return dp[T];
    }
};
```

### Python3

### Ruby

### Java
