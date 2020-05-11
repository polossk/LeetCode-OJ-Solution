# Sqrt(x)

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode069-cpp-f34b7d.svg)   | 0 ms    | 5.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode069-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode069-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement `int sqrt(int x)`.

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

## EXAMPLE 1

```plain
Input: 4
Output: 2
```

## EXAMPLE 2

```plain
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

## SOLUTION

* 牛顿迭代法

## CODE

### C++

```cpp
class Solution
{
    constexpr static double EPS = 1e-7;
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        double a = x, x0 = x;
        while (true)
        {
            double x1 = 0.5 * (x0 + a / x0);
            if (fabs(x0 - x1) < EPS) break;
            x0 = x1;
        }
        return int(x0);
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
