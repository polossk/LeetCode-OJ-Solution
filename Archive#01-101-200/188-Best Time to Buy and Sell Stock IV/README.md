# Best Time to Buy and Sell Stock IV

![Hard](../../materials/-Hard-e05d44.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode188-cpp-f34b7d.svg)   | 8 ms    | 6.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode188-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode188-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete at most **k** transactions.

## EXAMPLE 1

```plain
Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

## EXAMPLE 2

```plain
Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

## NOTE

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

## SOLUTION

* `dp[i][k][0]` 表示没有持有 `i` 的最大收益，`dp[i][k][0]` 表示持有 `i` 的最大收益，中间的 `[k]` 表示当前交易数目。然后状态转移方程为
* `dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])`
* `dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])`
* 扫描一遍即可

## CODE

### C++

```cpp
class Solution
{
    int maxProfit_inf(vector<int> &prices)
    {
        int dp_i0 = 0, dp_i1 = INT_MIN;
        for (int item : prices)
        {
            int tmp = dp_i0;
            dp_i0 = std::max(dp_i0, dp_i1 + item);
            dp_i1 = std::max(dp_i1, tmp - item);
        }
        return dp_i0;
    }
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k >= (prices.size() >> 1))
            return maxProfit_inf(prices);
        vector<int> dp0(k + 1, 0), dp1(k + 1, INT_MIN);
        for (int item : prices)
            for (int kk = k; kk > 0; kk--)
        {
            dp0[kk] = std::max(dp0[kk], dp1[kk] + item);
            dp1[kk] = std::max(dp1[kk], dp0[kk - 1] - item);
        }
        return dp0[k];
    }
};
```

### Python3

```python
```

### Ruby

### Java
