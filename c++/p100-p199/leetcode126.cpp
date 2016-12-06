// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 126                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	typedef vector<string> Path;
	typedef vector<Path> Paths;
	typedef unordered_set<string> Dict;
	typedef unordered_map<string, Path> Tree;

	bool build(Dict &_front, Dict &_back, Dict &dict, Tree &tree, bool flag)
	{
		if (_front.empty()) return false;
		if (_front.size() > _back.size())
			return build(_back, _front, dict, tree, !flag);
		for (auto &word : _front) dict.erase(word);
		for (auto &word : _back) dict.erase(word);
		Dict hoge;
		bool piyo = false;
		for (auto &i : _front)
		{
			string word = i;
			for (auto &c : word)
			{
				char fuga = c;
				for (c = 'a'; c <= 'z'; c++)
				{
					if (c == fuga) continue;
					if (_back.count(word))
					{
						piyo = true;
						!flag ? tree[i].push_back(word): tree[word].push_back(i);
					}
					else if (!piyo && dict.count(word))
					{
						hoge.insert(word);
						!flag ? tree[i].push_back(word): tree[word].push_back(i);
					}
				}
				c = fuga;
			}
		}
		return piyo || build(hoge, _back, dict, tree, flag);
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
	Paths findLadders(string beginWord, string endWord, Dict &wordList)
	{
		Paths paths;
		Path path(1, beginWord);
		if (beginWord == endWord) { paths.push_back(path); return paths; }
		Dict _front, _back;
		_front.insert(beginWord);
		_back.insert(endWord);
		Tree tree;
		if (build(_front, _back, wordList, tree, false))
			getPath(beginWord, endWord, tree, path, paths);
		return paths;
	}
};

void test()
{
	Solution _;
	unordered_set<string> dic;
	vector<string> a = {"hot", "dot", "dog", "lot", "log"};
	for (auto e : a) dic.insert(e);
	_.findLadders("hit", "cog", a);
}

int main()
{
	test();
	return 0;
}
