# Count of Smaller Numbers After Self

![Hard](../../materials/-Hard-e05d44.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg) ![Divide_and_Conquer](../../materials/分治法-Divide_and_Conquer-007ec6.svg) ![Sort](../../materials/排序-Sort-007ec6.svg) ![Binary_Indexed_Tree](../../materials/树状数组-Binary_Indexed_Tree-007ec6.svg) ![Segment_Tree](../../materials/线段树-Segment_Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode307-cpp-f34b7d.svg)   | 60 ms   | 26.1 Mb      |
| ![python](https://img.shields.io/badge/leetcode307-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode307-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.

## EXAMPLE

```plain
Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

## SOLUTION

* 把数组从中间劈开。
* 对于左半区的任意数字 `e`，满足条件的总数 `cnt` 由两部分贡献得到：此时右半区的所有比 `e` 小的数字个数，此时 `e` 所在半区的个数。
* 对于右半区的任意数字 `e`，满足条件的总数 `cnt` 由一部分贡献得到：此时 `e` 所在半区的个数。
* 那么类似于归并排序的方式，将其递归分拆，随着数组的合并，`i` 和 `j` 在逐渐增加的过程中，就可以完成统计。注意，统计结果需要累加到对应位置。
* 如样例 `[5, 2, 6, 1]`：第一步拆解成两部分 `[5, 2]` 和 `[6, 1]`；继续拆解 `[5]`，`[2]`，`[6]`，`[1]`；
* 然后开始合并统计：`[5]` 和 `[2]` 而言，显然有 `5 > 2`，所以对应的排序和统计结果为 `[[2, 5], [1, 0]]`，累加后的统计结果为 `[5:1, 2:0, 6:0, 1:0]`；`[6]` 和 `[1]` 而言，显然有 `6 > 1`，所以对应的排序和统计结果为 `[[1, 6], [1, 0]]`，累加后的统计结果为 `[5:1, 2:0, 6:1, 1:0]`；
* 对于 `[2, 5]` 和 `[1, 6]`，合并过程为 `1->2->5->6`：`1` 被合并进来，说明此时的剩下的左半部分的数字都比 `1` 大，所以统计结果为 `[5:1, 2:1, 6:0, 1:0]`；随后 `2` 被合并进来，说明此时它的值被固定住，只有剩下的值有可能会再次更改，所以此时的统计结果为 `[5:1, 2:1, 6:0, 1:0]`；下一步，`5` 被合并进来，说明它的值也被固定了；最后 `6` 被合并进来，此次归并完成，这次的统计结果为 `[5:1, 2:1, 6:0, 1:0]`；累积统计结果为 `[5:2, 2:1, 6:1, 1:0]`

## CODE

### C++

```cpp
class Solution
{
    void merge_sort(vector<int>::iterator _first, vector<int>::iterator _last,
        vector<int>::iterator cnt, vector<int>::iterator idx,
        vector<int>::iterator d_first
        )
    {
        int first = _first - d_first, last = _last - d_first;
        int length = last - first;

        if (length <= 1) return;
        auto mid = first + length / 2;
        auto _mid = _first + length / 2;
        merge_sort(_first, _mid, cnt, idx, d_first);
        merge_sort(_mid, _last, cnt, idx, d_first);
        vector<int> tmp; tmp.reserve(length);
        auto i = first, j = mid;
        int hoge = 0;
        while (i < mid || j < last)
        {
            if (j == last || (i < mid && 
                *(d_first + *(idx + i)) <= *(d_first + *(idx + j)) ) )
            {
                tmp.push_back( *(idx + i) );
                *(cnt + *(idx + i++)) += hoge;
            }
            else
            {
                tmp.push_back( *(idx + j++) ); hoge++;
            }
        }
        std::move(tmp.begin(), tmp.end(), idx + first);
    }

public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> cnt(n, 0), idx(n, 0);
        std::iota(idx.begin(), idx.end(), 0);
        merge_sort(nums.begin(), nums.end(), cnt.begin(), idx.begin(), nums.begin());
        return cnt;
    }
};
```

### Python3

```python
```

### Ruby

### Java
