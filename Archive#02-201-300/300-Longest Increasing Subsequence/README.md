# Longest Increasing Subsequence

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg)  ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)
## RESULT

| Submission                                                                    | Runtime | Memory Usage |
| ----------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode300--dp-cpp-f34b7d.svg)           | 48 ms   | 7.9 Mb       |
| ![cpp](https://img.shields.io/badge/leetcode300--greedy--self-cpp-f34b7d.svg) | 0 ms    | 8 Mb         |
| ![cpp](https://img.shields.io/badge/leetcode300--greedy--std-cpp-f34b7d.svg)  | 0 ms    | 8 Mb         |
| ![python](https://img.shields.io/badge/leetcode300--dp-py-3572A5.svg)         | 836 ms  | 13 Mb        |
| ![python](https://img.shields.io/badge/leetcode300--greedy-py-3572A5.svg)     | 40 ms   | 13.2 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode300-rb-701516.svg)               | -       | -            |

## DESCRIPTION

Given an unsorted array of integers, find the length of longest increasing subsequence.

## EXAMPLE

```plain
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
```

## NOTE

* There may be more than one LIS combination, it is only necessary for you to return the length.
* Your algorithm should run in O(n^2) complexity.

## FOLLOW UP

Could you improve it to O(n log n) time complexity?

## SOLUTION

* 动态规划。定义 `dp[i]` 表示对于第 i 个元素，以他本身结尾的最长上升子序列的长度。状态转移方程 `dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i] for j < i`, 初值条件 `dp[:] = 1`。
* 贪心构造。定义数组 `trace[]` 用来存储一种可能的上升序列。如果希望上升序列的长度很长，那么反过来想就是希望上升的梯度很小，也就是尽可能的满足对于任意 `trace[]` 的两个相邻元素 `a` 和 `b`，`b` 应当为原数组仅大于 `a` 的元素。下一步就是如何构造这样的数组。我们对原数组逐项扫一遍，如果 `trace[-1] < elem` 说明保持了上升序列，应当将 `elem` 添加到 `trace[]` 的尾部；反之如果 `trace[-1] > elem`，说明此时把两项替换掉，上升序列的长度不变，而且还有希望变得更长（梯度减小了），这时需要从 `trace[]` 数组中找到刚才描述的只比 `elem` 小的元素，并替换。这样就在扫描的时候即保持了上升序列，同时尽可能压缩了梯度。最后我们便得到了一种可能的最长上升序列。

## CODE

### C++

```cpp
class Solution
{
public:
    // dp
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (!len) return 0;
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    // greedy
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (!len) return 0;
        vector<int> greedy; greedy.push_back(nums[0]);
        for (int i = 1; i < len; i++)
        {
            if (greedy.back() < nums[i]) greedy.push_back(nums[i]);
            else
            {
                // self implementation
                // int l = 0, r = greedy.size() - 1;
                // while (l < r)
                // {
                //     int mid = l + (r - l) >> 1;
                //     if (greedy[mid] < nums[i])
                //         l = mid + 1;
                //     else r = mid;
                // }
                // greedy[l] = nums[i];
                // std::lower_bound
                int pos = 0;
                do {
                    if (greedy.size() == 1) break;
                    auto it = std::lower_bound(greedy.begin(), greedy.end(), nums[i]);
                    pos = it == greedy.end() ? 0 : std::distance(greedy.begin(), it);
                } while (0);
                greedy[pos] = nums[i];
            }
        }
        return greedy.size();
    }
};
```

### Python3

```python
class Solution:
    # dp
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []: return 0
        dp = [1 for _ in range(len(nums))]
        for i in range(1, len(nums)):
            hoge = [dp[j] + 1 for j in range(i) if nums[j] < nums[i]]
            dp[i] = 1 if len(hoge) == 0 else max(hoge)
        return max(dp)

    # greedy
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) < 2: return len(nums)
        greedy = [nums[0]]
        for elem in nums[1:]:
            if greedy[-1] < elem:
                greedy.append(elem)
                continue
            l , r = 0, len(greedy) - 1
            while l < r:
                mid = l + (r - l) // 2
                if greedy[mid] < elem:
                    l = mid + 1
                else:
                    r = mid
            greedy[l] = elem
        return len(greedy)
```

### Ruby

### Java
