# The Skyline Problem

![Hard](../../materials/-Hard-e05d44.svg) ![Divide_and_Conquer](../../materials/分治法-Divide_and_Conquer-007ec6.svg) ![Heap](../../materials/堆-Heap-007ec6.svg) ![Binary_Indexed_Tree](../../materials/树状数组-Binary_Indexed_Tree-007ec6.svg) ![Segment_Tree](../../materials/线段树-Segment_Tree-007ec6.svg) ![Line_Sweep](../../materials/扫描线-Line_Sweep-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode218-cpp-f34b7d.svg)   | 80 ms   | 14.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode218-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode218-rb-701516.svg)   | -       | -            |

## DESCRIPTION

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are `given the locations and height of all the buildings` as shown on a cityscape photo (Figure A), write a program to `output the skyline` formed by these buildings collectively (Figure B).

<center>
<img alt="Figure_A" src="skyline1.png" style="max-width: 45%; border-width: 0px; border-style: solid;">

<img alt="Figure_B" src="skyline2.png" style="max-width: 45%; border-width: 0px; border-style: solid;">
</center>

The geometric information of each building is represented by a triplet of integers `[Li, Ri, Hi]`, where `Li` and `Ri` are the x coordinates of the left and right edge of the ith building, respectively, and `Hi` is its height. It is guaranteed that `0 ≤ Li`, `Ri ≤ INT_MAX`, `0 < Hi ≤ INT_MAX`, and `Ri - Li > 0`. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: `[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]`.

The output is a list of "**key points**" (red dots in Figure B) in the format of `[ [x1,y1], [x2, y2], [x3, y3], ... ]` that uniquely defines a skyline. **A key point is the left endpoint of a horizontal line segment**. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:`[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]`.

## NOTE

* The number of buildings in any input list is guaranteed to be in the range `[0, 10000]`.
* The input list is already sorted in ascending order by the left x position `Li`.
* The output list must be sorted by the x position.
* There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...[2 3], [4 5], [7 5], [11 5], [12 7]...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...[2 3], [4 5], [12 7], ...]`

## SOLUTION

* 离散扫描线问题。预处理每一个建筑（长方形）的左上、右上两个顶点，将左端点的高度设置为负数加以标记。从左到右依次扫描所有的端点，同时维护当前天际线的高度，以及当前经过的高度。如果是左端点，则将高度记录，否则删除此高度。如果此时的高度与上一次的高度不同，说明出现了转折，记录答案即可。

## CODE

### C++

```cpp
class Solution
{
public:
    using VI = std::vector<int>;
    using Rectangle = std::vector<std::vector<int>>;
    using Polygon = std::vector<VI>;
    Polygon getSkyline(Rectangle& buildings)
    {
        Polygon h, ret;
        std::multiset<int> m; m.insert(0);
        for (auto& a : buildings)
        {
            h.emplace_back(VI({a[0], -a[2]}));
            h.emplace_back(VI({a[1], a[2]}));
        }
        sort(h.begin(), h.end(), [](const VI& a, const VI& b) -> bool
        {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        int prevHeight = 0, height = 0;
        for (auto& a : h)
        {
            if (a[1] < 0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            height = *(m.rbegin());
            if (prevHeight != height)
            {
                ret.emplace_back(VI({a[0], height}));
                prevHeight = height;
            }
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
