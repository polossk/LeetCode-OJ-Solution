# Search a 2D Matrix

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode074-cpp-f34b7d.svg)   | 16 ms   | 7.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode074-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode074-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

## EXAMPLE 1

```plain
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
```

## EXAMPLE 2

```plain
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```

## SOLUTION

* 二分搜索

## CODE

### C++

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int l = 0, r = m * n - 1;
        while (l != r)
        {
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else r = mid;
        }
        return target == matrix[r / m][r % m];
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java

```java
```
