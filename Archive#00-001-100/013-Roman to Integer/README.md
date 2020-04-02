# Roman to Integer

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode013-cpp-f34b7d.svg)   | 32 ms   | 7.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode013-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode013-rb-701516.svg)   | -       | -            |

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, two is written as `II` in Roman numeral, just two one's added together. Twelve is written as, `XII`, which is simply `X + II`. The number twenty seven is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

* `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
* `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
* `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

## EXAMPLE 1

```plain
Input: "III"
Output: 3
```

## EXAMPLE 2

```plain
Input: "IV"
Output: 4
```

## EXAMPLE 3

```plain
Input: "IX"
Output: 9
```

## EXAMPLE 4

```plain
Input: "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3.
```

## EXAMPLE 5

```plain
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## SOLUTION

* 判断前一个字符是否比后一个字符代表的数字小。如果是的话说明此时是减法。

## CODE

### C++

```cpp
class Solution {
    unordered_map<char, int> _ = {
        { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 },
        { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
    };
public:
    int romanToInt(string s)
    {
        int ret = _[s.back()];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            ret -= (_[s[i]] < _[s[i + 1]]) ? _[s[i]] : -_[s[i]];
        }
        return ret;
    }
};
```

### Python3

### Ruby

