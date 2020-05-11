# Valid Perfect Square

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode367-cpp-f34b7d.svg)   | 16 ms   | 14.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode367-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode367-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a positive integer *num*, write a function which returns True if *num* is a perfect square else False.

## NOTE

**Do not** use any built-in library function such as `sqrt`.

## EXAMPLE 1

```plain
Input: 16
Output: true
```

## EXAMPLE 2

```plain
Input: 14
Output: false
```

## SOLUTION

* 先计算取整后的平方根然后判断其平方是否与原数相同

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
    constexpr static double EPS = 1e-7;
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
public:
    bool isPerfectSquare(int num)
    {
        int64 x = mySqrt(num);
        return x * x == num;
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
