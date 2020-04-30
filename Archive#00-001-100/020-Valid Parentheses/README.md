# Valid Parentheses

![Easy](../../materials/-Easy-5cb85c.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode020-cpp-f34b7d.svg)   | 0 ms    | 8.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode020-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode020-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

## EXAMPLE 1

```plain
Input: "()"
Output: true
```

## EXAMPLE 2

```plain
Input: "()[]{}"
Output: true
```

## EXAMPLE 3

```plain
Input: "(]"
Output: false
```

## EXAMPLE 4

```plain
Input: "([)]"
Output: false
```

## EXAMPLE 5

```plain
Input: "{[]}"
Output: true
```

## SOLUTION

* 堆栈模拟

## CODE

### C++

```cpp
class Solution {
private:
    set<char> left{ '(', '[', '{' };
    set<char> right{ ')', ']', '}' };
    map<char, char> query{ {')', '('},  {']', '['},  {'}', '{'} };
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (left.count(s[i])) { stk.push(s[i]); continue; }
            if (!right.count(s[i])) continue;
            if (stk.empty()) return false;
            if (query[s[i]] == stk.top()) { stk.pop(); }
            else return false;
        }
        return stk.empty();
    }
};
```

### Python3

### Ruby
