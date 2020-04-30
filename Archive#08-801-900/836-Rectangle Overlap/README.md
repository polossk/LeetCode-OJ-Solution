# Rectangle Overlap

![Easy](../../materials/-Easy-5cb85c.svg) ![Math](../../materials/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode836-cpp-f34b7d.svg)   | 0 ms    | 7.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode836-py-3572A5.svg) | 24 ms   | 12.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode836-rb-701516.svg)   | 24 ms   | 9.6 Mb       |

## DESCRIPTION

A rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` are the coordinates of its bottom-left corner, and `(x2, y2)` are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

## EXAMPLE 1

```plain
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
```

## EXAMPLE 2

```plain
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
```

## NOTE

1. Both rectangles `rec1` and `rec2` are lists of 4 integers.
2. All coordinates in rectangles will be between `-10^9` and `10^9`.

## SOLUTION

* 矩形重叠等价于 x 轴与 y 轴上有重叠部分
* 对任意轴上的左右两条线段 `(a1, b1)`，`(a2, b2)`，他们之间的几何关系有三种：包含、相交、相离。其相离的判断条件为相对左边的线段 `(a1, b1)` 的右顶点 `b1` 在相对右边线段 `(a2, b2)` 的左顶点 `a2` 的左边，即 `b1 <= a2`
* 判断四次相对位置即可

## CODE

### C++

```cpp
class Solution
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
};
```

### Python3

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return not (rec1[2] <= rec2[0] or   # left
                    rec1[3] <= rec2[1] or   # bottom
                    rec1[0] >= rec2[2] or   # right
                    rec1[1] >= rec2[3])     # top
```

### Ruby

```ruby
# @param {Integer[]} rec1
# @param {Integer[]} rec2
# @return {Boolean}
def is_rectangle_overlap(rec1, rec2)
  !(rec1[2] <= rec2[0] ||   # left
    rec1[3] <= rec2[1] ||   # bottom
    rec1[0] >= rec2[2] ||   # right
    rec1[1] >= rec2[3])     # top
end
```