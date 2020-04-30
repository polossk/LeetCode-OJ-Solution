# Next Permutation

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                                 | Runtime | Memory Usage |
| -------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode031--my--impl-cpp-f34b7d.svg)  | 8 ms    | 6.5 Mb       |
| ![cpp](https://img.shields.io/badge/leetcode031--std--impl-cpp-f34b7d.svg) | 8 ms    | 6.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode031-py-3572A5.svg)          | 44 ms   | 12.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode031-rb-701516.svg)            | -       | -            |

## DESCRIPTION

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place** and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

`1,2,3` → `1,3,2`

`3,2,1` → `1,2,3`

`1,1,5` → `1,5,1`

## SOLUTION

* 从后往前找到第一个减少的数字 A
* 从这个数字开始，找比它大的最小的数字 B
* 交换 A 和 B
* 把 A 之后的数字翻转

## CODE

### C++

```cpp
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0)
        {
            while (nums[j] <= nums[i]) j--;
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }

    // std impl
    void nextPermutation(vector<int> &nums)
    {
        std::next_permutation(nums.begin(), nums.end());
    }
};
```

### Python3

```python
from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j = len(nums) - 2, len(nums) - 1
        while i >= 0 and nums[i] >= nums[i + 1]: i -= 1
        if i >= 0:
            while nums[j] <= nums[i]: j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        i, j = i + 1, len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
```

### Ruby

### Java
