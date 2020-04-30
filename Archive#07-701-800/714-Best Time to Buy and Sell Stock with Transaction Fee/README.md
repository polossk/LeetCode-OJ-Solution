# Best Time to Buy and Sell Stock with Transaction Fee

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg) ![Greedy](../../materials/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode714-cpp-f34b7d.svg)   | 136  ms | 13 Mb        |
| ![python](https://img.shields.io/badge/leetcode714-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode714-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Your are given an array of integers `prices`, for which the `i`-th element is the price of a given stock on day `i`; and a non-negative integer `fee` representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

## EXAMPLE

```plain
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
* Buying at prices[0] = 1
* Selling at prices[3] = 8
* Buying at prices[4] = 4
* Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

## NOTE

* `0 < prices.length <= 50000`.
* `0 < prices[i] < 50000`.
* `0 <= fee < 50000`.

## SOLUTION

* `dp[i][0]` 表示没有持有 `i` 的最大收益，`dp[i][1]` 表示持有 `i` 的最大收益。然后状态转移方程为
* `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])`
* `dp[i][1] = max(dp[i-1][1], dp[i-1][0] - price[i] - fee)`
* 扫描一遍即可

## CODE

### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int tmp = INT_MIN, ret = 0;
        for (int item : prices)
        {
            int prev = ret;
            ret = std::max(ret, tmp + item);
            tmp = std::max(tmp, prev - item - fee);
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

### Java
