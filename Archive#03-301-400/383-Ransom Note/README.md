# Ransom Note

![Easy](../../materials/-Easy-5cb85c.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode383-cpp-f34b7d.svg)   | 16 ms   | 14.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode383-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode383-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

## NOTE

You may assume that both strings contain only lowercase letters.

## EXAMPLE

```plain
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
```

## SOLUTION

* 用字典维护出现的次数，然后逐字符判断是否有足够存货

## CODE

### C++

```cpp
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> cnt;
        for (auto ch : magazine) cnt[ch]++;
        for (auto ch : ransomNote)
        {
            if (cnt[ch] <= 0) return false;
            cnt[ch]--;
        }
        return true;
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
