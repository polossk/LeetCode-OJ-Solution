# Maximal Square

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode221-cpp-f34b7d.svg)   | 20 ms   | 8.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode221-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode221-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

## EXAMPLE

```plain
Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```

## SOLUTION

* `dp[i][j]` 表示到 `mat[i][j]` 时最大满足条件的正方形的边长
* 从上往下从左往右更新，当且仅当 `mat[i][j] == 1` 时，更新 `dp[i][j] := min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1`，否则 `dp[i][j] := 0`

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
