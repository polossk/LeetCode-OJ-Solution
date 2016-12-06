// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 211                                                 *
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

class WordDictionary
{
	TrieNode* root;
	bool query(const char *word, TrieNode *node)
	{
		TrieNode *current = node;
		for (int i = 0; word[i]; i++)
		{
			if (current && word[i] != '.')
				current = current -> next[word[i] - 'a'];
			else if (current && word[i] == '.')
			{
				TrieNode *tmp = current;
				for (int j = 0; j < 26; j++)
				{
					current = tmp -> next[j];
					if (query(word + i + 1, current))
						return true;
				}
			}
			else break;
		}
		return current && current -> flag;
	}
public:
	WordDictionary() { root = new TrieNode(); }

	// Adds a word into the data structure.
	void addWord(string word)
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

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) { return query(word.c_str(), root); }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

void test()
{

}

int main()
{

	return 0;
}
