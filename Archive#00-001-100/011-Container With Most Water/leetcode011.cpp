// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 011                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // if (height.empty()) return 0;
        int i = 0, j = height.size() - 1, ret = 0;
        while (i < j)
        {
            int tmp = std::min(height[i], height[j]) * (j - i);
            ret = std::max(ret, tmp);
            if (height[i] < height[j]) i++;
            else j--;
        }
        return ret;
    }
};

void test() { }

int main() { test(); return 0; }
