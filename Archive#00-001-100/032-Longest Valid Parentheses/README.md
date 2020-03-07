# Longest Valid Parentheses

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode031-cpp-f34b7d.svg)   | 4 ms    | 7.3 Mb       |
| ![python](https://img.shields.io/badge/leetcode031-py-3572A5.svg) | 48 ms   | 14 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode031-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

## EXAMPLE 1

```plain
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
```

## EXAMPLE 2

```plain
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
```

## SOLUTION

* 定义 `dp[i]` 表示到第 `i` 个字符结尾的最长有效串的长度
* 对于模式为 `......()` 的串，显然 `dp[i] := dp[i-2] + 2`
* 对于模式为 `......))` 的串，显然可以通过 `dp[i-1]` 来反推前面的字符，如果 `str[i - dp[i-1] - 1] == '('`，显然 `dp[i] := dp[i-1] + dp[i-dp[i-1]-2] + 2`，即此时的长度应该是之前的有效字符总长度加上一对括号

## CODE

### C++

```cpp
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int len = s.size();
        if (len < 2) return 0;
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '(') continue;
            int j = i - 1 - dp[i - 1];
            if (j >= 0 && s[j] == '(')
            {
                dp[i] = dp[i - 1] + 2;
                dp[i] += (j - 1 >= 0) ? dp[j - 1] : 0;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

### Python3

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        l = len(s)
        if l < 2: return 0
        dp = [0 for _ in range(l)]
        for i in range(1, l):
            if s[i] == ')':
                j = i - 1 - dp[i - 1]
                if j >= 0 and s[j] == '(':
                    dp[i] = dp[i - 1] + 2
                    if j - 1 >= 0:
                        dp[i] += dp[j - 1]
        return max(dp)
```

### Ruby

### Java
