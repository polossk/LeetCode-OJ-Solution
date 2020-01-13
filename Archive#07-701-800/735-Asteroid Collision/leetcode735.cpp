// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 735                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> ret;
        for (int i = 0, sz = asteroids.size(); i < sz; i++)
        {
            if (ret.empty() || asteroids[i] > 0 || (ret.back() < 0 && asteroids[i] < 0))
            {
                ret.push_back(asteroids[i]);
                continue;
            }
            // only (ret.back() > 0 && asteroids[i] < 0)
            if (ret.back() + asteroids[i] == 0)
            {
                ret.pop_back();
            }
            else if (ret.back() + asteroids[i] < 0)
            {
                ret.pop_back(); i--;
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
