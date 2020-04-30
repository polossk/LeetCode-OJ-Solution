# Divide Two Integers

![Medium](../../materials/-Medium-f0ad4e.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode029-cpp-f34b7d.svg)   | 4 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode029-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode029-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing `dividend` by `divisor`.

The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.

## NOTE

* Both dividend and divisor will be 32-bit signed integers.
* The divisor will never be 0.
* Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function **returns 2^31 − 1 when the division result overflows**.

## EXAMPLE 1

```plain
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
```

## EXAMPLE 2

```plain
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
```

## SOLUTION

* 用 `long long (int64_t)` 类型处理溢出，然后用快速乘法的逆操作做快速除法

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
public:
    int divide(int dividend, int divisor)
    {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = 1 - (((dividend > 0) ^ (divisor > 0)) << 1);
        int64 a = labs(dividend), b = labs(divisor);
        int64 ret = 0;
        while (a >= b)
        {
            int64 tmp = b, hoge = 1;
            while (a >= (tmp << 1)) { tmp <<= 1; hoge <<= 1; }
            a -= tmp; ret += hoge;
        }
        return int(sign * ret);
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
