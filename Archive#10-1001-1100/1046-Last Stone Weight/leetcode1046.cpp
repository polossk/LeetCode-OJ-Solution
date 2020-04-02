// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1046                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int v : stones) pq.push(v);
        while (pq.size() >= 2)
        {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            int v = abs(top1 - top2);
            if (v) pq.push(v);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};

void test() {}

int main() { test(); return 0; }
