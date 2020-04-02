# Longest Common Subsequence

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1143-cpp-f34b7d.svg)   | 36 ms   | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode1143-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1143-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

## EXAMPLE 1

```plain
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

## EXAMPLE 2

```plain
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

## EXAMPLE 3

```plain
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

## CONSTRAINTS

1. `1 <= text1.length <= 1000`
2. `1 <= text2.length <= 1000`
3. The input strings consist of lowercase English characters only.

## SOLUTION

* 基础 dp，令 `dp[i][j]` 记录 `text1[0:i]` 和 `text2[0:j]` 这两个子串匹配时的最大长度。
* `dp[i][j]` 的来源有三条：当且仅当 `text1[i] == text2[j]` 时，`dp[i][j] := dp[i-1][j-1] + 1`；否则，从 `dp[i-1][j]` 和 `dp[i-1][j]` 中选择较大的作为 `dp[i][j]` 的值

## CODE

### C++

```cpp
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int sz1 = text1.size(), sz2.text2.size();
        vector<int> dp(sz1 + 1, 0);
        int ret = 0;
        for (int j = 1; j <= sz2; j++)
        {
            int last = 0;
            for (int i = 1; i <= sz1; i++)
            {
                int tmp = dp[i];
                dp[i] = text1[i-1] == text2[j-1] ? (last + 1) : std::max(dp[i-1], dp[i]);
                ret = std::max(ret, dp[i]);
                last = tmp;
            }
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

