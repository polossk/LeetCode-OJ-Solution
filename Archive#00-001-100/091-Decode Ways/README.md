# Decode Ways

![Medium](../../materials/-Medium-f0ad4e.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode091-cpp-f34b7d.svg)   | 0 ms    | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode091-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode091-rb-701516.svg)   | -       | -            |

## DESCRIPTION

A message containing letters from `A-Z` is being encoded to numbers using the following mapping:

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

Given a **non-empty** string containing only digits, determine the total number of ways to decode it.

## EXAMPLE 1

```plain
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```

## EXAMPLE 2

```plain
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

## SOLUTION

* 拼字拆分组合

## CODE

### C++

```cpp
class Solution
{
    inline bool _(char __) { return __ != '0'; }

    inline bool _(char _1, char _2)
    {
        return _1 == '1' || (_1 == '2' && _2 <= '6');
    }
public:
    int numDecodings(string s)
    {
        int sz = s.size();
        if (sz == 0 || s[0] == '0') return 0;
        if (sz == 1) return 1;
        int ret = 0, a = 1, b = 1;
        for (int i = 1; i < sz; i++)
        {
            ret = 0;
            if (!_(s[i]) && !_(s[i - 1], s[i])) return 0;
            if (_(s[i])) ret = a;
            if (_(s[i-1], s[i])) ret += b;
            b = a; a = ret;
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java

```java
```
