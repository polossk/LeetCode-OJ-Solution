# Water and Jug Problem

![Medium](../../materials/-Medium-f0ad4e.svg) ![Math](../../materials/数学-Math-007ec6.svg)

## RESULT

| Submission                                                                  | Runtime | Memory Usage |
| --------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode365--naive--dfs-cpp-f34b7d.svg) | 1656 ms | 243.1 Mb     |
| ![cpp](https://img.shields.io/badge/leetcode365--optim--dfs-cpp-f34b7d.svg) | 4 ms    | 15.9 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode365--gcd-cpp-f34b7d.svg)        | 0 ms    | 5.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode365-py-3572A5.svg)           | 4756 ms | 165.2 Mb     |
| ![ruby](https://img.shields.io/badge/leetcode365-rb-701516.svg)             | -       | -            |

## DESCRIPTION

You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within **one or both buckets** by the end.

Operations allowed:

* Fill any of the jugs completely with water.
* Empty any of the jugs.
* Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

## EXAMPLE 1

```plain
Input: x = 3, y = 5, z = 4
Output: True
```

## EXAMPLE 2

```plain
Input: x = 2, y = 6, z = 5
Output: False
```

## SOLUTION

* 深度优先搜索
* 该问题相当于求解不定方程 `a * x + b * y = z`，所以直接计算 `g = gcd(x, y)` 然后判断 z 是否为 g 的倍数即可

## CODE

### C++

```cpp
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
```

### Python3

```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        stack = [(0, 0)]
        self.seen = set()
        while stack:
            nx, ny = stack.pop()
            if nx == z or ny == z or nx + ny == z:
                return True
            if (nx, ny) in self.seen:
                continue
            self.seen.add((nx, ny))
            stack.append((x, ny))
            stack.append((nx, y))
            stack.append((0, ny))
            stack.append((nx, 0))
            stack.append((nx - min(nx, y - ny), ny + min(nx, y - ny)))
            stack.append((nx + min(ny, x - nx), ny - min(ny, x - nx)))
        return False
```

### Ruby

### Java
