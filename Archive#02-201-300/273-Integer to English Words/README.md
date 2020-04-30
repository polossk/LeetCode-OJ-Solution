# Integer to English Words

![Hard](../../materials/-Hard-e05d44.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode273-cpp-f34b7d.svg)   | 4 ms    | 6.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode273-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode273-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

## EXAMPLE 1

```plain
Input: 123
Output: "One Hundred Twenty Three"
```

## EXAMPLE 2

```plain
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

## EXAMPLE 3

```plain
Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

## EXAMPLE 4

```plain
Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
```

## SOLUTION

* 注意特判0-20的数字即可

## CODE

### C++

```cpp
class Solution
{
    const string _1[20] = {
        "Zero", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", 
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    const string _2[10] = {
        "Zero", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    const int _3[3] = { 1000000000, 1000000, 1000 };

    string int2str(int n)
    {
        if (n >= _3[0])
            return int2str(n / _3[0]) + " Billion" + int2str(n % _3[0]);
        else if (n >= _3[1])
            return int2str(n / _3[1]) + " Million" + int2str(n % _3[1]);
        else if (n >= _3[2])
            return int2str(n / _3[2]) + " Thousand" + int2str(n % _3[2]);
        else if (n >= 100)
            return int2str(n / 100) + " Hundred" + int2str(n % 100);
        else if (n >= 20)
            return " " + _2[n / 10] + int2str(n % 10);
        else if (n >= 1)
            return " " + _1[n];
        else return "";
    }

public:
    string numberToWords(int num)
    {
        if (num == 0) return _1[0];
        else return int2str(num).substr(1);
    }
};
```

### Python3

### Ruby

### Java
