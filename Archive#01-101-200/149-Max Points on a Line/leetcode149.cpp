// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 149                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using uint64 = unsigned long long;
    template<class T>
    inline bool updateMax(T& a, T b) const { return a < b ? a = b, 1: 0; }
    inline uint64 encode(int a, int b) const { return (uint64(a) << 32) ^ b; }
    inline int gcd(int a, int b) const { return b == 0 ? a : gcd(b, a % b); }
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ret = 0;
        for (auto p1 : points)
        {
            unordered_map<uint64, int> mp;
            int same = 0, vertical = 0;
            for (auto p2 : points)
            {
                if (p1[0] == p2[0]) (p1[1] == p2[1]) ? same++ : vertical++;
                else if (p2[1] == p1[1]) mp[encode(0, 1)]++;
                else
                {
                    int y = p2[1] - p1[1], x = p2[0] - p1[0];
                    if (x < 0) { y *= -1; x *= -1; }
                    int g = gcd(x, y);
                    mp[encode(y / g, x / g)]++;
                }
            }
            for (auto elem : mp) updateMax(ret, elem.second + same);
            updateMax(ret, same + vertical);
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
