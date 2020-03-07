// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 068                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ret, line;
        int num = 0;
        for (int i = 0, sz = words.size(); i < sz; i++)
        {
            string word = words[i];
            if (num + word.size() + line.size() > maxWidth)
            {
                int length = line.size() - 1 + int(line.size() == 1);
                for (int j = 0; j < maxWidth - num; j++)
                {
                    line[j % length] += ' ';
                }
                ret.push_back(std::accumulate(line.begin(), line.end(), string("")));
                line.clear(); num = 0;
            }
            line.push_back(word);
            num += word.size();
        }
        string _ = std::accumulate(std::next(line.begin()), line.end(), *line.begin(),
            [](string a, string b) -> string { return a + " " + b; });
        for (int i = 0, sz = _.size(); i + sz <maxWidth; i++, _ += ' ');
        ret.push_back(_);
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
