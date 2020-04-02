# String to Integer (atoi)

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode008-cpp-f34b7d.svg)   | 0 ms    | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode008-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode008-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement `atoi` which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

## EXAMPLE 1

```plain
Input: "42"
Output: 42
```

## EXAMPLE 2

```plain
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
```

## EXAMPLE 3

```plain
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
```

## EXAMPLE 4

```plain
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
```

## EXAMPLE 5

```plain
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−2^31) is returned.
```

## NOTE

* Only the space character `' '` is considered as whitespace character.
* Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

## SOLUTION

* 众所周知，`2^31-1 == 2147483647`
* 只要判断第十位数字（从前往后数）是不是超过了 7 就行了
* 注意正负号

## CODE

### C++

```cpp
class Solution
{
public:
    int myAtoi(string str)
    {
        int sign = 1, ret = 0, idx = 0;
        while (str[idx] == ' ') idx++;
        if (str[idx] == '-' || str[idx] == '+')
        {
            sign = 1 - 2 * (str[idx++] == '-');
        }
        while (isdigit(str[idx]))
        {
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[idx] > '7'))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ret = ret * 10 + (str[idx++] - '0');
        }
        return sign * ret;
    }
};
```

### Python3

### Ruby

