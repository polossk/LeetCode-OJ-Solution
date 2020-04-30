# Basic Calculator

![Hard](../../materials/-Hard-e05d44.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode224-cpp-f34b7d.svg)   | 24 ms   | 8 Mb         |
| ![python](https://img.shields.io/badge/leetcode224-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode224-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open `(` and closing parentheses `)`, the plus `+` or minus sign `-`, **non-negative** integers and empty spaces .

## EXAMPLE 1

```plain
Input: "1 + 1"
Output: 2
```

## EXAMPLE 2

```plain
Input: " 2-1 + 2 "
Output: 3
```

## EXAMPLE 3

```plain
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

## NOTE

* You may assume that the given expression is always valid.
* **Do not** use the eval built-in library function.

## SOLUTION

* 维护两个堆栈，一个储存数字，另一个储存算符

## CODE

### C++

```cpp
class Solution
{
public:
    int calculate(string s)
    {
        if (s.size() < 1) return 0;
        vector<int> signs(2, 1);
        auto ch2i = [](char ch) -> int { return ch - '0'; };
        int ret = 0, tmp = 0;
        for (int i = 0, sz = s.size(); i < sz; )
        {
            if (isspace(s[i])) { i++; continue; }
            if (isdigit(s[i]))
            {
                tmp = 0;
                while (i < sz && isdigit(s[i]))
                    tmp = tmp * 10 + ch2i(s[i++]);
                ret += signs.back() * tmp;
                signs.pop_back();
            }
            else if (s[i] == ')') { signs.pop_back(); i++; }
            else if (s[i] != ' ')
                signs.push_back(signs.back() * (s[i++] == '-' ? -1 : 1));
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
