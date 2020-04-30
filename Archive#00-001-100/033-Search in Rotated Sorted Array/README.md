# Search in Rotated Sorted Array

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode033-cpp-f34b7d.svg)   | 8 ms    | 6.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode033-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode033-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

## EXAMPLE 1

```plain
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

## EXAMPLE 2

```plain
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

## SOLUTION

* 循环移位之后的数组仍保持局部的有序性，不妨假设原数组为 `[1, 2, 3, 4, 5, 6]`，移位操作之后为 `[4, 5, 6, 1, 2, 3]`，显然有 `nums[0] >= nums[-1]`（有序性），所以可以二分查找。
* 设置中央分隔符 `(mid, nums[mid])`。如果左半部分依旧满足有序性，即 `nums[left] <= nums[mid]`，说明左半部分是单调递增的；类似的，如果左半部分的有序性被破坏，即 `nums[left] > nums[mid]` 说明左半部分包含原数组的最小值（数组起点）。同样对右半部分这样分析可以得到类似的结果。
* 分类讨论。
  1. 左半部分单调递增，且 `nums[left] <= target < nums[mid]`，说明下一步需要在 `[left, mid)` 这个区间继续查找；
  2. 左半部分单调递增，但不满足上述不等式，说明左半部分一定不包含 `target` 这个数字，下一步应当在 `[mid + 1, right]` 中继续查找；
  3. 左半部分间断（则右半部分一定单调递增的），同时 `nums[mid] < target <= nums[right]`，说明下一步需要在 `[mid + 1, right]` 区间查找；
  4. 左半部分间断，但是不满足上述不等式，说明右半部分一定不包含 `target` 这个数字，下一步应当在 `[left, mid)` 中继续查找；
  5. 如果出现了长度为 2 的区间，此时的 `mid` 指针会与 `left` 重合，所以需要特判，即连续判断两次 `nums[mid]` 即可

## CODE

### C++

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[l])
            {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            }
            else if (nums[mid] < nums[l])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else r = mid - 1;
            }
            else l++;
        }
        return -1;
    }
};
```

### Python3

```python
```

### Ruby

### Java
