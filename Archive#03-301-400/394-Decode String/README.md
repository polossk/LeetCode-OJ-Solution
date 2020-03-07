# Maximum Product of Word Lengths

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Stack](https://img.shields.io/badge/堆栈-Stack-007ec6.svg) ![Depth--first_Search](https://img.shields.io/badge/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode394-cpp-f34b7d.svg)   | 4 ms    | 8.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode394-py-3572A5.svg) | 28 ms   | 12.7 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode394-rb-701516.svg)   | 28 ms   | 9.4 Mb       |

## DESCRIPTION

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the encoded_string inside the square brackets is being repeated exactly *k* times. Note that *k* is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, *k*. For example, there won't be input like `3a` or `2[4]`.

## EXAMPLE

```plain
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
```

## SOLUTION

* 回溯法从最后一个中括号开始解压
* 正则表达式水题, 匹配模式 `(\d+)\[([^\[^\]]*)\]`

## CODE

### C++

```cpp
class Solution {
    string dfs(string s, int &&idx)
    {
        string ret;
        while (idx < s.size() && s[idx] != ']')
        {
            if (isdigit(s[idx]))
            {
                int n = 0;
                while (idx < s.size() && isdigit(s[idx]))
                    n = n * 10 + s[idx++] - '0';
                idx++; string hoge = dfs(s, std::move(idx)); idx++;
                while (n-- > 0) ret += hoge;
            }
            else ret += s[idx++];
        }
        return ret;
    }
public:
    string decodeString(string s) { return dfs(s, 0); }
};
```

### Python3

```python
class Solution:
    def decodeString(self, s: str) -> str:
        while '[' in s:
            s = re.sub(r'(\d+)\[([^\[^\]]*)\]', lambda m: int(m.group(1)) * m.group(2), s)
        return s
```

### Ruby

```ruby
# @param {String} s
# @return {String}
def decode_string(s)
  1 while s.gsub!(/(\d+)\[([^\[^\]]*)\]/) { $2 * $1.to_i }
  s
end
```

### Java
