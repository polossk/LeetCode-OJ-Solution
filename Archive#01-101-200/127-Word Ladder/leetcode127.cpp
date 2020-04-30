// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 127                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test()
{
    Solution _;
    vector<string> a = {"hot", "dot", "dog", "lot", "log"};
    _.findLadders("hit", "cog", a);
}

int main() { test(); return 0; }
