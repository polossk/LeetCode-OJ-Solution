// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 126                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test()
{
    Solution _;
    vector<string> a = {"hot", "dot", "dog", "lot", "log"};
    _.findLadders("hit", "cog", a);
}

int main() { test(); return 0; }

