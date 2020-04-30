# Best Time to Buy and Sell Stock III

![Hard](../../materials/-Hard-e05d44.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode123-cpp-f34b7d.svg)   | 8 ms    | 7.3 Mb       |
| ![python](https://img.shields.io/badge/leetcode123-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode123-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

## EXAMPLE 1

```plain
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

## EXAMPLE 2

```plain
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```

## EXAMPLE 3

```plain
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## NOTE

You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).  

## SOLUTION

* `dp[i][1/2][0]` 表示没有持有 `i` 的最大收益，`dp[i][1/2][0]` 表示持有 `i` 的最大收益，中间的 `[1/2]` 表示当前交易数目。然后状态转移方程为
* `dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])`
* `dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])`
* `dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])`
* `dp[i][1][1] = max(dp[i-1][1][1], -prices[i])`
* 保证赋值顺序，然后扫描一遍即可

## CODE

### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int dp_i10 = 0, dp_i11 = INT_MIN, dp_i20 = 0, dp_i21 = INT_MIN;
        for (int item : prices)
        {
            dp_i20 = std::max(dp_i20, dp_i21 + item);
            dp_i21 = std::max(dp_i21, dp_i10 - item);
            dp_i10 = std::max(dp_i10, dp_i11 + item);
            dp_i11 = std::max(dp_i11, -item);
        }
        return dp_i20;
    }
};
```

### Python3

```python
```

### Ruby

### Java
