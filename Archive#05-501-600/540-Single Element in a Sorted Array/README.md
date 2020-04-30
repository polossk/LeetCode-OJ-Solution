# Single Element in a Sorted Array

![Medium](../../materials/-Medium-f0ad4e.svg) ![Binary_Search2](../../materials/二分查找-Binary_Search-009688.svg) ![Bit_Manipulation2](materials/位运算-Bit_Manipulation-009688.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode540-cpp-f34b7d.svg)   | 16 ms   | 11 Mb        |
| ![python](https://img.shields.io/badge/leetcode540-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode540-rb-701516.svg)   | 32 ms   | 9.9 Mb       |

## DESCRIPTION

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

## EXAMPLE 1

```plain
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
```

## EXAMPLE 2

```plain
Input: [3,3,7,7,10,11,11]
Output: 10
```

## NOTE

Your solution should run in O(log n) time and O(1) space.

## SOLUTION

* 二分查找，只需判断相邻下标的数字即可，其中 `mid = (l + r) / 2`
* `a^1` 的取值可以省去 `a&1` 的奇偶判断，当 `a` 为偶数时，`a^1 == a+1`，当 `a` 为奇数时，`a^1 == a-1`

## CODE

### C++

```cpp
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid ^ 1]) l = mid + 2;
            else r = mid;
        }
        return nums[l];
    }
};
```

### Python3


### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_non_duplicate(nums)
  nums[(0..nums.size).bsearch { |i| nums[i] != nums[i^1] }]
end
```
