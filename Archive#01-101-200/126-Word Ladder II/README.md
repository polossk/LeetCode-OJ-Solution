# Word Ladder II

![Hard](../../materials/-Hard-e05d44.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg) ![Breadth--first_Search](../../materials/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode543-cpp-f34b7d.svg)   | 44 ms   | 17.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode543-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode543-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two words (*beginWord* and *endWord*), and a dictionary's word list, find the length of shortest transformation sequence from *beginWord* to *endWord*, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list.

## EXAMPLE 1

```plain
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
```

## EXAMPLE 2

```plain
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

## NOTE

* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.

## SOLUTION

* 通过字典维护可选单词和途径路径，然后双向 bfs 搜索

## CODE

### C++

```cpp
class Solution
{
    using Path = vector<string>;
    using Paths = vector<Path>;
    using Dict = unordered_set<string>;
    using Tree = unordered_map<string, Path>;

    bool level_frist_search(Dict &front, Dict &back, Dict &dict, Tree &tree, bool flag)
    {
        if (front.empty()) return false;
        if (front.size() > back.size())
            return level_frist_search(back, front, dict, tree, !flag);
        for (auto &word : front) dict.erase(word);
        for (auto &word : back) dict.erase(word);
        Dict used;
        bool new_flag = false;
        for (auto &i : front)
        {
            string word = i;
            for (auto &c : word)
            {
                char temp = c;
                for (c = 'a'; c <= 'z'; c++)
                {
                    if (c == temp) continue;
                    if (back.count(word))
                    {
                        new_flag = true;
                        !flag ? tree[i].push_back(word): tree[word].push_back(i);
                    }
                    else if (!new_flag && dict.count(word))
                    {
                        used.insert(word);
                        !flag ? tree[i].push_back(word): tree[word].push_back(i);
                    }
                }
                c = temp;
            }
        }
        return new_flag || level_frist_search(used, back, dict, tree, flag);
    }

    void getPath(string &a, string &b, Tree &tree, Path &path, Paths &ret)
    {
        if (a == b) { ret.push_back(path); return; }
        for (auto &i : tree[a])
        {
            path.push_back(i);
            getPath(i, b, tree, path, ret);
            path.pop_back();
        }
    }
public:
    Paths findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        Paths ret;
        Path path(1, beginWord);
        if (beginWord == endWord) { ret.push_back(path); return ret; }
        Dict front, back, dict;
        for (auto str : wordList) dict.insert(str);
        if (dict.find(endWord) == dict.end()) { ret.clear(); return ret; }
        front.insert(beginWord);
        back.insert(endWord);
        Tree tree;
        if (level_frist_search(front, back, dict, tree, false))
            getPath(beginWord, endWord, tree, path, ret);
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [ch for ch in s.lower() if ch.isalnum()]
        return t == t[::-1]
```

### Ruby

```ruby
# @param {String} s
# @return {Boolean}
def is_palindrome(s)
  tmp = s.scan(/[A-Za-z0-9]/).join.downcase
  tmp == tmp.reverse
end
```