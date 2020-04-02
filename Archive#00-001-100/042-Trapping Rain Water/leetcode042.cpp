// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 042                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int ans = 0, cur = 0;
        stack<int> s;
        while (cur < height.size())
        {
            while (!s.empty() && height[cur] > height[s.top()])
            {
                int top = s.top(); s.pop();
                if (s.empty()) break;
                int well_width = cur - s.top() - 1;
                int well_depth = min(height[cur], height[s.top()]) - height[top];
                ans += well_width * well_depth;
            }
            s.push(cur++);
        }
        return ans;
    }
};

void test() {}

int main() { test(); return 0; }
