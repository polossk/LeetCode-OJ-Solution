// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 365                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    using State = pair<int, int>;
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z) return false;
        auto hash_State = [](const State &_) {
            return std::hash<int>()(_.first) ^ std::hash<int>()(_.second);
        };
        std::stack<State> s;
        s.emplace(0, 0);
        std::unordered_set<State, decltype(hash_State)> vis(0, hash_State);
        while (!s.empty())
        {
            auto now = s.top(); s.pop();
            if (vis.count(now)) continue;
            auto [nx, ny] = now;
            vis.emplace(nx, ny);
            if (nx == z || ny == z || nx + ny == z) return true;
            s.emplace(x, ny);
            s.emplace(nx, y);
            s.emplace(0, ny);
            s.emplace(nx, 0);
            s.emplace(nx - min(nx, y - ny), ny + min(nx, y - ny));
            s.emplace(nx + min(ny, x - nx), ny - min(ny, x - nx));
        }
        return false;
    }
};

class Solution_optim
{
    const static int MAXL = 150000 + 5; // testcase: 104579, 104593, 12444
    int x_, y_, z_;
    bool vis[MAXL];
public:
    bool dfs(int now)
    {
        if (now < 0) return false;
        if (now == z_ || now + x_ == z_ || now + y_ == z_
            || x_ - (y_ - now) == z_ || y_ - (x_ - now) == z_) return true;
        if (vis[now] == 1) return false;
        vis[now] = 1;
        return dfs(x_ - now) || dfs(y_ - now) || dfs(now - x_) || dfs(now - y_);
    }
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z) return false;
        std::tie(x_, y_, z_) = std::make_tuple(x, y, z);
        memset(vis, sizeof(vis), 0);
        return dfs(0);
    }
};

class Solution_gcd
{
    inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};


void test() {}

int main() { test(); return 0; }
