# First Unique Character in a String

![Easy](../../materials/-Easy-5cb85c.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode387-cpp-f34b7d.svg)   | 104 ms  | 10.8 Mb      |
| ![python](https://img.shields.io/badge/leetcode387-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode387-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

## NOTE

You may assume the string contain only lowercase letters.

## EXAMPLE

```plain
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

## SOLUTION

* 维护一个字典记录出现次数即可

## CODE

### C++

```cpp
class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::unordered_map<char, int> cnt;
        for (auto ch : s) cnt[ch]++;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            if (cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
