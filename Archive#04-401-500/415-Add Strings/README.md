# Add Strings

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode415-cpp-f34b7d.svg)   | 8 ms    | 58.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode415-py-3572A5.svg) | 36 ms   | 13.2 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode415-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two non-negative integers `num1` and `num2` represented as string, return the sum of `num1` and `num2`.

## NOTE

1. The length of both `num1` and `num2` is < 5100.
2. Both `num1` and `num2` contains only digits `0-9`.
3. Both `num1` and `num2` does not contain any leading zero.
4. You **must not use any built-in BigInteger library or convert the inputs to integer** directly.

## SOLUTION

* 字符串模拟基础

## CODE

### C++

```cpp
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0) { sum += (num1[i] - '0'); i--; }
            if (j >= 0) { sum += (num2[j] - '0'); j--; }
            sum += carry;
            carry = sum / 10;
            res = to_string(sum % 10) + res;
        }
        return res;
    }
};
```

### Python3

```python
import itertools

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        z = itertools.zip_longest(num1[::-1], num2[::-1], fillvalue='0')
        res, carry, zero2 = [], 0, 2 * ord('0')
        for i in z:
            cur_sum = ord(i[0]) + ord(i[1]) - zero2 + carry
            res.append(str(cur_sum % 10))
            carry = cur_sum // 10
        return ('1' if carry else '') + ''.join(res[::-1])
```

### Ruby

### Java
