// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 165                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    vector<string> split(const string &str, char sep)
    {
        vector<string> ret;
        if (str.empty()) return ret;
        stringstream iss(str);
        for (string _; getline(iss, _, sep); ret.push_back(_));
        return ret;
    }
public:
    int compareVersion(string version1, string version2)
    {
        vector<string> _1 = split(version1, '.');
        vector<string> _2 = split(version2, '.');
        auto modifier = [&](const vector<string>& in, vector<int>& out) -> void
        {
            transform(in.begin(), in.end(), out.begin(),
                [](string s) -> int { return atoi(s.c_str()); });
        };
        vector<int> v1(_1.size()), v2(_2.size());
        modifier(_1, v1); modifier(_2, v2);
        int sz1 = _1.size(), sz2 = _2.size();
        int sz = std::max(sz1, sz2);
        for (int i = 0; i < sz; i++)
        {
            int a = i < sz1 ? v1[i] : 0;
            int b = i < sz2 ? v2[i] : 0;
            if (a != b) return a > b ? 1 : -1;
        }
        return 0;
    }
};

void test() {}

int main() { test(); return 0; }
