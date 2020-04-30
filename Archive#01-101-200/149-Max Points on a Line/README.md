# Max Points on a Line

![Hard](../../materials/-Hard-e05d44.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg) ![Math](../../materials/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode149-cpp-f34b7d.svg)   | 48 ms   | 13.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode149-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode149-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given *n* points on a 2D plane, find the maximum number of points that lie on the same straight line.

## EXAMPLE 1

```plain
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
```

## EXAMPLE 2

```plain
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

## SOLUTION

* 逐点统计斜率（有理数）

## CODE

### C++

```cpp
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
```

### Python3

### Ruby
