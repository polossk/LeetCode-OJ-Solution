# Best Time to Buy and Sell Stock II

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Greedy](../../materials/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode122-cpp-f34b7d.svg)   | 8 ms    | 7.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode122-py-3572A5.svg) | 64 ms   | 14.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode122-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

## EXAMPLE 1

```plain
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
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

## CONSTRAINTS  Constraints

* `1 <= prices.length <= 3 * 10 ^ 4`
* `0 <= prices[i] <= 10 ^ 4`

## SOLUTION

* `dp[i][0]` 表示没有持有 `i` 的最大收益，`dp[i][1]` 表示持有 `i` 的最大收益。然后状态转移方程为
* `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])`
* `dp[i][1] = max(dp[i-1][1], dp[i-1][0] - price[i])`
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
            int prev = ret;
            ret = std::max(ret, tmp + item);
            tmp = std::max(tmp, prev - item);
        }
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, a - b) for a, b in zip(prices[1:], prices[:-1]))
```

### Ruby

### Java
