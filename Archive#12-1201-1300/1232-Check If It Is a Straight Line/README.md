# Check If It Is a Straight Line

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Math](../../materials/数学-Math-007ec6.svg) ![Geometry](../../materials/几何-Geometry-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1232-cpp-f34b7d.svg)   | 16 ms   | 10 Mb        |
| ![python](https://img.shields.io/badge/leetcode1232-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1232-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are given an array `coordinates`, `coordinates[i] = [x, y],` where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.

## EXAMPLE 1

```plain
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

## EXAMPLE 2

```plain
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

## CONSTRAINTS

* `2 <= coordinates.length <= 1000`
* `coordinates[i].length == 2`
* `-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4`
* `coordinates` contains no duplicate point.

## SOLUTION

* 扫一遍，判断以第一个点为起点的向量的外积为 0 即可

## CODE

### C++

```cpp
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x1 = coordinates[1][0] - coordinates[0][0];
        int y1 = coordinates[1][1] - coordinates[0][1];
        for (int i = 2, sz = coordinates.size(); i < sz; i++)
        {
            int x2 = coordinates[i][0] - coordinates[0][0];
            int y2 = coordinates[i][1] - coordinates[0][1];
            if (x1 * y2 != x2 * y1) return false;
        }
        return true;
    }
};
```

### Python3


### Ruby

