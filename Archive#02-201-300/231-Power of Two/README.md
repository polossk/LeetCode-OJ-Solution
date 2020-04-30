# Power of Two

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Bit_Manipulation](../../materials/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode231-cpp-f34b7d.svg)   | 0 ms    | 5.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode231-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode231-rb-701516.svg)   | 60 ms   | 9.2 Mb       |

## DESCRIPTION

Invert a binary tree.

## EXAMPLE 1

```plain
Input: 1
Output: true 
Explanation: 20 = 1
```

## EXAMPLE 2

```plain
Input: 16
Output: true
Explanation: 24 = 16
```

## EXAMPLE 3

```plain
Input: 218
Output: false
```

## SOLUTION

* 对于整型数字（-2^31 ~ 2^31 -1），如果是 2 的幂次项，那么他一定能被 2^32 整除
* 也可以递归分解判断是否能被 2 整除，递归深度不超过 32 层

## CODE

### C++

```cpp
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 1) return false;
        return 4294967296 % n == 0 ? 1 : 0;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_two( n )
  return false if (n % 2 != 0 && n != 1)
  return false if (n < 2 && n != 1)
  return true if (1..2).include?(n)
  is_power_of_two(n / 2)
end
```
