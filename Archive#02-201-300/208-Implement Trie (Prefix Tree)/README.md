# Implement Trie (Prefix Tree)

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Design](https://img.shields.io/badge/设计-Design-007ec6.svg) ![Tire](https://img.shields.io/badge/Tire树-Tire-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode208-cpp-f34b7d.svg)   | 84 ms   | 42.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode208-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode208-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement a trie with `insert`, `search`, and `startsWith` methods.

## EXAMPLE

```plain
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```

## NOTE

* You may assume that all inputs are consist of lowercase letters `a-z`.
* All inputs are guaranteed to be non-empty strings.

## SOLUTION

* 每一个节点拥有 26 个 `next` 指针，和一个 `flag` 数据域表示是否有值

## CODE

### C++

```cpp
class Trie
{
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
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word)
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

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *current = root;
        for (int i = 0, sz = word.size(); i < sz; i++)
        {
            if (!current) return false;
            current = current->next[word[i] - 'a'];
        }
        return current && current->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *current = root;
        for (int i = 0, sz = prefix.size(); i < sz; i++)
        {
            if (!(current->next[prefix[i] - 'a'])) return false;
            else current = current->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

### Python3

```python
```

### Ruby

```ruby
```
