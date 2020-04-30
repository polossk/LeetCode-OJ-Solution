# Longest Common Prefix

![Easy](../../materials/-Easy-5cb85c.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode014-cpp-f34b7d.svg)   | 4 ms    | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode014-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode014-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

## EXAMPLE 1

```plain
Input: ["flower","flow","flight"]
Output: "fl"
```

## EXAMPLE 2

```plain
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

## NOTE

All given inputs are in lowercase letters `a-z`.

## SOLUTION

* 暴力判断即可

## CODE

### C++

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ret;
        if (!strs.size()) return ret;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char curr = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i > strs[j].size() - 1 || curr != strs[j][i]) return ret;
            }
            ret.push_back(curr);
        }
        return ret;
    }
};
```

### Python3

### Ruby

