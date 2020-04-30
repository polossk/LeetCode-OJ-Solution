# Complement of Base 10 Integer

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1009-cpp-f34b7d.svg)   | 0 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode1009-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1009-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Every non-negative integer N has a binary representation.  For example, `5` can be represented as `"101"` in binary, `11` as `"1011"` in binary, and so on.  Note that except for `N = 0`, there are no leading zeroes in any binary representation.

The *complement* of a binary representation is the number in binary you get when changing every `1` to a `0` and `0` to a `1`.  For example, the complement of `"101"` in binary is `"010"` in binary.

For a given number `N` in base-10, return the complement of it's binary representation as a base-10 integer.

## NOTE

1. `0 <= N < 10^9`
2. This question is the same as 476: <https://leetcode.com/problems/number-complement/>

## EXAMPLE 1

```plain
Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

## EXAMPLE 2

```plain
Input: 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

## EXAMPLE 3

```plain
Input: 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

## SOLUTION

* 对 num 求其二进制数的长度（如 5 的二进制表示为 101，长度为 3），然后构造一个相同长度的全为 1 的数字 flag，让它和 num 做异或运算即可

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
public:
    int bitwiseComplement(int num)
    {
        if (num == 0) return 1;
        int64 save = num, flag = 1;
        while (num > 0) { flag <<= 1; num >>= 1; }
        return int((flag - 1) ^ save);
    }
};
```

### Python3

### Ruby

### Java
