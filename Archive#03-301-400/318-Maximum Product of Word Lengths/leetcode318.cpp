// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 318                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
    int encode(string str)
    {
        int ret = 0;
        for (auto ch : str)
        {
            ret |= 1 << (ch - 'a');
        }
        return ret;
    }

public:
    int maxProduct(vector<string>& words)
    {
        vector<int> encoded, len;
        for (auto str : words)
        {
            encoded.push_back(encode(str));
            len.push_back(str.size());
        }
        int ret = 0, sz = encoded.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (encoded[i] & encoded[j]) continue;
                int tmp = len[i] * len[j];
                ret = ret > tmp ? ret : tmp;
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
