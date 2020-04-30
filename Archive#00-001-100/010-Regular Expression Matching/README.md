# Regular Expression Matching

![Hard](../../materials/-Hard-e05d44.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode010-cpp-f34b7d.svg)   | 24 ms   | 12.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode010-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode010-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.

```plain
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
```

The matching should cover the **entire** input string (not partial).

## EXAMPLE 1

```plain
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

## EXAMPLE 2

```plain
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

## EXAMPLE 3

```plain
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

## EXAMPLE 4

```plain
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
```

## EXAMPLE 5

```plain
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```

## NOTE

* `s` could be empty and contains only lowercase letters `a-z`.
* `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.

## SOLUTION

* 直接暴力深搜即可

## CODE

### C++

```cpp
class Solution {
    bool dfs(const string& _s, const string& _p, int i, int j)
    {
        char s = _s[i], p = _p[j];
        if (p == '\0') return s == '\0';
        if (_p[j + 1] == '*')
            return dfs(_s, _p, i, j + 2)
                || (s != '\0' && (s == p || p =='.'))
                && dfs(_s, _p, i + 1, j);
        else
            return (s != '\0' && (s == p || p =='.'))
                && dfs(_s, _p, i + 1, j + 1);
    }
public:
    bool isMatch(string s, string p) { return dfs(s, p, 0, 0); }
};
```

### Python3

```python
```

### Ruby

```ruby
```
