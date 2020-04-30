# Move Zeroes

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode202-cpp-f34b7d.svg)   | 12 ms   | 7.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode202-py-3572A5.svg) | 52 ms   | 15 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode202-rb-701516.svg)   | 40 ms   | 9.8 Mb       |

## DESCRIPTION

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

## EXAMPLE

```plain
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

## NOTE

1. You must do this **in-place** without making a copy of the array.
2. Minimize the total number of operations.

## SOLUTION

* 额外维护一个计数器 `non-zero` 来储存，当处理到第 i 个元素 `nums[i]` 时，前面所有非零元素的个数。如果 `nums[i] != 0`，则直接把 `nums[i]` 与 `nums[nz]` 这个位置交换值即可，然后 `nz++`，这样就保证了前面 `nz` 个数字都是非零元素

## CODE

### C++

```cpp
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (int i = 0, nz = 0, sz = nums.size(); i < sz; i++)
            if (nums[i])
                std::swap(nums[i], nums[nz++]);
    }
};
```

### Python3

```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zeros = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[i], nums[non_zeros] = nums[non_zeros], nums[i]
                non_zeros += 1
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  non_zeros = 0
  (0...nums.length).each {|i|
    if nums[i] != 0 then
      nums[i], nums[non_zeros] = nums[non_zeros], nums[i]
      non_zeros += 1
    end
  }
end
```
