// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 208                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

class Trie
{
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode *current = root;
        for (auto ch : word)
        {
            if (!(current -> next[ch - 'a']))
                current -> next[ch - 'a'] = new TrieNode();
            current = current -> next[ch - 'a'];
        }
        current -> flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode *current = root;
        for (int i = 0, sz = word.size(); i < sz; i++)
        {
            if (!current) return false;
            current = current -> next[word[i] - 'a'];
        }
        return current && current -> flag;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *current = root;
        for (int i = 0, sz = prefix.size(); i < sz; i++)
        {
            if (!(current -> next[prefix[i] - 'a'])) return false;
            else current = current -> next[prefix[i] - 'a'];
        }
        return true;
    }
};

void test()
{
    Trie _;
    int d; string s;
    while (cin >> d >> s)
    {
        if (d == 0) _.insert(s);
        if (d == 1) cout << _.search(s) << endl;
        if (d == 2) cout << _.startsWith(s) << endl;
    }
}

int main(){ test(); return 0; }
