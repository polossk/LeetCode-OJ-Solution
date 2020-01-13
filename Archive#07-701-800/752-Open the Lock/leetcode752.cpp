// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 752                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
private:
    const string start = "0000";
    unordered_set<string> deadset, vis{start};
    int bfs(const string &target)
    {
        int ret = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty())
        {
            ret++;
            for (int i = 0, sz = q.size(); i < sz; i++)
            {
                string now = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int leap = j * 2 - 1;
                        string r = now;
                        r[i] = (r[i] - '0' + leap + 10) % 10 + '0';
                        if (r == target) return ret;
                        if (deadset.count(r) || vis.count(r)) continue;
                        q.push(r); vis.insert(r);
                    }
                }
            }
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target)
    {
        deadset = unordered_set<string>(deadends.begin(), deadends.end());
        if (deadset.count(start)) return -1;
        return bfs(target);
    }
};

void test() {}

int main() { test(); return 0; }
