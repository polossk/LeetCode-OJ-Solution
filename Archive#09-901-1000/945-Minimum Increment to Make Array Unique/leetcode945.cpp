// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 945                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    const int MAXV = 2 * 40000 + 10;
public:
    int minIncrementForUnique(vector<int>& A)
    {
        vector<int> hoge(MAXV, 0);
        for (int i = 0, sz = A.size(); i < sz; i++)
            hoge[A[i]]++;
        int ret = 0;
        for (int i = 0; i < MAXV; i++)
        {
            if (hoge[i] <= 1) continue;
            ret += hoge[i] - 1;
            hoge[i + 1] += hoge[i] - 1;
            hoge[i] = 1;
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
