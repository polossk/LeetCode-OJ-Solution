# Reverse String II

![Easy](../../materials/-Easy-5cb85c.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode541-cpp-f34b7d.svg)   | 4 ms    | 9.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode541-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode541-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

## EXAMPLE

```plain
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

## RESTRICTIONS

1. The string consists of lower English letters only.
2. Length of the given string and k will in the range [1, 10000]

## SOLUTION

* String 基础操作，先确定交换的区间然后再逐元素交换位置即可

## CODE

### C++

```cpp
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int it = 0, _ = s.size() / (2 * k); it <= _; it++)
        {
            int i = it * 2 * k; int j = i + k - 1;
            j = j > s.size() - 1 ? s.size() - 1 : j;
            while (i < j) std::swap(s[i++], s[j--]);
        }
        return s;
    }
};
```

### Python3


### Ruby

