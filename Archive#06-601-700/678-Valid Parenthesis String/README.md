# Valid Parenthesis String

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode678-cpp-f34b7d.svg)   | 0 ms    | 6.3 Mb       |
| ![python](https://img.shields.io/badge/leetcode678-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode678-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string containing only three types of characters: `'('`, `')'` and `'*'`, write a function to check whether this string is valid. We define the validity of a string by these rules:

1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string.
5. An empty string is also valid.

## EXAMPLE 1

```plain
Input: "()"
Output: True
```

## EXAMPLE 2

```plain
Input: "(*)"
Output: True
```

## EXAMPLE 2

```plain
Input: "(*))"
Output: True
```

## NOTE

1. The string size will be in the range [1, 100].

## SOLUTION

* 括号匹配时要求任意一个左括号都要在其右边存在一个右括号，任意一个右括号同样需要在其左边存在一个左括号。所以可以借助这一条件，在从左到右扫描字符串时，预先判断处理不满足右括号左边需要左括号的情况。
* 之后再从右到左扫描判断任意多余左括号能否用右边的一个星号匹配的情况。

## CODE

### C++

```cpp
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> left, star;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (s[i] == '(') { left.push(i); }
            else if (s[i] == '*') { star.push(i); }
            else // s[i] == ')'
            {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        if (left.size() > star.size()) return false;
        while (!left.empty())
        {
            int left_idx = left.top(); left.pop();
            int star_idx = star.top(); star.pop();
            if (left_idx > star_idx) return false;
        }
        return true;
    }
};
```

### Python3

### Ruby

### Java
