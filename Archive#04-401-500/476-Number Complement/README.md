# Number Complement

![Easy](../../materials/-Easy-5cb85c.svg) ![Bit_Manipulation](../../materials/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode476-cpp-f34b7d.svg)   | 0 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode476-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode476-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

## NOTE

1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.
3. This question is the same as 1009: <https://leetcode.com/problems/complement-of-base-10-integer/>

## EXAMPLE 1

```plain
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

## EXAMPLE 2

```plain
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
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
    int findComplement(int num)
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
