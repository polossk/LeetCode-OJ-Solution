# Find Words That Can Be Formed by Characters

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1160-cpp-f34b7d.svg)   | 72 ms   | 21.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode1160-py-3572A5.svg) | 132 ms  | 13.2 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1160-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are given an array of strings `words` and a string `chars`.

A string is good if it can be formed by characters from `chars` (each character can only be used once).

Return the sum of lengths of all good strings in `words`.

## EXAMPLE 1

```plain
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
```

## EXAMPLE 2

```plain
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
```

## NOTE

1. `1 <= words.length <= 1000`
2. `1 <= words[i].length, chars.length <= 100`
3. All strings contain lowercase English letters only.

## SOLUTION

* `ch-'a'` 统计字符数量，然后判断即可

## CODE

### C++

```cpp
class Solution
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int ret = 0;
        vector<int> cnt(26, 0);
        for (int i = 0, sz = chars.size(); i < sz; i++)
            cnt[chars[i] - 'a']++;
        for (auto word : words)
        {
            vector<int> tmp = vector<int>(cnt);
            int sz = word.size(), flag = 1;
            for (int i = 0; i < sz; i++)
            {
                if (tmp[word[i] - 'a'] == 0) { flag = 0; break; }
                else tmp[word[i] - 'a']--;
            }
            ret += flag ? sz : 0;
        }
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def loc(ch): return ord(ch) - ord('a')
        
        fqcs = [0 for _ in range(26)]
        for ch in chars: fqcs[loc(ch)] += 1
        ret = 0
        for word in words:
            tmp = fqcs[:]
            flag = 1
            for ch in word:
                if tmp[loc(ch)] == 0:
                    flag = 0
                    break
                else:
                    tmp[loc(ch)] -= 1
            ret += len(word) if flag == 1 else 0
        return ret
```

### Ruby

