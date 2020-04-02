# Leftmost Column with at Least a One

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcodeXXXX-cpp-f34b7d.svg)   | 0 ms    | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcodeXXXX-py-3572A5.svg) | 80 ms   | 14.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcodeXXXX-rb-701516.svg)   | 52 ms   | 9.5 Mb       |

## DESCRIPTION

*(This problem is an **interactive** problem.)*

A binary matrix means that all elements are `0` or `1`. For each **individual** row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a `1` in it. If such index doesn't exist, return `-1`.

**You can't access the Binary Matrix directly**. You may only access the matrix using a `BinaryMatrix` interface:

* `BinaryMatrix.get(x, y)` returns the element of the matrix at index `(x, y)` (0-indexed).
* `BinaryMatrix.dimensions()` returns a list of 2 elements `[n, m]`, which means the matrix is `n * m`.

Submissions making more than `1000` calls to `BinaryMatrix.get` will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix `mat` as input in the following four examples. You will not have access the binary matrix directly.

## EXAMPLE 1

```plain
Input: mat = [[0,0],[1,1]]
Output: 0
```

## EXAMPLE 2

```plain
Input: mat = [[0,0],[0,1]]
Output: 1
```

## EXAMPLE 3

```plain
Input: mat = [[0,0],[0,0]]
Output: -1
```

## EXAMPLE 4

```plain
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
```

## CONSTRAINTS

* `1 <= mat.length, mat[i].length <= 100`
* `mat[i][j]` is either `0` or `1`.
* `mat[i]` is sorted in a non-decreasing way.

## SOLUTION

* 从右上角开始走，遇到 `1` 说明可能左边还有 `1`，遇到 `0` 说明这一行的 `1` 已经走完了，可以去判断下一行的 `01` 分布。
* 路途上记录走的步数，最后判断走出地图之后的上一个遇到 `1` 的位置

## CODE

### C++

```cpp
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> size = binaryMatrix.dimensions();
        int n = size[0], m = size[1];
        int x = 0, y = m - 1;
        int y_move = 0, x_move = 0;
        while (x < n && y >= 0)
        {
            if (binaryMatrix.get(x, y))
                { y--; x_move = 0; y_move++; }
            else
                { x++; y_move = 0; x_move++; }
        }
        if (y_move) return 0;
        else if (x - x_move < n && y + 1 < m)
            return binaryMatrix.get(x - x_move, y + 1) ? y + 1 : -1;
        else return -1;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```