# Best Time to Buy and Sell Stock

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode121-cpp-f34b7d.svg)   | 12 ms   | 7.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode121-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode121-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

## EXAMPLE 1

```plain
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

## EXAMPLE 2

```plain
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## SOLUTION

* `dp[i][0]` 表示没有持有 `i` 的最大收益，`dp[i][1]` 表示持有 `i` 的最大收益。然后状态转移方程为
* `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])`
* `dp[i][1] = max(dp[i-1][1], - price[i])`
* 扫描一遍即可

## CODE

### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int tmp = INT_MIN, ret = 0;
        for (int item : prices)
        {
            ret = std::max(ret, tmp + item);
            tmp = std::max(tmp, -item);
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
