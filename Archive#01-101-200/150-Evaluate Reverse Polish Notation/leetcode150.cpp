// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 150                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution {
    map<string, std::function<int(int, int)>> op
    {
        {"+", [](int a, int b)->int { return a + b; }},
        {"-", [](int a, int b)->int { return a - b; }},
        {"*", [](int a, int b)->int { return a * b; }},
        {"/", [](int a, int b)->int { return a / b; }},
    };

public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> host;
        for (auto &str : tokens)
        {
            if (op.count(str))
            {
                int rhs = host.top(); host.pop();
                int lhs = host.top(); host.pop();
                host.push(op[str](lhs, rhs));
            }
            else host.push(atoi(str.c_str()));
        }
        return host.top();
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
