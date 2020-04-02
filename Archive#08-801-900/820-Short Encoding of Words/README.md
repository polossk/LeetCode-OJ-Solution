# Short Encoding of Words

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Structured_Approach](https://img.shields.io/badge/构造法-Structured_Approach-009688.svg) ![Tire2](https://img.shields.io/badge/Tire树-Tire-009688.svg) 

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode820-cpp-f34b7d.svg)   | 68 ms   | 9.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode820-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode820-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a list of words, we may encode it by writing a reference string `S` and a list of indexes `A`.

For example, if the list of words is `["time", "me", "bell"]`, we can write it as `S = "time#bell#"` and `indexes = [0, 2, 5]`.

Then for each index, we will recover the word by reading from the reference string from that index until we reach a `"#"` character.

What is the length of the shortest reference string S possible that encodes the given words?

## NOTE

1. `1 <= words.length <= 2000`.
2. `1 <= words[i].length <= 7`.
3. Each word has only lowercase letters.

## EXAMPLE

```plain
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
```

## SOLUTION

* 根据样例可以想到一个简单的答案构造方法：贪心合并，假设固定其中一个串 `A`，从剩下的字符串中查找一个最长的后缀串 `B`，这样这两个子串就可以合并，从而减少总的字节长度。
* 那么就很容易想到以字符 `#` 为根节点反向构建 Tire 树，最后统计每一个叶子节点的深度求和即可
* 既然可以反向构建 Tire 树，那么也可以反向排序字符串，即从最后一个字符判断大小而不是从第一个字符开始判断，最后对排序好的序列扫一遍，判断当前的字符串是否为下一个的合法后缀即可

## CODE

### C++

```cpp
class Solution
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        int sz = words.size();
        sort(words.begin(), words.end(), [](const string &_1, const string &_2) -> bool
        {
            int sz1 = _1.size(), sz2 = _2.size();
            for (int i = 0, sz = min(sz1, sz2); i < sz; i++)
            {
                char c1 = _1[sz1 - 1 - i], c2 = _2[sz2 - 1 - i];
                if (c1 == c2) continue;
                return c1 < c2;
            }
            return sz1 < sz2;
        });
        int ret = 0;
        auto tail_check = [](const string &body, const string &tail) -> bool
        {
            int sz_bd = body.size(), sz_tl = tail.size();
            if (sz_bd < sz_tl) return false;
            for (int i = 0; i < sz_tl; i++)
            {
                if (body[sz_bd - sz_tl + i] == tail[i]) continue;
                return false;
            }
            return true;
        };
        for (int i = 0; i < sz; i++)
        {
            if (i + 1 < sz && tail_check(words[i + 1], words[i])) continue;
            ret += words[i].size() + 1; // plus #
        }
        return ret;
    }
};
```

### Python3

### Ruby
