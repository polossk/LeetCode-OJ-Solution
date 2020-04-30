# Surrounded Regions

![Medium](../../materials/-Medium-f0ad4e.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg) ![Breadth--first_Search](../../materials/广度优先搜索-Breadth--first_Search-007ec6.svg) ![Union_Find](../../materials/并查集-Union_Find-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode130-cpp-f34b7d.svg)   | 36 ms   | 10.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode130-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode130-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a 2D board containing `'X'` and `'O'` (**the letter O**), capture all regions surrounded by `'X'`.

A region is captured by flipping all `'O'`s into `'X'`s in that surrounded region.

## EXAMPLE

```plain
X X X X
X O O X
X X O X
X O X X
```

After running your function, the board should be:

```plain
X X X X
X X X X
X X X X
X O X X
```

## EXPLANATION

Surrounded regions shouldn’t be on the border, which means that any `'O'` on the border of the board are not flipped to `'X'`. Any `'O'` that is not on the border and it is not connected to an `'O'` on the border will be flipped to `'X'`. Two cells are connected if they are adjacent cells connected horizontally or vertically.


## NOTE

* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.

## SOLUTION

* 通过字典维护可选单词，然后双向 bfs 搜索

## CODE

### C++

```cpp
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
```

### Python3

```python
```

### Ruby

```ruby
```