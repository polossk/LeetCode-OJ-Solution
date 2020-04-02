// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 218                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    using VI = std::vector<int>;
    using Rectangle = std::vector<std::vector<int>>;
    using Polygon = std::vector<VI>;
    Polygon getSkyline(Rectangle& buildings)
    {
        Polygon h, ret;
        std::multiset<int> m; m.insert(0);
        for (auto& a : buildings)
        {
            h.emplace_back(VI({a[0], -a[2]}));
            h.emplace_back(VI({a[1], a[2]}));
        }
        sort(h.begin(), h.end(), [](const VI& a, const VI& b) -> bool
        {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        int prevHeight = 0, height = 0;
        for (auto& a : h)
        {
            if (a[1] < 0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            height = *(m.rbegin());
            if (prevHeight != height)
            {
                ret.emplace_back(VI({a[0], height}));
                prevHeight = height;
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
