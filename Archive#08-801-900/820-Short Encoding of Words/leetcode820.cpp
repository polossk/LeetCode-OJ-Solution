// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 820                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        int sz = words.size();
        sort(words.begin(), words.end(), [](const string &_1, const string &_2) -> bool
        {
            int sz1 = _1.size(), sz2 = _2.size();
            for (int i = 0, sz = min(sz1, sz2); i < sz; i++)
            {
                char c1 = _1[sz1 - 1 - i], c2 = _2[sz2 - 1 - i];
                if (c1 == c2) continue;
                return c1 < c2;
            }
            return sz1 < sz2;
        });
        int ret = 0;
        auto tail_check = [](const string &body, const string &tail) -> bool
        {
            int sz_bd = body.size(), sz_tl = tail.size();
            if (sz_bd < sz_tl) return false;
            for (int i = 0; i < sz_tl; i++)
            {
                if (body[sz_bd - sz_tl + i] == tail[i]) continue;
                return false;
            }
            return true;
        };
        for (int i = 0; i < sz; i++)
        {
            if (i + 1 < sz && tail_check(words[i + 1], words[i])) continue;
            ret += words[i].size() + 1; // plus #
        }
        return ret;
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
