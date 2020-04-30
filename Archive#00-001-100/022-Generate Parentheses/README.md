# Valid Parentheses

![Medium](../../materials/-Medium-f0ad4e.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode022-cpp-f34b7d.svg)   | 8 ms    | 15.3 Mb      |
| ![python](https://img.shields.io/badge/leetcode022-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode022-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given *n* = 3, a solution set is:

```plain
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

## SOLUTION

* 记录当前剩余的左右括号字符数量然后 dfs

## CODE

### C++

```cpp
class Solution
{
    void dfs(vector<string> &ans, string &&cur, int Left, int Right)
    {
        if (Left == 0 && Right == 0) { ans.push_back(cur); return; }
        if (Left > Right) return; // using too much left parenthes
        if (Left > 0) { dfs(ans, cur + "(", Left - 1, Right); }
        if (Right > 0) { dfs(ans, cur + ")", Left, Right - 1); }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        if (n == 0) return ret;
        dfs(ret, "", n, n);
        return ret;
    }
};
```

### Python3

### Ruby
