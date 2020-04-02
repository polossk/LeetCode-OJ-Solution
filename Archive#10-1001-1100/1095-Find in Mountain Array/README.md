# Find in Mountain Array

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg)
## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1095-cpp-f34b7d.svg)   | 8 ms    | 7.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode1095-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1095-rb-701516.svg)   | -       | -            |

## DESCRIPTION

*(This problem is an **interactive problem**.)*

You may recall that an array `A` is a *mountain array* if and only if:

* `A.length >= 3`
* There exists some `i` with `0 < i < A.length - 1` such that:
  * `A[0] < A[1] < ... A[i-1] < A[i]`
  * `A[i] > A[i+1] > ... > A[A.length - 1]`

Given a mountain array mountainArr, return the **minimum** index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

**You can't access the mountain array directly**.  You may only access the array using a `MountainArray` interface:

* `MountainArray.get(k)` returns the element of the array at index k (0-indexed).
* `MountainArray.length()` returns the length of the array.

Submissions making more than `100` calls to `MountainArray.get` will be judged *Wrong Answer*. Also, any solutions that attempt to circumvent the judge will result in disqualification.

## EXAMPLE 1

```plain
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
```

## EXAMPLE 2

```plain
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
```

## CONSTRAINTS

* `3 <= mountain_arr.length() <= 10000`
* `0 <= target <= 10^9`
* `0 <= mountain_arr.get(index) <= 10^9`

## SOLUTION

* 先通过类似三分的方法，找到峰顶的位置 `peak`
* 以 `peak` 为界再执行两次二分查找即可

## CODE

### C++

```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
    int target_, size_;
    int binSearch(MountainArray &mArr, int left, int right, bool is_inc)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int val = mArr.get(mid);
            if (val == target_) { return mid; }
            if (is_inc) val < target_ ? (left = mid + 1) : (right = mid - 1);
            else val < target_ ? (right = mid - 1) : (left = mid + 1);
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mArr)
    {
        this->size_ = mArr.length();
        this->target_ = target;
        int left = 0, right = size_ - 1;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            int val = mArr.get(mid);
            int mid_next = mArr.get(mid + 1);
            if (val < mid_next) left = mid + 1;
            else right = mid;
        }
        int peak = left;
        int tmp = binSearch(mArr, 0, peak, true);
        return tmp == -1 ? binSearch(mArr, peak + 1, size_ - 1, false) : tmp;
    }
};
```

### Python3

```python
```

### Ruby

