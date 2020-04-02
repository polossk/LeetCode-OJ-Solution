# Palindrome Number

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode009-cpp-f34b7d.svg)   | 24 ms   | 6.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode009-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode009-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

## EXAMPLE 1

```plain
Input: 121
Output: true
```

## EXAMPLE 2

```plain
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

## EXAMPLE 3

```plain
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

## FOLLOW UP

Coud you solve it without converting the integer to a string?

## SOLUTION

* 反复除 10

## CODE

### C++

```cpp
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int hoge = 0;
        while (x > hoge)
        {
            hoge = hoge * 10 + x % 10;
            x /= 10;
        }
        return (x == hoge || x == hoge / 10);
    }
};
```

### Python3

### Ruby

