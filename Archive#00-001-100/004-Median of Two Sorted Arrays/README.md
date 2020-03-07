# Median of Two Sorted Arrays

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg) ![Divide_and_Conquer](https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode004-cpp-f34b7d.svg)   | 32 ms   | 9.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode004-py-3572A5.svg) | 96 ms   | 12.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode004-rb-701516.svg)   | 52 ms   | 11.5 Mb      |

## DESCRIPTION

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume **nums1** and **nums2** cannot be both empty.

## EXAMPLE 1

```plain
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

## EXAMPLE 2

```plain
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

## SOLUTION

### 二分做法

* 一个有序数组的中位数的实际上是这个数组的中间划分，所划分出的两个子数组的大小相同，所以找多数组的中位数等价于寻找各自数组的划分位置，使其保持左右两边的个数平衡
* 所以只需要对其中一个数组的划分位置进行二分，便可以数值上直接确定另一个数组的可能划分位置
* 由于数组是有序的，在确定划分位置后根据中位数的定义，直接判断当前划分点是否正确即可

### 维护双数组的 k-th

* 中位数是*特殊*的 k-th 值：当数组长度为奇数时，中位数是 `(l+1)/2`-th 值；当数组长度为偶数时，相当于确定两个值 `l/2`-th 与 `l/2+1`-th 之后求其平均
* 对于 k-th 值，注意到数组是有序的，如果我们已经确定了前面的 `x` 个值，那么只需要确定剩余数组的第 `k-x` -th 值即可
* 可以通过二分确定 k-th 值，即先确定 `k/2`-th，再确定剩余部分的 `k/4`-th，如此循环
* 终止条件为 k 的取值为 1，此时即判断剩余数组的最小值，也就是两个数组剩余部分的第一个值

## CODE

### C++

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int l1 = nums1.size(), l2 = nums2.size();
        vector<int> &sh = l1 > l2 ? nums2 : nums1;
        vector<int> &lg = l1 > l2 ? nums1 : nums2;
        if (l1 < l2) swap(l1, l2); // l1 = lg.size(), l2 = sh.size()
        if (l2 == 0) return (lg[(l1 - 1) / 2] + lg[l1 / 2]) / 2.0;

        int l = 0, r = l2 * 2;
        while (l <= r)
        {
            int mid2 = (l + r) >> 1;
            int mid1 = l1 + l2 - mid2;
            int sh_lo = (mid2 == 0) ? INT_MIN : sh[(mid2 - 1) / 2];
            int lg_lo = (mid1 == 0) ? INT_MIN : lg[(mid1 - 1) / 2];
            int sh_hi = (mid2 == l2 * 2) ? INT_MAX : sh[mid2 / 2];
            int lg_hi = (mid1 == l1 * 2) ? INT_MAX : lg[mid1 / 2];
            if (lg_lo > sh_hi)
                l = mid2 + 1;
            else if (sh_lo > lg_hi)
                r = mid2 - 1;
            else return (max(sh_lo, lg_lo) + min(sh_hi, lg_hi)) / 2.0;
        }
        return -1;
    }
};
```

### Python3

```python
class Solution:
    def kth(self, nums1: List[int], nums2: List[int], idx1: int, idx2: int, k: int) -> int:
        l1, l2 = len(nums1), len(nums2)
        if idx1 >= l1: return nums2[k - 1]
        if idx2 >= l2: return nums1[k - 1]
        if k == 1: return min(nums1[idx1], nums2[idx2])
        if l1 - idx1 > l2 - idx2:
            print("call kth(nums2, nums1, {idx2}, {idx1}, {k}))
            return self.kth(nums2, nums1, idx2, idx1, k)
        p1 = min(l1 - idx1, k // 2)
        p2 = k - p1
        if nums1[idx1 + p1 - 1] < nums2[idx2 + p2 - 1]:
            print("call kth(nums1, nums2, {idx1 + p1}, {idx2}, {p2}))
            return self.kth(nums1, nums2, idx1 + p1, idx2, p2)
        else:
            print("call kth(nums1, nums2, {idx1}, {idx2 + p2}, {p1}))
            return self.kth(nums1, nums2, idx1, idx2 + p2, p1)
    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l = len(nums1) + len(nums2)
        hoge = self.kth(nums1, nums2, 0, 0, l // 2 + 1)
        if l % 2:
            return hoge
        else:
            hoge += self.kth(nums1, nums2, 0, 0, l // 2)
            return hoge / 2.0
```

### Ruby

```ruby
# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  a, b = [nums1, nums2].sort_by(&:size)
  m, n = a.size, b.size
  hoge = (m + n - 1) / 2
  i = (0...m).bsearch { |i| hoge - i - 1 < 0 || a[i] >= b[hoge - i - 1] } || m
  tmp = (a[i, 2] + b[hoge - i, 2]).sort
  (tmp[0] + tmp[1 - (m + n) % 2]) / 2.0
end
```
