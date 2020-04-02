// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 466                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        if (n1 == 0) return 0;
        int i = 0, order_1 = 0, order_2 = 0;
        int len_1 = s1.size(), len_2 = s2.size();
        unordered_map<int, pair<int, int>> memo;
        pair<int, int> head, loop;
        while (true)
        {
            order_1++;
            for (char ch : s1)
                if (ch == s2[i])
            {
                i++;
                if (i == len_2) { ++order_2; i = 0; }
            }
            // no more s1
            if (order_1 == n1) return order_2 / n2;
            // find s2[i] once again
            if (memo.count(i))
            {
                auto [order_1_fst, order_2_fst] = memo[i];
                head = {order_1_fst, order_2_fst};
                loop = {order_1 - order_1_fst, order_2 - order_2_fst};
                break;
            }
            else memo[i] = {order_1, order_2};
        }
        int ret = head.second + (n1 - head.first) / loop.first * loop.second;
        int rest = (n1 - head.first) % loop.first;
        for (int _ = 0; _ < rest; _++)
            for (char ch: s1)
                if (ch == s2[i])
        {
            i++;
            if (i == s2.size()) { ret++; i = 0; }
        }
        return ret / n2;
    }
};

void test() {}

int main() { test(); return 0; }
