// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 011                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;


class Solution {
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
public:
    int maxArea(vector<int>& height)
    {
        if (height.empty() || height.size() == 0) return 0;
        int ret = 0, left = 0, right = height.size() - 1;
        while (left < right)
        {
            updateMax(ret, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                int hoge = height[left];
                for (left++; height[left] <= hoge; left++);
            }
            else
            {
                int hoge = height[right];
                for (right--; height[right] <= hoge; right--);
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
