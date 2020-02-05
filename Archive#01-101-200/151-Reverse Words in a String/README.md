# Reverse Words in a String

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode151-cpp-f34b7d.svg)   | 8 ms    | 9.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode151-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode151-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an input string, reverse the string word by word.

## NOTE

* A word is defined as a sequence of non-space characters.
* Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
* You need to reduce multiple spaces between two words to a single space in the reversed string.

## EXAMPLE 1

```plain
Input: "the sky is blue"
Output: "blue is sky the"
```

## EXAMPLE 2

```plain
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

## EXAMPLE 3

```plain
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

## SOLUTION

* 字符串模拟基础

## CODE

### C++

```cpp
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int hoge = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') continue;
            if (hoge != 0) s[hoge++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ')
                s[hoge++] = s[j++];
            reverse(s.begin() + hoge + i - j, s.begin() + hoge);
            i = j;
        }
        s.erase(s.begin() + hoge, s.end());
        return s;
    }
};
```

### Python3

### Ruby
