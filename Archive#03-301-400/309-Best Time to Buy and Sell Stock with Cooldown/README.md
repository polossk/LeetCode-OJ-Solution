# Best Time to Buy and Sell Stock with Cooldown

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode309-cpp-f34b7d.svg)   | 0 ms    | 6.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode309-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode309-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
* After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

## EXAMPLE

```plain
Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

## SOLUTION

* `dp[i][0]` 表示没有持有 `i` 的最大收益，`dp[i][1]` 表示持有 `i` 的最大收益。然后状态转移方程为
* `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])`
* `dp[i][1] = max(dp[i-1][1], dp[i-2][0] - price[i])`
* 扫描一遍即可

## CODE

### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int curr = INT_MIN, prev = 0, ret = 0, tmp = 0;
        for (int item : prices)
        {
            prev = curr;
            curr = max(tmp - item, prev);
            tmp = ret;
            ret = max(prev + item, tmp);
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
