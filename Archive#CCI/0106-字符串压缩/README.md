# 字符串压缩

![Easy](../../materials/-Easy-5cb85c.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                    | Runtime | Memory Usage |
| ------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cci0106-cpp-f34b7d.svg)   | 8 ms    | 9.7 Mb       |
| ![python](https://img.shields.io/badge/cci0106-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cci0106-rb-701516.svg)   | -       | -            |

## DESCRIPTION

字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串 `aabcccccaaa` 会变为 `a2b1c5a3`。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

## EXAMPLE 1

```plain
输入："aabcccccaaa"
输出："a2b1c5a3"
```

## EXAMPLE 2

```plain
输入："abbccd"
输出："abbccd"
解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
```

## EXAMPLE 3

```plain
Input: str1 = "LEET", str2 = "CODE"
Output: ""
```

## HINT

1. 字符串长度在[0, 50000]范围内。

## SOLUTION

* 用 `stringstream` 来存临时字符串，然后把字符串取出就行

## CODE

### C++

```cpp
class Solution
{
public:
    string compressString(string S)
    {
        if (S.size() == 0) return S;
        stringstream tmp;
        int cnt = 1, sz = S.size();
        char ch = S[0];
        for (int i = 1; i < sz; i++)
        {
            if (S[i] == ch) cnt++;
            else
            {
                tmp << ch << cnt;
                ch = S[i];
                cnt = 1;
            }
        }
        tmp << ch << cnt;
        string ret; tmp >> ret;
        return sz <= ret.size() ? S : ret;
    }
};
```

### Python3


### Ruby

