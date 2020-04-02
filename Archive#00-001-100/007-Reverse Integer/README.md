# Reverse Integer

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode007-cpp-f34b7d.svg)   | 0 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode007-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode007-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a 32-bit signed integer, reverse digits of an integer.

## EXAMPLE 1

```plain
Input: 123
Output: 321
```

## EXAMPLE 2

```plain
Input: -123
Output: -321
```

## EXAMPLE 3

```plain
Input: 120
Output: 21
```

## NOTE

Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

## SOLUTION

* 反复除 10

## CODE

### C++

```cpp
class Solution {
    using int64 = long long;
public:
    int reverse(int x)
    {
        int64 ret = 0;
        while ( x != 0)
        {
            int digit = x % 10;
            int64 hoge = ret * 10 + digit;
            if ((hoge - digit) / 10 != ret) return 0;
            ret = hoge; x /= 10;
        }
        return ret == int(ret) ? int(ret) : 0;
    }
};
```

### Python3

### Ruby

