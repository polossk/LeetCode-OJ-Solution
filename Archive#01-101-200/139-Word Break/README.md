# Word Break

![Medium](../../materials/-Medium-f0ad4e.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode139-cpp-f34b7d.svg)   | 36 ms   | 14.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode139-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode139-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a **non-empty** string s and a dictionary *wordDict* containing a list of **non-empty** words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

## NOTE

* The same word in the dictionary may be reused multiple times in the segmentation.
* You may assume the dictionary does not contain duplicate words.

## EXAMPLE 1

```plain
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

## EXAMPLE 2

```plain
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```

## EXAMPLE 3

```plain
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

## SOLUTION

* 逐子串搜索，用 hash 表维护字典

## CODE

### C++

```cpp
class Solution {
    unordered_set<string> fail_, dict_;
    bool dfs(string s)
    {
        if (s.length() == 0) return true;
        for (int i = 1, sz = s.size(); i <= sz; i++)
        {
            string hoge = s.substr(0, i);
            if (dict_.find(hoge) != dict_.end())
            {
                string piyo = s.substr(i);
                if (fail_.find(piyo) == fail_.end())
                {
                    if (dfs(piyo)) return true;
                    else fail_.insert(piyo);
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        dict_ = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};
```

### Python3

### Ruby
