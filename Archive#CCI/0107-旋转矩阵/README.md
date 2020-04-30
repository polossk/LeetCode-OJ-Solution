# 旋转矩阵

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                    | Runtime | Memory Usage |
| ------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cci0107-cpp-f34b7d.svg)   | 0 ms    | 7 Mb         |
| ![python](https://img.shields.io/badge/cci0107-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cci0107-rb-701516.svg)   | -       | -            |

## DESCRIPTION

给你一幅由 `N × N` 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

## EXAMPLE 1

```plain
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

## EXAMPLE 2

```plain
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

## SOLUTION

* 顺时针旋转 90 度等同于两个操作：上下翻转，然后延主对角线两侧对称翻转

## CODE

### C++

```cpp
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - i - 1][j]);
        // 主对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
```

### Python3


### Ruby

