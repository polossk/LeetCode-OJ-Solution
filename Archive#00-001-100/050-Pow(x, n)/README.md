# Pow(x, n)

![Medium](../../materials/-Medium-f0ad4e.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode050-cpp-f34b7d.svg)   | 0 ms    | 5.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode050-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode050-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement pow(x, n), which calculates x raised to the power n (x^n).

## EXAMPLE 1

```plain
Input: 2.00000, 10
Output: 1024.00000
```

## EXAMPLE 2

```plain
Input: 2.10000, 3
Output: 9.26100
```

## EXAMPLE 3

```plain
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

## NOTE

* -100.0 < x < 100.0
* n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

## SOLUTION

* 快速幂

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
    double qmul(double x, int64 n)
    {
        double ret = 1.0;
        while (n)
        {
            if (n & 1) ret *= x;
            n >>= 1;
            x *= x;
        }
        return ret;
    }
public:
    double myPow(double x, int n)
    {
        return n >= 0 ? qmul(x, n) : 1.0 / qmul(x, -int64(n));
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
