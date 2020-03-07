// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1013                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int s = accumulate(A.begin(), A.end(), 0);
        if (s % 3 != 0) return false;
        int target = s / 3, current = 0;
        int i = 0, sz = A.size();
        while (i < sz)
        {
            current += A[i++];
            if (current == target) break;
        }
        if (current != target) return false;
        current = 0;
        while (i + 1 < sz)
        {
            current += A[i++];
            if (current == target) break;
        }
        return current == target;
    }
};

void test() {}

int main() { test(); return 0; }
