# Reverse Pairs

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg) ![Divide_and_Conquer](https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg) ![Sort](https://img.shields.io/badge/排序-Sort-007ec6.svg) ![Binary_Indexed_Tree](https://img.shields.io/badge/树状数组-Binary_Indexed_Tree-007ec6.svg) ![Segment_Tree](https://img.shields.io/badge/线段树-Segment_Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode493-cpp-f34b7d.svg)   | 536 ms  | 77.1 Mb      |
| ![python](https://img.shields.io/badge/leetcode493-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode493-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array `nums`, we call `(i, j)` an **important reverse pair** if `i < j` and `nums[i] > 2*nums[j]`.

You need to return the number of important reverse pairs in the given array.

## NOTE

1. The length of the given array will not exceed `50,000`.
2. All the numbers in the input array are in the range of 32-bit integer.

## EXAMPLE 1

```plain
Input: [1,3,2,3,1]
Output: 2
```

## EXAMPLE 2

```plain
Input: [2,4,3,5,1]
Output: 3
```

## SOLUTION

* 求特殊的逆序对 `i < j && nums[i] > 2*nums[j]`
* 类似于归并排序的处理方式，将数组一分为二，最终答案显然等于只考虑左半部分的逆序对，只考虑右半部分的逆序对，和跨分界线的逆序对。对于左右部分，分别递归处理即可。对于跨分界线部分，新建两个指针同时从各自的头部开始查询是否满足 `i < j && nums[i] > 2*nums[j]` 定义即可。

## CODE

### C++

```cpp
class Solution
{
    int merge_sort(vector<int>::iterator first, vector<int>::iterator last)
    {
        if (last - first <= 1) return 0;
        auto mid = first + (last - first) / 2;
        int ret = merge_sort(first, mid) + merge_sort(mid, last);
        for (auto i = first, j = mid; i != mid; i++)
        {
            while (j != last && ( (*i) > 2LL * (*j) ) ) j++;
            ret += j - mid;
        }
        std::inplace_merge(first, mid, last);
        return ret;
    }
public:
    int reversePairs(vector<int>& nums)
    {
        return merge_sort(nums.begin(), nums.end());
    }
};
```

### Python3

### Ruby

### Java
