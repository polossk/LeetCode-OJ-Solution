# Integer to Roman

![Medium](../../materials/-Medium-f0ad4e.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode012-cpp-f34b7d.svg)   | 20 ms   | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode012-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode012-rb-701516.svg)   | -       | -            |

## DESCRIPTION

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

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

## EXAMPLE 1

```plain
Input: 3
Output: "III"
```

## EXAMPLE 2

```plain
Input: 4
Output: "IV"
```

## EXAMPLE 3

```plain
Input: 9
Output: "IX"
```

## EXAMPLE 4

```plain
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```

## EXAMPLE 5

```plain
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## SOLUTION

* 按规则匹配即可

## CODE

### C++

```cpp
class Solution {
    const string Roman[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
public:
    string intToRoman(int num)
    {
        return Roman[3][num / 1000 % 10] + Roman[2][num / 100 % 10]
            + Roman[1][num / 10 % 10] + Roman[0][num % 10];
    }
};
```

### Python3

### Ruby

