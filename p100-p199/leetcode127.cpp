// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 127                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	typedef unordered_set<string> Dict;

	int build(Dict &_front, Dict &_back, Dict &dict, int depth)
	{
		if (_front.empty()) return 0;
		if (_front.size() > _back.size())
			return build(_back, _front, dict, depth);
		Dict hoge;
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
						return depth + 1;
					}
					else if (!piyo && dict.count(word))
					{
						hoge.insert(word);
						dict.erase(word);
					}
				}
				c = fuga;
			}
		}
		return build(hoge, _back, dict, depth + 1);
	}

public:
	int ladderLength(string beginWord, string endWord, Dict &wordList)
	{
		if (beginWord == endWord) return 1;
		Dict _front, _back;
		_front.insert(beginWord);
		_back.insert(endWord);
		wordList.erase(beginWord);
		wordList.erase(endWord);
		return build(_front, _back, wordList, 1);
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
