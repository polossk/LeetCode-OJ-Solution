# Minimum Cost For Tickets

![Medium](../../materials/-Medium-f0ad4e.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode983-cpp-f34b7d.svg)   | 4 ms    | 9.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode983-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode983-rb-701516.svg)   | -       | -            |

## DESCRIPTION

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array `days`.  Each day is an integer from `1` to `365`.

Train tickets are sold in 3 different ways:

* a 1-day pass is sold for `costs[0]` dollars;
* a 7-day pass is sold for `costs[1]` dollars;
* a 30-day pass is sold for `costs[2]` dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of `days`.

## NOTE

1. `1 <= days.length <= 365`
2. `1 <= days[i] <= 365`
3. `days` is in strictly increasing order.
4. `costs.length == 3`
5. `1 <= costs[i] <= 1000`

## EXAMPLE 1

```plain
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
```

## EXAMPLE 2

```plain
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.
```

## SOLUTION

* 记忆化搜索，令 `dp[i]` 表示从 `day[i]` 开始走到最后的最小花费。则他的取值来源有三条：今天买单天票，买周票，或者买月票。三种不同的买票策略会改变之后的对应的天数内的取值不再改变，直到下一个没票的日期。记 `dp[i] := min $ [ dp[j_a] + costs[0], dp[j_b] + costs[1], dp[j_c] + costs[2] ]`，`dp[j_{a, b, c}]` 分别表示从 `days[i]` 开始往后数 1, 7, 30 天的最小 `days[]` 元素，也就是下一个没票的日期。记忆化搜索即可。

## CODE

### C++

```cpp
class Solution
{
    vector<int> *days, *costs, dp;
    int durations[3] = {1, 7, 30};

    int dfs(int i)
    {
        if (i >= days->size()) { return 0; }
        if (dp[i] != -1) { return dp[i]; }
        dp[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++)
        {
            while (j < days->size() && days->at(j) < days->at(i) + durations[k]) { j++; }
            dp[i] = std::min(dp[i], dfs(j) + costs->at(k));
        }
        return dp[i];
    }
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        this->days = &days;
        this->costs = &costs;
        dp.assign(days.size(), -1);
        return dfs(0);
    }
};
```

### Python3

### Ruby

### Java
