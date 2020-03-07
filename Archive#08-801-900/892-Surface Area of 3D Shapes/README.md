# Surface Area of 3D Shapes

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg) ![Geometry](https://img.shields.io/badge/几何-Geometry-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode892-cpp-f34b7d.svg)   | 8 ms    | 7.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode892-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode892-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode892-java-b07219.svg) | -       | -            |

## DESCRIPTION

On a `N * N` grid, we place some `1 * 1 * 1` cubes.

Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of grid cell `(i, j)`.

Return the total surface area of the resulting shapes.

## EXAMPLE 1

```plain
Input: [[2]]
Output: 10
```

## EXAMPLE 2

```plain
Input: [[1,2],[3,4]]
Output: 34
```

## EXAMPLE 3

```plain
Input: [[1,0],[0,2]]
Output: 16
```

## EXAMPLE 4

```plain
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
```

## EXAMPLE 5

```plain
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
```

## NOTE

* `1 <= N <= 50`
* `0 <= grid[i][j] <= 50`

## SOLUTION

* 对每一个格点，只计算增量，即上下两个面和前后左右四个方向的高度差

## CODE

### C++

```cpp
class Solution
{
    static const int MAXD = 4;
    const int dx[MAXD] = {1, 0, -1, 0};
    const int dy[MAXD] = {0, 1, 0, -1};
    inline bool valid(int x, int limit)
    {
        return 0 <= x && x < limit;
    }
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
        {
            int height = grid[i][j];
            if (height <= 0) continue;
            ret += 2; // up and down
            for (int k = 0; k < MAXD; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                int that_pillar = 0;
                if (valid(x, n) && valid(y, n)) that_pillar = grid[x][y];
                ret += max(0, height - that_pillar);
            }

        }
        return ret;
    }
};
```

### Python3


### Ruby


### Java

