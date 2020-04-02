# Product of Array Except Self

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode238-cpp-f34b7d.svg)   | 36 ms   | 10.3 Mb      |
| ![python](https://img.shields.io/badge/leetcode238-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode238-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array `nums` of n integers where *n* > 1,  return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

## EXAMPLE

```plain
Input:  [1,2,3,4]
Output: [24,12,8,6]
```

## CONSTRAINT

It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

## NOTE

Please solve it **without division** and in O(n).

## FOLLOW UP

Could you solve it with constant space complexity? (The output array **does not** count as extra space for the purpose of space complexity analysis.)

## SOLUTION

* 构造两个数组 `lhs[]` 与 `rhs[]` 使得其满足 `lhs[i] * nums[i] * rhs[i] == prod(nums) := nums[0] * nums[1] * ... * nums[n]`，显然有以下性质
* `lhs[i+1] := lhs[i] * nums[i]`
* `rhs[i-1] := rhs[i] * nums[i]`
* 先从左到右扫一遍，计算 `lhs[]`，然后再从右到左计算 `rhs[]`，注意到后者其实不需要全部记录，只需记录当前使用到的值即可

## CODE

### C++

```cpp
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int sz = nums.size();
        if (sz <= 1) return nums;
        vector<int> ans(sz, 1);
        for (int i = 0; i + 1 < sz; i++)
            ans[i + 1] = ans[i] * nums[i];
        int tmp = 1;
        for (int i = sz - 1; i >= 0; i--)
        {
            ans[i] *= tmp;
            tmp *= nums[i];
        }
        return ans;
    }
};
```

### Python3

### Ruby

### Java
