# Additive Number

![Medium](../../materials/-Medium-f0ad4e.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode306-cpp-f34b7d.svg)   | 4 ms    | 7.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode306-py-3572A5.svg) | 28 ms   | 12.5 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode306-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain **at least** three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits `'0'-'9'`, write a function to determine if it's an additive number.

## EXAMPLE 1

```plain
Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
```

## EXAMPLE 2

```plain
Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
```

## NOTE

Numbers in the additive sequence **cannot** have leading zeros, so sequence `1`, `2`, `03` or `1`, `02`, `3` is invalid.

## CONSTRAINTS

* `num` consists only of digits `'0'-'9'`.
* `1 <= num.length <= 35`

## FOLLOW UP

How would you handle overflow for very large input integers?

## SOLUTION

* 深度优先搜索枚举可能情况然后剪枝即可

## CODE

### C++

```cpp
class Solution
{
public:
    typedef long long int64;
    
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3) return false;
        return dfs(num, 0);
    }

    bool dfs(string s, int start)
    {
        for (int i = start, i_end = s.size() - 2; i < i_end; i++)
        {
            int64 a = 0, b = 0;
            for (int j = i + 1, j_end = s.size(); j < j_end; j++)
            {
                
                a = std::stoll(s.substr(start, i + 1 - start));
                b = std::stoll(s.substr(i + 1, j - i));
                string ans = std::to_string(a + b);
                string sc = s.substr(j + 1, ans.size());
                if (ans == sc)
                {
                    if (j + 1 + ans.size() == s.size()) return true;
                    if (dfs(s, i + 1)) return true;
                    break;
                }
                if (b == 0) break;
            }
            if (a == 0) return false;
        }
        return false;
    }
};
```

### Python3

```python
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        if len(num) < 3: return False
        return self.dfs(num, 0)
    
    def dfs(self, s, start):
        # select a, b from s, then check a + b = rest
        # print(">>> dfs(s, ", start, ")")
        for i in range(start, len(s) - 2):
            for j in range(i + 1, len(s)):
                a = int(s[start:i + 1])
                b = int(s[i + 1:j + 1])
                ans = str(a + b)
                s3 = s[j + 1:j + 1 + len(ans)]
                # print("i= ", i, "j= ", j, "a= ", a, "b= ", b, "ans= ", ans, "s3= ", s3, )
                if ans == s3:
                    if j + 1 + len(ans) == len(s): return True
                    rest = self.dfs(s, i + 1)
                    if rest: return True
                    break
                if b == 0: break
            if a == 0: return False
        return False
```

### Ruby

### Java
