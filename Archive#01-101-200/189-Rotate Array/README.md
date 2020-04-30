# Rotate Array

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode189-cpp-f34b7d.svg)   | 16 ms   | 8.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode189-py-3572A5.svg) | 60 ms   | 14.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode189-rb-701516.svg)   | 44 ms   | 9.9 Mb       |

## DESCRIPTION

Given an array, rotate the array to the right by *k* steps, where *k* is non-negative.

## EXAMPLE 1

```plain
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

## EXAMPLE 2

```plain
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

## NOTE

* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* Could you do it in-place with O(1) extra space?

## SOLUTION

* 模拟法：模拟右移
* 拼接法：直接拼接移动部分
* 调头法：假设原数组为 `ABCDE`，最终需要的结果为 `CDE-AB`，可以分别将需要移动的块翻转 `AB-CDE => BA-EDC`，然后再将整体翻转 `BAEDC => CDEAB`

## CODE

### C++

```cpp
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int len = nums.size();
        k %= len;
        reverse(nums.begin(), nums.begin() + (len - k));
        reverse(nums.begin() + (len - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```

### Python3

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        nums[:] = nums[-k:] + nums[:-k]
```

### Ruby

```ruby
# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def rotate(nums, k)
  nums.rotate!(-k)
end
```