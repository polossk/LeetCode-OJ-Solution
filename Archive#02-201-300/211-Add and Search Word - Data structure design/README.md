# Add and Search Word - Data structure design

![Medium](../../materials/-Medium-f0ad4e.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg) ![Design](../../materials/设计-Design-007ec6.svg) ![Tire](../../materials/Tire树-Tire-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode211-cpp-f34b7d.svg)   | 120 ms  | 42 Mb        |
| ![python](https://img.shields.io/badge/leetcode211-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode211-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Design a data structure that supports the following two operations:

```plain
void addWord(word)
bool search(word)
```

search(word) can search a literal word or a regular expression string containing only letters `a-z` or `.`. A `.` means it can represent any one letter.

## EXAMPLE

```plain
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```

## NOTE

You may assume that all words are consist of lowercase letters `a-z`.

## SOLUTION

* 预处理平方不超过 10 的数字，可以发现除了 `1 * 1 == 1` 之外，0，2 和 3 都不满足条件，所以可以设置 `0b0010` 来表示结果
* 为了存储方便，我们设置一个 16 位的无符号整数来储存 0-15 的结果，然后对每一个数字将其处理至小于 16 即可

## CODE

### C++

```cpp
class TrieNode
{
public:
    bool flag;
    TrieNode* next[26];
    TrieNode(): flag(false)
    {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary
{
    TrieNode* root;
    bool query(const char *word, TrieNode *node)
    {
        TrieNode *current = node;
        for (int i = 0; word[i]; i++)
        {
            if (current && word[i] != '.')
                current = current->next[word[i] - 'a'];
            else if (current && word[i] == '.')
            {
                TrieNode *tmp = current;
                for (int j = 0; j < 26; j++)
                {
                    current = tmp->next[j];
                    if (query(word + i + 1, current))
                        return true;
                }
            }
            else break;
        }
        return current && current->flag;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *current = root;
        for (auto ch : word)
        {
            if (!(current->next[ch - 'a']))
                current->next[ch - 'a'] = new TrieNode();
            current = current->next[ch - 'a'];
        }
        current->flag = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) { return query(word.c_str(), root); }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

### Python3

```python
```

### Ruby

```ruby
```
