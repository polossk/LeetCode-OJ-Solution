# Last Stone Weight II

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1049-cpp-f34b7d.svg)   | 4 ms    | 6.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode1049-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1049-rb-701516.svg)   | -       | -            |

## DESCRIPTION

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose **any two rocks** and smash them together.  Suppose the stones have weights `x` and `y` with `x <= y`.  The result of this smash is:

* If `x == y`, both stones are totally destroyed;
* If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left.  Return the **smallest possible** weight of this stone (the weight is 0 if there are no stones left.)

## EXAMPLE 1

```plain
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
```

## NOTE

* `1 <= stones.length <= 30`
* `1 <= stones[i] <= 100`

## SOLUTION

* 01 背包问题，找到一种划分形式，使得两堆石子的分别重量尽量是 `sum / 2`，定义 `dp[i][j]` 表示前 `i` 种石头中，背包容量为 `j` 的情况下，所能得到的最大值。
* 对于每一个 `stones[i]`，如果不放入这个石头，相当于 `dp[i][j] = dp[i-1][j]`；如果选择放入这个石头，需要首先考虑剩余空间 `stones[i] <= j`，如果剩余空间不足，则不能放入；如果放进去了，则相当于 `dp[i][j] = dp[i-1][j-stones[i]] + stones[i]`

## CODE

### C++

```cpp
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sz = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int length = 1 + (sum >> 1);
		vector<int> dp(length, 0);
        for(int i = 0; i < sz; i++)
		{
            for(int j = length - 1; j >= stones[i]; j--)
			{
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[length - 1];
    }
};
```

### Python3

```python
```

### Ruby

