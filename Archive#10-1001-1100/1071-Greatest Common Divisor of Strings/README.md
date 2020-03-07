# Greatest Common Divisor of Strings

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1071-cpp-f34b7d.svg)   | 4 ms    | 8.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode1071-py-3572A5.svg) | 28 ms   | 12.7 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1071-rb-701516.svg)   | -       | -            |

## DESCRIPTION

For strings `S` and `T`, we say "`T` divides `S`" if and only if `S = T + ... + T`  (`T` concatenated with itself 1 or more times)

Return the largest string `X` such that `X` divides `str1` and `X` divides `str2`.

## EXAMPLE 1

```plain
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
```

## EXAMPLE 2

```plain
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
```

## EXAMPLE 3

```plain
Input: str1 = "LEET", str2 = "CODE"
Output: ""
```

## NOTE

1. `1 <= str1.length <= 1000`
2. `1 <= str2.length <= 1000`
3. `str1[i]` and `str2[i]` are English uppercase letters.

## SOLUTION

* 首先给出完整的字符串与整数集合的相关运算。在这里，把两个字符串的连接操作定义为字符串的加法，我们姑且认为减法运算应当是前者的逆运算。类似整数的乘法描述重复加法一样，定义 `a * S` 描述整数 `a` 乘以字符串 `S`，其结果为执行 `a` 次 `+S` 运算。那么字符串的除法 `a = T / S` 相当于前者的逆运算。由于乘法运算是加法运算的进一步抽象，其优先级是高于加法运算的。
* 假设对于字符串 `S` 和 `T` 而言，其公因子为 `G`，那么显然有 `S = a * G`，`T = b * G`，注意到虽然字符串的加法并不满足交换律（`A + B != B + A`），但是如果两者有公共因子 `G`，此时 `S + T = a * G + b * G = (a + b) * G = (b + a) * G = T + S`。也就是说 `S + T == T + S` 是字符串 `S` 和 `T` 有公因子 `G` 的必要条件。
* 考虑逆命题，假设 `X := S + T`，`Y := T + S`，`len(S) >= len(T)`，此时我们有 `S + T == T + S`。这说明，对于任意位置，两字符串的字符相同。既然如此，我们选取其中长度为 `g = gcd(len(S), len(T))` 的第一条子串，由于 `X[:g] == Y[:g]` 也就说明 `S[:g] == T[:g]`。而其余剩下的每一条长度为 `g` 的子串均可以推导出类似性质。也就是说，`S` 和 `T` 均有最大公因子 `S[:g]`。即证明充分性。
* 所以只需判断条件 `S + T ?= T + S`，然后在直接计算 `S[:g]` 即可

## CODE

### C++

```cpp
class Solution
{
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
```

### Python3

```python
import math
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        return str1[:(math.gcd(len(str1), len(str2)))]
```

### Ruby

