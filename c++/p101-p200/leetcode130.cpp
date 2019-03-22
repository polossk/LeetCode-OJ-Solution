// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 166                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class JointUnionSet
{
    vector<int> fa, rank;
    int _size, _capaciity;
public:
    JointUnionSet(int _) : _size(_), _capaciity(_)
    {
        fa.resize(_); rank.resize(_);
        while (_-- > 0) fa[_] = _;
    }
    
    int find(int x)
    {
        while (x != fa[x])
        {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    }
    
    int size() { return _size; }

    bool same(int x, int y) { return find(x) == find(y); }

    void link(int x, int y)
    {
        int a = find(x), b = find(y);
        if (a == b) return;
        if (rank[a] < rank[b]) fa[a] = b;
        else if (rank[a] > rank[a]) fa[b] = a;
        else
        {
            fa[b] = a; rank[a]++;
        }
        _size--;
    }
};

class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        int dummy = n * m;
        JointUnionSet _ = JointUnionSet(dummy + 1);

        auto __ = [&](int i, int j) -> bool { return board[i][j] == 'O'; };
        
        auto _0 = [](int i, int n) -> bool { return i == 0 || i == n - 1; };

        auto ___ = [=](int i, int j) -> bool { return _0(i, n) || _0(j, m); };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!__(i, j)) continue;
                if (___(i, j)) { _.link(i * m + j, dummy); continue; }
                if (__(i - 1, j)) _.link(i * m + j, (i - 1) * m + j);
                if (__(i + 1, j)) _.link(i * m + j, (i + 1) * m + j);
                if (__(i, j - 1)) _.link(i * m + j, i * m + j - 1);
                if (__(i, j + 1)) _.link(i * m + j, i * m + j + 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!_.same(i * m + j, dummy)) board[i][j] = 'X';
            }
        }
    }
};

void test() {}

int main() { test(); return 0; }
