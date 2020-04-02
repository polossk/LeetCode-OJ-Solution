# Fraction to Recurring Decimal

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode166-cpp-f34b7d.svg)   | 4 ms    | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode166-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode166-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode166-java-b07219.svg) | -       | -            |

## DESCRIPTION

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

## EXAMPLE 1

```plain
Input: numerator = 1, denominator = 2
Output: "0.5"
```

## EXAMPLE 2

```plain
Input: numerator = 2, denominator = 1
Output: "2"
```

## EXAMPLE 3

```plain
Input: numerator = 2, denominator = 3
Output: "0.(6)"
```

## NOTE

Do not modify the linked list.

## FOLLOW UP

* Can you solve it without using extra space?


## SOLUTION

* 用哈希表维护小数出现的位置即可

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
public:
    string fractionToDecimal(int64 n, int64 d)
    {
        if (n == 0) return "0";
        string ret = "";
        if (n < 0 ^ d < 0) ret += '-';
        n = abs(n); d = abs(d);
        ret += to_string(n / d);
        if (n % d == 0) return ret;
        ret += '.';
        unordered_map<int64, int> m;
        for (int64 r = n % d; r; r %= d)
        {
            if (m.count(r) > 0)
            {
                ret.insert(m[r], 1, '(');
                ret += ')';
                return ret;
            }
            m[r] = ret.size();
            r *= 10;
            ret += to_string(r / d);
        }
        return ret;
    }
};
```

### Python3


### Ruby


### Java

