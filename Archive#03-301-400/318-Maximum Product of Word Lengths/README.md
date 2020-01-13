# Maximum Product of Word Lengths

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Bit%20Manipulation](https://img.shields.io/badge/-Bit%20Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode318-cpp-f34b7d.svg)   | 40 ms   | 15.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode318-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode318-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string array `words`, find the maximum value of `length(word[i]) * length(word[j])` where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

## NOTE

* The length of `asteroids` will be at most `10000`.
* Each asteroid will be a non-zero integer in the range `[-1000, 1000]`.

## EXAMPLE 1:

```plain
Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
```

## Example 2:

```plain
Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
```

## Example 3:

```plain
Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
```

## SOLUTION

* 用 `int` 型数据记录字符 ch 是否出现（类 Hash 编码），然后对两个单词的编码后的数据做与运算（`&`）来判断是否有相同字符

## CODE

### C++

```cpp
class Solution {
    int encode(string str)
    {
        int ret = 0;
        for (auto ch : str)
        {
            ret |= 1 << (ch - 'a');
        }
        return ret;
    }

public:
    int maxProduct(vector<string>& words)
    {
        vector<int> encoded, len;
        for (auto str : words)
        {
            encoded.push_back(encode(str));
            len.push_back(str.size());
        }
        int ret = 0, sz = encoded.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (encoded[i] & encoded[j]) continue;
                int tmp = len[i] * len[j];
                ret = ret > tmp ? ret : tmp;
            }
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
