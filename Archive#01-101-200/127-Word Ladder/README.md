# Word Ladder

![Medium](../../materials/-Medium-f0ad4e.svg) ![Breadth--first_Search](../../materials/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode127-cpp-f34b7d.svg)   | 36 ms   | 14.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode127-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode127-rb-701516.svg)   | -       | -            |

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

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

## EXAMPLE 2

```plain
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

## NOTE

* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.

## SOLUTION

* 通过字典维护可选单词，然后双向 bfs 搜索

## CODE

### C++

```cpp
class Solution
{
    using Dict = unordered_set<string>;
    int level_frist_search(Dict &front, Dict &back, Dict &dict, int depth)
    {
        if (front.empty()) return 0;
        if (front.size() > back.size())
            return level_frist_search(back, front, dict, depth);
        Dict used;
        for (auto &i : front)
        {
            string word = i;
            for (auto &c : word)
            {
                char temp = c;
                for (c = 'a'; c <= 'z'; c++)
                {
                    if (c == temp) continue;
                    if (back.count(word)) return depth + 1;
                    else if (dict.count(word))
                    {
                        used.insert(word);
                        dict.erase(word);
                    }
                }
                c = temp;
            }
        }
        return level_frist_search(used, back, dict, depth + 1);
    }
public:
    int ladderLength(string beginWord, string endWord,  vector<string> &wordList)
    {
        if (beginWord == endWord) return 1;
        Dict front, back, dict;
        for (auto str : wordList) dict.insert(str);
        if (dict.find(endWord) == dict.end()) return 0;
        front.insert(beginWord);
        back.insert(endWord);
        dict.erase(beginWord);
        dict.erase(endWord);
        return level_frist_search(front, back, dict, 1);
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```